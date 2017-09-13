/*
** fill_the_struct.c for lem-in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Apr 20 17:15:42 2015 Alban Meurice
** Last update Sat May  2 22:02:48 2015 pierre jallut
*/

#include <stdlib.h>
#include "parser.h"

int	search_start_and_end(t_tools *tools)
{
  int	x;
  int	return_func;

  x = 1;
  while (tools->file[x] != NULL)
    {
      if (tools->file[x][0] == '#' && tools->file[x][1] == '#')
	{
	  if ((return_func = get_cmd(tools->file[x])) == -1)
	    return (-1);
	  if (return_func == 0)
	    tools->line_start = x;
	  else if (return_func == 1)
	    tools->line_end = x;
	}
      x = x + 1;
    }
  if (tools->line_start == 0 || tools->line_end == 0)
    return (-1);
  return (0);
}

int	search_second_part(char **file)
{
  int	lock;
  int	x;

  x = 1;
  lock = 0;
  while (file[x] != NULL && lock == 0)
    {
      if (check_is_room(file, x) == -1)
	lock = 1;
      else
	x = x + 1;
    }
  if (it_s_tube_def(file[x]) == -1)
    return (-1);
  return (x);
}
