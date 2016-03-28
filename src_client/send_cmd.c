/*
** send_cmd.c for send_cmd.c in /home/chauch_a/rendu/PSU_2013_zappy
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Jun 25 15:08:07 2014 CHAUCHET Alan
** Last update Fri Jul 11 15:36:47 2014 CHAUCHET Alan
*/

#include		"pointer_to_func.h"

int			send_with_param(t_client *c, char *cmd, char *param)
{
  char			*msg;

  if (param == NULL)
    return (2);
  if ((msg = malloc(strlen(cmd) + strlen(param) + 3)) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  memset(msg, '\0', strlen(cmd) + strlen(param) + 3);
  strcpy(msg, cmd);
  msg[strlen(cmd)] = ' ';
  strcpy(&(msg[strlen(cmd) + 1]), param);
  msg[strlen(msg)] = '\n';
  if (rw(c->socket, msg, strlen(msg), W) == FAILURE)
    {
      free(msg);
      return (FAILURE);
    }
  free(msg);
  return (SUCCESS);
}

int			send_no_param(t_client *c, char *cmd, char *param)
{
  (void)param;
  if (rw(c->socket, cmd, strlen(cmd), W) == FAILURE)
    return (FAILURE);
  return (rw(c->socket, "\n", 1, W));
}

static t_send_cmd	g_send_cmd[NB_CMD] =
  {
    {FORWARD, &send_no_param},
    {RIGHT, &send_no_param},
    {LEFT, &send_no_param},
    {LOOK, &send_no_param},
    {INVENTORY, &send_no_param},
    {PUSH, &send_no_param},
    {ELEVATION, &send_no_param},
    {FORK, &send_no_param},
    {CONNECT_NBR, &send_no_param},
    {TAKE, &send_with_param},
    {PUT, &send_with_param},
    {BROADCAST, &send_with_param}
  };

int			send_cmd(t_client *c, char *cmd, char *param)
{
  unsigned int		count;

  printf("client : (%s) (%s)\n", cmd, param);
  count = -1;
  if (cmd == NULL)
    return (2);
  while (++count < NB_CMD && strcmp(g_send_cmd[count].cmd, cmd))
    ;
  if (count >= NB_CMD)
    return (2);
  if ((g_send_cmd[count].func)(c, cmd, param) == SUCCESS)
      return (SUCCESS);
  return (FAILURE);
}
