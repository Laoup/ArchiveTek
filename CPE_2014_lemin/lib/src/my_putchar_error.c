/*
** my_putchar.c for lib3.0 in /home/meuric_a/Project/push_swap/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Dec 11 22:56:03 2014 alban meurice
** Last update Fri May  1 16:29:06 2015 pierre jallut
*/

#include <unistd.h>
#include "nest.h"

int	my_putchar_error(char c)
{
  if (write(2, &c, 1) != 1)
    return (-1);
  return (0);
}
