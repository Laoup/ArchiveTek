/*
** my_putchar.c for my_putchar in /home/guzman_y/rendu/Piscine_C_J11/lib/my
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Mon Oct 20 18:29:33 2014 yoann guzman
** Last update Wed Jan 21 00:56:34 2015 yoann guzman
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

void	my_putchar_color(char c, char *COLOR)
{
  my_putstr(COLOR);
  my_putchar(c);
  my_putstr(END);
}
