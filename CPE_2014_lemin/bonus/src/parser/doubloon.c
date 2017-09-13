/*
** doubloon.c for  in /home/grosso_a/workspace/CPE_2014_lemin
** 
** Made by Arthur Grosso
** Login   <grosso_a@epitech.net>
** 
** Started on  Sun May  3 21:28:06 2015 Arthur Grosso
** Last update Sun May  3 21:28:24 2015 Arthur Grosso
*/

#include <stdlib.h>
#include "parser.h"

int	find_doubloon(t_data *data)
{
  int	x;
  char	*w_1;
  char	*w_2;

  x = 0;
  while (data->tubes[x] != NULL)
    {
      if ((w_1 = get_word_one2(data->tubes[x])) == NULL)
	return (-1);
      if ((w_2 = get_word_two2(data->tubes[x])) == NULL)
	return (-1);
      if ((w_1 = fmt_line2(w_2, w_1)) == NULL)
	return (-1);
      if (find_doubloon2(data, w_1, x) == -1)
	if ((data->tubes = supr_doubloon(data->tubes, x)) == NULL)
	  return (-1);
      x++;
    }
  return (0);
}

int	find_doubloon2(t_data *data, char *w_1, int ref)
{
  int	x;

  x = 0;
  while (data->tubes[x] != NULL)
    {
      if (x == ref)
	x++;
      if (data->tubes[x] == NULL)
	return (0);
      if (my_strcmp(data->tubes[x], data->tubes[ref]) == 0)
	return (-1);
      if (my_strcmp(data->tubes[x], w_1) == 0)
	return (-1);
      x++;
    }
  return (0);
}

char	**supr_doubloon(char **tubes, int x)
{
  char	**new_tab;
  int	x_cpy;
  int	x2;

  x_cpy = 0;
  while (tubes[x_cpy] != NULL)
    x_cpy = x_cpy + 1;
  if ((new_tab = malloc((x_cpy - 1) * sizeof(char *))) == NULL)
    return (NULL);
  x_cpy = 0;
  x2 = 0;
  while (tubes[x_cpy] != NULL)
    {
      if (x_cpy == x)
	x_cpy = x_cpy + 1;
      if ((new_tab[x2] = malloc(my_strlen(tubes[x_cpy]) * sizeof(char)
				)) == NULL)
	return (NULL);
      if ((new_tab[x2] = my_strdup(tubes[x_cpy])) == NULL)
	return (NULL);
      x2 = x2 + 1;
      x_cpy = x_cpy + 1;
    }
  new_tab[x2] = NULL;
  return (new_tab);
}
