/*
** get_file.c for lem_in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sat Apr 18 16:09:49 2015 Alban Meurice
** Last update Sun May  3 21:26:48 2015 Arthur Grosso
*/

#include <stdlib.h>
#include <unistd.h>
#include "parser.h"
#include "nest.h"

char	**get_file(char **file)
{
  char	**cpy_tab;
  char	*line;
  int	x;

  line = NULL;
  x = 0;
  while ((line = my_strdup(get_next_line(0))) != NULL && x != 1000)
    {
      my_putstr(line);
      my_putchar('\n');
      if (file != NULL)
	if ((cpy_tab = copy_tab(file, x + 1)) == NULL)
	  return (NULL);
      if ((file = put_line_in_file(line, file, cpy_tab, x + 1)) == NULL)
	return (NULL);
      x = x + 1;
      free(line);
    }
  if (file != NULL)
    if ((file = clear_file(file)) == NULL)
      return (NULL);
  return (file);
}

char	**copy_tab(char **tab, int x_ref)
{
  char	**cpy_tab;
  int	x;

  x = 0;
  if (x_ref != 0)
    {
      if ((cpy_tab = malloc(x_ref * sizeof(char *))) == NULL)
	return (NULL);
      while (x < (x_ref - 1))
	{
	  if ((cpy_tab[x] = my_strdup(tab[x])) == NULL)
	    return (NULL);
	  x = x + 1;
	}
      cpy_tab[x] = NULL;
    }
  else
    {
      while (tab[x] != NULL)
	x = x + 1;
      if ((cpy_tab = copie_file(tab, x)) == NULL)
	return (NULL);
    }
  return (cpy_tab);
}

char	**copie_file(char **tab, int x_ref)
{
  char	**cpy_tab;
  int	x;

  if ((cpy_tab = malloc((x_ref + 1) * sizeof(char *))) == NULL)
    return (NULL);
  x = 0;
  while (x < x_ref)
    {
      if ((cpy_tab[x] = my_strdup(tab[x])) == NULL)
	return (NULL);
      x = x + 1;
    }
  cpy_tab[x] = NULL;
  return (cpy_tab);
}

char	**put_line_in_file(char *line, char **file, char **cpy_tab, int x_ref)
{
  int	x;

  x = 0;
  if ((file = malloc((x_ref + 1) * sizeof(char *))) == NULL)
    return (NULL);
  if (x_ref == 1)
    {
      if ((file[0] = my_strdup(line)) == NULL)
	return (NULL);
      file[1] = NULL;
      return (file);
    }
  while (x < (x_ref - 1))
    {
      if ((file[x] = my_strdup(cpy_tab[x])) == NULL)
	return (NULL);
      x = x + 1;
    }
  if ((file[x] = my_strdup(line)) == NULL)
    return (NULL);
  x = x + 1;
  file[x] = NULL;
  return (file);
}

char	**clear_file(char **file)
{
  char	**copy_file;
  int	x;
  int	y;

  if ((copy_file = start_clear_file(file, &x)) == NULL)
    return (NULL);
  while (file[x] != NULL)
    {
      if (file[x][0] == '#' && file[x][1] != '#')
	{
	  if ((file = supr_line_file(file, copy_file, x)) == NULL)
	    return (NULL);
	  if ((copy_file = copy_tab(file, 0)) == NULL)
	    return (NULL);
	}
      else if ((y = i_f_comment(file[x])) != -1)
	{
	  if ((file[x] = supr_comment(file[x], y)) == NULL)
	    return (NULL);
	  x = x + 1;
	}
      else
	x = x + 1;
    }
  return (file);
}
