/*
** pie_cmd.c for pie_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jun 24 16:47:28 2014 abgral_f
** Last update Sat Jul  5 14:55:33 2014 abgral_f
*/

#include		"graphic.h"

int			pie_cmd(char **args, t_graphic *c)
{
  t_client              *tmp;

  if (atoi(args[0]) < 0 || (unsigned int)atoi(args[0]) >= c->x
      || atoi(args[1]) < 0 || (unsigned int)atoi(args[1]) >= c->y)
    return (my_error("Unknown coordinates", FAILURE));
  tmp = c->client;
  while (tmp != NULL)
    {
      if (tmp->x == (unsigned int)atoi(args[0])
	  && tmp->y == (unsigned int)atoi(args[1]))
	{
	  tmp->anim = UNDEFINED;
	  tmp->isAscending = -1;
	}
      tmp = tmp->next;
    }
  if (atoi(args[2]) != 0 && atoi(args[2]) != 1)
    return (my_error("Unknown incantion result", FAILURE));
  if (atoi(args[2]) != 1)
    printf("Incantation in %d/%d failed", atoi(args[0]), atoi(args[1]));
  return (SUCCESS);
}
