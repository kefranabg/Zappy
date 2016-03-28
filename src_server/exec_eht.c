/*
** exec_eht.c for exec_eht.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu Jun 12 15:54:54 2014 LOEB Thomas
** Last update Thu Jun 12 15:56:07 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_eht(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (EHT" #"));
  nbr_to_str(s->tmp_teams->tmp_eggs->id,
             s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
