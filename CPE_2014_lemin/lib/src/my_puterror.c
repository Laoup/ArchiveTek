/*
** my_putstr.c for lib3.0 in /home/meuric_a/Project/push_swap/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Dec 12 14:42:23 2014 alban meurice
** Last update Fri May  1 16:28:56 2015 pierre jallut
*/

#include "nest.h"

int	my_puterror(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_putchar_error(str[i]) == -1)
	return (-1);
      i = i + 1;
    }
  return (0);
}
