/*
** sgt_cmd.c for sgt_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Jun 25 12:37:03 2014 abgral_f
** Last update Wed Jun 25 12:40:01 2014 abgral_f
*/

#include		"graphic.h"

int			sgt_cmd(char **args, t_graphic *c)
{
  if (atoi(args[0]) < 0)
    return (my_error("Time unity can't be negativ", FAILURE));
  c->time = atoi(args[0]);
  return (SUCCESS);
}
