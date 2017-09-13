/*
** main.c for corewar in /home/guzman_y/test_corewar/srcs
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Tue Mar 31 15:27:50 2015 yoann guzman
** Last update Sun Apr 12 23:04:52 2015 yoann guzman
*/

#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "my.h"

void		display(int x, header_t *tab)
{
  my_putstr_color("PLAYER ", GREEN);
  my_put_nbr_color(x, BLUE);
  my_putstr_color(" :\n", BLUE);
  my_putstr_color("MAGIC NUMBER : ", GREEN);
  my_put_nbr_color(tab[x - 1].magic, BLUE);
  my_putchar('\n');
  my_putstr_color("NAME : ", GREEN);
  my_putstr_color(tab[x - 1].prog_name, BLUE);
  my_putchar('\n');
  my_putstr_color("PROG SIZE : ", GREEN);
  my_put_nbr_color(tab[x - 1].prog_size, BLUE);
  my_putchar('\n');
  my_putstr_color("COMMENT : ", GREEN);
  my_putstr_color(tab[x - 1].comment, BLUE);
  my_putchar('\n');
  my_putchar('\n');
}

int		main(int ac, char **av)
{
  header_t	*tab;
  int		x;

  x = 1;
  if (check_arg(ac, av) == -1)
    return (1);
  if ((tab = malloc(sizeof(header_t) * ac - 1)) == NULL)
    return (my_put_error("Can't perform malloc", 1));
  if (fill_my_struct_player(ac, av, tab) == -1)
    return (1);
  while (av[x])
    {
      display(x, tab);
      ++x;
    }
  return (0);
}
