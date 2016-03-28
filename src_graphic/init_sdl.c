/*
** init_sdl.c for init_sdl.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Mon Jun 30 16:56:48 2014 abgral_f
** Last update Fri Jul 11 13:46:56 2014 abgral_f
*/

#include		"graphic.h"

void			free_surfaces(t_graphic *c)
{
  int			count;

  count = 0;
  while (count != SURFACE_NB)
    {
      if (c->display.list[count] != NULL)
	SDL_FreeSurface(c->display.list[count]);
      count++;
    }
  free(c->display.list);
}

static int		set_transparency(t_graphic *c)
{
  int			count;

  count = 1;
  while (count != SURFACE_NB)
    {
      if (SDL_SetColorKey(c->display.list[count], SDL_SRCCOLORKEY,
			  SDL_MapRGB(c->display.list[count]->format,
				     0, 0, 170)) == -1)
	return (my_error(SDL_GetError(), FAILURE));
      count++;
    }
  return (SUCCESS);
}

static void		init_display(t_graphic *c)
{
  c->display.cursor_x = 0;
  c->display.cursor_y = 0;
  c->display.coord_x = 0;
  c->display.coord_y = 0;
  c->display.color.r = 255;
  c->display.color.g = 255;
  c->display.color.b = 255;
}

static int		init_ttf(t_graphic *c)
{
  if (TTF_Init() == -1)
    return (my_error(TTF_GetError(), FAILURE));
  if ((c->display.font = TTF_OpenFont("font/BEBAS___.TTF", 24)) == NULL)
    return (my_error(TTF_GetError(), FAILURE));
  return (SUCCESS);
}

int			init_sdl(t_graphic *c)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (my_error(SDL_GetError(), FAILURE));
  if ((c->display.list = malloc(sizeof (*c->display.list)
				* SURFACE_NB)) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  if ((c->display.list[WINDOW] =
       SDL_SetVideoMode(WIN_X, WIN_Y, 32, SDL_HWSURFACE)) == NULL)
    return (my_error(SDL_GetError(), FAILURE));
  SDL_WM_SetCaption("Zappy", NULL);
  if ((c->display.list[MAP] = SDL_LoadBMP("sprites/map.bmp")) == NULL
      || (c->display.list[ITEMS] = SDL_LoadBMP("sprites/items.bmp")) == NULL
      || (c->display.list[LINK] = SDL_LoadBMP("sprites/link.bmp")) == NULL
      || (c->display.list[EGG] = SDL_LoadBMP("sprites/egg.bmp")) == NULL
      || (c->display.list[MOVES] = SDL_LoadBMP("sprites/moves.bmp")) == NULL
      || (c->display.list[LAY] = SDL_LoadBMP("sprites/lay.bmp")) == NULL
      || (c->display.list[KIK] = SDL_LoadBMP("sprites/kik.bmp")) == NULL
      || (c->display.list[DROP] = SDL_LoadBMP("sprites/drop.bmp")) == NULL
      || (c->display.list[GUI] = SDL_LoadBMP("sprites/gui.bmp")) == NULL
      || (c->display.list[INCANT] = SDL_LoadBMP("sprites/incant.bmp")) == NULL)
    return (my_error(SDL_GetError(), FAILURE));
  if (set_transparency(c) == FAILURE)
    return (FAILURE);
  init_display(c);
  return (init_ttf(c));
}
