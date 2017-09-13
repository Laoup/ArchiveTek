/*
** my_putstr.c for my_putstr in /home/guzman_y/rendu/Piscine_C_J04
**
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
**
** Started on  Fri Oct  3 20:44:43 2014 yoann guzman
** Last update Sun Apr 12 21:48:33 2015 Moisset Raphael
*/

#include <unistd.h>
#include "my.h"

char	my_putstr(char *str)
{
  int	x;

  x = 0;
  while (str && str[x] != '\0')
    {
      my_putchar(str[x]);
      x = x + 1;
    }
  return (0);
}

int	my_put_error(char *str, int return_value)
{
  int	x;

  x = 0;
  while (str[x])
    {
      my_putchar_error(str[x]);
      x = x + 1;
    }
  return (return_value);
}

void	*my_put_error_null(char *str)
{
  int	x;

  x = 0;
  while (str[x])
    {
      my_putchar_error(str[x]);
      x = x + 1;
    }
  return (NULL);
}

void	my_putstr_color(char *str, char *COLOR)
{
  my_putstr(COLOR);
  my_putstr(str);
  my_putstr(END);
}
