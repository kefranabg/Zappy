/*
** parse.c for parse.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue May 13 12:55:52 2014 LOEB Thomas
** Last update Mon May 19 11:51:54 2014 LOEB Thomas
*/

#include		"common.h"

void			free_words(t_parse *p)
{
  unsigned int		i;

  i = -1;
  while (++i < p->len)
    free(p->cmd[i]);
  free(p->cmd);
  memset(p, '\0', sizeof(t_parse));
}

static int		nb_words(char *s)
{
  unsigned int		i;
  unsigned int		ret;

  i = -1;
  ret = 0;
  while (s[++i] != '\0')
    if (s[i] != ' ' && s[i] != '\t' &&
	(i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t'))
      ++ret;
  return (ret);
}

static int		new_word(t_parse *p, char *s, unsigned int *i,
				 unsigned int idx_word)
{
  unsigned int		len_word;
  unsigned int		len_cpy;

  len_word = strlen(s + (*i));
  len_cpy = len_word;
  if (len_word >= ARG_LEN - 1)
    len_cpy = ARG_LEN - 1;
  if ((p->cmd[idx_word] = malloc((len_cpy + 1) * sizeof(char))) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  strncpy(p->cmd[idx_word], s + (*i), len_cpy);
  p->cmd[idx_word][len_cpy] = '\0';
  (*i) += len_word;
  return (SUCCESS);
}

int			parse_cmd(t_parse *p, char *s)
{
  unsigned int		len_tmp;
  unsigned int		idx_word;
  unsigned int		i;

  if (p->cmd != NULL)
    free_words(p);
  memcpy(p->line, s, BUFF_LEN);
  p->len = nb_words(s);
  if ((p->cmd = malloc((p->len + 1) * sizeof(char *))) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  p->cmd[p->len] = NULL;
  len_tmp = strlen(s);
  i = -1;
  while (++i < len_tmp)
    if (s[i] == ' ' || s[i] == '\t')
      s[i] = '\0';
  idx_word = -1;
  i = -1;
  while (++i < len_tmp)
    if (s[i] != '\0' && (i == 0 || s[i - 1] == '\0') &&
	new_word(p, s, &i, ++idx_word) == FAILURE)
      return (FAILURE);
  return (SUCCESS);
}
