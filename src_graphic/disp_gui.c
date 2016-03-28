/*
** disp_gui.c for disp_gui.c in /home/abgral_f/backups/zappy7/src_graphic
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Thu Jul 10 21:32:48 2014 abgral_f
** Last update Fri Jul 11 13:43:06 2014 abgral_f
*/

#include		"graphic.h"

static int		display_gui_text(t_graphic *c)
{
  if ((c->display.text = TTF_RenderText_Blended(c->display.font,
						c->display.str,
						c->display.color)) == NULL)
    return (my_error(TTF_GetError(), FAILURE));
  if (SDL_BlitSurface(c->display.text, NULL, c->display.list[WINDOW],
		      &c->display.pos) == -1)
    return (my_error(SDL_GetError(), FAILURE));
  SDL_FreeSurface(c->display.text);
  return (SUCCESS);
}

static int		display_gui_items(t_graphic *c)
{
  int			count;

  count = 0;
  while (count != NB_STONE)
    {
      c->display.pos.x = MAP_X + MARGE_GUI_ITEMS_X;
      c->display.pos.y = MARGE_GUI_ITEMS_Y + MARGE_GUI * count;
      sprintf(c->display.str, "%d",
	      (int)c->map[c->display.coord_x
			  + c->display.coord_y * c->x].b.stone[count]);
      if (display_gui_text(c) == FAILURE)
	return (FAILURE);
      count++;
    }
  c->display.pos.y = 150 + 40 * count;
  sprintf(c->display.str, "%d",
	  (int)c->map[c->display.coord_x + c->display.coord_y * c->x].b.food);
  if (display_gui_text(c) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

static int		display_gui_coord(t_graphic *c)
{
  c->display.pos.x = MAP_X + 70;
  c->display.pos.y = 55;
  sprintf(c->display.str, "%d", c->display.coord_x);
  if (display_gui_text(c) == FAILURE)
    return (FAILURE);
  c->display.pos.x = MAP_X + 230;
  c->display.pos.y = 55;
  sprintf(c->display.str, "%d", c->display.coord_y);
  if (display_gui_text(c) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

static int		display_gui_teams(t_graphic *c)
{
  t_client		*tmp;
  int			count;

  tmp = c->client;
  count = 0;
  while (tmp != NULL)
    {
      c->display.pos.x = MAP_X + 20;
      if (tmp->x == c->display.coord_x && tmp->y == c->display.coord_y
	  && count <= GUI_LIST_MAX)
	{
	  c->display.pos.y = 470 + 40 * count;
	  sprintf(c->display.str, "%s", tmp->team->name);
	  if (display_gui_text(c) == FAILURE)
	    return (FAILURE);
	  c->display.pos.x = MAP_X + 175;
	  sprintf(c->display.str, "%d", tmp->lvl);
	  if (display_gui_text(c) == FAILURE)
	    return (FAILURE);
	  c->display.pos.x = MAP_X + 275;
	  sprintf(c->display.str, "%d", (int)tmp->inventory.food);
	  if (display_gui_text(c) == FAILURE)
	    return (FAILURE);
	  count++;
	}
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int			display_gui(t_graphic *c)
{
  c->display.pos.x = MAP_X;
  c->display.pos.y = 0;
  if (SDL_BlitSurface(c->display.list[GUI], NULL, c->display.list[WINDOW],
		      &c->display.pos) == -1)
    return (my_error(SDL_GetError(), FAILURE));
  if (display_gui_items(c) == FAILURE
      || display_gui_coord(c) == FAILURE
      || display_gui_teams(c) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
