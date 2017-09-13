/*
** check1.c for corwar in /home/guzman_y/test_corewar/srcs
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Tue Mar 31 15:27:33 2015 yoann guzman
** Last update Tue Mar 31 16:18:52 2015 yoann guzman
*/

#include "my.h"

int	check_extension(char **av)
{
  int	i;
  int	j;

  i = 1;
  while (av[i])
    {
      j = 0;
      while (av[i][j])
	j++;
      j--;
      if (av[i][j] != 'r' || av[i][j - 1] != 'o'
	  || av[i][j - 2] != 'c' || av[i][j - 3] != '.')
	return (-1);
      i++;
    }
  return (0);
}

int	check_arg(int ac, char **av)
{
  if (ac < 2 || ac > 5)
    return (my_put_error("Usage:./corewar prog_name.cor(Min 1 - Max 4)\n", -1));
  if (check_extension(av) == -1)
    return (my_put_error("Usage:./corewar prog_name.cor(Min 1 - Max 4)\n", -1));
  return (0);
}
