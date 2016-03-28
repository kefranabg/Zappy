/*
** map.c for map.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May 30 14:54:59 2014 LOEB Thomas
** Last update Sat Jul 12 12:43:26 2014 abgral_f
*/

#include		"server.h"

int			create_map(t_server *s)
{
  unsigned int		i;

  if ((s->map = malloc(s->x * s->y * sizeof(t_box))) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  memset(s->map, '\0', s->x * s->y * sizeof(t_box));
  i = -1;
  while (++i < (unsigned int)(s->x * s->y))
    {
      s->map[i].stone[rand() % NB_STONE] = 1;
      s->map[i].stone[rand() % NB_STONE] = 1;
      s->map[i].food = 1;
    }
  return (SUCCESS);
}

bool			is_empty_box(t_server *s, int x, int y)
{
  t_client		*tmp;
  unsigned int		i;

  tmp = s->clients;
  while (tmp != NULL)
    if (tmp != s->tmp_clients && (int)tmp->x == x && (int)tmp->y == y)
      return (FALSE);
    else
      tmp = tmp->next;
  if (s->map[x + y * s->x].food != 0)
    return (FALSE);
  i = -1;
  while (++i < NB_STONE)
    if (s->map[x + y * s->x].stone[i] != 0)
      return (FALSE);
  return (TRUE);
}

static void		inform_graphic(t_server *s, int x, int y)
{
  if (write_graphic(s) == FAILURE)
    return ;
  exec_bct_fill(s, x, y);
}

void			refill_map(t_server *s)
{
  unsigned int		i;
  int			randVal;
  bool			refill;

  if (rand() % 30 != 0)
    return ;
  i = -1;
  while (++i < (unsigned int)(s->x * s->y))
    {
      refill = FALSE;
      if (s->map[i].food == 0 && rand() % 10 == 0)
	{
	  refill = TRUE;
	  s->map[i].food = 1;
	}
      randVal = rand() % NB_STONE;
      if (s->map[i].stone[randVal] == 0 && rand() % 100 == 0)
	{
	  refill = TRUE;
	  s->map[i].stone[randVal] = 1;
	}
      if (refill == TRUE)
	inform_graphic(s, i % s->x, i / s->x);
    }
}
