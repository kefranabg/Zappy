/*
** exec_forward.c for exec_forward.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 13:21:25 2014 LOEB Thomas
** Last update Fri Jun 13 14:31:51 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_left(t_server *s)
{
  --s->tmp_clients->direction;
  if ((int)s->tmp_clients->direction < 0)
    s->tmp_clients->direction = D_LEFT;
  strcpy(s->tmp_clients->send, OK("\n"));
  exec_ppo(s);
  return (FALSE);
}
