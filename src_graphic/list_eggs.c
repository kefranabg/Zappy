/*
** list_eggs.c for list_eggs.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jun 24 18:37:35 2014 abgral_f
** Last update Thu Jul  3 14:06:01 2014 abgral_f
*/

#include		"graphic.h"

void			free_eggs(t_graphic *c)
{
  t_egg 	        *tmp;

  tmp = c->eggs;
  while (c->eggs != NULL)
    {
      tmp = c->eggs;
      c->eggs = c->eggs->next;
      free(tmp);
    }
}

int			add_egg(t_graphic *c, char *team, char *id)
{
  t_egg              *new;

  if ((new = malloc(sizeof(t_egg))) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  new->next = c->eggs;
  new->prev = NULL;
  if (c->eggs != NULL)
    c->eggs->prev = new;
  c->eggs = new;
  if (check_team(c, team) == FAILURE)
    {
      del_egg(c, atoi(id));
      return (my_error(strcat(team, " does not exist"), FAILURE));
    }
  else
    new->team = get_team_by_name(c, team);
  new->id = atoi(id);
  new->isHatched = FALSE;
  return (SUCCESS);
}

int			del_egg(t_graphic *c, unsigned int id)
{
  t_egg			*tmp;

  tmp = c->eggs;
  while (tmp != NULL && tmp->id != id)
    tmp = tmp->next;
  if (tmp == NULL)
    return (FAILURE);
  else if (tmp->next == NULL && tmp->prev == NULL)
    c->eggs = NULL;
  else if (tmp->prev == NULL)
    {
      c->eggs = tmp->next;
      c->eggs->prev = NULL;
    }
  else if (tmp->next == NULL)
    tmp->prev->next = tmp->next;
  else
    {
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
    }
  free(tmp);
  return (SUCCESS);
}
