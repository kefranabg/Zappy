/*
** exec_forward.c for exec_forward.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 13:21:25 2014 LOEB Thomas
** Last update Thu Jun 12 16:00:57 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_fork(t_server *s)
{
  add_egg(s);
  strcpy(s->tmp_clients->send, OK("\n"));
  exec_enw(s);
  return (FALSE);
}
