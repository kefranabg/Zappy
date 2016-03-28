/*
** manual_action.c for manual_action.c in /home/acca_b/rendu/PSU_2013_zappy
**
** Made by Baptiste Acca
** Login   <acca_b@epitech.net>
**
** Started on  Thu Jul 10 15:57:07 2014 Baptiste Acca
** Last update Fri Jul 11 20:18:22 2014 Baptiste Acca
*/

#include		"client.h"

static t_keycodes	g_cmd[NB_CMD] =
  {
    {FORWARD, NULL, {27, 91, 65} },
    {RIGHT, NULL, {27, 91, 67} },
    {LEFT, NULL, {27, 91, 68} },
    {LOOK, NULL, {118, 0, 0} },
    {INVENTORY, NULL, {105, 0, 0} },
    {TAKE, NULL, {101, 0, 0} },
    {PUT, NULL, {114, 0, 0} },
    {PUSH, NULL, {112, 0, 0} },
    {BROADCAST, NULL, {10, 0, 0} },
    {ELEVATION, NULL, {32, 0, 0} },
    {FORK, NULL, {102, 0, 0} },
    {CONNECT_NBR, NULL, {110, 0, 0} }
  };

static t_items		g_items[NB_STONE + 1] =
  {
    {LINEMATE, 49},
    {DERAUMERE, 50},
    {SIBUR, 51},
    {MENDIANE, 52},
    {PHIRAS, 53},
    {THYSTAME, 54},
    {FOOD, 55}
  };

static void		reinit_tab(char *buffer)
{
  unsigned int		i;

  i = 0;
  while (i < NB_CMD)
    {
      g_cmd[i].param = NULL;
      if (i > 2)
	{
	  g_cmd[i].keycodes[1] = buffer[1];
	  g_cmd[i].keycodes[2] = buffer[2];
	}
      ++i;
    }
}

static int		manual_put_cmd(t_client *c, unsigned int cmd_nb)
{
  char			buffer[2];
  unsigned int		i;

  printf("Which item do you want to drop ?\n%s\n", M_PUT_LISTITEMS);
  if (memset(buffer, 0, 2) == NULL)
    return (my_error(SYSCALL("memset"), FAILURE));
  if ((read(0, buffer, 1)) == -1)
    return (my_error(READ_FAIL, FAILURE));
  i = 0;
  while (i < NB_STONE && buffer[0] != g_items[i].keycode)
    ++i;
  if (i == NB_STONE)
    return (SUCCESS);
  add_action(c, g_cmd[cmd_nb].cmd, g_items[i].name, 1);
  return (SUCCESS);
}

static int		manual_take_cmd(t_client *c, unsigned int cmd_nb)
{
  char			buffer[2];
  unsigned int		i;

  printf("Which item do you want to take ?\n%s\n", M_TAKE_LISTITEMS);
  if (memset(buffer, 0, 2) == NULL)
    return (my_error(SYSCALL("memset"), FAILURE));
  if ((read(0, buffer, 1)) == -1)
    return (my_error(READ_FAIL, FAILURE));
  i = 0;
  while (i < (NB_STONE + 1) && buffer[0] != g_items[i].keycode)
    ++i;
  if (i == NB_STONE + 1)
    return (SUCCESS);
  add_action(c, g_cmd[cmd_nb].cmd, g_items[i].name, 1);
  return (SUCCESS);
}

static int		manual_broadcast_cmd(t_client *c, unsigned int cmd_nb)
{
  char			buffer[4096];

  printf("What message do you want to broadcast ?\n");
  c->termcaps.c_lflag |= ICANON;
  c->termcaps.c_lflag |= ECHO;
  if (tcsetattr(0, 0, &c->termcaps) == -1)
    return (my_error(TCSETATTR_FAIL, FAILURE));
  if (memset(buffer, 0, 4096) == NULL)
    return (my_error(SYSCALL("memset"), FAILURE));
  if ((read(0, buffer, 4095)) == -1)
    return (my_error(READ_FAIL, FAILURE));
  buffer[strlen(buffer) - 1] = '\0';
  c->termcaps.c_lflag &= ~ICANON;
  c->termcaps.c_lflag &= ~ECHO;
  if (tcsetattr(0, 0, &c->termcaps) == -1)
    return (my_error(TCSETATTR_FAIL, FAILURE));
  add_action(c, g_cmd[cmd_nb].cmd, buffer, 1);
  return (SUCCESS);
}

int			manual_action(t_client *c)
{
  char			buffer[4];
  unsigned int		i;

  if (memset(buffer, 0, 4) == NULL)
    return (my_error(SYSCALL("memset"), FAILURE));
  if ((read(0, buffer, 3)) <= 0)
    return (my_error(READ_FAIL, FAILURE));
  reinit_tab(buffer);
  i = 0;
  while (i < NB_CMD && ((buffer[0] != g_cmd[i].keycodes[0]) ||
			(buffer[1] != g_cmd[i].keycodes[1]) ||
			(buffer[2] != g_cmd[i].keycodes[2])))
    ++i;
  if (i == NB_CMD)
    {
      aff_cmds();
      return (SUCCESS);
    }
  if (strcmp(g_cmd[i].cmd, TAKE) == 0)
    return (manual_take_cmd(c, i));
  if (strcmp(g_cmd[i].cmd, PUT) == 0)
    return (manual_put_cmd(c, i));
  if (strcmp(g_cmd[i].cmd, BROADCAST) == 0)
    return (manual_broadcast_cmd(c, i));
  return (add_action(c, g_cmd[i].cmd, g_cmd[i].param, 1));
}
