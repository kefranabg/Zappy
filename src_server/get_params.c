/*
** get_params.c for get_params.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue May  6 13:02:15 2014 LOEB Thomas
** Last update Fri May 16 13:23:13 2014 LOEB Thomas
*/

#include		"server.h"
#include		"get_params_fct.c"

static int		get_x(t_server *s, char **av, int *i)
{
  unsigned int		j;

  if (av[++(*i)] == NULL)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  j = -1;
  while (av[(*i)][++j] != '\0')
    if (av[(*i)][j] < '0' || av[(*i)][j] > '9')
      return (my_error(BAD_VALUE_OPT, FAILURE));
  if ((s->x = atoi(av[(*i)])) <= 0)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  return (SUCCESS);
}

static int		get_y(t_server *s, char **av, int *i)
{
  unsigned int		j;

  if (av[++(*i)] == NULL)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  j = -1;
  while (av[(*i)][++j] != '\0')
    if (av[(*i)][j] < '0' || av[(*i)][j] > '9')
      return (my_error(BAD_VALUE_OPT, FAILURE));
  if ((s->y = atoi(av[(*i)])) <= 0)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  return (SUCCESS);
}

static int		get_nb_per_team(t_server *s, char **av, int *i)
{
  unsigned int		j;

  if (av[++(*i)] == NULL)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  j = -1;
  while (av[(*i)][++j] != '\0')
    if (av[(*i)][j] < '0' || av[(*i)][j] > '9')
      return (my_error(BAD_VALUE_OPT, FAILURE));
  s->nb_per_team = atoi(av[(*i)]);
  return (SUCCESS);
}

static int		get_delay(t_server *s, char **av, int *i)
{
  unsigned int		j;
  unsigned char		comma;

  if (av[++(*i)] == NULL)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  j = -1;
  comma = 0;
  while (av[(*i)][++j] != '\0')
    if ((av[(*i)][j] < '0' || av[(*i)][j] > '9') &&
	(comma == 1 || (comma == 0 && av[(*i)][j] != '.')))
      return (my_error(BAD_VALUE_OPT, FAILURE));
    else if (av[(*i)][j] == '.')
      comma = 1;
  if ((s->delay = atof(av[(*i)])) <= 0)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  return (SUCCESS);
}

static int		(*g_get[SERVER_NB_OPT])(t_server *, char **, int *) =
{
  &get_names,
  &get_port,
  &get_x,
  &get_y,
  &get_nb_per_team,
  &get_delay
};

int			get_params(t_server *s, char **av, int *i, int pos)
{
  return ((*g_get[pos])(s, av, i));
}
