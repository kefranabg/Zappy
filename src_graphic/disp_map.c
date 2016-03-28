/*
** disp_map.c for disp_map.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Jul  4 15:07:15 2014 abgral_f
** Last update Thu Jul 10 19:44:06 2014 abgral_f
*/

#include		"graphic.h"

static void	        set_sprite_size(t_graphic *c, int value)
{
  c->display.sprite.w = SPRITE_SIZE + value;
  c->display.sprite.h = SPRITE_SIZE + value;
}

int			display_map(t_graphic *c)
{
  unsigned int          count_x;
  unsigned int          count_y;

  count_y = c->display.cursor_y - 1;
  set_sprite_size(c, -1);
  c->display.sprite.y = 0;
  while (++count_y != c->y && count_y !=
	 c->display.cursor_y + WIN_Y / SPRITE_SIZE)
    {
      count_x = c->display.cursor_x - 1;
      while (++count_x != c->x && count_x !=
	     c->display.cursor_x + MAP_X / SPRITE_SIZE)
	{
	  if (c->map[count_x + count_y * c->x].sprite_one == FALSE)
	    c->display.sprite.x = 0;
	  else
	    c->display.sprite.x = SPRITE_SIZE;
	  c->display.pos.x = (count_x - c->display.cursor_x) * SPRITE_SIZE;
	  c->display.pos.y = (count_y - c->display.cursor_y) * SPRITE_SIZE;
	  if (SDL_BlitSurface(c->display.list[MAP],
			      &c->display.sprite, c->display.list[WINDOW],
			      &c->display.pos) == -1)
	    return (my_error(SDL_GetError(), FAILURE));
	}
     }
  set_sprite_size(c, 0);
  return (SUCCESS);
}
