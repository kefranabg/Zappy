/*
** pointer_to_func.h for pointer_to_func.h in /home/chauch_a/rendu/PSU_2013_zappy
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Mon Jul  7 10:32:58 2014 CHAUCHET Alan
** Last update Thu Jul 10 16:01:15 2014 CHAUCHET Alan
*/

#ifndef			POINTER_TO_FUNC_H_
# define		POINTER_TO_FUNC_H_

# include		"client.h"

typedef int		(*send_cmd_func)(t_client *, char *, char *);

typedef struct		s_send_cmd
{
  char			*cmd;
  send_cmd_func		func;
}			t_send_cmd;

typedef void		(*direction_move)(t_client *c, e_direction);

#endif
