/*
** msz_cmd.c for msz_cmd.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Thu Jun 19 14:52:01 2014 abgral_f
** Last update Thu Jul 10 23:42:19 2014 abgral_f
*/

#include		"graphic.h"

static void		set_items_pos(t_graphic *c)
{
  unsigned int		count;
  int			count_stone;

  count = 0;
  while (count != c->x * c->y)
    {
      c->map[count].isUpdate = FALSE;
      c->map[count].sprite_one = (bool)rand() % 2;
      c->map[count].b.food_pos[0] = rand()
	% (SPRITE_SIZE - WIDTH_FOOD)  - MARGE_HOR;
      c->map[count].b.food_pos[1] = rand()
	% (SPRITE_SIZE - HEIGHT_FOOD) - MARGE_VER + 1;
      count_stone = -1;
      while (++count_stone != NB_STONE)
	{
	  c->map[count].b.stone_pos[count_stone][0] = MARGE_HOR * -1
	    + rand() % (SPRITE_SIZE - WIDTH_STONE);
	  c->map[count].b.stone_pos[count_stone][1] = MARGE_VER * -1
	    + rand() % (SPRITE_SIZE - HEIGHT_STONE);
	}
      count++;
    }
}

int			msz_cmd(char **args, t_graphic *c)
{
  unsigned int		count;
  int			count_stones;

  if (c->map == NULL)
    {
      c->x = atoi(args[0]);
      c->y = atoi(args[1]);
      if ((c->map = malloc(sizeof (*c->map) * c->x * c->y)) == NULL)
	return (my_perror(SYSCALL("malloc"), CONTINUE));
      set_items_pos(c);
      count = 0;
      while (count != c->x * c->y)
	{
	  count_stones = 0;
	  while (count_stones != NB_STONE)
	    {
	      c->map[count].b.stone[count_stones] = 0;
	      c->map[count].b.food = 0;
	      count_stones++;
	    }
	  count++;
	}
    }
  return (SUCCESS);
}
