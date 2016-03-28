/*
** pnw_cmd.c for pnw_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Thu Jun 19 20:37:05 2014 abgral_f
** Last update Thu Jul  3 16:49:29 2014 abgral_f
*/

#include		"graphic.h"

static void		free_plv_arg(char **plv_args,
				     bool free_case_one, bool free_case_two)
{
  if (free_case_one == TRUE)
    free(plv_args[0]);
  if (free_case_two == TRUE)
    free(plv_args[1]);
  free(plv_args);
}

int			pnw_cmd(char **args, t_graphic *c)
{
  char			**plv_args;

  if (check_player(atoi(args[0] + 1), c) == SUCCESS)
    return (my_error("This player's id already exist", FAILURE));
  if (add_client(c, args[5], args[0] + 1) == FAILURE)
    return (FAILURE);
  else if ((plv_args = malloc(sizeof (*plv_args) * 2)) == NULL
	   || (plv_args[0] = strdup(args[0])) == NULL
	   || (plv_args[1] = strdup(args[4])) == NULL
	   || plv_cmd(plv_args, c) == FAILURE
	   || ppo_cmd(args, c) == FAILURE)
    {
      del_client(c, atoi(args[0] + 1));
      if (plv_args != NULL)
	free(plv_args);
      else if (plv_args[0] == NULL)
	free_plv_arg(plv_args, TRUE, FALSE);
      else if (plv_args[1] == NULL)
	free_plv_arg(plv_args, TRUE, TRUE);
      else
	return (my_perror(SYSCALL("malloc"), FAILURE));
      return (FAILURE);
    }
  free_plv_arg(plv_args, TRUE, TRUE);
  return (SUCCESS);
}
