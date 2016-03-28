/*
** nbrlen.c for nbrlen.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Sun May 18 17:52:15 2014 LOEB Thomas
** Last update Wed Jun 25 14:01:47 2014 LOEB Thomas
*/

#include		"common.h"

int			nbrlen(int nb)
{
  int			len;

  len = 1;
  while (nb / 10 != 0)
    {
      nb /= 10;
      ++len;
    }
  return (len);
}

int			nbr_to_str(int nb, char *s, char *after_nb)
{
  unsigned int		idx;
  unsigned int		after;
  int			len;

  if (nb < 0)
    nb = 0;
  idx = -1;
  len = nbrlen(nb) - 1;
  while (nb / 10 != 0)
    {
      s[len - ++idx] = nb % 10 + 48;
      nb /= 10;
    }
  s[len - ++idx] = nb + 48;
  if (after_nb != NULL)
    {
      after = -1;
      while (after_nb[++after] != '\0')
	s[++idx] = after_nb[after];
      s[++idx] = '\0';
    }
  return (SUCCESS);
}

int			nb_space(char *s)
{
  unsigned int		i;
  int			ret;

  i = -1;
  ret = 0;
  while (s[++i] != '\0')
    if (s[i] == ' ')
      ++ret;
  return (ret);
}
