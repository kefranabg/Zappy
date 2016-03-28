/*
** pfk_cmd.c for pfk_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jun 24 17:07:50 2014 abgral_f
** Last update Sat Jul  5 18:27:16 2014 abgral_f
*/

#include		"graphic.h"

int			pfk_cmd(char **args, t_graphic *c)
{
  t_client              *tmp;

  if (check_player(atoi(args[0] + 1), c) == FAILURE)
    return (my_error("Unknown player id", FAILURE));
  tmp = c->client;
  while (tmp->id != (unsigned int)atoi(args[0] + 1))
    tmp = tmp->next;
  tmp->anim = LAY;
  tmp->count_anim = 0;
  return (SUCCESS);
}
