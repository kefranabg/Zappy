/*
** server.h for server.h in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Tue May  6 11:13:26 2014 LOEB Thomas
** Last update Sat Jul 12 15:40:14 2014 abgral_f
*/

#ifndef			SERVER_H_
# define		SERVER_H_

# include		<time.h>
# include		"common.h"

# define		ABS(x)			(((x) < 0) ? -(x) : (x))

# define		STD_X			"30"
# define		STD_Y			"30"
# define		STD_NB			"10"
# define		STD_DELAY		"100"

# define		SERVER_USAGE		("USAGE: ./server "     \
						 "[-n NAME1("STD_TEAM1") NAME2("STD_TEAM2") ...] " \
						 "[-p PORT("STD_PORT")] " \
						 "[-x WIDTH("STD_X")] "	\
						 "[-y HEIGHT("STD_Y")] "\
						 "[-c NB_PER_TEAM("STD_NB")] "\
						 "[-t DELAY("STD_DELAY")]")
# define		SERVER_NB_OPT		6

# define		STD_LIFE		10
# define		FOOD_TIME		126

# define		EGG_TIME		600

# define		SEC_TO_USEC		1000000

# define		CLIENT_ACTIONS		12
# define		GRAPHIC_ACTIONS		9

typedef struct		s_egg
{
  unsigned int		id;
  unsigned int		id_client;
  unsigned int		life;
  t_action		action_life;
  t_action		action;
  bool			isThereAction;
  unsigned int		x;
  unsigned int		y;
  e_direction		direction;
  struct s_egg		*next;
  struct s_egg		*prev;
}			t_egg;

typedef struct		s_team
{
  int			nb_remaining;
  int			nb_egg_remaining;
  char			*name;
  t_egg			*eggs;
  t_egg			*tmp_eggs;
  struct s_team		*next;
  struct s_team		*prev;
}			t_team;

typedef struct		s_client
{
  unsigned int		id;
  bool			isConnected;
  int			isAscending;
  int			socket;
  t_team		*team;
  char			send[BUFF_LEN];
  unsigned int		life;
  t_action		action_life;
  t_action		action;
  bool			isThereAction;
  t_buffer		b;
  unsigned int		x;
  unsigned int		y;
  e_direction		direction;
  unsigned int		level;
  unsigned char		stone[NB_STONE];
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef struct		s_server
{
  t_box			*map;
  int			socket;
  struct sockaddr_in	server;
  t_team		*teams;
  t_team		*tmp_teams;
  t_client		*clients;
  t_client		*tmp_clients;
  int			port;
  int			x;
  int			y;
  int			nb_per_team;
  double		delay;
  t_parse		p;
  clock_t		time;
  t_client		*graphic;
}			t_server;

int			is_in_opts(char *);
int			get_params(t_server *, char **, int *, int);
int			add_team(t_server *, char *);
void			init_teams(t_server *);
void			free_teams(t_server *);
void			add_client(t_server *);
void			del_client(t_server *, bool);
void			free_clients(t_server *);
void			complete_client(t_server *);
void			add_egg(t_server *);
void			del_egg(t_server *);
void			free_eggs(t_server *);
void			take_last_egg(t_server *);
int			open_to_clients(t_server *);
int			close_server(t_server *, int);
void			my_signal(void);
int			check_fds(t_server *);
t_action		action_life(double);
t_action		action_egg(double);
t_action		action_create(t_server *);
int			write_on_fds(t_server *, t_select *);
int			read_from_fds(t_server *, t_select *);
int			check_cmds(t_server *);
int			write_nb_and_size(t_server *);
void			update_timers(t_server *, t_select *);
bool			check_take(t_server *);
bool			check_put(t_server *);
bool			check_elevation(t_server *);
bool			exec_forward(t_server *);
bool			exec_right(t_server *);
bool			exec_left(t_server *);
bool			exec_look(t_server *);
bool			exec_inventory(t_server *);
bool			exec_take(t_server *);
bool			exec_put(t_server *);
bool			exec_push(t_server *);
bool			exec_broadcast(t_server *);
bool			exec_elevation(t_server *);
bool			exec_fork(t_server *);
bool			exec_connect_nbr(t_server *);
int			create_map(t_server *);
bool			is_empty_box(t_server *, int, int);
int			get_orientation(t_server *, t_client *, t_client *);
void			refill_map(t_server *);
int			connect_graphic(t_server *);
void			action_graphic(t_server *);
bool			check_bct(t_server *);
bool			check_no_player(t_server *);
bool			check_sst(t_server *);
bool			exec_msz(t_server *);
bool			exec_bct_manual(t_server *);
bool			exec_bct(t_server *);
bool			exec_mct(t_server *);
bool			exec_tna(t_server *);
bool			exec_ppo_manual(t_server *);
bool			exec_ppo(t_server *);
bool			exec_plv_manual(t_server *);
bool			exec_plv(t_server *);
bool			exec_pin_manual(t_server *);
bool			exec_pin(t_server *);
bool			exec_sgt(t_server *);
bool			exec_sst(t_server *);
void			exec_bct_fill(t_server *, int, int);
bool			exec_pnw(t_server *);
int			write_graphic(t_server *);
bool			exec_pex(t_server *);
bool			exec_pbc(t_server *);
bool			exec_pic(t_server *);
bool			exec_pie(t_server *, char);
bool			exec_pfk(t_server *);
bool			exec_pdr(t_server *, char);
bool			exec_pgt(t_server *, char);
bool			exec_pdi(t_server *);
bool			check_fork(t_server *);
bool			exec_enw(t_server *);
bool			exec_enw_manual(t_server *, t_egg *);
bool			exec_eht(t_server *);
bool			exec_ebo(t_server *);
bool			exec_edi(t_server *);
bool			exec_seg(t_server *);
bool			exec_suc(t_server *);
bool			exec_sbp(t_server *);
bool			check_elevation_send(t_server *);

#endif			/* SERVER_H_ */
