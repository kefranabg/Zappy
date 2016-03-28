/*
** check_cmds.c for check_cmds.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue May 13 12:39:09 2014 LOEB Thomas
** Last update Fri Jul 11 15:33:18 2014 CHAUCHET Alan
*/

#include		"client.h"

static int		check_connection(t_client *c)
{
  if (strcmp(c->p.line, WELCOME_CLIENT("")) == 0)
    {
      if (rw(c->socket, c->name, strlen(c->name), W) == FAILURE ||
	  rw(c->socket, "\n", 1, W) == FAILURE)
	return (FAILURE);
    }
  else if (c->p.len == 1)
    {
      if ((c->remaining = getnbr(c->p.line)) <= 0)
	return (FAILURE);
    }
  else if (c->p.len == 2)
    {
      if ((c->x = getnbr(c->p.cmd[0])) <= 0 ||
	  (c->y = getnbr(c->p.cmd[1])) <= 0)
	return (FAILURE);
      c->connected = TRUE;
    }
  else
    return (FAILURE);
  return (SUCCESS);
}

int			check_cmds(t_client *c)
{
  int			pos;

  if ((pos = pos_cmd(&c->b)) != -1)
    {
      get_cmd(&c->b, pos);
      if (parse_cmd(&c->p, c->b.tmp) == FAILURE)
	return (CONTINUE);
      printf("server : (%s)\n", c->p.line);
      if (c->connected == FALSE)
	return (check_connection(c));
      else if (strcmp(c->p.line, DEATH("")) == 0)
	return (FAILURE);
    }
  return (SUCCESS);
}
