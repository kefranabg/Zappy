/*
** getline.c for getline.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 15:10:29 2014 LOEB Thomas
** Last update Wed May 14 12:27:01 2014 LOEB Thomas
*/

#include		"common.h"

int			my_getline(t_line *l)
{
  l->retGetline = getline(&l->line, &l->len, l->stream);
  if (l->retGetline > 0)
    l->len_line = strlen(l->line);
  else
    l->len_line = 0;
  return (l->retGetline);
}
