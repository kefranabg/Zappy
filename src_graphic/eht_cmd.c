/*
** eht_cmd.c for eht_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jun 24 20:40:21 2014 abgral_f
** Last update Wed Jul  2 15:16:10 2014 abgral_f
*/

#include		"graphic.h"

int			eht_cmd(char **args, t_graphic *c)
{
  t_egg			*tmp;

  if (check_egg(atoi(args[0] + 1), c) == FAILURE)
    return (my_error("Unknown egg id", FAILURE));
  tmp = c->eggs;
  while (tmp->id != (unsigned int)atoi(args[0] + 1))
    tmp = tmp->next;
  tmp->isHatched = TRUE;
  return (SUCCESS);
}
