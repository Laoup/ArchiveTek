/*
** fc_cover.c for  in /home/grosso_a/workspace/lem_in
** 
** Made by Arthur Grosso
** Login   <grosso_a@epitech.net>
** 
** Started on  Wed Apr 29 17:45:42 2015 Arthur Grosso
** Last update Sun May  3 20:19:45 2015 pierre jallut
*/

#include <stdio.h>
#include <stdlib.h>
#include "nest.h"

t_fourmiz	*fill_check(t_fourmiz ***paths, t_fourmiz *in, t_fourmiz *out)
{
  t_fourmiz	*check;
  int		i;
  int		j;

  i = 0;
  check = NULL;
  while (paths[i] != NULL)
    {
      j = 0;
      while (paths[i][j] != NULL)
	{
	  if ((paths[i][j] != in) && (paths[i][j] != out))
	    {
	      check = add_pile(check, paths[i][j]);
	    }
	  j++;
	}
      i++;
    }
  return (check);
}

void		aff_list(t_fourmiz *in)
{
  t_fourmiz	*tmp;

  tmp = in;
  while (tmp != NULL)
    {
      printf("id = %s\n", tmp->id);
      tmp = tmp->next;
    }
}

int		is_check(t_fourmiz *var, t_fourmiz *file)
{
  t_fourmiz	*tmp;

  tmp = file;
  while ((tmp != NULL) && (tmp != var))
    {
      tmp = tmp->next;
    }
  if (tmp != NULL)
    return (1);
  else
    return (0);
}
