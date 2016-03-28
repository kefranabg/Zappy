##
## Makefile for Makefile in /home/chauch_a/rendu/PSU_2013_zappy
## 
## Made by CHAUCHET Alan
## Login   <chauch_a@epitech.net>
## 
## Started on  Fri Jul 11 15:38:06 2014 CHAUCHET Alan
## Last update Fri Jul 11 23:34:36 2014 abgral_f
##

##		BSC

SRC		= src

INC		= inc

CFLAGS		= -Wall -Werror -Wextra -I $(INC)/

COMPILE		= cc

CLEAN		= rm -f

L_MATH		= -lm

##		COMMON

COMMON		= common

COMMON_FOLDER	= $(SRC)_$(COMMON)/

COMMON_SRC	= $(COMMON_FOLDER)error.c		\
		  $(COMMON_FOLDER)select.c		\
		  $(COMMON_FOLDER)getline.c		\
		  $(COMMON_FOLDER)stop.c		\
		  $(COMMON_FOLDER)rw.c			\
		  $(COMMON_FOLDER)circular.c		\
		  $(COMMON_FOLDER)parse.c		\
		  $(COMMON_FOLDER)nbr_str.c		\
		  $(COMMON_FOLDER)getnbr.c		\
		  $(COMMON_FOLDER)str_to_wordtab.c	\

##		CLIENT

CLIENT		= client

CLIENT_FOLDER	= $(SRC)_$(CLIENT)/

CLIENT_SRC	= $(CLIENT_FOLDER)client.c		\
		  $(CLIENT_FOLDER)get_params.c		\
		  $(CLIENT_FOLDER)connect_to_server.c	\
		  $(CLIENT_FOLDER)close_client.c	\
		  $(CLIENT_FOLDER)check_fds.c		\
		  $(CLIENT_FOLDER)signal.c		\
		  $(CLIENT_FOLDER)check_cmds.c		\
		  $(CLIENT_FOLDER)send_cmd.c		\
		  $(CLIENT_FOLDER)list_action.c		\
		  $(CLIENT_FOLDER)termcaps_functions.c	\
		  $(CLIENT_FOLDER)manual_action.c	\
		  $(COMMON_SRC)				\

CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)

##		GRAPHIC

GRAPHIC		= graphic

GRAPHIC_FOLDER	= $(SRC)_$(GRAPHIC)/

GRAPHIC_SRC	= $(GRAPHIC_FOLDER)graphic.c		\
		  $(GRAPHIC_FOLDER)get_params.c		\
		  $(GRAPHIC_FOLDER)connect_to_server.c	\
		  $(GRAPHIC_FOLDER)close_graphic.c	\
		  $(GRAPHIC_FOLDER)check_fds.c		\
		  $(GRAPHIC_FOLDER)signal.c		\
		  $(GRAPHIC_FOLDER)check_cmds.c		\
		  $(GRAPHIC_FOLDER)check_team.c		\
		  $(GRAPHIC_FOLDER)check_player.c	\
		  $(GRAPHIC_FOLDER)check_egg.c	\
		  $(GRAPHIC_FOLDER)list_clients.c	\
		  $(GRAPHIC_FOLDER)list_eggs.c		\
		  $(GRAPHIC_FOLDER)get_team_by_name.c	\
		  $(GRAPHIC_FOLDER)msz_cmd.c		\
		  $(GRAPHIC_FOLDER)bct_cmd.c		\
		  $(GRAPHIC_FOLDER)tna_cmd.c		\
		  $(GRAPHIC_FOLDER)pnw_cmd.c		\
		  $(GRAPHIC_FOLDER)ppo_cmd.c		\
		  $(GRAPHIC_FOLDER)plv_cmd.c		\
		  $(GRAPHIC_FOLDER)pin_cmd.c		\
		  $(GRAPHIC_FOLDER)pex_cmd.c		\
		  $(GRAPHIC_FOLDER)pbc_cmd.c		\
		  $(GRAPHIC_FOLDER)pic_cmd.c		\
		  $(GRAPHIC_FOLDER)pie_cmd.c		\
		  $(GRAPHIC_FOLDER)pfk_cmd.c		\
		  $(GRAPHIC_FOLDER)pdr_cmd.c		\
		  $(GRAPHIC_FOLDER)pgt_cmd.c		\
		  $(GRAPHIC_FOLDER)pdi_cmd.c		\
		  $(GRAPHIC_FOLDER)enw_cmd.c		\
		  $(GRAPHIC_FOLDER)eht_cmd.c		\
		  $(GRAPHIC_FOLDER)ebo_cmd.c		\
		  $(GRAPHIC_FOLDER)edi_cmd.c		\
		  $(GRAPHIC_FOLDER)sgt_cmd.c		\
		  $(GRAPHIC_FOLDER)seg_cmd.c		\
		  $(GRAPHIC_FOLDER)smg_cmd.c		\
		  $(GRAPHIC_FOLDER)suc_cmd.c		\
		  $(GRAPHIC_FOLDER)sbp_cmd.c		\
		  $(GRAPHIC_FOLDER)init_sdl.c		\
		  $(GRAPHIC_FOLDER)display_sdl.c	\
		  $(GRAPHIC_FOLDER)map_update.c		\
		  $(GRAPHIC_FOLDER)disp_map.c		\
		  $(GRAPHIC_FOLDER)disp_items.c		\
		  $(GRAPHIC_FOLDER)disp_eggs.c		\
		  $(GRAPHIC_FOLDER)disp_player.c	\
                  $(GRAPHIC_FOLDER)disp_gui.c           \
		  $(GRAPHIC_FOLDER)is_anim.c		\
		  $(GRAPHIC_FOLDER)event.c		\
		  $(GRAPHIC_FOLDER)anim.c		\
                  $(GRAPHIC_FOLDER)get_click_coord.c    \
		  $(COMMON_SRC)				\

