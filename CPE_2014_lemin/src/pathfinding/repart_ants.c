/*
** repart_ants.c for  in /home/grosso_a/workspace/lem_in
** 
** Made by Arthur Grosso
** Login   <grosso_a@epitech.net>
** 
** Started on  Fri May  1 20:22:00 2015 Arthur Grosso
** Last update Sun May  3 20:18:54 2015 pierre jallut
*/

#include <stdio.h>
#include <stdlib.h>
#include "nest.h"

void	aff_ants(t_1001 **tab_ants)
{
  int	i;

  i = 0;
  if (tab_ants != NULL)
    {
      while (tab_ants[i] != NULL)
	{
	  printf("Ants n°%d is in path %d\n", i, tab_ants[i]->path);
	  i++;
	}
    }
}

int	get_paths_size(t_fourmiz ***paths, int **paths_size, int **tab_ants)
{
  int	nb_paths;
  int	i;
  int	j;

  i = 0;
  nb_paths = 0;
  while (paths[nb_paths] != NULL)
    nb_paths++;
  if ((*paths_size = malloc(sizeof(int) * (nb_paths + 1))) == NULL)
    return (1);
  if ((*tab_ants = malloc(sizeof(int) * (nb_paths + 1))) == NULL)
    return (1);
  while (paths[i] != NULL)
    {
      j = 0;
      while (paths[i][j] != NULL)
	j++;
      (*paths_size)[i] = j - 2;
      (*tab_ants)[i] = 0;
      i++;
    }
  (*paths_size)[i] = -1;
  (*tab_ants)[i] = -1;
  return (0);
}

void	asigne_ants(int *nb_ants, int *paths_size, int *tab_ants_repart)
{
  int	i;
  int	assigne;

  i = 0;
  assigne = 0;
  while ((paths_size[i] != -1) && (assigne == 0))
    {
      if (tab_ants_repart[i] < paths_size[i])
	{
	  *nb_ants = i;
	  tab_ants_repart[i] += 1;
	  assigne = 1;
	}
      else
	{
	  if (tab_ants_repart[i] < 0)
	    tab_ants_repart[i] = 0;
	  else
	    tab_ants_repart[i] -= 1;

	}
      i++;
    }
}

int	repart_ants(t_fourmiz ***paths, t_1001 **tab_ants)
{
  int	*paths_size;
  int	*tab_ants_repart;
  int	i;

  i = 0;
  if (get_paths_size(paths, &paths_size, &tab_ants_repart))
    return (-1);
  while (tab_ants[i] != NULL)
    {
      asigne_ants(&(tab_ants[i]->path), paths_size, tab_ants_repart);
      i++;
    }
  free(paths_size);
  free(tab_ants_repart);
  return (0);
}

void	simple_repart_ants(t_fourmiz ***paths,
		       t_1001 **ants)
{
  int	size;
  int	i;
  int	b;

  size = 0;
  while (paths[size])
    size++;
  i = 0;
  while (ants[i])
    {
      b = 0;
      while (ants[i] && b < size)
	{
	  ants[i]->path = b;
	  b++;
	  i++;
	}
    }
}
