/*
** get_click_coord.c for get_click_coord.c in /home/abgral_f/backups/zappy7
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Thu Jul 10 20:15:06 2014 abgral_f
** Last update Fri Jul 11 13:43:34 2014 abgral_f
*/

#include		"graphic.h"

int			get_click_coord(t_graphic *c)
{
  if (c->display.event.type == SDL_MOUSEBUTTONDOWN)
    {
      if (c->display.event.button.x / SPRITE_SIZE < c->x
	  && c->display.event.button.y / SPRITE_SIZE < c->y
	  && c->display.event.button.x < MAP_X)
	{
	  c->display.coord_x = c->display.event.button.x
	    / SPRITE_SIZE + c->display.cursor_x;
	  c->display.coord_y = c->display.event.button.y
	    / SPRITE_SIZE + c->display.cursor_y;
	}
    }
  return (SUCCESS);
}
