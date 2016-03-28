/*
** smg_cmd.c for smg_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Jun 25 12:46:13 2014 abgral_f
** Last update Wed Jun 25 12:56:25 2014 abgral_f
*/

#include		"graphic.h"

int			smg_cmd(char **args,
				__attribute__((unused))t_graphic *c)
{
  printf("Server say : %s\n", args[0]);
  return (SUCCESS);
}
