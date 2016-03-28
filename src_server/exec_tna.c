/*
** exec_tna.c for exec_tna.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 13:13:04 2014 LOEB Thomas
** Last update Wed Jun 11 16:42:35 2014 LOEB Thomas
*/

#include		"server.h"

static void		exec_tna_fill(t_server *s)
{
  strcpy(s->graphic->send + strlen(TNA) + 1, s->tmp_teams->name);
  s->graphic->send[strlen(s->graphic->send)] = '\n';
}

bool			exec_tna(t_server *s)
{
  t_client		*tmp;

  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (TNA" "));
  s->tmp_teams = s->teams;
  while (s->tmp_teams != NULL && s->tmp_teams->next != NULL)
    {
      exec_tna_fill(s);
      if (rw(s->graphic->socket, s->graphic->send,
	     strlen(s->graphic->send), W) == FAILURE)
	{
	  tmp = s->tmp_clients;
	  s->tmp_clients = s->graphic;
	  del_client(s, TRUE);
	  s->tmp_clients = tmp;
	  return (FALSE);
	}
      s->tmp_teams = s->tmp_teams->next;
    }
  exec_tna_fill(s);
  return (TRUE);
}
