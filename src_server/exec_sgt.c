/*
** exec_sgt.c for exec_sgt.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 13:13:04 2014 LOEB Thomas
** Last update Tue Jun 10 14:17:45 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_sgt(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  sprintf(s->graphic->send, "sgt %f\n", s->delay);
  return (TRUE);
}
