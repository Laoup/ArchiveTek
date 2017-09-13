/*
** map.c for zappy in /home/docqui_a/PSU_2015_zappy/server/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Tue Jun 14 20:13:37 2016 Avel Docquin
** Last update Sun Jun 26 22:59:19 2016 Avel Docquin
*/

#include "map.h"

static unsigned int	my_rand(unsigned int r)
{
  unsigned int		nb;

  srand(time(NULL));
  nb = (rand() + r) % 13;
  return (nb);
}

static unsigned int	init_case(int*** const map, const unsigned int x,
				  const unsigned int y, unsigned int r)
{
  unsigned int		i;
  unsigned int		nb;
  unsigned int		tmp;

  i = 0;
  while (i < 7)
    {
      map[y][x][i] = 0;
      ++i;
    }
  map[y][x][7] = -1;
  nb = my_rand(++r);
  if (nb < 7)
    {
      tmp = (my_rand(++r) * 12) % 5;
      map[y][x][nb] = tmp;
    }
  return (r);
}

int		init_map(t_param* const param)
{
  int		i;
  int		d;
  int		r;

  if (!(param->map = malloc(sizeof(int**) * (param->hauteur + 1))))
    return (-1);
  i = (r = 0);
  while (i < param->hauteur)
    {
      if (!(param->map[i] = malloc(sizeof(int*) * (param->largeur + 1))))
	return (-1);
      d = 0;
      while (d < param->largeur)
	{
	  if (!(param->map[i][d] = malloc(sizeof(int) * 8)))
	    return (-1);
	  r = init_case(param->map, d, i, r);
	  ++d;
	}
      param->map[i][d] = NULL;
      ++i;
    }
  param->map[i] = NULL;
  return (0);
}
