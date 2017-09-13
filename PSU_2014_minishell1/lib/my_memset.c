/*
** my_memset.c for lib in /home/meuric_a/Project/BSQ/V4_NORME/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sun Jan 18 16:57:39 2015 alban meurice
** Last update Sun Jan 18 18:00:06 2015 alban meurice
*/

#include "../include/my.h"

void	my_memset(char *str, char c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      i = i + 1;
    }
}
