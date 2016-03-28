/*
** check_cmds.c for check_cmds.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon May 12 17:03:05 2014 LOEB Thomas
** Last update Tue Jun 24 13:40:23 2014 LOEB Thomas
*/

#include		"server.h"

static int		check_graphic_cmds(t_server *s)
{
  int			pos;

  if ((pos = pos_cmd(&s->graphic->b)) != -1)
    {
      get_cmd(&s->graphic->b, pos);
      if (parse_cmd(&s->p, s->graphic->b.tmp) == SUCCESS)
	action_graphic(s);
    }
  return (SUCCESS);
}

static int		check_cmd(t_server *s)
{
  s->tmp_clients->action = action_create(s);
  if (s->tmp_clients->action.cmd != NULL)
    {
      s->tmp_clients->isThereAction = TRUE;
      if (s->tmp_clients->action.id == 9)
	check_elevation_send(s);
      else
	s->tmp_clients = s->tmp_clients->next;
    }
  else
    {
      if (s->tmp_clients->action.id == 9 &&
	  rw(s->tmp_clients->socket, KO("\n"), strlen(KO("\n")), W) == FAILURE)
	del_client(s, TRUE);
      else
	s->tmp_clients = s->tmp_clients->next;
    }
  return (SUCCESS);
}

static int		check_name_team(t_server *s)
{
  if (strcmp(s->p.line, GRAPHIC_CLIENT("")) == 0)
    return (connect_graphic(s));
  s->tmp_teams = s->teams;
  while (s->tmp_teams != NULL && strcmp(s->tmp_teams->name, s->p.line) != 0)
    s->tmp_teams = s->tmp_teams->next;
  if (s->tmp_teams == NULL || (s->tmp_teams->nb_remaining <= 0 &&
  			       s->tmp_teams->nb_egg_remaining <= 0))
    {
      rw(s->tmp_clients->socket, "0\n", 2, W);
      del_client(s, FALSE);
      printf((s->tmp_teams == NULL) ?
	     "Client disconnected: unknown team name\n" :
	     "Client disconnected: not enough place in this team\n");
      return (SUCCESS);
    }
  s->tmp_clients->team = s->tmp_teams;
  s->tmp_clients->isConnected = TRUE;
  write_nb_and_size(s);
  if (s->tmp_teams->nb_egg_remaining != 0)
    take_last_egg(s);
  else
    complete_client(s);
  printf("Client connected\n");
  s->tmp_clients = s->tmp_clients->next;
  return (SUCCESS);
}

int			check_cmds(t_server *s)
{
  int			pos;

  s->tmp_clients = s->clients;
  while (s->tmp_clients != NULL)
    if (s->tmp_clients->isThereAction == FALSE &&
	s->tmp_clients->isAscending == -1 &&
	(pos = pos_cmd(&s->tmp_clients->b)) != -1)
      {
	get_cmd(&s->tmp_clients->b, pos);
	if (parse_cmd(&s->p, s->tmp_clients->b.tmp) == SUCCESS)
	  if (s->tmp_clients->team == NULL)
	    check_name_team(s);
	  else
	    check_cmd(s);
	else
	  s->tmp_clients = s->tmp_clients->next;
      }
    else
      s->tmp_clients = s->tmp_clients->next;
  if (s->graphic != NULL)
    check_graphic_cmds(s);
  return (SUCCESS);
}
