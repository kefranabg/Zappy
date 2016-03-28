/*
** list_action.c for list_action.c in /home/chauch_a/rendu/PSU_2013_zappy
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Mon Jun 30 17:43:31 2014 CHAUCHET Alan
** Last update Fri Jul 11 13:20:00 2014 CHAUCHET Alan
*/

#include		"client.h"

int			add_action(t_client *c, char *cmd,
				   char *param, int nb_time)
{
  t_list_action		*new;
  t_list_action		*prov;

  printf("add action 1 : (%s) (%s) (%d)\n", cmd, param, nb_time);
  if ((new = malloc(sizeof(t_list_action))) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  new->cmd = strdup(cmd);
  new->param = (param == NULL) ? NULL : strdup(param);
  new->nb_time = nb_time;
  new->next = NULL;
  if (c->list_action == NULL)
    c->list_action = new;
  else
    {
      prov = c->list_action;
      while (prov->next != NULL)
	prov = prov->next;
      prov->next = new;
    }
  return (SUCCESS);
}

int			add_action_front(t_client *c, char *cmd,
					 char *param, int nb_time)
{
  t_list_action		*new;

  printf("add action 2 : (%s) (%s) (%d)\n", cmd, param, nb_time);
  if ((new = malloc(sizeof(t_list_action))) == NULL)
    return (my_perror(SYSCALL("malloc"), FAILURE));
  new->cmd = strdup(cmd);
  new->param = (param == NULL) ? NULL : strdup(param);
  new->nb_time = nb_time;
  new->next = NULL;
  if (c->list_action == NULL)
    c->list_action = new;
  else
    {
      new->next = c->list_action;
      c->list_action = new;
    }
  return (SUCCESS);

}

void			pop_front_action(t_client *c)
{
  t_list_action		*prov;

  if (c->list_action == NULL)
    return ;
  prov = c->list_action;
  c->list_action = c->list_action->next;
  free(prov->cmd);
  free(prov->param);
  free(prov);
}

void			del_list_action(t_client *c)
{
  while (c->list_action)
    pop_front_action(c);
}

int			exec_action(t_client *c)
{
  int			ret;

  if (!c->list_action)
    return (SUCCESS);
  if ((ret = send_cmd(c, c->list_action->cmd,
		      c->list_action->param)) == FAILURE)
    return (FAILURE);
  --c->list_action->nb_time;
  if (c->list_action->nb_time <= 0)
    pop_front_action(c);
  return (ret);
}
