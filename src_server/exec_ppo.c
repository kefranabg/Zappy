/*
** exec_ppo.c for exec_ppo.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 13:13:04 2014 LOEB Thomas
** Last update Wed Jun 11 16:55:11 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_ppo_manual(t_server *s)
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
  nbr_to_str(tmp->x, s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(tmp->y, s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(tmp->direction + 1,
	     s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}

bool			exec_ppo(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (PPO" #"));
  nbr_to_str(s->tmp_clients->id,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->x,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->y,
	     s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->tmp_clients->direction + 1,
	     s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
