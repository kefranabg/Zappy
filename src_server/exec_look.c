/*
** exec_look.c for exec_look.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Sun Jun  1 13:46:47 2014 LOEB Thomas
** Last update Tue Jun 17 12:46:53 2014 LOEB Thomas
*/

#include		"server.h"

static char		*g_look[NB_STONE + 2][2] =
  {
    {PLAYER, S_PLAYER},
    {FOOD, S_FOOD},
    {LINEMATE, S_LINEMATE},
    {DERAUMERE, S_DERAUMERE},
    {SIBUR, S_SIBUR},
    {MENDIANE, S_MENDIANE},
    {PHIRAS, S_PHIRAS},
    {THYSTAME, S_THYSTAME}
  };

static void		exec_look_strcpy(t_server *s, char *cpy, char *state)
{
  if (*state == 0)
    *state = 1;
  strcpy(s->tmp_clients->send + strlen(s->tmp_clients->send), cpy);
}

static void		exec_look_write(t_server *s, int x, int y, char state)
{
  t_client		*tmp;
  unsigned int		i;
  unsigned int		j;

  if (state == 2)
    state = 1;
  tmp = s->clients;
  while (tmp != NULL)
    {
      if (tmp != s->tmp_clients && (int)tmp->x == x && (int)tmp->y == y)
	exec_look_strcpy(s, g_look[0][(int)state], &state);
      tmp = tmp->next;
    }
  j = -1;
  while (++j < s->map[x + y * s->x].food)
    exec_look_strcpy(s, g_look[1][(int)state], &state);
  i = -1;
  while (++i < NB_STONE)
    {
      j = -1;
      while (++j < s->map[x + y * s->x].stone[i])
	exec_look_strcpy(s, g_look[i + 2][(int)state], &state);
    }
}

static void		exec_look_check(t_server *s, int x, int y, char state)
{
  if (x < 0)
    x = s->x - (x % s->x);
  else if (x > s->x)
    x %= s->x;
  if (y < 0)
    y = s->y - (y % s->y);
  else if (y > s->y)
    y %= s->y;
  if (is_empty_box(s, x, y) == FALSE)
    exec_look_write(s, x, y, state);
  if (state != 2)
    s->tmp_clients->send[strlen(s->tmp_clients->send)] = ',';
}

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

bool			exec_look(t_server *s)
{
  unsigned int		i;
  unsigned int		k;
  char			state;

  i = -1;
  state = 0;
  strcpy(s->tmp_clients->send, "{");
  while (++i != s->tmp_clients->level + 1)
    {
      k = -1;
      while (++k < i * 2 + 1)
	{
	  if (k == i * 2 && i == s->tmp_clients->level)
	    state = 2;
	  exec_look_check(s, s->tmp_clients->x + g_x[s->tmp_clients->direction]
			  * i + (i - k) * g_y[s->tmp_clients->direction],
			  s->tmp_clients->y + g_y[s->tmp_clients->direction]
			  * i + (i - k) * g_x[s->tmp_clients->direction],
			  state);
	  if (state == 0)
	    state = 1;
	}
    }
  strcpy(s->tmp_clients->send + strlen(s->tmp_clients->send), "}\n");
  return (FALSE);
}
