/*
** exec_forward.c for exec_forward.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 13:21:25 2014 LOEB Thomas
** Last update Wed Jun 11 16:10:58 2014 LOEB Thomas
*/

#include		"server.h"

static char		*g_inventory[NB_STONE] =
  {
    (" "LINEMATE" "),
    (" "DERAUMERE" "),
    (" "SIBUR" "),
    (" "MENDIANE" "),
    (" "PHIRAS" "),
    (" "THYSTAME" ")
  };

bool			exec_inventory(t_server *s)
{
  unsigned int		food;
  unsigned int		i;

  strcpy(s->tmp_clients->send, ("{"FOOD" "));
  food = FOOD_TIME * (s->tmp_clients->life - 1)
    + (FOOD_TIME - (s->tmp_clients->action_life.usec / SEC_TO_USEC));
  nbr_to_str(food, s->tmp_clients->send + strlen(s->tmp_clients->send), ",");
  i = -1;
  while (++i < NB_STONE)
    {
      strcpy(s->tmp_clients->send + strlen(s->tmp_clients->send),
	     g_inventory[i]);
      nbr_to_str(s->tmp_clients->stone[i],
		 s->tmp_clients->send + strlen(s->tmp_clients->send),
		 (i + 1 == NB_STONE) ? NULL : ",");
    }
  strcpy(s->tmp_clients->send + strlen(s->tmp_clients->send), "}\n");
  return (FALSE);
}
