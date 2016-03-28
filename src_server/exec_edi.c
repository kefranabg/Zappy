/*
** exec_edi.c for exec_edi.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu Jun 12 16:07:56 2014 LOEB Thomas
** Last update Thu Jun 12 16:08:02 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_edi(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (EDI" #"));
  nbr_to_str(s->tmp_teams->tmp_eggs->id,
             s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
