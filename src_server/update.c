/*
** update.c for update.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu May 29 18:13:05 2014 LOEB Thomas
** Last update Thu Jun 19 17:52:29 2014 LOEB Thomas
*/

#include		"server.h"

static bool		update_client_life(t_server *s, unsigned long passed)
{
  if (passed >= (unsigned long)s->tmp_clients->action_life.usec)
    {
      s->tmp_clients->action_life = action_life(s->delay);
      --s->tmp_clients->life;
      if (s->tmp_clients->life == 0)
	{
	  rw(s->tmp_clients->socket, DEATH("\n"), strlen(DEATH("\n")), W);
	  printf("Client %u is dead\n", s->tmp_clients->id);
	  return (TRUE);
	}
      printf("Client %u lost one life\n", s->tmp_clients->id);
    }
  else
    s->tmp_clients->action_life.usec -= passed;
  return (FALSE);
}

static void		update_client_timers(t_server *s, unsigned long passed)
{
  bool			delClient;

  if (s->tmp_clients->isConnected == TRUE)
    {
      if ((delClient = update_client_life(s, passed)) == FALSE &&
	  s->tmp_clients->isThereAction == TRUE)
	{
	  if (passed >= (unsigned long)s->tmp_clients->action.usec)
	    {
	      s->tmp_clients->isThereAction = FALSE;
	      delClient = (*s->tmp_clients->action.exec)(s);
	      printf("Client %u executed '%s'\n",
		     s->tmp_clients->id, s->tmp_clients->action.cmd);
	    }
	  else
	    s->tmp_clients->action.usec -= passed;
	}
      if (delClient == TRUE)
	del_client(s, TRUE);
      else
	s->tmp_clients = s->tmp_clients->next;
    }
  else
    s->tmp_clients = s->tmp_clients->next;
}

static bool		update_egg_life(t_server *s, unsigned long passed)
{
  if (passed >= (unsigned long)s->tmp_teams->tmp_eggs->action_life.usec)
    {
      s->tmp_teams->tmp_eggs->action_life = action_life(s->delay);
      --s->tmp_teams->tmp_eggs->life;
      if (s->tmp_teams->tmp_eggs->life == 0)
	{
	  exec_edi(s);
	  printf("Egg is dead\n");
	  return (TRUE);
	}
      printf("Egg lost one life\n");
    }
  else
    s->tmp_teams->tmp_eggs->action_life.usec -= passed;
  return (FALSE);
}

static void		update_egg_timers(t_server *s, unsigned long passed)
{
  s->tmp_teams->tmp_eggs = s->tmp_teams->eggs;
  while (s->tmp_teams->tmp_eggs != NULL)
    if (s->tmp_teams->tmp_eggs->isThereAction == FALSE)
      if (update_egg_life(s, passed) == TRUE)
	del_egg(s);
      else
	s->tmp_teams->tmp_eggs = s->tmp_teams->tmp_eggs->next;
    else
      {
	if (passed >= (unsigned long)s->tmp_teams->tmp_eggs->action.usec)
	  {
	    s->tmp_teams->tmp_eggs->isThereAction = FALSE;
	    ++s->tmp_teams->nb_egg_remaining;
	    exec_eht(s);
	    printf("Egg is now open\n");
	  }
	else
	  s->tmp_teams->tmp_eggs->action.usec -= passed;
	s->tmp_teams->tmp_eggs = s->tmp_teams->tmp_eggs->next;
      }
}

void			update_timers(t_server *s, t_select *sel)
{
  unsigned long		passed;

  passed = s->time + (sel->save.tv_usec - sel->tv.tv_usec);
  s->tmp_teams = s->teams;
  while (s->tmp_teams != NULL)
    {
      update_egg_timers(s, passed);
      s->tmp_teams = s->tmp_teams->next;
    }
  s->tmp_clients = s->clients;
  while (s->tmp_clients != NULL)
    update_client_timers(s, passed);
}
