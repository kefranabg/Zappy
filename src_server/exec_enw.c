/*
** exec_enw.c for exec_enw.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu Jun 12 15:41:15 2014 LOEB Thomas
** Last update Fri Jun 13 13:49:50 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_enw(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (ENW" #"));
  nbr_to_str(s->tmp_clients->team->eggs->id,
             s->graphic->send + strlen(s->graphic->send), " #");
  nbr_to_str(s->tmp_clients->id,
             s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->x,
             s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->y,
             s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}

bool			exec_enw_manual(t_server *s, t_egg *e)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (ENW" #"));
  nbr_to_str(e->id, s->graphic->send + strlen(s->graphic->send), " #");
  nbr_to_str(e->id_client, s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(e->x, s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(e->y, s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
