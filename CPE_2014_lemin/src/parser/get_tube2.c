/*
** get_tube2.c for lem_in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Apr 24 13:51:53 2015 Alban Meurice
** Last update Sun May  3 21:20:23 2015 Arthur Grosso
*/

#include <stdlib.h>
#include "parser.h"

int	count_tubes(char **tab)
{
  int	x;

  x = 0;
  while (tab[x] != NULL)
    x = x + 1;
  return (x + 1);
}

char	**copy_tubes_tab(char **tab)
{
  char	**cpy_tab;
  int	size;
  int	x;

  cpy_tab = NULL;
  size = count_tubes(tab);
  if ((cpy_tab = malloc(size * sizeof(char *))) == NULL)
    return (NULL);
  x = 0;
  while (tab[x] != NULL)
    {
      if ((cpy_tab[x] = my_strdup(tab[x])) == NULL)
	return (NULL);
      x = x + 1;
    }
  cpy_tab[x] = NULL;
  return (cpy_tab);
}

int	add_ligne_tab(t_data *data, char ** cpy_tab, char *line, int size)
{
  int	x;

  if ((data->tubes = malloc((size + 1) * sizeof(char *))) == NULL)
    return (-1);
  x = 0;
  while (cpy_tab[x] != NULL)
    {
      if ((data->tubes[x] = my_strdup(cpy_tab[x])) == NULL)
	return (-1);
      x = x + 1;
    }
  if ((data->tubes[x++] = my_strdup(line)) == NULL)
    return (-1);
  data->tubes[x] = NULL;
  return (0);
}
