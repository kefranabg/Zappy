/*
** client.c for client.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon May  5 15:36:39 2014 LOEB Thomas
** Last update Fri Jul 11 19:35:15 2014 Baptiste Acca
*/

#include		"client.h"

static t_opt		g_opt[CLIENT_NB_OPT + 1] =
  {
    {"-n", 0, 1},
    {"-p", 0, 1},
    {"-h", 0, 1},
    {"--help", 0, 0}
  };

static int		is_in_opts(char *s)
{
  unsigned int		i;

  i = 0;
  while (i < CLIENT_NB_OPT + 1 && strcmp(g_opt[i].s, s) != 0)
    ++i;
  if (i == CLIENT_NB_OPT + 1)
    return (FAILURE);
  return (i);
}

static int		parse_params(t_client *c, char **av)
{
  int			i;
  int			pos;

  i = 0;
  while (av[i] != NULL)
    {
      if ((pos = is_in_opts(av[i])) == FAILURE)
	return (my_error(WRONG_OPT, FAILURE));
      else if (pos == CLIENT_NB_OPT)
	{
	  printf("%s\n", CLIENT_USAGE);
	  return (FAILURE);
	}
      else
	{
	  ++g_opt[pos].occurrence;
	  if (g_opt[pos].occurrence != g_opt[pos].occurrence_max)
	    my_error(TOO_MANY_OPT, CONTINUE);
	  if (get_params(c, av, &i, pos) == FAILURE)
	    return (FAILURE);
	}
      if (av[i] != NULL)
	++i;
    }
  return (SUCCESS);
}

static void		display(t_client *c)
{
  printf(("Client not yet connected\n\tName of team: %s\n"	\
	  "\tPort: %d\n\tIp: %s\n"),
	 c->name, c->port, c->ip);
}

int			main(int ac __attribute__((__unused__)), char **av)
{
  t_client		c;

  memset(&c, '\0', sizeof(t_client));
  c.name = STD_TEAM1;
  c.port = atoi(STD_PORT);
  c.ip = STD_IP;
  c.socket = -1;
  c.l.stream = stdin;
  c.level = STD_LEVEL;
  if (parse_params(&c, av + 1) == FAILURE)
    return (FAILURE);
  my_signal();
  display(&c);
  return (connect_to_server(&c));
}
