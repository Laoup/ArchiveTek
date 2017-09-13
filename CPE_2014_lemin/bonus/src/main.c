/*
** main.c for lem-in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sat Apr 18 14:46:55 2015 Alban Meurice
** Last update Sun May  3 18:08:16 2015 pierre jallut
*/

#include "nest.h"
#include "nest_graph.h"
#include "parser.h"

int		main(void)
{
  t_data	data;
  t_1001	**ants;
  t_fourmiz	*nest;

  init_struct(&data);
  if (parsing(&data) == -1)
    {
      my_putstr("False\n");
      return (-1);
    }
  if (!(nest = init_nest(&data)))
    {
      printf("Problème initialisation de la fourmilière (init_nest)\n");
      return (-1);
    }
  if (!(ants = init_ants(nest)))
    return (-1);
    graphic_init(nest, ants);
  return (0);
}
