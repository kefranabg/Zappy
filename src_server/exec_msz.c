/*
** exec_msz.c for exec_msz.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 13:13:04 2014 LOEB Thomas
** Last update Wed Jun 11 16:09:57 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_msz(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (MSZ" "));
  nbr_to_str(s->x, s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->y, s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
