/*
** exec_pie.c for exec_pie.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed Jun 11 15:10:20 2014 LOEB Thomas
** Last update Wed Jun 11 16:09:27 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_pie(t_server *s, char c)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (PIE" "));
  nbr_to_str(s->tmp_clients->x,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->y,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(c, s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
