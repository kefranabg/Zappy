/*
** disp_items.c for disp_items.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Jul  4 15:11:00 2014 abgral_f
** Last update Thu Jul 10 19:44:23 2014 abgral_f
*/

#include		"graphic.h"

static t_stones         stones[NB_STONE] =
  {
    {0, 0, 0},
    {1, SPRITE_SIZE, 0},
    {2, SPRITE_SIZE * 2, 0},
    {3, 0, SPRITE_SIZE},
    {4, SPRITE_SIZE, SPRITE_SIZE},
    {5, SPRITE_SIZE * 2, SPRITE_SIZE}
  };

static int		display_stones(t_graphic *c, int count_x,
				       int count_y, int stone_nb)
{
  if (c->map[count_x + count_y * c->x].b.stone[stone_nb] > 0)
    {
      c->display.sprite.y = stones[stone_nb].pos_y;
      c->display.sprite.x = stones[stone_nb].pos_x;
      c->display.pos.x = (count_x - c->display.cursor_x) * SPRITE_SIZE
	+ c->map[count_x + count_y * c->x].b.stone_pos[stone_nb][0];
      c->display.pos.y = (count_y - c->display.cursor_y) * SPRITE_SIZE
	+ c->map[count_x + count_y * c->x].b.stone_pos[stone_nb][1];
      if (SDL_BlitSurface(c->display.list[ITEMS], &c->display.sprite,
			  c->display.list[WINDOW],
			  &c->display.pos) == -1)
	return (my_error(SDL_GetError(), FAILURE));
    }
  return (SUCCESS);
}

static int		display_food(t_graphic *c, int count_x, int count_y)
{
  if (c->map[count_x + count_y * c->x].b.food > 0)
    {
      c->display.sprite.y = SPRITE_SIZE * 2;
      c->display.sprite.x = 0;
      c->display.pos.x = (count_x - c->display.cursor_x) * SPRITE_SIZE
	+ c->map[count_x + count_y * c->x].b.food_pos[0];
      c->display.pos.y = (count_y - c->display.cursor_y) * SPRITE_SIZE
	+ c->map[count_x + count_y * c->x].b.food_pos[1];
      if (SDL_BlitSurface(c->display.list[ITEMS],
			  &c->display.sprite, c->display.list[WINDOW],
			  &c->display.pos) == -1)
	return (my_error(SDL_GetError(), FAILURE));
    }
  return (SUCCESS);
}

int			display_items(t_graphic *c)
{
  unsigned int          count_x;
  unsigned int          count_y;
  int                   stone_nb;

  count_y = c->display.cursor_y - 1;
  while (++count_y != c->y && count_y !=
	 c->display.cursor_y + WIN_Y / SPRITE_SIZE)
    {
      count_x = c->display.cursor_x - 1;
      while (++count_x != c->x && count_x !=
	     c->display.cursor_x + MAP_X / SPRITE_SIZE)
        {
	  stone_nb = 0;
	  while (stone_nb != NB_STONE)
	    {
	      if (display_stones(c, count_x, count_y, stone_nb) == FAILURE)
		return (FAILURE);
	      stone_nb++;
	    }
	  if (display_food(c, count_x, count_y) == FAILURE)
	    return (FAILURE);
	}
    }
  return (SUCCESS);
}
