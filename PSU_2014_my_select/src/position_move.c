/*
** position.c for my_select project in /home/meuric_a/Project/my_select/V2.0
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Dec 30 22:46:22 2014 alban meurice
** Last update Sun Jan 11 13:19:19 2015 alban meurice
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <ncurses/curses.h>
#include "../include/my_select.h"

int	move_head(t_pos **curs_position, t_rep **repere)
{
  char	*cursm;

  (*curs_position)->x = 0;
  if ((cursm = tgetstr("cm", NULL)) == NULL)
    return (-1);
  tputs(tgoto(cursm, (*curs_position)->y, (*curs_position)->x), 0, &my_put);
  end_rev_video();
  if ((*repere)->cursor->reverse == 1)
    {
      start_soulignement();
      start_rev_video();
    }
  else
    start_soulignement();
  my_show_list_elem(*repere);
  return (0);
}

int	move_low(t_pos **curs_position, t_rep **repere)
{
  char	*cursm;

  (*curs_position)->x = (*curs_position)->x + 1;
  if ((cursm = tgetstr("cm", NULL)) == NULL)
    return (-1);
  tputs(tgoto(cursm, (*curs_position)->y, (*curs_position)->x), 0, &my_put);
  end_rev_video();
  if ((*repere)->cursor->reverse == 1)
    {
      start_soulignement();
      start_rev_video();
    }
  else
    start_soulignement();
  my_show_list_elem(*repere);
  return (0);
}

int     low_curs(t_pos **curs_position, t_rep **repere)
{
  end_soulignement(&*curs_position, &*repere);
  (*repere)->cursor = (*repere)->cursor->next;
  if ((*repere)->cursor == (*repere)->head)
    {
      if (move_head(curs_position, repere) == -1)
	return (-1);
    }
  else
    {
      if (move_low(curs_position, repere) == -1)
	return (-1);
    }
  return (0);
}

int	select_curs(t_pos **curs_position, t_rep **repere)
{
  char	*cursm;

  if ((*repere)->cursor->reverse == 1)
    {
      (*repere)->cursor->reverse = 0;
      if (end_rev_video() == -1)
	return (-1);
    }
  else
    {
      (*repere)->cursor->reverse = 1;
      if (start_rev_video() == -1)
	return (-1);
    }
  if ((cursm = tgetstr("cm", NULL)) == NULL)
    return (-1);
  tputs(tgoto(cursm, (*curs_position)->y, (*curs_position)->x), 0, &my_put);
  my_show_list_elem(*repere);
  if (low_curs(&*curs_position, &*repere) == -1)
    return (-1);
  return (0);
}
