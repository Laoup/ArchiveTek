/*
** func_for_graphpart.c for lem_in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri May  1 18:40:38 2015 Alban Meurice
** Last update Sat May  2 22:00:20 2015 pierre jallut
*/

#include <stdlib.h>
#include "parser.h"

void	get_data_for_graphpart(t_data *data)
{
  int	x;
  int	val_x;
  int	val_y;

  x = 0;
  val_x = 0;
  val_y = 0;
  while (data->pos_room[x] != NULL)
    {
      if (data->pos_room[x][0] > val_x)
	val_x = data->pos_room[x][0];
      if (data->pos_room[x][1] > val_y)
	val_y = data->pos_room[x][1];
      x = x + 1;
    }
  data->x_max = val_x;
  data->y_max = val_y;
  data->nb_rooms = x;
}
