/*
** manage_file.c for  in /home/grosso_a/workspace/lem_in
** 
** Made by Arthur Grosso
** Login   <grosso_a@epitech.net>
** 
** Started on  Thu Apr 23 22:25:47 2015 Arthur Grosso
** Last update Sun May  3 20:19:06 2015 pierre jallut
*/

#include <stdio.h>
#include <stdlib.h>
#include "nest.h"

t_fourmiz	*add_pile(t_fourmiz *file, t_fourmiz *elem)
{
  t_fourmiz	*tmp;

  if (elem == NULL)
    return (file);
  if (file == NULL)
    {
      elem->next = NULL;
      return (elem);
    }
  tmp = file;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->next = NULL;
  return (file);
}

t_fourmiz	*get_pile(t_fourmiz **file)
{
  t_fourmiz	*tmp;

  tmp = *file;
  if (*file != NULL)
    *file = (*file)->next;
  return (tmp);
}

int		show_pile(t_fourmiz *file)
{
  t_fourmiz	*tmp;

  tmp = file;
  while (tmp != NULL)
    {
      printf("File Id = %s\n", tmp->id);
      tmp = tmp->next;
    }
  return (0);
}
