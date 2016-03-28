/*
** exec_pnw.c for exec_pnw.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 17:22:26 2014 LOEB Thomas
** Last update Thu Jul  3 17:06:16 2014 abgral_f
*/

#include		"server.h"

bool			exec_pnw(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (PNW" #"));
  nbr_to_str(s->tmp_clients->id,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->x,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->y,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->direction + 1,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->level,
	     s->graphic->send + strlen(s->graphic->send), " ");
  strcpy(s->graphic->send + strlen(s->graphic->send),
	 s->tmp_clients->team->name);
  s->graphic->send[strlen(s->graphic->send)] = '\n';
  return (TRUE);
}
