/*
** read.c for read.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Sun May 11 12:55:25 2014 LOEB Thomas
** Last update Mon Jun  9 11:51:58 2014 LOEB Thomas
*/

#include		"server.h"

static int		nb_cmd(t_client *c)
{
  unsigned int		i;
  int			ret;

  i = -1;
  ret = 0;
  while (++i < BUFF_LEN)
    if (c->b.circular[i] == '\n')
      ++ret;
  return (ret);
}

static void		read_one_fd(t_server *s, t_select *sel)
{
  if (nb_cmd(s->tmp_clients) < 10 &&
      FD_ISSET(s->tmp_clients->socket, &sel->rdfds))
    {
      memset(s->tmp_clients->b.tmp, '\0', BUFF_LEN);
      if (rw(s->tmp_clients->socket,
	     s->tmp_clients->b.tmp, BUFF_LEN, R) == FAILURE)
	del_client(s, TRUE);
      else
	{
	  buffer_to_circular(&s->tmp_clients->b);
	  s->tmp_clients = s->tmp_clients->next;
	}
    }
  else
    s->tmp_clients = s->tmp_clients->next;
}

int			read_from_fds(t_server *s, t_select *sel)
{
  s->tmp_clients = s->clients;
  while (s->tmp_clients != NULL)
    read_one_fd(s, sel);
  if (s->graphic != NULL)
    {
      s->tmp_clients = s->graphic;
      read_one_fd(s, sel);
    }
  return (SUCCESS);
}
