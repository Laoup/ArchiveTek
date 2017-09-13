/*
** my_flags.c for my_flags in /home/meuric_a/Project/my_printf/my_printf
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Nov 13 01:38:33 2014 alban meurice
** Last update Sat Nov 15 02:19:46 2014 alban meurice
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

void	flag_d(va_list ap)
{
  int	nb;

  nb = va_arg(ap, int);
  my_put_nbr(nb);
}

void	flag_c(va_list ap)
{
  char	c;

  c = va_arg(ap, int);
  my_putchar(c);
}

void	flag_s(va_list ap)
{
  char	*s;

  s = va_arg(ap, char *);
  my_putstr(s);
}

void	flag_p(va_list ap)
{
  int	p;

  p = va_arg(ap, int);
  my_put_nbr(p);
}

void	flag_B(va_list ap)
{
  int	B;

  B = va_arg(ap, int);
  if (B == 0)
    my_putstr("true");
  else if (B == 1)
    my_putstr("false");
  else
    my_putstr("error");    
}
