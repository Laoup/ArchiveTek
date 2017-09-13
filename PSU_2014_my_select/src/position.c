/*
** position.c for my_select project in /home/meuric_a/Project/my_select/V2.0
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Dec 30 22:46:22 2014 alban meurice
** Last update Sat Jan 10 23:46:58 2015 alban meurice
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <ncurses/curses.h>
#include "../include/my_select.h"

int	init_pos(t_pos **curs_position)
{
  if ((*curs_position = malloc(sizeof(t_pos))) == NULL)
    return (-1);
  (*curs_position)->x = 0;
  (*curs_position)->y = 0;
  return (0);
}

int	go_head(t_pos **curs_position, t_rep **repere)
{
  char	*cursm;
  
  (*repere)->cursor = (*repere)->head;
  if ((cursm = tgetstr("cm", NULL)) == NULL)
    return (-1);
  tputs(tgoto(cursm, (*curs_position)->y, (*curs_position)->x), 0, &my_put);
  start_soulignement();
  my_show_list_elem(*repere);
  return (0);
}
