/*
** close_graphic.c for close_graphic.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 13:22:05 2014 LOEB Thomas
** Last update Thu Jul 10 22:35:28 2014 abgral_f
*/

#include		"graphic.h"

int			close_graphic(t_graphic *c, int retVal)
{
  if (stop(STOP_VALUE) < STOP_VALUE)
    fprintf(stderr, "ERROR: graphic did not quit correctly (%d)\n",
	    stop(STOP_VALUE));
  else if (stop(STOP_VALUE) > STOP_VALUE)
    fprintf(stderr, "SUCCESS: graphic quitted correctly (%d)\n",
	    stop(STOP_VALUE));
  if (c->p.cmd != NULL)
    free_words(&c->p);
  if (c->l.line != NULL)
    free(c->l.line);
  if (c->map != NULL)
    free(c->map);
  if (c->socket != -1 && close(c->socket) == -1)
    my_perror(SYSCALL("close"), CONTINUE);
  if (c->teams != NULL)
    free_teams(c);
  if (c->eggs != NULL)
    free_eggs(c);
  if (c->client != NULL)
    free_clients(c);
  if (c->display.list != NULL)
    free_surfaces(c);
  SDL_Quit();
  TTF_Quit();
  return (retVal);
}
