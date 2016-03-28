/*
** ppo_cmd.c for ppo_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Mon Jun 23 17:55:07 2014 abgral_f
** Last update Wed Jul  9 15:46:35 2014 abgral_f
*/

#include		"graphic.h"

int			ppo_cmd(char **args, t_graphic *c)
{
  t_client		*tmp;

  if (check_player(atoi(args[0] + 1), c) == FAILURE)
    return (my_error("Unknown player id", FAILURE));
  if (atoi(args[1]) < 0 || (unsigned int)atoi(args[1]) >= c->x
      || atoi(args[2]) < 0 || (unsigned int)atoi(args[2]) >= c->y)
    return (my_error("Unknown coordinates", FAILURE));
  if (atoi(args[3]) < 1 || atoi(args[3]) > 4)
    return (my_error("Unknown direction", FAILURE));
  tmp = c->client;
  while (tmp->id != (unsigned int)atoi(args[0] + 1))
    tmp = tmp->next;
  tmp->direction = atoi(args[3]) - 1;
  if (args[4] == NULL &&
      ((unsigned int)atoi(args[1]) != tmp->x
       || (unsigned int)atoi(args[2]) != tmp->y))
    {
      tmp->last_coords[0] = tmp->x;
      tmp->last_coords[1] = tmp->y;
      tmp->anim = MOVES;
      tmp->count_anim = 0;
  }
  tmp->x = atoi(args[1]);
  tmp->y = atoi(args[2]);
  return (SUCCESS);
}
