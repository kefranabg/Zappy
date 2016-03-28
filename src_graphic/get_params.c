/*
** get_params.c for get_params.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue May  6 10:31:40 2014 LOEB Thomas
** Last update Thu Jun 12 18:10:20 2014 LOEB Thomas
*/

#include		"graphic.h"

static int		get_port(t_graphic *c, char **av, int *i)
{
  unsigned int		j;

  if (av[++(*i)] == NULL)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  j = -1;
  while (av[(*i)][++j] != '\0')
    if (av[(*i)][j] < '0' || av[(*i)][j] > '9')
      return (my_error(BAD_VALUE_OPT, FAILURE));
  c->port = atoi(av[(*i)]);
  return (SUCCESS);
}

static int		get_ip(t_graphic *c, char **av, int *i)
{
  if ((c->ip = av[++(*i)]) == NULL)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  return (SUCCESS);
}

static int		(*g_get[GRAPHIC_NB_OPT])(t_graphic *, char **, int *) =
{
  &get_port,
  &get_ip
};

int			get_params(t_graphic *c, char **av, int *i, int pos)
{
  return ((*g_get[pos])(c, av, i));
}
