/*
** select.c for select.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 14:50:19 2014 LOEB Thomas
** Last update Thu May  8 13:31:45 2014 LOEB Thomas
*/

#include		"common.h"

int			my_select(t_select *s, e_mode flag)
{
  if (flag == R)
    s->retSelect = select(s->maxfd, &s->rdfds, NULL, NULL, &s->tv);
  else if (flag == W)
    s->retSelect = select(s->maxfd, NULL, &s->wrfds, NULL, &s->tv);
  else if (flag == RW)
    s->retSelect = select(s->maxfd, &s->rdfds, &s->wrfds, NULL, &s->tv);
  return (s->retSelect);
}
