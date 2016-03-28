/*
** exec_pdi.c for exec_pdi.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed Jun 11 17:03:13 2014 LOEB Thomas
** Last update Wed Jun 11 17:03:13 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_pdi(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (PDI" #"));
  nbr_to_str(s->tmp_clients->id,
	     s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
