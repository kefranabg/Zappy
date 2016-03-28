/*
** action.c for action.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Fri May  9 17:29:16 2014 LOEB Thomas
** Last update Thu Jun 26 17:39:54 2014 LOEB Thomas
*/

#include		"server.h"

t_action		action_life(double delay)
{
  t_action		ret;

  ret.cmd = "life";
  ret.usec = (FOOD_TIME * SEC_TO_USEC) / delay;
  ret.id = CLIENT_ACTIONS + 1;
  return (ret);
}

t_action		action_egg(double delay)
{
  t_action		ret;

  ret.cmd = "egg";
  ret.usec = (EGG_TIME * SEC_TO_USEC) / delay;
  ret.id = CLIENT_ACTIONS + 2;
  return (ret);
}

static t_action		g_actions[CLIENT_ACTIONS] =
  {
    {FORWARD, "", 7, 0, 1, NULL, &exec_forward},
    {RIGHT, "", 7, 1, 1, NULL, &exec_right},
    {LEFT, "", 7, 2, 1, NULL, &exec_left},
    {LOOK, "", 7, 3, 1, NULL, &exec_look},
    {INVENTORY, "", 1, 4, 1, NULL, &exec_inventory},
    {TAKE, "", 7, 5, 2, &check_take, &exec_take},
    {PUT, "", 7, 6, 2, &check_put, &exec_put},
    {PUSH, "", 7, 7, 1, NULL, &exec_push},
    {BROADCAST, "", 7, 8, 2, NULL, &exec_broadcast},
    {ELEVATION, "", 300, 9, 1, &check_elevation, &exec_elevation},
    {FORK, "", 42, 10, 1, &check_fork, &exec_fork},
    {CONNECT_NBR, "", 0, 11, 1, NULL, &exec_connect_nbr}
  };

t_action		action_create(t_server *s)
{
  unsigned int		i;
  t_action		ret;

  ret.cmd = NULL;
  ret.id = -1;
  if (s->p.cmd[0] == NULL)
    return (ret);
  i = 0;
  while (i < CLIENT_ACTIONS && strcmp(s->p.cmd[0], g_actions[i].cmd) != 0)
    ++i;
  if (i < CLIENT_ACTIONS && s->p.len == g_actions[i].nb_param &&
      (g_actions[i].check == NULL || (*g_actions[i].check)(s) == TRUE))
    {
      ret.id = i;
      ret.cmd = g_actions[i].cmd;
      if (s->p.len == 2)
	strcpy(ret.param, s->p.cmd[1]);
      ret.usec = g_actions[i].usec * SEC_TO_USEC / s->delay;
      ret.exec = g_actions[i].exec;
    }
  return (ret);
}

static t_action		g_graphic[GRAPHIC_ACTIONS] =
  {
    {MSZ, "", 0, 0, 1, NULL, &exec_msz},
    {BCT, "", 0, 1, 3, &check_bct, &exec_bct_manual},
    {MCT, "", 0, 2, 1, NULL, &exec_mct},
    {TNA, "", 0, 3, 1, NULL, &exec_tna},
    {PPO, "", 0, 4, 2, &check_no_player, &exec_ppo_manual},
    {PLV, "", 0, 5, 2, &check_no_player, &exec_plv_manual},
    {PIN, "", 0, 6, 2, &check_no_player, &exec_pin_manual},
    {SGT, "", 0, 7, 1, NULL, &exec_sgt},
    {SST, "", 0, 8, 2, &check_sst, &exec_sst}
  };

void			action_graphic(t_server *s)
{
  unsigned int		i;

  if (s->p.cmd[0] == NULL)
    exec_suc(s);
  else
    {
      i = 0;
      while (i < GRAPHIC_ACTIONS && strcmp(s->p.cmd[0], g_graphic[i].cmd) != 0)
	++i;
      if (i == GRAPHIC_ACTIONS)
	exec_suc(s);
      else if (s->p.len != g_graphic[i].nb_param ||
	       (g_graphic[i].check != NULL && (*g_graphic[i].check)(s) == FALSE))
	exec_sbp(s);
      else
	{
	  g_graphic[i].exec(s);
	  printf("Graphic executed '%s'\n", s->p.cmd[0]);
	}
    }
}
