/*
** get_team_by_name.c for get_team_by_name.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Mon Jun 23 19:40:06 2014 abgral_f
** Last update Mon Jun 23 19:43:15 2014 abgral_f
*/

#include		"graphic.h"

t_team			*get_team_by_name(t_graphic *c, char *name)
{
  t_team		*ret;

  ret = c->teams;
  while (ret != NULL && strcmp(name, ret->name) != 0)
    ret = ret->next;
  if (ret == NULL)
    return (NULL);
  return (ret);
}
