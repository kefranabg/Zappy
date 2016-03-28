/*
** edi_cmd.c for edi_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jun 24 20:53:22 2014 abgral_f
** Last update Wed Jul  2 15:16:51 2014 abgral_f
*/

#include                "graphic.h"

int                     edi_cmd(char **args, t_graphic *c)
{
  if (check_egg(atoi(args[0] + 1), c) == FAILURE)
    return (my_error("Unknown egg id", FAILURE));
  del_egg(c, atoi(args[0] + 1));
  return (SUCCESS);
}
