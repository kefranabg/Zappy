/*
** bct_cmd.c for bct_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Thu Jun 19 15:45:35 2014 abgral_f
** Last update Fri Jul  4 22:20:12 2014 abgral_f
*/

#include		"graphic.h"

int			bct_cmd(char **args, t_graphic *c)
{
  int			count;

  if (atoi(args[0]) < 0 || (unsigned int)atoi(args[0]) >= c->x
      || atoi(args[1]) < 0 || (unsigned int)atoi(args[1]) >= c->y)
    return (my_error("Unknown coordinates", FAILURE));
  c->map[atoi(args[0]) + atoi(args[1]) * c->x].isUpdate = TRUE;
  c->map[atoi(args[0]) + atoi(args[1]) * c->x].b.food = atoi(args[2]);
  count = -1;
  while (++count != NB_STONE)
    {
      c->map[atoi(args[0]) + atoi(args[1])
	     * c->x].b.stone[count] = atoi(args[3 + count]);
    }
  return (SUCCESS);
}
