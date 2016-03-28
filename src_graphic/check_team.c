/*
** check_if_team_exist.c for check_if_team_exist.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Jun 20 12:41:09 2014 abgral_f
** Last update Wed Jun 25 13:03:45 2014 abgral_f
*/

#include		"graphic.h"

int                     check_team(t_graphic *c, char *team)
{
  t_team               *tmp;

  tmp = c->teams;
  while (tmp != NULL &&
         strcmp(tmp->name, team) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (FAILURE);
  if (strcmp(tmp->name, team) == 0)
    return (SUCCESS);
  return (FAILURE);
}
