/*
** my_put_nbr.c for my_put_nbr in /home/guzman_y/test_rendu
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Thu Oct  2 23:37:06 2014 yoann guzman
** Last update Wed Jan 21 23:09:12 2015 yoann guzman
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  long	nb_bis;

  nb_bis = nb;
  if (nb_bis < 0)
    {
      my_putchar('-');
      nb_bis = nb_bis * (-1);
    }
  if (nb_bis > 9)
    my_put_nbr(nb_bis / 10);
  my_putchar(nb_bis % 10 + '0');
  return (0);
}

int	my_put_nbr_color(int nb, char *COLOR)
{
  long	nb_bis;

  nb_bis = nb;
  if (nb_bis < 0)
    {
      my_putchar_color('-', COLOR);
      nb_bis = nb_bis * (-1);
    }
  if (nb_bis > 9)
    my_put_nbr_color(nb_bis / 10, COLOR);
  my_putchar_color(nb_bis % 10 + '0', COLOR);
  return (0);
}
