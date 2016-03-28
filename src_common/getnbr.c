/*
** getnbr.c for getnbr.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu May 29 16:39:34 2014 LOEB Thomas
** Last update Thu May 29 16:41:17 2014 LOEB Thomas
*/

#include		"common.h"

int			getnbr(char *s)
{
  unsigned int		i;

  i = -1;
  while (s[++i] != '\0')
    if (s[i] < '0' || s[i] > '9')
      return (-1);
  return (atoi(s));
}
