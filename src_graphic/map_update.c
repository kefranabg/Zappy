/*
** map_update.c for map_update.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Jul  2 17:10:58 2014 abgral_f
** Last update Wed Jul  9 18:13:51 2014 abgral_f
*/

#include		"graphic.h"

int			is_map_update(t_graphic *c)
{
  unsigned int		count;
  char			*cmd;

  if (c->map == NULL)
    return (FAILURE);
  count = -1;
  while (++count != c->x * c->y)
    {
      if (c->map[count].isUpdate == FALSE)
	{
	  if ((cmd = malloc(sizeof (*cmd) * (7 + nbrlen(count % c->x)
					     + nbrlen(count / c->x)))) == NULL)
	    return (my_perror(SYSCALL("malloc"), FAILURE));
	  memset(cmd, '\0', 7 + nbrlen(count % c->x) + nbrlen(count / c->x));
	  strcat(cmd, "bct ");
	  nbr_to_str(count % c->x, &cmd[strlen(cmd)], " ");
	  nbr_to_str(count / c->x, &cmd[strlen(cmd)], "\n");
	  write(c->socket, cmd, strlen(cmd));
	  free(cmd);
	  return (FAILURE);
	}
    }
  return (SUCCESS);
}
