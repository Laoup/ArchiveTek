/*
** my_putnbr_base.c for my_putnbr_base in /home/guzman_y/lib
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Sat Nov  1 20:06:22 2014 yoann guzman
** Last update Sun Feb 22 21:32:45 2015 yoann guzman
*/

#include "my.h"

int	my_putnbr_base(int nb, char *base)
{
  int	p;
  int	base_1;

  base_1 = my_strlen(base);
  p = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  while (nb / p >= base_1)
    {
      p = p * base_1;
    }
  while (p > 0)
    {
      my_putchar(base[((nb/ p) % base_1)]);
      p = p / base_1;
    }
  return (0);
}