GRAPHIC_OBJ	= $(GRAPHIC_SRC:.c=.o)

##		SERVER

SERVER		= server

SERVER_FOLDER	= $(SRC)_$(SERVER)/

SERVER_SRC	= $(SERVER_FOLDER)server.c		\
		  $(SERVER_FOLDER)get_params.c		\
		  $(SERVER_FOLDER)list_team.c		\
		  $(SERVER_FOLDER)list_client.c		\
		  $(SERVER_FOLDER)list_egg.c		\
		  $(SERVER_FOLDER)open_to_clients.c	\
		  $(SERVER_FOLDER)close_server.c	\
		  $(SERVER_FOLDER)signal.c		\
		  $(SERVER_FOLDER)check_fds.c		\
		  $(SERVER_FOLDER)action.c		\
		  $(SERVER_FOLDER)write.c		\
		  $(SERVER_FOLDER)read.c		\
		  $(SERVER_FOLDER)check_cmds.c		\
		  $(SERVER_FOLDER)update.c		\
		  $(SERVER_FOLDER)check_action.c	\
		  $(SERVER_FOLDER)exec_forward.c	\
		  $(SERVER_FOLDER)exec_right.c		\
		  $(SERVER_FOLDER)exec_left.c		\
		  $(SERVER_FOLDER)exec_look.c		\
		  $(SERVER_FOLDER)exec_inventory.c	\
		  $(SERVER_FOLDER)exec_take.c		\
		  $(SERVER_FOLDER)exec_put.c		\
		  $(SERVER_FOLDER)exec_push.c		\
		  $(SERVER_FOLDER)exec_broadcast.c	\
		  $(SERVER_FOLDER)exec_elevation.c	\
		  $(SERVER_FOLDER)exec_fork.c		\
		  $(SERVER_FOLDER)exec_connect_nbr.c	\
		  $(SERVER_FOLDER)map.c			\
		  $(SERVER_FOLDER)orientation.c		\
		  $(SERVER_FOLDER)connect.c		\
		  $(SERVER_FOLDER)check_graphic.c	\
		  $(SERVER_FOLDER)exec_msz.c		\
		  $(SERVER_FOLDER)exec_bct.c		\
		  $(SERVER_FOLDER)exec_mct.c		\
		  $(SERVER_FOLDER)exec_tna.c		\
		  $(SERVER_FOLDER)exec_ppo.c		\
		  $(SERVER_FOLDER)exec_plv.c		\
		  $(SERVER_FOLDER)exec_pin.c		\
		  $(SERVER_FOLDER)exec_sgt.c		\
		  $(SERVER_FOLDER)exec_sst.c		\
		  $(SERVER_FOLDER)exec_pnw.c		\
		  $(SERVER_FOLDER)exec_pex.c		\
		  $(SERVER_FOLDER)exec_pbc.c		\
		  $(SERVER_FOLDER)exec_pic.c		\
		  $(SERVER_FOLDER)exec_pie.c		\
		  $(SERVER_FOLDER)exec_pfk.c		\
		  $(SERVER_FOLDER)exec_pdr.c		\
		  $(SERVER_FOLDER)exec_pgt.c		\
		  $(SERVER_FOLDER)exec_pdi.c		\
		  $(SERVER_FOLDER)check_fork.c		\
		  $(SERVER_FOLDER)exec_enw.c		\
		  $(SERVER_FOLDER)exec_eht.c		\
		  $(SERVER_FOLDER)exec_ebo.c		\
		  $(SERVER_FOLDER)exec_edi.c		\
		  $(SERVER_FOLDER)exec_seg.c		\
		  $(SERVER_FOLDER)exec_suc.c		\
		  $(SERVER_FOLDER)exec_sbp.c		\
		  $(SERVER_FOLDER)check_elevation.c	\
		  $(COMMON_SRC)				\

SERVER_OBJ	= $(SERVER_SRC:.c=.o)

all:		$(CLIENT) $(GRAPHIC) $(SERVER)

$(CLIENT):	$(CLIENT_OBJ)
		$(COMPILE) -o $@ $^

$(GRAPHIC):	$(GRAPHIC_OBJ)
		$(COMPILE) -o $@ $^ -lSDL -lSDL_ttf

$(SERVER):	$(SERVER_OBJ)
		$(COMPILE) -o $@ $^ $(L_MATH)

clean:
		$(CLEAN) $(CLIENT_OBJ) $(GRAPHIC_OBJ) $(SERVER_OBJ)

fclean:		clean
		$(CLEAN) $(CLIENT) $(GRAPHIC) $(SERVER)

re: 		fclean all

debug:		CFLAGS = -I $(INC)/ -g

debug:		re
