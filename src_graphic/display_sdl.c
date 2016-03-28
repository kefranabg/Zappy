/*
** display_sdl.c for display_sdl.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Jul  1 14:47:58 2014 abgral_f
** Last update Sat Jul 12 15:16:53 2014 abgral_f
*/

#include		"graphic.h"

static t_anim		cmp[NB_ANIMS] =
  {
    {MOVES, &anim_moves},
    {KIK, &anim_kik},
    {DROP, &anim_drop},
    {LAY, &anim_lay},
    {INCANT, &anim_incant}
  };

static int		display_anims(t_graphic *c)
{
  t_client              *tmp;
  int			count;

  tmp = c->client;
  while (tmp != NULL)
    {
      count = 0;
      while (count != NB_ANIMS)
	{
	  if (tmp->anim == cmp[count].anim)
	    if ((*(cmp[count].ptr_func))(c, tmp) == FAILURE)
	      return (FAILURE);
	    count++;
	}
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int			display_sdl(t_graphic *c)
{
  if (SDL_FillRect(c->display.list[WINDOW], NULL, 0x000000) == -1)
    return (my_error(SDL_GetError(), FAILURE));
  if (c->map != NULL && (display_map(c) == FAILURE ||
			 display_items(c) == FAILURE ||
			 display_eggs(c) == FAILURE ||
			 display_player(c) == FAILURE ||
			 display_anims(c) == FAILURE ||
			 display_gui(c) == FAILURE))
    return (FAILURE);
  if (SDL_Flip(c->display.list[WINDOW]) == -1)
    return (my_error(SDL_GetError(), FAILURE));
  if (SDL_PollEvent(&c->display.event) == -1)
    return (my_error((SDL_GetError()), FAILURE));
  SDL_Delay(1000 * 7 / c->time / NB_SPRITES_ANIM);
  return (event(c));
}
