/*
** exec_forward.c for exec_forward.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 13:21:25 2014 LOEB Thomas
** Last update Fri Jun 13 14:33:56 2014 LOEB Thomas
*/

#include		"server.h"

static char		*g_objects[NB_STONE] =
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  };

bool			exec_put(t_server *s)
{
  unsigned int		i;

  i = 0;
  while (i < NB_STONE &&
	 strcmp(s->tmp_clients->action.param, g_objects[i]) != 0)
    ++i;
  if (i == NB_STONE || s->tmp_clients->stone[i] == 0)
    {
      strcpy(s->tmp_clients->send, KO("\n"));
      return (FALSE);
    }
  --s->tmp_clients->stone[i];
  ++s->map[s->tmp_clients->x + s->tmp_clients->y * s->x].stone[i];
  strcpy(s->tmp_clients->send, OK("\n"));
  exec_pdr(s, i + 1);
  exec_pin(s);
  exec_bct(s);
  return (FALSE);
}
