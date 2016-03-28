/*
** list_team.c for list_team.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue May  6 13:29:52 2014 LOEB Thomas
** Last update Fri May 16 13:20:43 2014 LOEB Thomas
*/

#include		"server.h"

int			add_team(t_server *s, char *name)
{
  t_team		*new;

  if ((new = malloc(sizeof(t_team))) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  new->name = name;
  new->eggs = NULL;
  new->nb_egg_remaining = 0;
  new->next = s->teams;
  new->prev = NULL;
  if (s->teams != NULL)
    s->teams->prev = new;
  s->teams = new;
  return (SUCCESS);
}

void			init_teams(t_server *s)
{
  if (s->teams == NULL)
    {
      add_team(s, STD_TEAM1);
      add_team(s, STD_TEAM2);
    }
  s->tmp_teams = s->teams;
  while (s->tmp_teams != NULL)
    {
      s->tmp_teams->nb_remaining = s->nb_per_team;
      s->tmp_teams = s->tmp_teams->next;
    }
}

void			free_teams(t_server *s)
{
  t_team		*tmp;

  s->tmp_teams = s->teams;
  while (s->tmp_teams != NULL)
    {
      tmp = s->tmp_teams;
      free_eggs(s);
      s->tmp_teams = s->tmp_teams->next;
      free(tmp);
    }
  s->teams = NULL;
}
