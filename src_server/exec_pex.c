/*
** exec_pex.c for exec_pex.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue Jun 10 14:19:39 2014 LOEB Thomas
** Last update Wed Jun 11 16:09:13 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_pex(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (PEX" #"));
  nbr_to_str(s->tmp_clients->id,
	     s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
