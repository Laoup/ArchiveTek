/*
** fill_the_struct.c for lem-in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Apr 20 17:15:42 2015 Alban Meurice
** Last update Sun May  3 21:25:16 2015 Arthur Grosso
*/

#include <stdlib.h>
#include "parser.h"

int	get_first_line(char **file)
{
  int	i;
  int	nb_ants;

  i = 0;
  while (file[0][i] != '\0')
    {
      if (file[0][i] < '0' || file[0][i] > '9')
	return (-1);
      i = i + 1;
    }
  nb_ants = my_getnbr(file[0]);
  return (nb_ants);
}

int	get_first_part(t_data *data, t_tools *tools)
{
  int	lock;
  int	x;

  x = 1;
  lock = 0;
  while (tools->file[x] != NULL && lock == 0)
    {
      if (x == tools->line_start)
	{
	  x = x + 1;
	  if (get_start_room(data, tools, tools->line_start + 1) == -1)
	    return (-1);
	}
      else if (x == tools->line_end)
	{
	  x = x + 1;
	  if (get_end_room(data, tools, tools->line_end + 1) == -1)
	    return (-1);
	}
      else
	if (get_room(data, tools->file[x]) == -1)
	  return (-1);
      get_first_part_end_while(tools, &x, &lock);
    }
  return (0);
}

void	get_first_part_end_while(t_tools *tools, int *x, int *lock)
{
  *x = *x + 1;
  if (check_is_room(tools->file, *x) == -1)
    *lock = 1;
}

int	get_second_part(t_data *data, t_tools *tools)
{
  int	x;

  if ((x = search_second_part(tools->file)) == -1)
    return (-1);
  while (tools->file[x] != NULL)
    {
      if (it_s_tube_def(tools->file[x])== -1)
	return (-1);
      if (get_tube(tools->file[x], data, x) == -1)
	return (-1);
      x = x + 1;
    }
  return (0);
}
