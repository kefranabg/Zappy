/*
** check_elevation.c for check_elevation.c in /home/loeb_t/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu Jun 19 16:07:30 2014 LOEB Thomas
** Last update Thu Jul 10 14:19:13 2014 LOEB Thomas
*/

#include		"server.h"

static int		g_ascend[LEVEL_MAX - 1][NB_STONE + 1] =
  {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
  };

static void		check_elevation_delete(t_server *s, t_client **c)
{
  t_client		*tmp;

  tmp = *c;
  *c = s->tmp_clients;
  s->tmp_clients = tmp;
  tmp = tmp->next;
  del_client(s, TRUE);
  s->tmp_clients = *c;
  *c = tmp;
}

static int		check_elevation_fill(t_server *s, t_client *tmp, char *send)
{
  tmp->isThereAction = TRUE;
  tmp->isAscending = s->tmp_clients->id;
  memcpy(&tmp->action, &s->tmp_clients->action, sizeof(t_action));
  if (rw(tmp->socket, send, strlen(send), W) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

bool			check_elevation_send(t_server *s)
{
  t_client		*tmp;
  char			send[20];

  strcpy(send, ELEVATION_LAUNCH("\n"));
  tmp = s->clients;
  while (tmp != NULL)
    if (tmp != s->tmp_clients && tmp->x == s->tmp_clients->x &&
	tmp->y == s->tmp_clients->y && tmp->level == s->tmp_clients->level)
      {
	if (check_elevation_fill(s, tmp, send) == FAILURE)
	  check_elevation_delete(s, &tmp);
	else
	  tmp = tmp->next;
      }
    else
      tmp = tmp->next;
  exec_pic(s);
  if (check_elevation_fill(s, s->tmp_clients, send) == FAILURE)
    del_client(s, TRUE);
  else
    s->tmp_clients = s->tmp_clients->next;
  return (TRUE);
}

static bool		check_elevation_nbr(t_server *s)
{
  t_client		*tmp;
  unsigned int		i;

  i = 0;
  tmp = s->clients;
  while (tmp != NULL)
    {
      if (tmp->x == s->tmp_clients->x && tmp->y == s->tmp_clients->y &&
	  tmp->level == s->tmp_clients->level)
	++i;
      tmp = tmp->next;
    }
  if ((int)i < g_ascend[s->tmp_clients->level - 1][0])
    return (FALSE);
  i = -1;
  while (++i < NB_STONE)
    if (s->map[s->tmp_clients->x + s->tmp_clients->y * s->x].stone[i] <
	g_ascend[s->tmp_clients->level - 1][i + 1])
      return (FALSE);
  i = -1;
  while (++i < NB_STONE)
    s->map[s->tmp_clients->x + s->tmp_clients->y * s->x].stone[i] -=
      g_ascend[s->tmp_clients->level - 1][i + 1];
  return (TRUE);
}

bool			check_elevation(t_server *s)
{
  if (s->tmp_clients->level == LEVEL_MAX || check_elevation_nbr(s) == FALSE)
    return (FALSE);
  return (TRUE);
}
