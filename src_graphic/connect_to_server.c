/*
** connect_to_server.c for connect_to_server.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 13:03:52 2014 LOEB Thomas
** Last update Thu Jun 12 17:51:00 2014 LOEB Thomas
*/

#include		"graphic.h"

int			connect_to_server(t_graphic *c)
{
  c->server.sin_family = AF_INET;
  c->server.sin_port = htons(c->port);
  if (((c->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1 &&
       my_perror(SYSCALL("socket"), FAILURE) == FAILURE) ||
      (inet_aton(c->ip, IN_ADDR(&c->server.sin_addr.s_addr)) == -1 &&
       my_perror(SYSCALL("inet_aton"), FAILURE) == FAILURE) ||
      (connect(c->socket, C_SOCKADDR(&c->server), sizeof(c->server)) == -1 &&
       my_perror(SYSCALL("connect"), FAILURE) == FAILURE))
    return (close_graphic(c, FAILURE));
  printf("Graphic trying to connect\n");
  return (check_fds(c));
}
