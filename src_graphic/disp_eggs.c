/*
** disp_eggs.c for disp_eggs.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Jul  4 15:19:37 2014 abgral_f
** Last update Wed Jul  9 15:21:45 2014 abgral_f
*/

#include		"graphic.h"

int			display_eggs(t_graphic *c)
{
  t_egg                 *tmp;

  tmp = c->eggs;
  c->display.sprite.y = 0;
  while (tmp != NULL)
    {
      if (tmp->isHatched == TRUE)
        c->display.sprite.x = SPRITE_SIZE;
      else
        c->display.sprite.x = 0;
      c->display.pos.x = (tmp->x - c->display.cursor_x) * SPRITE_SIZE;
      c->display.pos.y = (tmp->y - c->display.cursor_y) * SPRITE_SIZE;
      if (SDL_BlitSurface(c->display.list[EGG],
			  &c->display.sprite, c->display.list[WINDOW],
			  &c->display.pos) == -1)
        return (my_error(SDL_GetError(), FAILURE));
      tmp = tmp->next;
    }
  return (SUCCESS);
}
