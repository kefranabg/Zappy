/*
** check_action.c for check_action.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 12:34:17 2014 LOEB Thomas
** Last update Thu Jun 19 17:37:13 2014 LOEB Thomas
*/

#include		"server.h"

static char		*g_objects[NB_STONE + 1] =
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    FOOD
  };

bool			check_take(t_server *s)
{
  unsigned int		i;

  i = 0;
  while (i < NB_STONE + 1 && strcmp(s->p.cmd[1], g_objects[i]) != 0)
    ++i;
  if (i == NB_STONE + 1)
    return (FALSE);
  return (TRUE);
}

bool			check_put(t_server *s)
{
  unsigned int		i;

  i = 0;
  while (i < NB_STONE && strcmp(s->p.cmd[1], g_objects[i]) != 0)
    ++i;
  if (i == NB_STONE)
    return (FALSE);
  return (TRUE);
}
