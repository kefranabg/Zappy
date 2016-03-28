/*
** pin_cmd.c for pin_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Mon Jun 23 18:32:22 2014 abgral_f
** Last update Wed Jul  2 15:17:26 2014 abgral_f
*/

#include		"graphic.h"

int			pin_cmd(char **args, t_graphic *c)
{
  int			count;
  int			i;
  t_client		*tmp;

  if (check_player(atoi(args[0] + 1), c) == FAILURE)
    return (my_error("Unknown player id", FAILURE));
  tmp = c->client;
  while (tmp->id != (unsigned int)atoi(args[0] + 1))
    tmp = tmp->next;
  count = 3;
  i = 0;
  while (count != 10)
    {
      if (atoi(args[count]) < 0)
	return (my_perror("Items number can't have a negativ value", FAILURE));
      if (count == 3)
	tmp->inventory.food = atoi(args[count]);
      else
	tmp->inventory.stone[count - 4] = atoi(args[count]);
      count++;
      i++;
    }
  return (SUCCESS);
}
