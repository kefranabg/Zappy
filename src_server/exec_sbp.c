/*
** exec_sbp.c for exec_sbp.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu Jun 12 16:47:34 2014 LOEB Thomas
** Last update Thu Jun 12 16:47:54 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_sbp(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (SBP"\n"));
  return (TRUE);
}
