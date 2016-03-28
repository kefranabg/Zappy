/*
** exec_mct.c for exec_mct.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 13:13:04 2014 LOEB Thomas
** Last update Tue Jun 10 14:17:06 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_mct(t_server *s)
{
  unsigned int		i;
  t_client		*tmp;

  if (write_graphic(s) == FAILURE)
    return (FALSE);
  i = -1;
  while (++i < (unsigned int)(s->x * s->y - 1))
    {
      exec_bct_fill(s, i % s->x, i / s->x);
      if (rw(s->graphic->socket, s->graphic->send,
	     strlen(s->graphic->send), W) == FAILURE)
	{
	  tmp = s->tmp_clients;
	  s->tmp_clients = s->graphic;
	  del_client(s, TRUE);
	  s->tmp_clients = tmp;
	  return (FALSE);
	}
      memset(s->graphic->send, '\0', BUFF_LEN);
    }
  exec_bct_fill(s, s->x - 1, s->y - 1);
  return (TRUE);
}
