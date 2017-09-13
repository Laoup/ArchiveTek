/*
** check_func.c for lem-in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Apr 20 10:18:30 2015 Alban Meurice
** Last update Sat May  2 21:58:43 2015 pierre jallut
*/

#include <stdlib.h>
#include "parser.h"
#include "nest.h"

int	i_f_comment(char *line)
{
  int	y;

  y = 0;
  while (line[y] != '\0')
    {
      if (line[y] == '#' && (line[y + 1] != '#' && line[y - 1] != '#'))
	return (y);
      y = y + 1;
    }
  return (-1);
}

int	check_is_room(char **file, int x)
{
  int	y;

  y = 0;
  if (file[x] != NULL)
    {
      if (file[x][0] == '#' && file[x + 1] != NULL)
	x = x + 1;
      while (file[x][y] != ' ')
	{
	  if (file[x][y] == '\0' || file[x][y] == '-')
	    return (-1);
	  y = y + 1;
	}
      y = y + 1;
      if ((y = is_pos(file, x, y)) == -1)
	return (-1);
      if (file[x][y] != ' ')
	return (-1);
      y = y + 1;
      if ((y = is_pos(file, x, y)) == -1)
	return (-1);
      if (file[x][y] == '\0')
	return (0);
    }
  return (-1);
}

int	is_pos(char **file, int x, int y)
{
  if (file[x][y] >= '0' && file[x][y] <= '9')
    {
      while (file[x][y] >= '0' && file[x][y] <= '9')
	y = y + 1;
      return (y);
    }
  return (-1);
}

int	it_s_tube_def(char *line_file)
{
  int	y;

  y = 0;
  if (line_file != NULL)
    {
      if (line_file[0] == '#')
	return (-1);
      if (line_file[0] != ' ')
	{
	  while (line_file[y] != '-')
	    {
	      if (line_file[y] == '\0')
		return (-1);
	      y = y + 1;
	    }
	  y = y + 1;
	  if (line_file[y] == '\0')
	    return (-1);
	  return (0);
	}
    }
  return (-1);
}
