/*
** map.h for zappy in /home/docqui_a/map/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Tue Jun 14 18:50:07 2016 Avel Docquin
** Last update Thu Jun 23 16:32:03 2016 Jaime Dossantos
*/

#ifndef _MAP_H_
# define _MAP_H_

# include "stdlib.h"
# include "time.h"
# include "my.h"

# define NORD 0
# define OUEST 1
# define SUD 2
# define EST 3

enum resources
{
  FOOD,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME
};

typedef struct	s_case
{
  int		ressources[8];
}		t_case;

int	init_map(t_param *);

#endif /* !_MAP_H_ */
