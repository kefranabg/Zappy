/*
** exec_pdr.c for exec_pdr.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed Jun 11 15:39:50 2014 LOEB Thomas
** Last update Wed Jun 11 16:03:57 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_pdr(t_server *s, char c)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (PDR" #"));
  nbr_to_str(s->tmp_clients->id,
             s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(c, s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
