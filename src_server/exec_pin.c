/*
** exec_pin.c for exec_pin.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 13:13:04 2014 LOEB Thomas
** Last update Wed Jun 11 16:58:56 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_pin_manual(t_server *s)
{
  t_client		*tmp;
  int			pos;
  unsigned int		i;

  if (write_graphic(s) == FAILURE)
    return (FALSE);
  pos = atoi(s->p.cmd[1] + 1);
  tmp = s->clients;
  while (tmp->id != (unsigned int)pos)
    tmp = tmp->next;
  strcpy(s->graphic->send, s->p.line);
  s->graphic->send[strlen(s->graphic->send)] = ' ';
  nbr_to_str(tmp->x, s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(tmp->y, s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(tmp->life, s->graphic->send + strlen(s->graphic->send), " ");
  i = -1;
  while (++i < NB_STONE)
    nbr_to_str(tmp->stone[i], s->graphic->send + strlen(s->graphic->send),
	       (i + 1 == NB_STONE) ? "\n" : " ");
  return (TRUE);
}

bool			exec_pin(t_server *s)
{
  unsigned int		i;

  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (PIN" #"));
  nbr_to_str(s->tmp_clients->id,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->x,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->y,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->life,
	     s->graphic->send + strlen(s->graphic->send), " ");
  i = -1;
  while (++i < NB_STONE)
    nbr_to_str(s->tmp_clients->stone[i],
	       s->graphic->send + strlen(s->graphic->send),
	       (i + 1 == NB_STONE) ? "\n" : " ");
  return (TRUE);
}
