/*
** check_fds.c for check_fds.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 14:42:27 2014 LOEB Thomas
** Last update Sat Jul 12 15:49:10 2014 abgral_f
*/

#include		"graphic.h"

static int		check_stdin(t_graphic *c, t_select *sel)
{
  if (FD_ISSET(STDIN_FILENO, &sel->rdfds))
    {
      if (my_getline(&c->l) > 0 && c->l.line[0] != '\0')
 	{
	  if (rw(c->socket, c->l.line, c->l.len_line, W) == FAILURE)
	    return (FAILURE);
	  memset(c->l.line, '\0', c->l.len_line);
	}
    }
  return (SUCCESS);
}

static int		nb_cmd(t_graphic *c)
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

static int		check_socket(t_graphic *c, t_select *sel)
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

int			check_fds(t_graphic *c)
{
  t_select		sel;

  c->teams = NULL;
  sel.tv.tv_usec = 0;
  sel.tv.tv_sec = 0;
  while (stop(STOP_VALUE) == STOP_VALUE)
    {
      FD_ZERO(&sel.rdfds);
      FD_SET(STDIN_FILENO, &sel.rdfds);
      FD_SET(c->socket, &sel.rdfds);
      sel.maxfd = c->socket + 1;
      if (my_select(&sel, RW) == -1 && stop(STOP_VALUE) != STOP_VALUE)
	return (close_graphic(c, my_perror(SYSCALL("select"), FAILURE)));
      if ((sel.retSelect > 0 &&
	   (check_stdin(c, &sel) == FAILURE ||
	    check_socket(c, &sel) == FAILURE)) || check_cmds(c) == FAILURE)
	return (close_graphic(c, FAILURE));
      if (c->teams != NULL)
	if (display_sdl(c) == FAILURE)
	  return (close_graphic(c, FAILURE));
    }
  return (close_graphic(c, SUCCESS));
}
