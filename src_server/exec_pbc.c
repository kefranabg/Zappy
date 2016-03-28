/*
** exec_pbc.c for exec_pbc.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue Jun 10 14:25:34 2014 LOEB Thomas
** Last update Wed Jun 11 16:48:25 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_pbc(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (PBC" #"));
  nbr_to_str(s->tmp_clients->id,
             s->graphic->send + strlen(s->graphic->send), " ");
  strcpy(s->graphic->send + strlen(s->graphic->send),
	 s->tmp_clients->action.param);
  s->graphic->send[strlen(s->graphic->send)] = '\n';
  return (TRUE);
}
