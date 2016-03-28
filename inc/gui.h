/*
** gui.h for gui.h in /home/manzan_m/Project/zappy_sdl
**
** Made by Maxime Manzano
** Login   <manzan_m@epitech.net>
**
** Started on  Mon Jul  7 14:27:00 2014 Maxime Manzano
** Last update Fri Jul 11 14:02:04 2014 Maxime Manzano
*/

#ifndef			GUI_H_
# define		GUI_H_

#include		<SDL/SDL_ttf.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		<SDL/SDL.h>

# define		POS_PLA 225
# define		POS_INV 65
# define		LI_INV 150
# define		DER_INV 210
# define		SIB_INV 270
# define		MEN_INV 330
# define		PHI_INV 390
# define		THY_INV 450
# define		LI_PLA 310
# define		DER_PLA 370
# define		SIB_PLA 430
# define		MEN_PLA 490
# define		PHI_PLA 550
# define		THY_PLA 610
# define		WIN_X 1024
# define		WIN_Y (WIN_X / 4 * 3)
# define		MAP_X (WIN_X - WIN_X / 4)
# define		MAP_Y WIN_Y
# define		GUI_X (WIN_X / 4)
# define		GUI_Y WIN_Y
# define		BPP 32
# define		SIZE_SPRITE (MAP_X / 24)
# define		POS_TAB(x, y, size) ((y) * size + (x))
# define		SIZE_FONT 25
# define		FONT "font/font_gui.ttf"
# define		BACKGROUND "sprites/sprite_gui.bmp"


typedef			struct s_gui
{
  TTF_Font		*font;
  SDL_Surface		*background;
  SDL_Surface		*text;
  SDL_Color		color;
  SDL_Rect		conf;
  SDL_Rect		conf_screen;
  SDL_Rect		conf_background;
  int			modx;
  int			mody;
  int			x;
  int			y;

}			t_gui;


#endif
