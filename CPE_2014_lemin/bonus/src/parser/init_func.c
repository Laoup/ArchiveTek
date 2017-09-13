/*
** init_func.c for lem_in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sat Apr 18 15:51:30 2015 Alban Meurice
** Last update Sat May  2 22:02:34 2015 pierre jallut
*/

#include <stdlib.h>
#include "parser.h"

void	init_struct(t_data *data)
{
  data->tubes = NULL;
  data->name_room = NULL;
  data->pos_room = NULL;
  data->nb_ants = 0;
  data->nb_rooms = 0;
  data->x_max = 0;
  data->y_max = 0;
}
