/*
** exec_forward.c for exec_forward.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 13:21:25 2014 LOEB Thomas
** Last update Thu Jun 12 16:00:48 2014 LOEB Thomas
*/

#include		"server.h"

static void		exec_broadcast_delete(t_server *s, t_client **c)
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

static void		exec_broadcast_send(t_server *s, t_client **tmp,
					    char *send, unsigned int len)
{
  send[8] = get_orientation(s, (*tmp), s->tmp_clients);
  if (rw((*tmp)->socket, send, len, W) == FAILURE)
    exec_broadcast_delete(s, tmp);
  else
    (*tmp) = (*tmp)->next;
}

bool			exec_broadcast(t_server *s)
{
  t_client		*tmp;
  char			send[ARG_LEN + 12];
  unsigned int		len;

  tmp = s->clients;
  strcpy(send, MSG);
  strcpy(send + strlen(send), s->tmp_clients->action.param);
  send[strlen(send)] = '\n';
  len = strlen(send);
  while (tmp != NULL)
    if (tmp != s->tmp_clients)
      exec_broadcast_send(s, &tmp, send, len);
    else
      tmp = tmp->next;
  strcpy(s->tmp_clients->send, OK("\n"));
  exec_pbc(s);
  return (FALSE);
}
