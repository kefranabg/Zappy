/*
** list_client.c for list_client.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 17:52:19 2014 LOEB Thomas
** Last update Sat Jul 12 15:45:24 2014 abgral_f
*/

#include		"server.h"

void			add_client(t_server *s)
{
  t_client		*new;
  struct sockaddr_in	c;
  socklen_t		size_c;

  size_c = sizeof(struct sockaddr_in);
  if ((new = malloc(sizeof(t_client))) == NULL &&
       my_perror(SYSCALL("malloc"), CONTINUE) == CONTINUE)
    return ;
  memset(new, '\0', sizeof(t_client));
  if ((new->socket = accept(s->socket, SOCKADDR(&c), &size_c)) == -1 &&
      my_perror(SYSCALL("accept"), CONTINUE) == CONTINUE)
    return ;
  strcpy(new->send, WELCOME_CLIENT("\n"));
  new->life = STD_LIFE;
  new->action_life = action_life(s->delay);
  new->level = STD_LEVEL;
  new->isAscending = -1;
  new->next = s->clients;
  if (s->clients != NULL)
    {
      new->id = s->clients->id + 1;
      s->clients->prev = new;
    }
  s->clients = new;
  printf("Client attempting to connect\n");
}

void			del_client(t_server *s, bool closeClient)
{
  t_client		*tmp;

  exec_pdi(s);
  if (s->tmp_clients->team != NULL)
    ++s->tmp_clients->team->nb_remaining;
  if (s->tmp_clients->prev != NULL)
    s->tmp_clients->prev->next = s->tmp_clients->next;
  if (s->tmp_clients->next != NULL)
    s->tmp_clients->next->prev = s->tmp_clients->prev;
  if (s->tmp_clients->prev == NULL)
    {
      if (s->tmp_clients == s->graphic)
	s->graphic = NULL;
      else
	s->clients = s->clients->next;
    }
  tmp = s->tmp_clients;
  s->tmp_clients = s->tmp_clients->next;
  if (closeClient == TRUE && close(tmp->socket) == -1)
    my_perror(SYSCALL("close"), CONTINUE);
  free(tmp);
}

void			free_clients(t_server *s)
{
  s->tmp_clients = s->clients;
  while (s->tmp_clients != NULL)
    del_client(s, TRUE);
  s->clients = NULL;
}

void			complete_client(t_server *s)
{
  --s->tmp_teams->nb_remaining;
  s->tmp_clients->x = rand() % s->x;
  s->tmp_clients->y = rand() % s->y;
  s->tmp_clients->direction = rand() % 4;
  exec_pnw(s);
}
