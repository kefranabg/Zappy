/*
** disp_player.c for disp_player.c in /home/abgral_f/rendu/PSU_2013_zappy
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Jul  4 15:20:58 2014 abgral_f
** Last update Wed Jul  9 18:19:17 2014 abgral_f
*/

#include		"graphic.h"

static t_direction      direction[NB_DIRECTIONS] =
  {
    {D_BOTTOM, 0, 0, (SPRITE_SIZE + 4) / 10},
    {D_TOP, SPRITE_SIZE - 1, 0, (SPRITE_SIZE + 4) / 10 * -1},
    {D_LEFT, SPRITE_SIZE * 2 - 2, (SPRITE_SIZE + 7) / 10 * -1, 0},
    {D_RIGHT, SPRITE_SIZE * 3 - 2, (SPRITE_SIZE + 7) / 10, 0}
  };

void			set_position(t_graphic *c, t_client *tmp)
{
  int                   count;

  count = 0;
  while (count != NB_DIRECTIONS && tmp->direction
         != direction[count].direction)
    count++;
  c->display.sprite.y = direction[count].sprite_pos;
  c->display.sprite.x = SPRITE_SIZE * tmp->count_anim;
  c->display.pos.x = (tmp->x - c->display.cursor_x) * SPRITE_SIZE;
  c->display.pos.y = (tmp->y - c->display.cursor_y) * SPRITE_SIZE;
}

int			display_player(t_graphic *c)
{
  t_client              *tmp;
  int                   count;

  tmp = c->client;
  c->display.sprite.y = 0;
  while (tmp != NULL)
    {
      count = 0;
      while (count != NB_DIRECTIONS)
        {
          if (tmp->direction == direction[count].direction)
            c->display.sprite.x = direction[count].sprite_pos;
          count++;
        }
      c->display.pos.x = (tmp->x - c->display.cursor_x) * SPRITE_SIZE;
      c->display.pos.y = (tmp->y - c->display.cursor_y) * SPRITE_SIZE;
      if (tmp->anim == UNDEFINED)
        if (SDL_BlitSurface(c->display.list[LINK],
                            &c->display.sprite, c->display.list[WINDOW],
                            &c->display.pos) == -1)
          return (my_error(SDL_GetError(), FAILURE));
      tmp = tmp->next;
    }
  return (SUCCESS);
}
