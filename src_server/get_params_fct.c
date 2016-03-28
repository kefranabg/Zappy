/*
** get_params_fct.c for get_params_fct.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue May  6 13:58:26 2014 LOEB Thomas
** Last update Mon Jun 23 18:45:56 2014 LOEB Thomas
*/

static int		get_names(t_server *s, char **av, int *i)
{
  free_teams(s);
  if (av[(*i) + 1] == NULL)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  while (av[++(*i)] != NULL && is_in_opts(av[(*i)]) == FAILURE)
    if (nb_space(av[(*i)]) != 0)
      return (my_error(BAD_VALUE_OPT, FAILURE));
    else if (add_team(s, av[(*i)]) == FAILURE)
      {
	free_teams(s);
	return (FAILURE);
      }
  if (s->teams == NULL)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  --(*i);
  return (SUCCESS);
}

static int		get_port(t_server *s, char **av, int *i)
{
  unsigned int		j;

  if (av[++(*i)] == NULL)
    return (my_error(BAD_VALUE_OPT, FAILURE));
  j = -1;
  while (av[(*i)][++j] != '\0')
    if (av[(*i)][j] < '0' || av[(*i)][j] > '9')
      return (my_error(BAD_VALUE_OPT, FAILURE));
  s->port = atoi(av[(*i)]);
  return (SUCCESS);
}
