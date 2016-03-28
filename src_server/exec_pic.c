/*
** exec_pic.c for exec_pic.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue Jun 10 14:32:32 2014 LOEB Thomas
** Last update Mon Jun 30 16:01:39 2014 LOEB Thomas
*/

#include		"server.h"

static void		exec_pic_clients(t_server *s)
{
  t_client		*tmp;

  tmp = s->clients;
  while (tmp != NULL)
    {
      if (tmp != s->tmp_clients &&
	  tmp->isAscending == (int)s->tmp_clients->id &&
	  strlen(s->graphic->send) + nbrlen(tmp->id) + 2 < BUFF_LEN)
	{
	  s->graphic->send[strlen(s->graphic->send)] = '#';
	  nbr_to_str(tmp->id,
		     s->graphic->send + strlen(s->graphic->send), " ");
	}
      tmp = tmp->next;
    }
  s->graphic->send[strlen(s->graphic->send) - 1] = '\n';
}

bool			exec_pic(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (PIC" "));
  nbr_to_str(s->tmp_clients->x,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->y,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->level + 1,
	     s->graphic->send + strlen(s->graphic->send), " #");
  nbr_to_str(s->tmp_clients->id,
	     s->graphic->send + strlen(s->graphic->send), " ");
  exec_pic_clients(s);
  return (TRUE);
}
