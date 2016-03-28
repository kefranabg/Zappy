/*
** connect.c for connect.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon Jun  9 11:21:27 2014 LOEB Thomas
** Last update Wed Jun 25 14:43:49 2014 LOEB Thomas
*/

#include		"server.h"

static void		send_graphic(t_server *s)
{
  t_client		*tmp;

  tmp = s->tmp_clients;
  s->tmp_clients = s->clients;
  while (s->tmp_clients != NULL)
    {
      exec_pnw(s);
      s->tmp_clients = s->tmp_clients->next;
    }
  s->tmp_clients = tmp;
  s->tmp_teams = s->teams;
  while (s->tmp_teams != NULL)
    {
      s->tmp_teams->tmp_eggs = s->tmp_teams->eggs;
      while (s->tmp_teams->tmp_eggs != NULL)
	{
	  exec_enw_manual(s, s->tmp_teams->tmp_eggs);
	  s->tmp_teams->tmp_eggs = s->tmp_teams->tmp_eggs->next;
	}
      s->tmp_teams = s->tmp_teams->next;
    }
}

int			connect_graphic(t_server *s)
{
  if (s->graphic != NULL)
    {
      del_client(s, TRUE);
      return (SUCCESS);
    }
  s->graphic = s->tmp_clients;
  if (s->tmp_clients->prev != NULL)
    s->tmp_clients->prev->next = s->tmp_clients->next;
  if (s->tmp_clients->next != NULL)
    s->tmp_clients->next->prev = s->tmp_clients->prev;
  if (s->tmp_clients->prev == NULL)
    s->clients = s->clients->next;
  s->graphic->next = NULL;
  s->graphic->prev = NULL;
  exec_msz(s);
  exec_sgt(s);
  exec_mct(s);
  exec_tna(s);
  send_graphic(s);
  s->tmp_clients = s->tmp_clients->next;
  printf("Graphic connected\n");
  return (SUCCESS);
}
