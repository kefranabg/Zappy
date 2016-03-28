/*
** exec_forward.c for exec_forward.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 13:21:25 2014 LOEB Thomas
** Last update Thu Jul  3 17:06:37 2014 abgral_f
*/

#include		"server.h"

static int		g_x[4] =
  {
    0,
    1,
    0,
    -1
  };

static int		g_y[4] =
  {
    -1,
    0,
    1,
    0
  };

bool			exec_forward(t_server *s)
{
  s->tmp_clients->x += g_x[s->tmp_clients->direction];
  if ((int)s->tmp_clients->x < 0)
    s->tmp_clients->x = s->x - 1;
  else if (s->tmp_clients->x >= (unsigned int)s->x)
    s->tmp_clients->x = 0;
  s->tmp_clients->y += g_y[s->tmp_clients->direction];
  if ((int)s->tmp_clients->y < 0)
    s->tmp_clients->y = s->y - 1;
  else if (s->tmp_clients->y >= (unsigned int)s->y)
    s->tmp_clients->y = 0;
  strcpy(s->tmp_clients->send, OK("\n"));
  exec_ppo(s);
  return (FALSE);
}
