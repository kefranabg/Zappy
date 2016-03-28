/*
** close_server.c for close_server.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 17:44:22 2014 LOEB Thomas
** Last update Fri May 30 15:02:22 2014 LOEB Thomas
*/

#include		"server.h"

int			close_server(t_server *s, int retVal)
{
  if (stop(STOP_VALUE) < STOP_VALUE)
    fprintf(stderr, "ERROR: server did not quit correctly (%d)\n",
            stop(STOP_VALUE));
  else if (stop(STOP_VALUE) > STOP_VALUE)
    fprintf(stderr, "SUCCESS: server quitted correctly (%d)\n",
            stop(STOP_VALUE));
  if (s->map != NULL)
    free(s->map);
  if (s->p.cmd != NULL)
    free_words(&s->p);
  free_clients(s);
  free_teams(s);
  if (s->socket != -1 && close(s->socket) == -1)
    my_perror(SYSCALL("close"), CONTINUE);
  return (retVal);
}
