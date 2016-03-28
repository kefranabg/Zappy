/*
** error.c for error.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon May  5 15:33:11 2014 LOEB Thomas
** Last update Mon May  5 15:55:59 2014 LOEB Thomas
*/

#include		"error.h"

int			my_perror(char *message, int retVal)
{
  perror(message);
  return (retVal);
}

int			my_error(char *message, int retVal)
{
  fprintf(stderr, "%s\n", message);
  return (retVal);
}
