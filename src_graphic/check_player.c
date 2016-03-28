/*
** check_if_player_exist.c for check_if_player_exist.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Jun 20 12:34:30 2014 abgral_f
** Last update Wed Jul  2 15:08:28 2014 abgral_f
*/

#include		"graphic.h"

int                     check_player(unsigned int id, t_graphic *c)
{
  t_client              *tmp;

  tmp = c->client;
  while (tmp != NULL &&
	 tmp->id != id)
    tmp = tmp-> next;
  if (tmp == NULL)
    return (FAILURE);
  if (tmp->id == id)
    return (SUCCESS);
  return (FAILURE);
}
