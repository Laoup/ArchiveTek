/*
** func_in_list.c for my_select in /home/meuric_a/Project/my_select/V3.0
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sat Jan  3 16:53:34 2015 alban meurice
** Last update Sun Jan 11 16:45:10 2015 alban meurice
*/

#include <stdlib.h>
#include <termios.h>
#include "../include/my_select.h"
#include "../include/my.h"

int		end_prog(t_rep **repere, struct termios *term)
{
  t_rep		*final_list;
  int		i;

  i = 0;
  if (init_list(&final_list) == -1)
    return (-1);
  if (back_param(term) == -1)
    return (-1);
  my_clear_screen();
  (*repere)->cursor = (*repere)->head;
  while (i != (*repere)->lenght)
    {
      if ((*repere)->cursor->reverse == 1)
	{
	  if ((my_put_end_list(&final_list, (*repere)->cursor->str)) != 0)
	    return (-1);
	}
      i = i + 1;
      (*repere)->cursor = (*repere)->cursor->next;
    }
  my_show_list_next(final_list, term);
  exit(0);
}

int		supr_elem(t_pos **curs_position, t_rep **repere, struct termios *term)
{
  if ((*repere)->lenght == 1)
    {
      (*repere)->head = NULL;
      my_clear_screen();
      if (back_param(term) == -1)
	return (-1);
      my_puterror("la liste est vide\n");
      exit(0);
    }
  else
    {
      supr_elem_in_list(curs_position, repere);
      if (back_list(curs_position, repere, term) == -1)
	return (-1);
    }
  return (0);
}
