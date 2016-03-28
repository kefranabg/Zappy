/*
** anim.c for anim.c in /home/abgral_f/backups/zappy5
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Wed Jul  9 18:17:20 2014 abgral_f
** Last update Wed Jul  9 18:20:25 2014 abgral_f
*/

#include		"graphic.h"

static t_direction      direction[NB_DIRECTIONS] =
  {
    {D_BOTTOM, 0, 0, (SPRITE_SIZE + 4) / 10},
    {D_TOP, SPRITE_SIZE - 1, 0, (SPRITE_SIZE + 4) / 10 * -1},
    {D_LEFT, SPRITE_SIZE * 2 - 2, (SPRITE_SIZE + 7) / 10 * -1, 0},
    {D_RIGHT, SPRITE_SIZE * 3 - 2, (SPRITE_SIZE + 7) / 10, 0}
  };

int                     anim_kik(t_graphic *c, t_client *tmp)
{
  set_position(c, tmp);
  if (SDL_BlitSurface(c->display.list[KIK],
                      &c->display.sprite, c->display.list[WINDOW],
                      &c->display.pos) == -1)
    return (my_error(SDL_GetError(), FAILURE));
  tmp->count_anim++;
  if (tmp->count_anim > 4)
    tmp->anim = UNDEFINED;
  return (SUCCESS);
}

int                     anim_drop(t_graphic *c, t_client *tmp)
{
  set_position(c, tmp);
  if (SDL_BlitSurface(c->display.list[DROP],
                      &c->display.sprite, c->display.list[WINDOW],
                      &c->display.pos) == -1)
    return (my_error(SDL_GetError(), FAILURE));
  tmp->count_anim++;
  if (tmp->count_anim > 2)
    tmp->anim = UNDEFINED;
  return (SUCCESS);
}

int                     anim_lay(t_graphic *c, t_client *tmp)
{
  set_position(c, tmp);
  if (SDL_BlitSurface(c->display.list[LAY],
                      &c->display.sprite, c->display.list[WINDOW],
                      &c->display.pos) == -1)
    return (my_error(SDL_GetError(), FAILURE));
  tmp->count_anim++;
  if (tmp->count_anim > 2)
    tmp->count_anim = 0;
  return (SUCCESS);
}

int                     anim_incant(t_graphic *c, t_client *tmp)
{
  set_position(c, tmp);
  if (SDL_BlitSurface(c->display.list[INCANT],
                      &c->display.sprite, c->display.list[WINDOW],
                      &c->display.pos) == -1)
    return (my_error(SDL_GetError(), FAILURE));
  tmp->count_anim++;
  if (tmp->count_anim > NB_SPRITES_ANIM - 2)
    tmp->count_anim = 0;
  return (SUCCESS);
}

int                     anim_moves(t_graphic *c, t_client *tmp)
{
  int                   count;

  count = 0;
  while (count != NB_DIRECTIONS && tmp->direction
         != direction[count].direction)
    count++;
  c->display.sprite.y = direction[count].sprite_pos;
  c->display.sprite.x = SPRITE_SIZE * tmp->count_anim;
  c->display.pos.x = (tmp->last_coords[0] - c->display.cursor_x) * SPRITE_SIZE
    + direction[count].move_x * tmp->count_anim;
  c->display.pos.y = (tmp->last_coords[1] - c->display.cursor_y) * SPRITE_SIZE
    + direction[count].move_y * tmp->count_anim;
  if (SDL_BlitSurface(c->display.list[MOVES],
                      &c->display.sprite, c->display.list[WINDOW],
                      &c->display.pos) == -1)
    return (my_error(SDL_GetError(), FAILURE));
  tmp->count_anim++;
  if (tmp->count_anim > NB_SPRITES_ANIM - 1)
    tmp->anim = UNDEFINED;
  return (SUCCESS);
}
