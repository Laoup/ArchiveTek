/*
** my_put_nbr.c for my_put_nbr in /home/jallut_p/git_repos/Piscine/Piscine_C_J07/lib/my
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Wed Oct  8 19:04:05 2014 pierre jallut
** Last update Wed Apr 22 14:09:57 2015 pierre jallut
*/

#include "nest.h"

void	my_putnbr(int nb)
{
  int   result;
  int   diviseur;

  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
        {
          my_putchar('-');
          nb = -nb;
        }
      diviseur = 1;
      while ((nb / diviseur) >= 10)
        diviseur = diviseur * 10;
      while (diviseur > 0)
        {
          result = (nb /diviseur) % 10;
          my_putchar(48 + result);
          diviseur = diviseur / 10;
        }
    }
}
