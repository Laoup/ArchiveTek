/*
** fill_tab_name2.c for lem_in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Apr 22 01:13:34 2015 Alban Meurice
** Last update Sun May  3 23:06:02 2015 pierre jallut
*/

#include <stdlib.h>
#include "nest.h"
#include "parser.h"

int	putnbr_in_pos_tab2(t_data *data, char *word, int x, int y)
{
  int	**cpy_tab;
  int	x_cpy;

  cpy_tab = ver_maloc("error_malloc", malloc((x + 2) * sizeof(int *)));
  x_cpy = -1;
  while (++x_cpy <= x)
    {
      if ((cpy_tab = while_func2(cpy_tab, data->pos_room, x_cpy, y)) == NULL)
	return (-1);
    }
  if ((data->pos_room = malloc((x + 3) * sizeof(int *))) == NULL)
    return (-1);
  x_cpy = -1;
  while (++x_cpy <= x)
    {
      if ((data->pos_room = while_func2(data->pos_room,
					cpy_tab, x_cpy, y)) == NULL)
	return (-1);
    }
  if ((data->pos_room[x++][y] = my_getnbr(word)) == -1)
    return (-1);
  data->pos_room[x] = NULL;
  return (0);
}

int	**while_func2(int **tab, int **cpy_tab, int x, int y)
{
  if ((tab[x] = malloc(2 * sizeof(int))) == NULL)
    return (NULL);
  if (cpy_tab[x] == NULL)
    {
      tab[x][0] = 0;
      tab[x][1] = 0;
    }
  else
    {
      tab[x][1] = cpy_tab[x][1];
      tab[x][0] = cpy_tab[x][0];
    }
  (void) y;
  return (tab);
}
