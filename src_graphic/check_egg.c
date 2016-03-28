/*
** check_egg.c for check_egg.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jun 24 18:47:56 2014 abgral_f
** Last update Tue Jun 24 18:48:50 2014 abgral_f
*/

#include		"graphic.h"

int			check_egg(unsigned int id, t_graphic *c)
{
  t_egg			*tmp;

  tmp = c->eggs;
  while (tmp != NULL &&
         tmp->id != id)
    tmp = tmp-> next;
  if (tmp == NULL)
    return (FAILURE);
  if (tmp->id == id)
    return (SUCCESS);
  return (FAILURE);
}
