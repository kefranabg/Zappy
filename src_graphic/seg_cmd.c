/*
** seg_cmd.c for seg_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Jun 25 12:42:29 2014 abgral_f
** Last update Wed Jun 25 12:49:36 2014 abgral_f
*/

#include		"graphic.h"

int			seg_cmd(char **args, t_graphic *c)
{
  if (check_team(c, args[0]) == FAILURE)
    return (my_error("This team does not exist", FAILURE));
  printf("%s win!\n", args[0]);
  return (SUCCESS);
}
