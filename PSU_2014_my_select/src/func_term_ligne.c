/*
** func_term_ligne.c for project my_select in /home/meuric_a/Project/my_select/V2.0
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Dec 31 16:59:10 2014 alban meurice
** Last update Sun Jan 11 13:07:00 2015 alban meurice
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <ncurses/curses.h>
#include "../include/my_select.h"

int		start_soulignement()
{
  char		*res;

  if ((res = tgetstr("us", NULL)) == NULL)
    return (-1);
  tputs(res, 0, &my_put);
  return (0);
}

int		end_soulignement(t_pos **curs_position, t_rep **repere)
{
  char		*res;
  char		*cursm;

  if ((cursm = tgetstr("cm", NULL)) == NULL)
    return (-1);
  tputs(tgoto(cursm, (*curs_position)->y, (*curs_position)->x), 0, &my_put);
  if ((res = tgetstr("ue", NULL)) == NULL)
    return (-1);
  tputs(res, 0, &my_put);
  my_show_list_elem(*repere);
  return (0);
}

int		start_rev_video()
{
  char		*res;

  if ((res = tgetstr("so", NULL)) == NULL)
    return (-1);
  tputs(res, 0, &my_put);
  return (0);
}

int		end_rev_video()
{
  char		*res;

  if ((res = tgetstr("se", NULL)) == NULL)
    return (-1);
  tputs(res, 0, &my_put);
  return (0);
}
