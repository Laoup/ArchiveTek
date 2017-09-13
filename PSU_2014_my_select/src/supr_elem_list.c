/*
** func_in_list.c for my_select in /home/meuric_a/Project/my_select/V3.0
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sat Jan  3 16:53:34 2015 alban meurice
** Last update Sat Jan 10 23:47:14 2015 alban meurice
*/

#include <stdlib.h>
#include <termios.h>
#include "../include/my_select.h"

void	supr_elem_in_list(t_pos **curs_position, t_rep **repere)
{
  t_list	*tmp;
  t_rep		*tmp2;
  int		i;

  i = 0;
  tmp = (*repere)->head;
  if (init_list(&tmp2) == -1)
    exit(0);
  tmp2->cursor = (*repere)->cursor;
  while (i != (*curs_position)->x)
    {
      tmp = tmp->next;
      i = i + 1;
    }
  if ((*repere)->cursor == (*repere)->head)
    supr_head_list(repere);
  else if ((*repere)->cursor == (*repere)->tail)
    supr_tail_list(repere);
  else
    supr_elem_list(repere, tmp2, tmp);
  (*repere)->lenght = (*repere)->lenght - 1;  
}

void	supr_head_list(t_rep **repere)
{
  (*repere)->head = (*repere)->cursor->next;
  (*repere)->tail->next = (*repere)->head;
  (*repere)->head->prev = (*repere)->tail;
  (*repere)->cursor = (*repere)->head;
}

void	supr_tail_list(t_rep **repere)
{
  (*repere)->tail = (*repere)->cursor->prev;
  (*repere)->head->prev = (*repere)->tail;
  (*repere)->tail->next = (*repere)->head;
  (*repere)->cursor = (*repere)->tail;
}

void	supr_elem_list(t_rep **repere, t_rep *tmp2, t_list *tmp)
{
  (*repere)->cursor = tmp->prev;
  tmp2->cursor = (*repere)->cursor;
  tmp = tmp->next;
  (*repere)->cursor->next = tmp;
  (*repere)->cursor = (*repere)->cursor->next;
  (*repere)->cursor->prev = tmp2->cursor;
}
