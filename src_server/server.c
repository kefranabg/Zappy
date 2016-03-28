/*
** server.c for server.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon May  5 15:36:46 2014 LOEB Thomas
** Last update Sat Jul 12 15:38:15 2014 abgral_f
*/

#include		"server.h"

static t_opt		g_opt[SERVER_NB_OPT + 1] =
  {
    {"-n", 0, 1},
    {"-p", 0, 1},
    {"-x", 0, 1},
    {"-y", 0, 1},
    {"-c", 0, 1},
    {"-t", 0, 1},
    {"--help", 0, 0}
  };

int			is_in_opts(char *s)
{
  unsigned int		i;

  i = 0;
  while (i < SERVER_NB_OPT + 1 && strcmp(g_opt[i].s, s) != 0)
    ++i;
  if (i == SERVER_NB_OPT + 1)
    return (FAILURE);
  return (i);
}

static int		parse_params(t_server *s, char **av, int i)
{
  int			pos;

  while (av[i] != NULL)
    {
      if ((pos = is_in_opts(av[i])) == FAILURE)
	return (my_error(WRONG_OPT, FAILURE));
      else if (pos == SERVER_NB_OPT)
	{
	  free_teams(s);
	  printf("%s\n", SERVER_USAGE);
	  return (FAILURE);
	}
      else
	{
	  ++g_opt[pos].occurrence;
	  if (g_opt[pos].occurrence != g_opt[pos].occurrence_max)
	    my_error(TOO_MANY_OPT, CONTINUE);
	  if (get_params(s, av, &i, pos) == FAILURE)
	    return (FAILURE);
	}
      if (av[i] != NULL)
	++i;
    }
  return (SUCCESS);
}

static void		display(t_server *s)
{
  printf("Server not yet online\n\tName of teams:");
  s->tmp_teams = s->teams;
  while (s->tmp_teams != NULL)
    {
      if (s->tmp_teams->prev == NULL)
	printf(" %s", s->tmp_teams->name);
      else
	printf(" | %s", s->tmp_teams->name);
      s->tmp_teams = s->tmp_teams->next;
    }
  printf(("\n\tPort: %d\n\tWidth: %d\n\tHeight: %d\n"	\
	  "\tNb per team: %d\n\tDelay: %f\n"),
	 s->port, s->x, s->y, s->nb_per_team, s->delay);
}

int			main(int ac __attribute__((__unused__)), char **av)
{
  t_server		s;

  srand(time(NULL));
  memset(&s, '\0', sizeof(t_server));
  s.socket = -1;
  s.port = atoi(STD_PORT);
  s.x = atoi(STD_X);
  s.y = atoi(STD_Y);
  s.nb_per_team = atoi(STD_NB);
  s.delay = atof(STD_DELAY);
  if (parse_params(&s, av + 1, 0) == FAILURE)
    return (FAILURE);
  init_teams(&s);
  my_signal();
  display(&s);
  return (open_to_clients(&s));
}
