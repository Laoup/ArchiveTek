/*
** my_putnbr.c for lib3.0 in /home/meuric_a/Ressources/lib3.O
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Dec 11 13:58:01 2014 alban meurice
** Last update Sat Jan 10 23:56:07 2015 alban meurice
*/

#include "../include/my.h"

int	my_put_nbr(int nb)
{
  int	d;

  d = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  while (nb / d > 9)
    {
      d = d * 10;
    }
  while (d > 0)
    {
      my_putchar((nb / d) % 10 + 48);
      d = d / 10;
    }
  return (0);
}
