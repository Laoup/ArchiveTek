/*
** main.c for my_select in /home/meuric_a/Project/my_select/V2.0
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Dec 30 02:18:38 2014 alban meurice
** Last update Sun Jan 11 12:39:56 2015 alban meurice
*/

#include <stdlib.h>
#include "../include/my_select.h"

void		my_put_end_list_first(t_rep **repere, t_list *new_elem)
{
  (*repere)->lenght = 1;
  (*repere)->head = new_elem;
  (*repere)->tail = new_elem;
  new_elem->next = new_elem;
  new_elem->prev = new_elem;
}

int		*my_put_end_list(t_rep **repere, char *str)
{
  t_list	*new_elem;
  t_list	*tmp;

  tmp = (*repere)->head;
  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  new_elem->str = str;
  new_elem->reverse = 0;
  if ((*repere)->head == NULL)
    {
      my_put_end_list_first(repere, new_elem);
      return (0);
    }
  (*repere)->tail = new_elem;
  (*repere)->lenght = (*repere)->lenght + 1;
  new_elem->next = (*repere)->head;
  tmp->prev = new_elem;
  while (tmp->next != (*repere)->head)
      tmp = tmp->next;
  new_elem->prev = tmp;
  tmp->next = new_elem;
  (*repere)->cursor = tmp;
  return (0);
}
