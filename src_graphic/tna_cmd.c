/*
** tna_cmd.c for tna_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Thu Jun 19 16:41:03 2014 abgral_f
** Last update Thu Jul  3 16:44:03 2014 abgral_f
*/

#include		"graphic.h"

void		        free_teams(t_graphic *c)
{
  t_team                *tmp;

  while (c->teams != NULL)
    {
      tmp = c->teams;
      c->teams = c->teams->next;
      free(tmp->name);
      free(tmp);
    }
}

static int		add_team(t_graphic *c, char *name)
{
  t_team                *new;

  if ((new = malloc(sizeof(t_team))) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  new->name = strdup(name);
  new->next = c->teams;
  new->prev = NULL;
  if (c->teams != NULL)
    c->teams->prev = new;
  c->teams = new;
  return (SUCCESS);
}

int			tna_cmd(char **args, t_graphic *c)
{
  if (check_team(c, args[0]) == SUCCESS)
    return (my_error("This team already exist", FAILURE));
  if (add_team(c, args[0]) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
