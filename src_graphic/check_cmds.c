/*
** check_cmds.c for check_cmds.c in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue May 13 12:39:09 2014 LOEB Thomas
** Last update Thu Jul 10 23:43:35 2014 abgral_f
*/

#include		"graphic.h"

static t_cmds		cmp[24] =
  {
    {"msz", 3, &msz_cmd},
    {"bct", 10, &bct_cmd},
    {"tna", 2, &tna_cmd},
    {"pnw", 7, &pnw_cmd},
    {"ppo", 5, &ppo_cmd},
    {"plv", 3, &plv_cmd},
    {"pin", 11, &pin_cmd},
    {"pex", 2, &pex_cmd},
    {"pbc", 3, &pbc_cmd},
    {"pic", 0, &pic_cmd},
    {"pie", 4, &pie_cmd},
    {"pfk", 2, &pfk_cmd},
    {"pdr", 3, &pdr_cmd},
    {"pgt", 3, &pgt_cmd},
    {"pdi", 2, &pdi_cmd},
    {"enw", 5, &enw_cmd},
    {"eht", 2, &eht_cmd},
    {"ebo", 2, &ebo_cmd},
    {"edi", 2, &edi_cmd},
    {"sgt", 2, &sgt_cmd},
    {"seg", 2, &seg_cmd},
    {"smg", 2, &smg_cmd},
    {"suc", 1, &suc_cmd},
    {"sbp", 1, &sbp_cmd}
  };

static int		check_connection(t_graphic *c)
{
  if (strcmp(c->p.line, WELCOME_CLIENT("")) == 0)
    {
      if (rw(c->socket, GRAPHIC_CLIENT("\n"),
	     strlen(GRAPHIC_CLIENT("\n")), W) == FAILURE)
	return (FAILURE);
      c->connected = TRUE;
      printf("Graphic connected\n");
    }
  return (SUCCESS);
}

static int		compare_cmd(t_graphic *c)
{
  int			count;

  count = 0;
  while (count != 24)
    {
      if (c->p.cmd[0] != NULL)
	{
	  if (strcmp(c->p.cmd[0], cmp[count].cmd) == 0
	      && cmp[count].nb_args == c->p.len)
	    return ((*(cmp[count].ptr_func))(&(c->p.cmd[1]), c));
	  else if (strcmp(c->p.cmd[0], cmp[count].cmd) == 0
		   && cmp[count].nb_args == 0 && c->p.len > 4)
	    return ((*(cmp[count].ptr_func))(&(c->p.cmd[1]), c));
	  else if (strcmp(c->p.cmd[0], cmp[count].cmd) == 0
		   && cmp[count].nb_args != c->p.len)
	    return (my_error("Wrong parameter number", FAILURE));
	}
      count++;
    }
  return (my_error("Command undefined", FAILURE));
}

int			check_cmds(t_graphic *c)
{
  int			pos;

  if ((pos = pos_cmd(&c->b)) != -1)
    {
      get_cmd(&c->b, pos);
      if (parse_cmd(&c->p, c->b.tmp) == FAILURE)
	return (CONTINUE);
      printf("(%s)\n", c->p.line);
      if (c->connected == FALSE)
	return (check_connection(c));
      else
	compare_cmd(c);
    }
  return (SUCCESS);
}
