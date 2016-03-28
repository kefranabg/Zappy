/*
** rw.c for rw.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 15:16:42 2014 LOEB Thomas
** Last update Sat Jul 12 12:25:26 2014 abgral_f
*/

#include		"common.h"

static int		read_simple(int fd, void *buf, size_t count)
{
  if (read(fd, buf, count) <= 0)
    return (my_perror(SYSCALL("read"), FAILURE));
  return (SUCCESS);
}

static int		write_loop(int fd, const void *buf, size_t count)
{
  unsigned int		i;
  int			ret;

  i = 0;
  while (i < count)
    {
      if ((ret = write(fd, buf + i, count - i)) <= 0)
	return (my_perror(SYSCALL("write"), FAILURE));
      if (stop(STOP_VALUE) == STOP_BRK_PIPE)
	{
	  stop(STOP_RESET);
	  return (my_error(BRK_PIPE, FAILURE));
	}
      i += ret;
    }
  return (SUCCESS);
}

int			rw(int fd, void *buf, size_t count, e_mode flag)
{
  if (flag == R)
    return (read_simple(fd, buf, count));
  else if (flag == W)
    return (write_loop(fd, buf, count));
  else
    return (FAILURE);
}
