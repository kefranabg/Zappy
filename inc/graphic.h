/*
** graphic.h for graphic.h in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon May  5 15:58:59 2014 LOEB Thomas
** Last update Sun Jul 13 11:29:58 2014 abgral_f
*/

#ifndef			GRAPHIC_H_
# define		GRAPHIC_H_

# include		<SDL/SDL.h>
# include		<SDL/SDL_ttf.h>
# include		"common.h"

# define		GRAPHIC_USAGE		("USAGE: ./graphic "	\
						 "[-p PORT("STD_PORT")] " \
						 "[-h IP("STD_IP")]")

# define		BUFF			256

# define		GRAPHIC_NB_OPT		2

# define		WIN_X			1100
# define		WIN_Y			750
# define		MAP_X			720

# define		SPRITE_SIZE		30
# define		WIDTH_FOOD		8
# define		HEIGHT_FOOD		8
# define		WIDTH_STONE		5
# define		HEIGHT_STONE		11
# define		MARGE_HOR		12
# define		MARGE_VER		9
# define		MARGE_GUI_ITEMS_X	120
# define		MARGE_GUI_ITEMS_Y	150
# define		MARGE_GUI		40
# define		GUI_LIST_MAX		7

# define		SURFACE_NB		11
# define		NB_DIRECTIONS		4
# define		NB_SPRITES_ANIM		10
# define		NB_ANIMS		5

typedef enum		e_sprites
  {
    WINDOW		= 0,
    MAP			= 1,
    LINK		= 2,
    ITEMS		= 3,
    EGG			= 4,
    MOVES		= 5,
    INCANT		= 6,
    KIK			= 7,
    DROP		= 8,
    LAY			= 9,
    GUI			= 10,
    UNDEFINED		= 11
  }			e_sprites;

typedef struct		s_team
{
  char			*name;
  struct s_team		*next;
  struct s_team		*prev;
}			t_team;

typedef struct		s_egg
{
  unsigned int		id;
  unsigned int		x;
  unsigned int		y;
  bool			isHatched;
  t_team		*team;
  struct s_egg		*next;
  struct s_egg		*prev;
}			t_egg;

typedef struct		s_client
{
  t_box			inventory;
  t_team		*team;
  unsigned int		id;
  unsigned int		x;
  unsigned int		y;
  unsigned int		lvl;
  e_direction		direction;
  unsigned int		level;
  int                   isAscending;
  e_sprites		anim;
  unsigned int		last_coords[2];
  int			count_anim;
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef struct		s_case
{
  t_box			b;
  bool			sprite_one;
  bool			isUpdate;
}			t_case;

typedef struct		s_sdl
{
  SDL_Surface		**list;
  SDL_Rect              pos;
  SDL_Rect              sprite;
  SDL_Event		event;
  unsigned int	        cursor_x;
  unsigned int		cursor_y;
  unsigned int		coord_x;
  unsigned int		coord_y;
  TTF_Font		*font;
  SDL_Color             color;
  SDL_Surface           *text;
  char			str[BUFF];
}			t_sdl;

typedef struct		s_graphic
{
  bool			connected;
  int			port;
  char			*ip;
  int			socket;
  struct sockaddr_in    server;
  t_line		l;
  t_buffer		b;
  t_parse		p;
  unsigned int		x;
  unsigned int		y;
  double      		time;
  t_sdl			display;
  t_team                *teams;
  t_client		*client;
  t_case		*map;
  t_egg			*eggs;
}			t_graphic;

typedef struct          s_cmds
{
  char			*cmd;
  unsigned int 		nb_args;
  int                   (*ptr_func)(char **, t_graphic *);
}                       t_cmds;

typedef struct		s_anim
{
  e_sprites		anim;
  int                   (*ptr_func)(t_graphic *, t_client *);
}			t_anim;

typedef struct		s_direction
{
  e_direction		direction;
  int			sprite_pos;
  int			move_x;
  int			move_y;
}			t_direction;

typedef struct		s_stones
{
  int			stone;
  int			pos_x;
  int			pos_y;
}			t_stones;

int			get_params(t_graphic *, char **, int *, int);
int			connect_to_server(t_graphic *);
int			close_graphic(t_graphic *, int);
int			check_fds(t_graphic *);
void			my_signal(void);
int			check_cmds(t_graphic *);
int			msz_cmd(char **, t_graphic *);
int			bct_cmd(char **, t_graphic *);
int			tna_cmd(char **, t_graphic *);
int			ppo_cmd(char **, t_graphic *);
int			pnw_cmd(char **, t_graphic *);
int			plv_cmd(char **, t_graphic *);
int			pin_cmd(char **, t_graphic *);
int			pex_cmd(char **, t_graphic *);
int			pbc_cmd(char **, t_graphic *);
int			pic_cmd(char **, t_graphic *);
int			pie_cmd(char **, t_graphic *);
int			pfk_cmd(char **, t_graphic *);
int			pdr_cmd(char **, t_graphic *);
int			pgt_cmd(char **, t_graphic *);
int			pdi_cmd(char **, t_graphic *);
int			enw_cmd(char **, t_graphic *);
int			eht_cmd(char **, t_graphic *);
int			ebo_cmd(char **, t_graphic *);
int			edi_cmd(char **, t_graphic *);
int			sgt_cmd(char **, t_graphic *);
int			seg_cmd(char **, t_graphic *);
int			smg_cmd(char **, t_graphic *);
int			suc_cmd(char **, t_graphic *);
int			sbp_cmd(char **, t_graphic *);
int                     add_client(t_graphic *, char *, char *);
int                     add_egg(t_graphic *, char *, char *);
int                     check_player(unsigned int, t_graphic *);
int                     check_egg(unsigned int, t_graphic *);
int                     check_team(t_graphic *, char *);
int			del_client(t_graphic *, unsigned int);
int			del_egg(t_graphic *, unsigned int);
t_team			*get_team_by_name(t_graphic *, char *);
int			init_sdl(t_graphic *);
int			display_sdl(t_graphic *);
int		        is_map_update(t_graphic *);
void			free_teams(t_graphic *);
void			free_clients(t_graphic *);
void			free_eggs(t_graphic *);
void			free_surfaces(t_graphic *);
int			display_map(t_graphic *);
int			display_items(t_graphic *);
int			display_eggs(t_graphic *);
int			display_player(t_graphic *);
int			display_gui(t_graphic *);
int			anim_moves(t_graphic *, t_client *);
int			anim_incant(t_graphic *, t_client *);
int			anim_drop(t_graphic *, t_client *);
int			anim_lay(t_graphic *, t_client *);
int			anim_kik(t_graphic *, t_client *);
bool			is_anim(t_graphic *);
int			event(t_graphic *);
void			set_position(t_graphic *, t_client *);
int                     get_click_coord(t_graphic *);

#endif			/* GRAPHIC_H_ */
