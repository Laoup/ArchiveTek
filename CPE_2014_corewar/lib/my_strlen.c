/*
** my_strlen.c for my_strlen in /home/guzman_y/rendu/Piscine_C_J04
**
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
**
** Started on  Fri Oct  3 23:05:20 2014 yoann guzman
** Last update Mon Mar 30 16:33:33 2015 Moisset Raphael
*/

int	my_strlen(char *str)
{
  int	x;

  x = 0;
  while (str && str[x] != '\0')
    x = x + 1;
  return (x);
}
