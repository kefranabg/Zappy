/*
** open_to_clients.c for open_to_clients.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 17:37:03 2014 LOEB Thomas
** Last update Mon Jun  2 17:16:56 2014 LOEB Thomas
*/

#include		"server.h"

int			open_to_clients(t_server *s)
{
  s->map = NULL;
  s->server.sin_family = AF_INET;
  s->server.sin_port = htons(s->port);
  s->server.sin_addr.s_addr = INADDR_ANY;
  if (((s->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1 &&
       my_perror(SYSCALL("socket"), FAILURE) == FAILURE) ||
      (bind(s->socket, C_SOCKADDR(&s->server), sizeof(s->server)) == -1 &&
       my_perror(SYSCALL("bind"), FAILURE) == FAILURE) ||
      (listen(s->socket, WAITING_LIST) == -1 &&
       my_perror(SYSCALL("listen"), FAILURE) == FAILURE))
    return (close_server(s, FAILURE));
  printf("Server online\n");
  if (create_map(s) == FAILURE)
    return (close_server(s, FAILURE));
  return (check_fds(s));
}
