/*
** exec_bct.c for exec_bct.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 13:13:04 2014 LOEB Thomas
** Last update Wed Jun 11 16:52:57 2014 LOEB Thomas
*/

#include		"server.h"

void			exec_bct_fill(t_server *s, int x, int y)
{
  int			p;
  unsigned int		i;

  p = x + y * s->x;
  strcpy(s->graphic->send, (BCT" "));
  nbr_to_str(x, s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(y, s->graphic->send + strlen(s->graphic->send), " ");
  nbr_to_str(s->map[p].food, s->graphic->send + strlen(s->graphic->send), " ");
  i = -1;
  while (++i < NB_STONE)
    nbr_to_str(s->map[p].stone[i],
	       s->graphic->send + strlen(s->graphic->send),
	       (i + 1 == NB_STONE) ? "\n" : " ");
}

bool			exec_bct_manual(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  exec_bct_fill(s, atoi(s->p.cmd[1]), atoi(s->p.cmd[2]));
  return (TRUE);
}

bool			exec_bct(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  exec_bct_fill(s, s->tmp_clients->x, s->tmp_clients->y);
  return (TRUE);
}
