/*
** exec_forward.c for exec_forward.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 13:21:25 2014 LOEB Thomas
** Last update Wed Jun 11 16:03:45 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_connect_nbr(t_server *s)
{
  nbr_to_str(s->tmp_teams->nb_remaining + s->tmp_teams->nb_egg_remaining,
	     s->tmp_clients->send, "\n");
  return (FALSE);
}
