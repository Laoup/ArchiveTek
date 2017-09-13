/*
** my_printf.c for my_printf in /home/meuric_a/my_printf
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Nov 13 01:23:26 2014 alban meurice
** Last update Sat Nov 15 02:17:50 2014 alban meurice
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

static const	t_tab	tab_flags[] =
  {
    {'d', &flag_d},
    {'c', &flag_c},
    {'s', &flag_s},
    {'p', &flag_p},
    {'B', &flag_B},
    {'b', &flag_b},
    {'x', &flag_x},
    {'o', &flag_o},
    {'S', &flag_S},
    {0, NULL}
  };

int		my_printf(const char *fmt, ...)
{
  int		i;
  int		j;
  va_list	ap;

  va_start(ap, fmt);
  i = 0;
  if (fmt == NULL)
    return (0);
  while (fmt[i])
    {
      j = 0;
      if (fmt[i] == '%')
	{
	  ++i;
	  while (fmt[i] != tab_flags[j].flag)
	    ++j;
	  tab_flags[j].fct(ap);
	}
      else
	my_putchar(fmt[i]);
      ++i;
    }
  va_end(ap);
  return (0);
}
