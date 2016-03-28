/*
** signal.c for signal.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Thu May  8 12:49:53 2014 LOEB Thomas
** Last update Sat Jul 12 12:17:00 2014 abgral_f
*/

#include		"server.h"

static void		my_signal_handler(int sig)
{
  signal(SIGINT, &my_signal_handler);
  signal(SIGTERM, &my_signal_handler);
  signal(SIGPIPE, &my_signal_handler);
  if (sig == SIGINT || sig == SIGTERM)
    stop(STOP_QUIT);
  else if (sig == SIGPIPE)
    stop(STOP_BRK_PIPE);
}

void			my_signal(void)
{
  signal(SIGINT, &my_signal_handler);
  signal(SIGTERM, &my_signal_handler);
  signal(SIGPIPE, &my_signal_handler);
}
