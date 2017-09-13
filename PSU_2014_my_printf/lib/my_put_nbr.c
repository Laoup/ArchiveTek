/*
** my_put_nbr.c for my_put_nbr in /home/meuric_a/rendu_j3
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Oct  2 09:44:23 2014 alban meurice
** Last update Fri Nov 14 23:33:30 2014 alban meurice
*/

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
