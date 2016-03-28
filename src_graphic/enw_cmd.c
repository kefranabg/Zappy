/*
** enw_cmd.c for enw_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jun 24 18:50:50 2014 abgral_f
** Last update Sat Jul  5 18:29:14 2014 abgral_f
*/

#include		"graphic.h"

static void		set_egg_position(char **args, t_graphic *c)
{
  t_egg			*tmp;

  tmp = c->eggs;
  while (tmp->id != (unsigned int)atoi(args[0] + 1))
    tmp = tmp->next;
  tmp->x = atoi(args[2]);
  tmp->y = atoi(args[3]);
}

int			enw_cmd(char **args, t_graphic *c)
{
  t_client		*tmp;

  if (check_egg(atoi(args[0] + 1), c) == SUCCESS)
    return (my_error("This egg's id already exist", FAILURE));
  if (check_player(atoi(args[1] + 1), c) == FAILURE)
    return (my_error("This player's id does not exist", FAILURE));
  tmp = c->client;
  while (tmp->id != (unsigned int)atoi(args[1] + 1))
    tmp = tmp->next;
  if (add_egg(c, tmp->team->name, args[0] + 1) == FAILURE)
    return (FAILURE);
  if (atoi(args[2]) < 0 || (unsigned int)atoi(args[2]) >= c->x
      || atoi(args[3]) < 0 || (unsigned int)atoi(args[3]) >= c->y)
    {
      del_egg(c, atoi(args[0] + 1));
      return (my_error("Unknown coordinates", FAILURE));
    }
  set_egg_position(args, c);
  tmp->anim = UNDEFINED;
  return (SUCCESS);
}
