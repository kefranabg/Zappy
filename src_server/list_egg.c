/*
** list_egg.c for list_egg.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May 14 18:13:00 2014 LOEB Thomas
** Last update Thu Jul 10 14:16:21 2014 LOEB Thomas
*/

#include		"server.h"

void			add_egg(t_server *s)
{
  t_egg			*new;

  if ((new = malloc(sizeof(t_egg))) == NULL &&
      my_perror(SYSCALL("malloc"), CONTINUE) == CONTINUE)
    return ;
  new->id = 0;
  new->id_client = s->tmp_clients->id;
  new->life = STD_LIFE;
  new->action_life = action_life(s->delay);
  new->action = action_egg(s->delay);
  new->isThereAction = TRUE;
  new->x = s->tmp_clients->x;
  new->y = s->tmp_clients->y;
  new->direction = s->tmp_clients->direction;
  new->next = s->tmp_clients->team->eggs;
  new->prev = NULL;
  if (s->tmp_clients->team->eggs != NULL)
    {
      new->id = s->tmp_clients->team->eggs->id + 1;
      s->tmp_clients->team->eggs->prev = new;
    }
  s->tmp_clients->team->eggs = new;
}

void			del_egg(t_server *s)
{
  t_egg			*tmp;

  --s->tmp_teams->nb_egg_remaining;
  if (s->tmp_teams->tmp_eggs->prev != NULL)
    s->tmp_teams->tmp_eggs->prev->next = s->tmp_teams->tmp_eggs->next;
  if (s->tmp_teams->tmp_eggs->next != NULL)
    s->tmp_teams->tmp_eggs->next->prev = s->tmp_teams->tmp_eggs->prev;
  if (s->tmp_teams->tmp_eggs->prev == NULL)
    s->tmp_teams->eggs = s->tmp_teams->eggs->next;
  tmp = s->tmp_teams->tmp_eggs;
  s->tmp_teams->tmp_eggs = s->tmp_teams->tmp_eggs->next;
  free(tmp);
}

void			free_eggs(t_server *s)
{
  s->tmp_teams->tmp_eggs = s->tmp_teams->eggs;
  while (s->tmp_teams->tmp_eggs != NULL)
    del_egg(s);
  s->tmp_teams->eggs = NULL;
}

void			take_last_egg(t_server *s)
{
  s->tmp_teams->tmp_eggs = s->tmp_teams->eggs;
  while (s->tmp_teams->tmp_eggs->next != NULL)
    s->tmp_teams->tmp_eggs = s->tmp_teams->tmp_eggs->next;
  s->tmp_clients->x = s->tmp_teams->tmp_eggs->x;
  s->tmp_clients->y = s->tmp_teams->tmp_eggs->y;
  s->tmp_clients->direction = s->tmp_teams->tmp_eggs->direction;
  s->tmp_clients->life = s->tmp_teams->tmp_eggs->life;
  exec_ebo(s);
  exec_pnw(s);
  del_egg(s);
}
