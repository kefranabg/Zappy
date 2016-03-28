/*
** stop.c for stop.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Wed May  7 14:54:20 2014 LOEB Thomas
** Last update Wed May  7 16:41:31 2014 LOEB Thomas
*/

#include		"common.h"

int			stop(int value)
{
  static int		stopValue = STOP_VALUE;

  if (value != STOP_VALUE)
    stopValue = value;
  if (value == STOP_RESET)
    stopValue = STOP_VALUE;
  return (stopValue);
}
