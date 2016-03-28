/*
** common.h for common.h in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon May  5 16:06:29 2014 LOEB Thomas
** Last update Thu Jul 10 17:28:36 2014 CHAUCHET Alan
*/

#ifndef			COMMON_H_
# define		COMMON_H_

# include		<stdlib.h>
# include		<unistd.h>
# include		<string.h>
# include		<time.h>
# include		"error.h"

# include		<sys/types.h>
# include		<sys/socket.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>

# include		<sys/select.h>
# include		<sys/time.h>

# include		<signal.h>

# define		FAILURE		-1
# define		SUCCESS		0
# define		CONTINUE	1

# define		STD_TEAM1	"TEAM_GROS_PORCS"
# define		STD_TEAM2	"EUL_TEAM"
# define		STD_PORT	"6666"
# define		STD_IP		"127.0.0.1"

# define		STD_LEVEL	1
# define		MAX_LEVEL	8

# define		WAITING_LIST	1000000

# define		C_SOCKADDR(x)	(const struct sockaddr *)(x)
# define		SOCKADDR(x)	(struct sockaddr *)(x)
# define		IN_ADDR(x)	(struct in_addr *)(x)

# define		NB_STONE	6

typedef struct		s_box
{
  unsigned char		stone[NB_STONE];
  unsigned char		food;
  int			stone_pos[NB_STONE][2];
  int			food_pos[2];
}			t_box;

typedef enum		e_direction
  {
    D_TOP		= 0,
    D_RIGHT		= 1,
    D_BOTTOM		= 2,
    D_LEFT		= 3
  }			e_direction;

typedef enum		e_bool
  {
    FALSE		= 0,
    TRUE		= 1
  }			bool;

typedef struct		s_opt
{
  char			*s;
  unsigned char		occurrence;
  unsigned char		occurrence_max;
}			t_opt;

typedef struct		s_line
{
  char			*line;
  size_t		len;
  unsigned int		len_line;
  FILE			*stream;
  int			retGetline;
}			t_line;

typedef struct		s_select
{
  unsigned char		flag;
  int			maxfd;
  fd_set		rdfds;
  fd_set		wrfds;
  int			retSelect;
  struct timeval	tv;
  struct timeval	save;
}			t_select;

# define		BUFF_LEN	4096

typedef struct		s_buffer
{
  char			circular[BUFF_LEN];
  char			tmp[BUFF_LEN];
  unsigned int		idx;
}			t_buffer;

# define		ARG_LEN		512

typedef struct		s_parse
{
  char			**cmd;
  unsigned int		len;
  char			line[BUFF_LEN];
}			t_parse;

typedef enum		e_mode
  {
    R			= 0,
    W			= 1,
    RW			= 2
  }			e_mode;

# include		"protocol.h"

int			my_select(t_select *, e_mode);
int			stop(int);
int			my_getline(t_line *);
int			rw(int, void *, size_t, e_mode);
void			buffer_to_circular(t_buffer *);
int			pos_cmd(t_buffer *);
void			get_cmd(t_buffer *, int);
int			parse_cmd(t_parse *, char *);
void			free_words(t_parse *);
int			nbrlen(int);
int			nbr_to_str(int, char *, char *);
int			getnbr(char *);
int			nb_space(char *);
char			**str_to_wordtab(char *, char *);
void			free_wordtab(char **);
unsigned int		count_high(unsigned int, unsigned int);
unsigned int		pos_up(unsigned int);
unsigned int		pos_down(unsigned int);

#endif			/* COMMON_H_ */
