/*
** client.h for client.h in /home/chauch_a/rendu/PSU_2013_zappy
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Fri Jun 27 10:20:32 2014 CHAUCHET Alan
** Last update Fri Jul 11 19:52:36 2014 Baptiste Acca
*/

#ifndef			CLIENT_H_
# define		CLIENT_H_

# include		<termios.h>
# include		"common.h"

# define		CLIENT_USAGE		("USAGE: ./client "	\
						 "[-n NAME("STD_TEAM1")] " \
						 "[-p PORT("STD_PORT")] " \
						 "[-h IP("STD_IP")]")

# define		CLIENT_NB_OPT		3

# define		EXPULSE_MSG		"deplacement:"
# define		BROADCAST_MSG		"message"

# define		WELCOME_MANUAL		("### Welcome to the manual" \
						 " version of the Zappy" \
						 " client ###")
# define		MANUAL_AV_CMDS		"Available Commands :"
# define		MANUAL_FORWARD_CMD	"UP ARROW : Go forward"
# define		MANUAL_LEFT_CMD		"LEFT ARROW : Turn left"
# define		MANUAL_RIGHT_CMD	"RIGHT ARROW : Turn right"
# define		MANUAL_ENTER_CMD	"SPACE BAR : Start elevation"
# define		MANUAL_LOOK_CMD		"V : Look"
# define		M_TAKE			"E : Take"
# define		M_PUT			"R : Drop"
# define		M_STONES_LINEMATE	"1 : linemate"
# define		M_STONES_DERAUMERE	"2 : deraumere"
# define		M_STONES_SIBUR		"3 : sibur"
# define		M_STONES_MENDIANE	"4 : mendiane"
# define		M_STONES_PHIRAS		"5 : phiras"
# define		M_STONES_THYSTAME	"6 : thystame"
# define		M_FOOD			"7 : food"
# define		MANUAL_INVENTORY	"I : Inventory"
# define		MANUAL_PUSH		"P : Push players"
# define		MANUAL_BROADCAST	"ENTER : Broadcast text"
# define		MANUAL_FORK		"F : Fork player"
# define		MANUAL_CONNECT_NBR	"N : Connect_nbr"
# define		M_TAKE_LISTITEMS	("1: Linemate - 2: Deraumere -" \
						 "3: Sibur - 4: Mendiane - " \
						 "5: Phiras - 6: Thystame - " \
						 "7: Food")

# define		M_PUT_LISTITEMS		("1: Linemate - 2: Deraumere -" \
						 "3: Sibur - 4: Mendiane - " \
						 "5: Phiras - 6: Thystame")

# define		NB_TEXT_MANUAL		21

# define		NB_CMD			12

typedef struct		s_list_action
{
  char			*cmd;
  char			*param;
  int			nb_time;
  struct s_list_action	*next;
}			t_list_action;

typedef struct		s_keycodes
{
  char			*cmd;
  char			*param;
  int			keycodes[3];
}			t_keycodes;

typedef struct		s_items
{
  char			*name;
  int			keycode;
}			t_items;

typedef struct		s_client
{
  bool			connected;
  bool			manual;
  char			*name;
  int			port;
  char			*ip;
  int			socket;
  struct sockaddr_in    server;
  t_line		l;
  int			remaining;
  unsigned int		x;
  unsigned int		y;
  t_buffer		b;
  t_parse		p;
  unsigned int		level;
  t_list_action		*list_action;
  struct termios	termcaps;
}			t_client;

int			get_params(t_client *, char **, int *, int);
int			connect_to_server(t_client *);
int			close_client(t_client *, int);
int			check_fds(t_client *);
void			my_signal(void);
int			check_cmds(t_client *);
int			send_cmd(t_client *, char *, char *);
int			exec_action(t_client *);
void			del_list_action(t_client *);
void			pop_front_action(t_client *);
int			add_action(t_client *, char *, char *, int);
int			raw_mode_init(t_client *);
int			raw_mode_exit(t_client *);
int			manual_action(t_client *);
void			aff_cmds(void);

#endif			/* CLIENT_H_ */
