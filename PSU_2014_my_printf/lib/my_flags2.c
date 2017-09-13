/*
** my_flags2.c for Project my_printf in /home/meuric_a/my_printf
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Nov 14 22:48:52 2014 alban meurice
** Last update Sat Nov 15 02:20:23 2014 alban meurice
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

void	flag_b(va_list ap)
{
  int	nb;

  nb = va_arg(ap, int);
  my_putnbr_bin(nb);
}

void	flag_x(va_list ap)
{
  int	nb;

  nb = va_arg(ap, int);
  my_putnbr_hexa(nb);
}

void	flag_o(va_list ap)
{
  int	nb;

  nb = va_arg(ap, int);
  my_putnbr_octal(nb);
}

void	flag_S(va_list ap)
{
  char	*str;
  int	i;

  i = 0;
  str = va_arg(ap, char *);
  if (str == NULL)
    my_putstr("error");
  while (str[i] != '\0')
    {
      if (str[i] >= 32 && str[i] < 127)
	my_putchar(str[i]);
      else
	{
	  my_putchar('\\');
	  my_putnbr_octal(str[i]);
	}
      i = i + 1;
    }
}
