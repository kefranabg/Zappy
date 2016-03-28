/*
** error.h for error.h in /home/loeb_t/rendu/PSU_2013_zappy
**
** Made by LOEB Thomas
** Login   <loeb_t@epitech.net>
**
** Started on  Mon May  5 15:33:04 2014 LOEB Thomas
** Last update Fri Jul 11 19:53:52 2014 Baptiste Acca
*/

#ifndef			ERROR_H_
# define		ERROR_H_

# include		<stdio.h>

# define		ERROR(error)		("ERROR: "error)
# define		WARNING(error)		("WARNING: "error)
# define		SYSCALL(syscall)	ERROR("syscall '"syscall"' failed")

# define		WRONG_OPT		ERROR("bad(s) option(s)")
# define		TOO_MANY_OPT		WARNING("too many options -> using the last one")
# define		BAD_VALUE_OPT		ERROR("bad value of option(s)")

# define		BAD_WAY_QUIT		ERROR("can not quit this way")

# define		BRK_PIPE		ERROR("client/server quitted during write")

# define		STOP_VALUE		0
# define		STOP_RESET		42

# define		STOP_BRK_PIPE		-1
# define		STOP_QUIT		1

# define		TCGETATTR_FAIL		SYSCALL("tcgetattr")
# define		TCSETATTR_FAIL		SYSCALL("tcsetattr")
# define		READ_FAIL		SYSCALL("Read")

int			my_perror(char *, int);
int			my_error(char *, int);

#endif			/* ERROR_H_ */
