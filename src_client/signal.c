/*
** signal.c for signal.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 16:02:45 2014 LOEB Thomas
** Last update Wed May  7 18:10:28 2014 LOEB Thomas
*/

#include		"client.h"

static void		my_signal_handler(int sig)
{
  signal(SIGINT, &my_signal_handler);
  signal(SIGTERM, &my_signal_handler);
  signal(SIGPIPE, &my_signal_handler);
  if (sig == SIGINT || sig == SIGTERM)
    my_error(BAD_WAY_QUIT, CONTINUE);
  else if (sig == SIGPIPE)
    stop(STOP_BRK_PIPE);
}

void			my_signal(void)
{
  signal(SIGINT, &my_signal_handler);
  signal(SIGTERM, &my_signal_handler);
  signal(SIGPIPE, &my_signal_handler);
}
