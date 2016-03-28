/*
** plv_cmd.c for plv_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Mon Jun 23 18:25:57 2014 abgral_f
** Last update Wed Jul  2 15:11:30 2014 abgral_f
*/

#include		"graphic.h"

int			plv_cmd(char **args, t_graphic *c)
{
  t_client              *tmp;

  if (check_player(atoi(args[0] + 1), c) == FAILURE)
    return (my_error("Unknown player id", FAILURE));
  if (atoi(args[1]) > 8 || atoi(args[1]) < 1)
    return (my_error("Invalid lvl", FAILURE));
  tmp = c->client;
  while (tmp->id != (unsigned int)atoi(args[0] + 1))
    tmp = tmp->next;
  tmp->lvl = atoi(args[1]);
  return (SUCCESS);
}
