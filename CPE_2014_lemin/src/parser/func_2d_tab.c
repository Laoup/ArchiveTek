/*
** func_2d_tab.c for lem-in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Apr 20 09:54:27 2015 Alban Meurice
** Last update Sat May  2 22:04:19 2015 pierre jallut
*/

#include <stdlib.h>
#include "parser.h"

char	**supr_line_file(char **file, char **cpy_file, int x_error)
{
  int	x;
  int	x2;

  x = 0;
  while (file[x] != NULL)
    x = x + 1;
  if ((file = malloc(x * sizeof(char *))) == NULL)
    return (NULL);
  x = 0;
  x2 = 0;
  while (cpy_file[x] != NULL)
    {
      if (x == x_error)
	x = x + 1;
      else
	{
	  if ((file[x2] = my_strdup(cpy_file[x])) == NULL)
	    return (NULL);
	  x = x + 1;
	  x2 = x2 + 1;
	}
    }
  file[x2] = NULL;
  return (file);
}

char	*supr_comment(char *line, int y)
{
  char	*cpy_line;
  int	i;

  i = 0;
  if ((cpy_line = my_strdup(line)) == NULL)
    return (NULL);
  if ((line = malloc(y * sizeof(char))) == NULL)
    return (NULL);
  while (i != y)
    {
      line[i] = cpy_line[i];
      i = i + 1;
    }
  line[i - 1] = '\0';
  free(cpy_line);
  return (line);
}

char	**start_clear_file(char **file, int *x)
{
  char	**copy_file;

  copy_file = NULL;
  *x = 0;
  if ((copy_file = copy_tab(file, *x)) == NULL)
    return (NULL);
  return (copy_file);
}
