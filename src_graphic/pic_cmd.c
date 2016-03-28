/*
** pic_cmd.c for pic_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jun 24 12:57:32 2014 abgral_f
** Last update Sat Jul  5 14:42:14 2014 abgral_f
*/

#include		"graphic.h"

int			pic_cmd(char **args, t_graphic *c)
{
  t_client		*tmp;
  int			count;

  if (atoi(args[0]) < 0 || (unsigned int)atoi(args[0]) >= c->x
      || atoi(args[1]) < 0 || (unsigned int)atoi(args[1]) >= c->y)
    return (my_error("Unknown coordinates", FAILURE));
  if (atoi(args[2]) > 8 || atoi(args[2]) < 1)
    return (my_error("Invalid lvl", FAILURE));
  count = 3;
  while (args[count] != NULL)
    {
      if (check_player(atoi(args[count] + 1), c) == FAILURE)
	return (my_error("Unknown player id", FAILURE));
      tmp = c->client;
      while (tmp->id != (unsigned int)atoi(args[count] + 1))
	tmp = tmp->next;
      tmp->isAscending = atoi(args[2]);
      tmp->anim = INCANT;
      tmp->count_anim = 0;
      count++;
    }
  return (SUCCESS);
}
