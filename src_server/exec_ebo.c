/*
** exec_ebo.c for exec_ebo.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu Jun 12 16:06:23 2014 LOEB Thomas
** Last update Thu Jun 12 16:06:30 2014 LOEB Thomas
*/

#include		"server.h"

bool			exec_ebo(t_server *s)
{
  if (write_graphic(s) == FAILURE)
    return (FALSE);
  strcpy(s->graphic->send, (EBO" #"));
  nbr_to_str(s->tmp_teams->tmp_eggs->id,
             s->graphic->send + strlen(s->graphic->send), "\n");
  return (TRUE);
}
