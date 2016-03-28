/*
** check_graphic.c for check_graphic.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 12:54:11 2014 LOEB Thomas
** Last update Mon Jun  9 17:39:13 2014 LOEB Thomas
*/

#include		"server.h"

bool			check_bct(t_server *s)
{
  int			coord;

  if ((coord = getnbr(s->p.cmd[1])) < 0 || coord >= s->x ||
      (coord = getnbr(s->p.cmd[2])) < 0 || coord >= s->y)
    return (FALSE);
  return (TRUE);
}

bool			check_no_player(t_server *s)
{
  int			pos;
  t_client		*tmp;

  if (s->p.cmd[1][0] != '#' || (pos = getnbr(s->p.cmd[1] + 1)) < 0)
    return (FALSE);
  tmp = s->clients;
  while (tmp != NULL && (unsigned int)pos != tmp->id)
    tmp = tmp->next;
  if (tmp == NULL)
    return (FALSE);
  return (TRUE);
}

bool			check_sst(t_server *s)
{
  unsigned int		i;
  unsigned char		comma;

  i = -1;
  comma = 0;
  while (s->p.cmd[1][++i] != '\0')
    if ((s->p.cmd[1][i] < '0' || s->p.cmd[1][i] > '9') &&
	(comma == 1 || (comma == 0 && s->p.cmd[1][i] != '.')))
      return (FALSE);
    else if (s->p.cmd[1][i] == '.')
      comma = 1;
  if (atoi(s->p.cmd[1]) <= 0)
    return (FALSE);
  return (TRUE);
}
