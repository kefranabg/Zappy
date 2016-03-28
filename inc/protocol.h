/*
** protocol.h for protocol.h in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon May 12 16:59:51 2014 LOEB Thomas
** Last update Tue Jun 17 11:59:18 2014 LOEB Thomas
*/

#ifndef			PROTOCOL_H_
# define		PROTOCOL_H_

# define		WELCOME_CLIENT(x)	("BIENVENUE"x)
# define		GRAPHIC_CLIENT(x)	("GRAPHIC"x)
# define		DEATH(x)		("mort"x)

# define		OK(x)			("ok"x)
# define		KO(x)			("ko"x)

# define		LEVEL_MAX		8

# define		ORIENTATION		"K"
# define		MOVE			("deplacement: "ORIENTATION"\n")
# define		MSG			("message "ORIENTATION",")

# define		ELEVATION_LAUNCH(x)	("elevation en cours"x)
# define		ELEVATION_DONE		("niveau actuel : "ORIENTATION"\n")

# define		FORWARD			"avance"
# define		RIGHT			"droite"
# define		LEFT			"gauche"
# define		LOOK			"voir"
# define		INVENTORY		"inventaire"
# define		TAKE			"prend"
# define		PUT			"pose"
# define		PUSH			"expulse"
# define		BROADCAST		"broadcast"
# define		ELEVATION		"incantation"
# define		FORK			"fork"
# define		CONNECT_NBR		"connect_nbr"

# define		S_FORWARD		(" "FORWARD)
# define		S_RIGHT			(" "RIGHT)
# define		S_LEFT			(" "LEFT)
# define		S_LOOK			(" "LOOK)
# define		S_INVENTORY		(" "INVENTORY)
# define		S_TAKE			(" "TAKE)
# define		S_PUT			(" "PUT)
# define		S_PUSH			(" "PUSH)
# define		S_BROADCAST		(" "BROADCAST)
# define		S_ELEVATION		(" "ELEVATION)
# define		S_FORK			(" "FORK)
# define		S_CONNECT_NBR		(" "CONNECT_NBR)

# define		PLAYER			"joueur"

# define		S_PLAYER		(" "PLAYER)

# define		LINEMATE		"linemate"
# define		DERAUMERE		"deraumêre"
# define		SIBUR			"sibur"
# define		MENDIANE		"mendiane"
# define		PHIRAS			"phiras"
# define		THYSTAME		"thystame"

# define		S_LINEMATE		(" "LINEMATE)
# define		S_DERAUMERE		(" "DERAUMERE)
# define		S_SIBUR			(" "SIBUR)
# define		S_MENDIANE		(" "MENDIANE)
# define		S_PHIRAS		(" "PHIRAS)
# define		S_THYSTAME		(" "THYSTAME)

# define		FOOD			"nourriture"

# define		S_FOOD			(" "FOOD)

# define		MSZ			"msz"
# define		BCT			"bct"
# define		MCT			"mct"
# define		TNA			"tna"
# define		PPO			"ppo"
# define		PLV			"plv"
# define		PIN			"pin"
# define		SGT			"sgt"
# define		SST			"sst"

# define		GRAPHIC_CMDS		26

# define		PNW			"pnw"
# define		PEX			"pex"
# define		PBC			"pbc"
# define		PIC			"pic"
# define		PIE			"pie"
# define		PFK			"pfk"
# define		PDR			"pdr"
# define		PGT			"pgt"
# define		PDI			"pdi"
# define		ENW			"enw"
# define		EHT			"eht"
# define		EBO			"ebo"
# define		EDI			"edi"
# define		SEG			"seg"
# define		SMG			"smg"
# define		SUC			"suc"
# define		SBP			"sbp"

# ifdef			SERVER_H_

typedef struct		s_server		t_server;

typedef struct		s_action
{
  char			*cmd;
  char			param[ARG_LEN];
  long			usec;
  unsigned int		id;
  unsigned int		nb_param;
  bool			(*check)(t_server *);
  bool			(*exec)(t_server *);
}			t_action;

# endif			/* SERVER_H_ */

#endif			/* PROTOCOL_H_ */
