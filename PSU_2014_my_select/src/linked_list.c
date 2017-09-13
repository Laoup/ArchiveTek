/*
** main.c for my_select in /home/meuric_a/Project/my_select/V2.0
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Dec 30 02:18:38 2014 alban meurice
** Last update Sun Jan 11 19:12:00 2015 alban meurice
*/

#include <stdlib.h>
#include <sys/ioctl.h>
#include "../include/my_select.h"
#include "../include/my.h"

int			init_list(t_rep **repere)
{
  if ((*repere = malloc(sizeof(t_rep))) == NULL)
    return (-1);
  (*repere)->lenght = 0;
  (*repere)->head = NULL;
  (*repere)->tail = NULL;
  (*repere)->cursor = NULL;
  return (0);
}

void			my_show_list_prev(t_rep *repere)
{
  t_list		*tmp;
  int			i;

  i = repere->lenght;
  tmp = repere->tail;
  while (i != 0)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->prev;
      i = i - 1;
    }
}

void			my_show_list_next(t_rep *repere, struct termios *term)
{
  struct winsize	size_term;
  t_list		*tmp;
  int			i;

  i = 0;
  ioctl(0, TIOCGWINSZ, &size_term);
  if (repere->lenght >= size_term.ws_row)
    {
      back_param(term);
      my_puterror("Fenetre trop petite");
      exit(0);
    }
  tmp = repere->head;
  while (i < repere->lenght)
    {
      if (tmp->reverse == 1)
	start_rev_video();
      my_putstr(tmp->str);
      my_putchar('\n');
      end_rev_video();
      tmp = tmp->next;
      i = i + 1;
    }
}

void			my_show_list_elem(t_rep *repere)
{
  my_putstr(repere->cursor->str);
}
