/*
** exec_forward.c for exec_forward.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 13:21:25 2014 LOEB Thomas
** Last update Fri Jun 13 14:33:10 2014 LOEB Thomas
*/

#include		"server.h"

static char             *g_objects[NB_STONE + 1] =
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    FOOD
  };

static bool		exec_take_sub(t_server *s, unsigned int i)
{
  if (i == NB_STONE)
    {
      --s->map[s->tmp_clients->x + s->tmp_clients->y * s->x].food;
      ++s->tmp_clients->life;
    }
  else
    {
      --s->map[s->tmp_clients->x + s->tmp_clients->y * s->x].stone[i];
      ++s->tmp_clients->stone[i];
    }
  strcpy(s->tmp_clients->send, OK("\n"));
  exec_pgt(s, (i + 1) % (NB_STONE + 1));
  exec_pin(s);
  exec_bct(s);
  return (FALSE);
}

bool			exec_take(t_server *s)
{
  unsigned int		i;

  i = 0;
  while (i < NB_STONE + 1 &&
	 strcmp(s->tmp_clients->action.param, g_objects[i]) != 0)
    ++i;
  if (i == NB_STONE + 1 ||
      (i == NB_STONE &&
       s->map[s->tmp_clients->x + s->tmp_clients->y * s->x].food == 0) ||
      s->map[s->tmp_clients->x + s->tmp_clients->y * s->x].stone[i] == 0)
    {
      strcpy(s->tmp_clients->send, KO("\n"));
      return (FALSE);
    }
  return (exec_take_sub(s, i));
}
