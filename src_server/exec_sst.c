/*
** exec_sst.c for exec_sst.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 13:13:04 2014 LOEB Thomas
** Last update Fri Jun 13 13:56:19 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_sst(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  s->delay = atof(s->p.cmd[1]);
  exec_sgt(s);
  return (TRUE);
}
