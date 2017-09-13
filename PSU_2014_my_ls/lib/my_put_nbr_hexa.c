/*
** my_put_nbrbase.c for my_put_nbr_base in /home/meuric_a/re_code
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Nov  3 21:18:17 2014 alban meurice
** Last update Fri Nov 14 16:28:07 2014 alban meurice
*/

int	my_putnbr_hexa(int nb)
{
  int	d;
  char	base[] = "0123456789ABCDEF";

  d = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  while (nb / d >= 16)
    {
      d = d * 16;
    }
  while (d > 0)
    {
      my_putchar(base[nb / d % 16]);
      d = d / 16;
    }
  return (0);
}
