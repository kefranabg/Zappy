/*
** close_client.c for close_client.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 13:22:05 2014 LOEB Thomas
** Last update Fri Jul 11 19:18:20 2014 Baptiste Acca
*/

#include		"client.h"

int			close_client(t_client *c, int retVal)
{
  if (stop(STOP_VALUE) < STOP_VALUE)
    fprintf(stderr, "ERROR: client did not quit correctly (%d)\n",
	    stop(STOP_VALUE));
  else if (stop(STOP_VALUE) > STOP_VALUE)
    fprintf(stderr, "SUCCESS: client quitted correctly (%d)\n",
	    stop(STOP_VALUE));
  if (c->p.cmd != NULL)
    free_words(&c->p);
  if (c->l.line != NULL)
    free(c->l.line);
  if (c->socket != -1 && close(c->socket) == -1)
    my_perror(SYSCALL("close"), CONTINUE);
  if (raw_mode_exit(c) == FAILURE)
    return (retVal);
  return (retVal);
}
