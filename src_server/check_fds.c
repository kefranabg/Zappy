/*
** check_fds.c for check_fds.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu May  8 13:14:20 2014 LOEB Thomas
** Last update Sat Jul  5 18:41:15 2014 abgral_f
*/

#include		"server.h"

static void		set_rdfds(t_server *s, t_select *sel)
{
  FD_ZERO(&sel->rdfds);
  sel->maxfd = s->socket;
  FD_SET(s->socket, &sel->rdfds);
  if (s->graphic != NULL)
    {
      if (s->graphic->socket > sel->maxfd)
	sel->maxfd = s->graphic->socket;
      FD_SET(s->graphic->socket, &sel->rdfds);
    }
  s->tmp_clients = s->clients;
  while (s->tmp_clients != NULL)
    {
      if (s->tmp_clients->socket > sel->maxfd)
	sel->maxfd = s->tmp_clients->socket;
      FD_SET(s->tmp_clients->socket, &sel->rdfds);
      s->tmp_clients = s->tmp_clients->next;
    }
  ++sel->maxfd;
}

static void		set_fds(t_server *s, t_select *sel)
{
  FD_ZERO(&sel->wrfds);
  if (s->graphic != NULL && s->graphic->send[0] != '\0')
    FD_SET(s->graphic->socket, &sel->wrfds);
  s->tmp_clients = s->clients;
  while (s->tmp_clients != NULL)
    {
      if (s->tmp_clients->send[0] != '\0')
	FD_SET(s->tmp_clients->socket, &sel->wrfds);
      s->tmp_clients = s->tmp_clients->next;
    }
  set_rdfds(s, sel);
}

static void		set_timer_egg(t_server *s, t_select *sel)
{
  s->tmp_teams = s->teams;
  while (s->tmp_teams != NULL)
    {
      s->tmp_teams->tmp_eggs = s->tmp_teams->eggs;
      while (s->tmp_teams->tmp_eggs != NULL)
	{
	  if (s->tmp_teams->tmp_eggs->isThereAction == FALSE &&
	      s->tmp_teams->tmp_eggs->action_life.usec < sel->tv.tv_usec)
	    sel->tv.tv_usec = s->tmp_teams->tmp_eggs->action_life.usec;
	  if (s->tmp_teams->tmp_eggs->isThereAction == TRUE &&
	      s->tmp_teams->tmp_eggs->action.usec < sel->tv.tv_usec)
	    sel->tv.tv_usec = s->tmp_teams->tmp_eggs->action.usec;
	  s->tmp_teams->tmp_eggs = s->tmp_teams->tmp_eggs->next;
	}
      s->tmp_teams = s->tmp_teams->next;
    }
}

static void		set_timer_client(t_server *s, t_select *sel)
{
  s->tmp_clients = s->clients;
  while (s->tmp_clients != NULL)
    {
      if (s->tmp_clients->isConnected == TRUE)
	{
	  if (s->tmp_clients->action_life.usec < sel->tv.tv_usec)
	    sel->tv.tv_usec = s->tmp_clients->action_life.usec;
	  if (s->tmp_clients->isThereAction == TRUE &&
	      s->tmp_clients->action.usec < sel->tv.tv_usec)
	    sel->tv.tv_usec = s->tmp_clients->action.usec;
	}
      s->tmp_clients = s->tmp_clients->next;
    }
  set_timer_egg(s, sel);
  if (s->time <= sel->tv.tv_usec)
    sel->tv.tv_usec -= s->time;
  else
    sel->tv.tv_usec = 0;
  memcpy(&sel->save, &sel->tv, sizeof(struct timeval));
}

int			check_fds(t_server *s)
{
  t_select		sel;

  sel.tv.tv_sec = 0;
  s->time = 0;
  while (stop(STOP_VALUE) == STOP_VALUE)
    {
      set_fds(s, &sel);
      sel.tv.tv_usec = SEC_TO_USEC;
      set_timer_client(s, &sel);
      if (my_select(&sel, RW) == -1 && stop(STOP_VALUE) <= STOP_VALUE)
	return (close_server(s, my_perror(SYSCALL("select"), FAILURE)));
      update_timers(s, &sel);
      s->time = clock();
      if (sel.retSelect > 0)
	{
	  write_on_fds(s, &sel);
	  read_from_fds(s, &sel);
	  if (FD_ISSET(s->socket, &sel.rdfds))
	    add_client(s);
	}
      check_cmds(s);
      refill_map(s);
      s->time = clock() - s->time;
    }
  return (close_server(s, SUCCESS));
}
