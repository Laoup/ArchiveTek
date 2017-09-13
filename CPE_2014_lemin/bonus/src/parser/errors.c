/*
** errors.c for  in /home/grosso_a/workspace/CPE_2014_lemin
** 
** Made by Arthur Grosso
** Login   <grosso_a@epitech.net>
** 
** Started on  Sun May  3 21:30:00 2015 Arthur Grosso
** Last update Sun May  3 22:36:10 2015 Arthur Grosso
*/

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int	name_error(t_data *data)
{
  int	i;
  int	j;
  int	check;

  i = 0;
  while (data->name_room[i] != NULL)
    {
      j = 0;
      check = 0;
      while (data->name_room[j] != NULL)
	{
	  if (my_strcmp(data->name_room[i], data->name_room[j]) == 0)
	    check++;
	  j++;
	}
      if (check > 1)
	return (-1);
      i++;
    }
  return (0);
}

int	position_error(t_data *data)
{
  int	i;
  int	j;

  i = 0;
  while (data->pos_room[i] != NULL)
    {
      j = 0;
      while (data->pos_room[j] != NULL)
        {
	  if (j == i)
	    j++;
	  if (data->pos_room[j] != NULL)
	    if (data->pos_room[i][0] == data->pos_room[j][0])
	      if (data->pos_room[i][1] == data->pos_room[j][1])
		return (-1);
          j++;
	}
      i++;
    }
  return (0);
}

int	neg_nb_ants(t_data *data)
{
  if (data->nb_ants < 0)
    {
      my_putstr("ERROR : This game requires one or more ants to run\n");
      return (-1);
    }
  return (0);
}
