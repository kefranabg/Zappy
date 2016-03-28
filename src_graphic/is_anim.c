/*
** is_anim.c for is_anim.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Jul  5 18:45:41 2014 abgral_f
** Last update Sat Jul  5 18:46:52 2014 abgral_f
*/

#include		"graphic.h"

bool			is_anim(t_graphic *c)
{
  t_client		*tmp;

  tmp = c->client;
  while (tmp != NULL)
    {
      if (tmp->anim != UNDEFINED)
	return (TRUE);
      tmp = tmp->next;
    }
  return (FALSE);
}
