/*
** exec_suc.c for exec_suc.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu Jun 12 16:46:26 2014 LOEB Thomas
** Last update Thu Jun 12 16:47:22 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_suc(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (SUC"\n"));
  return (TRUE);
}
