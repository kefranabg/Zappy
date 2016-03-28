/*
** pdi_cmd.c for pdi_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jun 24 18:28:02 2014 abgral_f
** Last update Wed Jul  2 15:14:43 2014 abgral_f
*/

#include		"graphic.h"

int			pdi_cmd(char **args, t_graphic *c)
{
  if (check_player(atoi(args[0] + 1), c) == FAILURE)
    return (my_error("Unknown player id", FAILURE));
  del_client(c, atoi(args[0] + 1));
  return (SUCCESS);
}
