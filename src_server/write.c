/*
** write.c for write.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Sun May 11 12:54:28 2014 LOEB Thomas
** Last update Sat Jul 12 15:39:57 2014 abgral_f
*/

#include		"server.h"

int			write_nb_and_size(t_server *s)
{
  nbr_to_str(s->tmp_teams->nb_remaining + s->tmp_teams->nb_egg_remaining,
	     s->tmp_clients->send, "\n");
  nbr_to_str(s->x, s->tmp_clients->send + strlen(s->tmp_clients->send), " ");
  nbr_to_str(s->y, s->tmp_clients->send + strlen(s->tmp_clients->send), "\n");
  return (SUCCESS);
}

static void		write_one_fd(t_server *s, t_select *sel)
{
  if (s->tmp_clients->send[0] != '\0' &&
      FD_ISSET(s->tmp_clients->socket, &sel->wrfds) &&
      rw(s->tmp_clients->socket, s->tmp_clients->send,
	 strlen(s->tmp_clients->send), W) == FAILURE)
    del_client(s, TRUE);
  else
    {
      memset(s->tmp_clients->send, '\0', BUFF_LEN);
      s->tmp_clients = s->tmp_clients->next;
    }
}

int			write_on_fds(t_server *s, t_select *sel)
{
  s->tmp_clients = s->clients;
  while (s->tmp_clients != NULL)
    write_one_fd(s, sel);
  if (s->graphic != NULL)
    {
      s->tmp_clients = s->graphic;
      write_one_fd(s, sel);
    }
  return (SUCCESS);
}

int			write_graphic(t_server *s)
{
  t_client		*tmp;

  if (s->graphic == NULL)
    return (FAILURE);
  if (s->graphic->send[0] == '\0')
    return (SUCCESS);
  if (rw(s->graphic->socket, s->graphic->send,
         strlen(s->graphic->send), W) == FAILURE)
    {
      tmp = s->tmp_clients;
      s->tmp_clients = s->graphic;
      del_client(s, TRUE);
      s->tmp_clients = tmp;
      return (FAILURE);
    }
  memset(s->graphic->send, '\0', BUFF_LEN);
  return (SUCCESS);
}
