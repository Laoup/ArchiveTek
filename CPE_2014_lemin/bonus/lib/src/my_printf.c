/*
** my_printf.c for my_printf in /home/jallut_p/git_repos/Piscine/PSU_2014_my_select/lib/my
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Wed Dec 17 07:45:02 2014 pierre jallut
** Last update Wed Apr 22 14:10:10 2015 pierre jallut
*/

#include <stdarg.h>
#include "nest.h"

void		my_printf(char *str, ...)
{
  int		i;
  va_list	va;

  va_start(va, str);
  i = -1;
  while (str[++i])
    if (str[i] == '%')
      {
	i++;
	if (str[i] == 's')
	  my_putstr(va_arg(va, char *));
	else if (str[i] == 'd')
	  my_putnbr(va_arg(va, int));
	else if (str[i] == 'c')
	  my_putchar(va_arg(va, int));
      }
    else
      my_putchar(str[i]);
  va_end(va);
}

