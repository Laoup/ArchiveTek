/*
** fc_paths.c for  in /home/grosso_a/workspace/lem_in
** 
** Made by Arthur Grosso
** Login   <grosso_a@epitech.net>
** 
** Started on  Wed Apr 29 17:55:37 2015 Arthur Grosso
** Last update Sun May  3 20:20:06 2015 pierre jallut
*/

#include <stdio.h>
#include <stdlib.h>
#include "nest.h"

void	aff_path(t_fourmiz ***paths)
{
  int	i;
  int	j;

  i = 0;
  while (paths[i] != NULL)
    {
      j = 0;
      printf("Path %d\n", i);
      while (paths[i][j] != NULL)
	{
	  printf("id = %s\n", paths[i][j]->id);
	  j++;
	}
      i++;
    }
}

t_fourmiz	***realloc_paths(t_fourmiz ***paths, int size)
{
  t_fourmiz	***out;
  int		i;

  i = 0;
  out = malloc(sizeof(t_fourmiz **) * (size + 1));
  if (out == NULL)
    return (out);
  while (i < size)
    {
      out[i] = paths[i];
      i++;
    }
  out[i] = NULL;
  free(paths);
  return (out);
}

int		len_path(t_fourmiz *out)
{
  t_fourmiz	*tmp;
  int		s_path;

  tmp = out;
  s_path = 0;
  while (tmp != NULL)
    {
      ++s_path;
      tmp = tmp->father;
    }
  return (s_path);
}

t_fourmiz	**get_path(t_fourmiz *out)
{
  t_fourmiz	**tab;
  t_fourmiz	*tmp;
  int		s_path;

  s_path = len_path(out);
  if ((tab = malloc(sizeof(t_fourmiz *) * (s_path + 1))) == NULL)
    return (NULL);
  tmp = out;
  tab[s_path--] = NULL;
  while (tmp != NULL)
    {
      tab[s_path] = tmp;
      tmp = tmp->father;
      s_path--;
    }
  return (tab);
}
