/*
** circular.c for circular.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue May 13 12:15:06 2014 LOEB Thomas
** Last update Fri Jun 13 14:10:53 2014 LOEB Thomas
*/

#include		"common.h"

int			pos_cmd(t_buffer *b)
{
  int			ret;

  ret = -1;
  while (++ret < BUFF_LEN)
    if (b->circular[ret] == '\n')
      return (ret);
  return (-1);
}

void			get_cmd(t_buffer *b, int pos)
{
  if (pos == -1)
    return ;
  strncpy(b->tmp, b->circular, pos);
  b->tmp[pos] = '\0';
  memmove(b->circular, b->circular + pos + 1, BUFF_LEN - (pos + 1));
  memset(b->circular + BUFF_LEN - (pos + 1), '\0', pos + 1);
  b->idx -= (pos + 1);
  while ((int)b->idx < 0)
    b->idx += BUFF_LEN;
}

void			buffer_to_circular(t_buffer *l)
{
  unsigned int		nbChar;

  if (l->tmp[BUFF_LEN - 1] == '\0')
    nbChar = strlen(l->tmp);
  else
    nbChar = BUFF_LEN;
  if (nbChar > BUFF_LEN - l->idx + 1)
    nbChar = BUFF_LEN - l->idx + 1;
  memmove(l->circular + l->idx, l->tmp, nbChar);
  l->idx = (l->idx + nbChar) % BUFF_LEN;
  if (l->tmp[BUFF_LEN - 1] != '\0' && nbChar != BUFF_LEN)
    {
      memmove(l->circular + l->idx, l->tmp + nbChar - 1,
	      BUFF_LEN - nbChar);
      l->idx += (BUFF_LEN - nbChar);
      l->idx %= BUFF_LEN;
    }
  else if (l->tmp[BUFF_LEN - 1] == '\0' && nbChar != strlen(l->tmp))
    {
      memmove(l->circular + l->idx, l->tmp + nbChar - 1,
	      strlen(l->tmp) - nbChar);
      l->idx += (strlen(l->tmp) - nbChar);
      l->idx %= BUFF_LEN;
    }
}
