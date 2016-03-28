/*
** exec_plv.c for exec_plv.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 13:13:04 2014 LOEB Thomas
** Last update Wed Jun 11 16:56:28 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_plv_manual(t_server *s)
{
  t_client		*tmp;
  int			pos;

  if (write_graphic(s) == FAILURE)
    return (FALSE);
  pos = atoi(s->p.cmd[1] + 1);
  tmp = s->clients;
  while (tmp->id != (unsigned int)pos)
    tmp = tmp->next;
  strcpy(s->graphic->send, s->p.line);
  s->graphic->send[strlen(s->graphic->send)] = ' ';
  nbr_to_str(tmp->level, s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}

bool			exec_plv(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (PLV" #"));
  nbr_to_str(s->tmp_clients->id,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->level,
	     s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
