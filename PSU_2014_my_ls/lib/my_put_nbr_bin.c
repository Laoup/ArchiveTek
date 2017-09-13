/*
** my_put_nbrbin.c for my_printf in /home/meuric_a/re_code
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Nov  3 21:18:17 2014 alban meurice
** Last update Fri Nov 14 15:04:21 2014 alban meurice
*/

int	my_putnbr_bin(int nb)
{
  int	d;
  
  d = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  while (nb / d >= 2)
    {
      d = d * 2;
    }
  while (d > 0)
    {
      my_putchar(nb / d % 2 + 48);
      d = d / 2;
    }
  return (0);
}
