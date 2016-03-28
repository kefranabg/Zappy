/*
** event.c for event.c in /home/abgral_f/backups/zappy5
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Jul  9 12:45:03 2014 abgral_f
** Last update Fri Jul 11 12:38:38 2014 abgral_f
*/

#include		"graphic.h"

int			event(t_graphic *c)
{
  if (c->display.event.type == SDL_KEYDOWN)
    {
      if (c->display.event.key.keysym.sym == SDLK_ESCAPE)
        return (FAILURE);
      if (c->display.event.key.keysym.sym == SDLK_LEFT
	  && c->display.cursor_x > 0)
	c->display.cursor_x--;
      else
        if (c->display.event.key.keysym.sym == SDLK_RIGHT
	    && MAP_X / SPRITE_SIZE + c->display.cursor_x + 1 <= c->x)
	  c->display.cursor_x++;
	else
          if (c->display.event.key.keysym.sym == SDLK_UP
	      && c->display.cursor_y > 0)
            c->display.cursor_y--;
          else
            if (c->display.event.key.keysym.sym == SDLK_DOWN
		&& WIN_Y / SPRITE_SIZE + c->display.cursor_y + 1 <= c->y)
              c->display.cursor_y++;
    }
  return (get_click_coord(c));
}
