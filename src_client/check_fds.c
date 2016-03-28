/*
** check_fds.c for check_fds.c in /home/chauch_a/rendu/PSU_2013_zappy
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed May  7 14:42:27 2014 LOEB Thomas
<<<<<<< HEAD
** Last update Fri Jul 11 17:11:48 2014 abgral_f
=======
** Last update Fri Jul 11 19:35:40 2014 Baptiste Acca
>>>>>>> 09b34583a1e8314459208570cd350de083b9db8a
*/

#include		"client.h"

static int		nb_cmd(t_client *c)
{
  unsigned int		i;
  unsigned int		ret;

  i = -1;
  ret = 0;
  while (++i < BUFF_LEN)
    if (c->b.circular[i] == '\n')
      ++ret;
  return (ret);
}

static int		check_socket(t_client *c, t_select *sel)
{
  if (nb_cmd(c) == 0 && FD_ISSET(c->socket, &sel->rdfds))
    {
      memset(c->b.tmp, '\0', BUFF_LEN);
      if (rw(c->socket, c->b.tmp, BUFF_LEN, R) == FAILURE)
	return (FAILURE);
      buffer_to_circular(&c->b);
    }
  return (SUCCESS);
}

int			check_fds(t_client *c)
{
  t_select		sel;

  if (raw_mode_init(c) == FAILURE)
    return (FAILURE);
  sel.tv.tv_usec = 0;
  while (stop(STOP_VALUE) == STOP_VALUE)
    {
      FD_ZERO(&sel.rdfds);
      FD_SET(c->socket, &sel.rdfds);
      FD_SET(STDIN_FILENO, &sel.rdfds);
      sel.maxfd = c->socket + 1;
      sel.tv.tv_sec = 1;
      if (my_select(&sel, R) == -1 && stop(STOP_VALUE) != STOP_VALUE)
	return (close_client(c, my_perror(SYSCALL("select"), FAILURE)));
      if ((sel.retSelect > 0 && check_socket(c, &sel) == FAILURE)
	  || check_cmds(c) == FAILURE)
	return (close_client(c, FAILURE));
      if (FD_ISSET(STDIN_FILENO, &sel.rdfds))
	if (manual_action(c) == FAILURE)
	  return (close_client(c, FAILURE));
      if (c->list_action)
	exec_action(c);
    }
  return (close_client(c, SUCCESS));
}
