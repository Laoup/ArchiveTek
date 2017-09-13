/*
** func_term.c for my_select proj in /home/meuric_a/Project/my_select/V2.0
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Dec 30 03:14:15 2014 alban meurice
** Last update Sun Jan 11 16:09:00 2015 alban meurice
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <ncurses/curses.h>
#include "../include/my_select.h"

int		my_put(int c)
{
  if (write(1, &c, 1) == 1)
    return (-1);
  return (0);
}

int		init_struct(struct termios *term, char **env)
{
  if (tcgetattr(0, term) == -1)
    return (-1);
  term->c_lflag &= ~ECHO;
  term->c_lflag &= ~ICANON;
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, term) == -1)
    return (-1);
  if (tgetent(NULL, my_getenv("TERM", env)) == -1)
    return (-1);
  return (0);
}

int		back_param(struct termios *term)
{
  char		*res;

  if ((res = tgetstr("ue", NULL)) == NULL)
    return (-1);
  tputs(res, 0, &my_put);
  if ((res = tgetstr("se", NULL)) == NULL)
    return (-1);
  tputs(res, 0, &my_put);
  if ((res = tgetstr("ve", NULL)) == NULL)
    return (-1);
  tputs(res, 0, &my_put);
  term->c_lflag = (ICANON | ECHO);
  if (tcsetattr(0, TCSANOW, term) == -1)
    return (-1);
  return (0);
}

int		my_clear_screen()
{
  char		*res;

  if ((res = tgetstr("cl", NULL)) == NULL)
    return (-1);
  tputs(res, 0, &my_put);
  return (0);
}
