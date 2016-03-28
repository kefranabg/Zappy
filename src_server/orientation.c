/*
** orientation.c for orientation.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Sun Jun  1 17:39:29 2014 LOEB Thomas
** Last update Tue Jun  3 19:20:55 2014 LOEB Thomas
*/

#include		<math.h>
#include		"server.h"

static int		g_terminal[8][2] =
  {
    {-23, 22},
    {22, 67},
    {67, 112},
    {112, 157},
    {157, 202},
    {202, 247},
    {247, 292},
    {292, 337}
  };

static int		calc_orientation(double angle)
{
  unsigned int		i;

  i = -1;
  while (++i < 8)
    if (angle >= g_terminal[i][0] && angle < g_terminal[i][1])
      return (i + 49);
  return (ORIENTATION[0]);
}

static int		g_angle[4] =
  {
    0,
    90,
    180,
    270
  };

int			get_orientation(t_server *s, t_client *c1,
					t_client *c2)
{
  int			x;
  int			y;
  double		angle;

  if (c2->x == c1->x && c2->y == c1->y)
    return ('0');
  x = c2->x - c1->x;
  if (ABS((int)c1->x + (s->x - (int)c2->x)) < ABS(x))
    x = -(c1->x + (s->x - c2->x));
  if (ABS((int)c2->x + (s->x - (int)c1->x)) < ABS(x))
    x = c2->x + (s->x - c1->x);
  y = c2->y - c1->y;
  if (ABS((int)c1->y + (s->y - (int)c2->y)) < ABS(y))
    y = -(c1->y + (s->y - c2->y));
  if (ABS((int)c2->y + (s->y - (int)c1->y)) < ABS(y))
    y = c2->y + (s->y - c1->y);
  angle = atan((double)(-x) / (double)(-y)) * 180 / M_PI;
  if (y > 0)
    angle += 180;
  else if (y <= 0 && x > 0)
    angle += 360;
  angle = (int)(angle + g_angle[c1->direction]) % 360;
  if (angle >= 337)
    angle -= 360;
  return (calc_orientation(angle));
}
