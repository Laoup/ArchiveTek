/*
** my_strlen.c for my_strlen.c in /home/meuric_a/Project/push_swap/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Jan  6 16:47:34 2015 alban meurice
** Last update Wed Mar 11 17:40:37 2015 Alban Meurice
*/

#include "../include/my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    i = i + 1;
  return (i);
}
