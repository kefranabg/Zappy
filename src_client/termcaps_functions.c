/*
** termcaps_functions.c for termcaps_functions.c in /home/acca_b/rendu/PSU_2013_zappy
**
** Made by Baptiste Acca
** Login   <acca_b@epitech.net>
**
** Started on  Thu Jul 10 16:09:59 2014 Baptiste Acca
** Last update Fri Jul 11 17:58:47 2014 Baptiste Acca
*/

#include		"client.h"

static char *cmds_desc[NB_TEXT_MANUAL] =
  {
    WELCOME_MANUAL,
    MANUAL_AV_CMDS,
    MANUAL_FORWARD_CMD,
    MANUAL_LEFT_CMD,
    MANUAL_RIGHT_CMD,
    MANUAL_ENTER_CMD,
    MANUAL_LOOK_CMD,
    M_TAKE,
    M_PUT,
    M_STONES_LINEMATE,
    M_STONES_DERAUMERE,
    M_STONES_SIBUR,
    M_STONES_MENDIANE,
    M_STONES_PHIRAS,
    M_STONES_THYSTAME,
    M_FOOD,
    MANUAL_INVENTORY,
    MANUAL_PUSH,
    MANUAL_BROADCAST,
    MANUAL_FORK,
    MANUAL_CONNECT_NBR
  };

void			aff_cmds(void)
{
  unsigned int		i;

  i = 0;
  while (i < NB_TEXT_MANUAL)
    {
      printf("%s\n", cmds_desc[i]);
      ++i;
    }
}

int			raw_mode_init(t_client *c)
{
  if (tcgetattr(0, &c->termcaps) == -1)
    return (my_error(TCGETATTR_FAIL, FAILURE));
  c->termcaps.c_lflag &= ~ICANON;
  c->termcaps.c_lflag &= ~ECHO;
  c->termcaps.c_cc[VMIN] = 1;
  c->termcaps.c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, &c->termcaps) == -1)
    return (my_error(TCSETATTR_FAIL, FAILURE));
  aff_cmds();
  return (SUCCESS);
}

int			raw_mode_exit(t_client *c)
{
  c->termcaps.c_lflag |= ICANON;
  c->termcaps.c_lflag |= ECHO;
  c->termcaps.c_cc[VMIN] = 1;
  c->termcaps.c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, &c->termcaps) == -1)
    return (my_error(TCSETATTR_FAIL, FAILURE));
  return (SUCCESS);
}
