/*
** exec_seg.c for exec_seg.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu Jun 12 16:21:06 2014 LOEB Thomas
** Last update Thu Jun 12 16:24:59 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_seg(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (SEG" #"));
  strcpy(s->graphic->send + strlen(s->graphic->send),
	 s->tmp_clients->team->name);
  s->graphic->send[strlen(s->graphic->send)] = '\n';
  return (TRUE);
}
