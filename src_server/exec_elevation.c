/*
** exec_forward.c for exec_forward.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 13:21:25 2014 LOEB Thomas
** Last update Fri Jun 13 15:02:31 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_elevation(t_server *s)
{
  strcpy(s->tmp_clients->send, ELEVATION_DONE);
  s->tmp_clients->send[16] = s->tmp_clients->level + 49;
  ++s->tmp_clients->level;
  s->tmp_clients->isAscending = -1;
  exec_pie(s, 1);
  exec_plv(s);
  exec_bct(s);
  if (s->tmp_clients->level == MAX_LEVEL)
    exec_seg(s);
  return (FALSE);
}
