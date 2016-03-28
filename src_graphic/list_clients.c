/*
** list_player.c for list_player.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Thu Jun 19 21:14:37 2014 abgral_f
** Last update Sat Jul  5 13:37:41 2014 abgral_f
*/

#include		"graphic.h"

static void		set_new_client(t_client *new)
{
  int			count;

  new->inventory.food = 10;
  count = -1;
  while (++count != 6)
    new->inventory.stone[count] = 0;
  new->isAscending = -1;
  new->anim = UNDEFINED;
  count = 0;
}

void			free_clients(t_graphic *c)
{
  t_client		*tmp;

  tmp = c->client;
  while (c->client != NULL)
    {
      tmp = c->client;
      c->client = c->client->next;
      free(tmp);
    }
}

int                     add_client(t_graphic *c, char *team, char *id)
{
  t_client		*new;

  if ((new = malloc(sizeof(t_client))) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  new->next = c->client;
  new->prev = NULL;
  if (c->client != NULL)
    c->client->prev = new;
  c->client = new;
  if (check_team(c, team) == FAILURE)
    {
      del_client(c, atoi(id));
      return (my_error(strcat(team, " does not exist"), FAILURE));
    }
  else
    new->team = get_team_by_name(c, team);
  new->id = atoi(id);
  set_new_client(new);
  return (SUCCESS);
}

int			del_client(t_graphic *c, unsigned int id)
{
  t_client		*tmp;

  tmp = c->client;
  while (tmp != NULL && tmp->id != id)
    tmp = tmp->next;
  if (tmp == NULL)
    return (FAILURE);
  else if (tmp->next == NULL && tmp->prev == NULL)
    c->client = NULL;
  else if (tmp->prev == NULL)
    {
      c->client = tmp->next;
      c->client->prev = NULL;
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
