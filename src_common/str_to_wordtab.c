/*
** point_on_words.c for point_on_words.c in /home/chauch_a/rendu/PSU_2013_zappy
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Tue Jun 24 16:40:54 2014 CHAUCHET Alan
** Last update Wed Jul  9 17:28:18 2014 CHAUCHET Alan
*/

#include		"common.h"

static bool		is_delim(char c, char *delim)
{
  unsigned int		count;

  count = -1;
  while (delim[++count])
    if (delim[count] == c)
      return (TRUE);
  return (FALSE);
}

static char		**create_word_tab(char *str, unsigned int nb_words,
					  unsigned int size)
{
  unsigned int		count;
  unsigned int		count_tab;
  char			**word_tab;

  if ((word_tab = malloc(sizeof(char *) * (nb_words + 1))) == NULL)
    {
      my_perror(SYSCALL("malloc"), FAILURE);
      return (NULL);
    }
  count = -1;
  count_tab = -1;
  while (++count < size)
    if (str[count] != '\0' && (count == 0 || str[count - 1] == '\0'))
      word_tab[++count_tab] = strdup(&(str[count]));
  word_tab[++count_tab] = NULL;
  free(str);
  return (word_tab);
}

char			**str_to_wordtab(char *param, char *delim)
{
  unsigned int		count;
  unsigned int		nb_words;
  unsigned int		size;
  char			*str;

  count = -1;
  size = strlen(param);
  nb_words = 0;
  if ((str = strdup(param)) == NULL)
    {
      my_perror(SYSCALL("malloc"), FAILURE);
      return (NULL);
    }
  while (++count < size)
    if (is_delim(str[count], delim))
      str[count] = '\0';
    else
      if (count == 0 || str[count - 1] == '\0')
	++nb_words;
  return (create_word_tab(str, nb_words, size));
}

void			free_wordtab(char **wordtab)
{
  unsigned int		count;

  count = -1;
  while (wordtab[++count])
    free(wordtab[count]);
  free(wordtab);
}
