/*
** exec_forward.c for exec_forward.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 13:21:25 2014 LOEB Thomas
** Last update Thu Jun 19 17:02:44 2014 LOEB Thomas
*/

#include		"server.h"

static void		exec_push_delete(t_server *s, t_client **c)
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

static void		exec_push_graphic(t_server *s, t_client **tmp)
{
  t_client		*swap;

  swap = s->tmp_clients;
  s->tmp_clients = (*tmp);
  exec_ppo(s);
  if (s->tmp_clients->isAscending != -1)
    {
      exec_pie(s, 0);
      exec_plv(s);
      exec_bct(s);
    }
  s->tmp_clients = swap;
}

static int		g_x[4] =
  {
    0,
    1,
    0,
    -1
  };

static int		g_y[4] =
  {
    -1,
    0,
    1,
    0
  };

static void		exec_push_send(t_server *s, t_client **tmp, char *send)
{
  (*tmp)->x = ((*tmp)->x + g_x[s->tmp_clients->direction]) % s->x;
  if ((int)(*tmp)->x < 0)
    (*tmp)->x += s->x;
  (*tmp)->y = ((*tmp)->y + g_y[s->tmp_clients->direction]) % s->y;
  if ((int)(*tmp)->y < 0)
    (*tmp)->y += s->y;
  if (s->graphic != NULL)
    exec_push_graphic(s, tmp);
  (*tmp)->isAscending = -1;
  send[13] = get_orientation(s, (*tmp), s->tmp_clients);
  if (rw((*tmp)->socket, send, strlen(MOVE), W) == FAILURE)
    exec_push_delete(s, tmp);
  else
    (*tmp) = (*tmp)->next;
}

bool			exec_push(t_server *s)
{
  t_client		*tmp;
  char			send[17];

  exec_pex(s);
  tmp = s->clients;
  strcpy(send, MOVE);
  while (tmp != NULL)
    if (tmp != s->tmp_clients &&
	tmp->x == s->tmp_clients->x &&
	tmp->y == s->tmp_clients->y)
      exec_push_send(s, &tmp, send);
    else
      tmp = tmp->next;
  strcpy(s->tmp_clients->send, OK("\n"));
  if (send[13] == ORIENTATION[0])
    strcpy(s->tmp_clients->send, KO("\n"));
  return (FALSE);
}
