/*
** pbc_cmd.c for pbc_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jun 24 12:44:11 2014 abgral_f
** Last update Wed Jul  2 15:12:50 2014 abgral_f
*/

#include		"graphic.h"

int			pbc_cmd(char **args, t_graphic *c)
{
  if (check_player(atoi(args[0] + 1), c) == FAILURE)
    return (my_error("Unknown player id", FAILURE));
  printf("Broadcast from player %d : <%s>\n", atoi(args[0] + 1), args[1]);
  return (SUCCESS);
}
