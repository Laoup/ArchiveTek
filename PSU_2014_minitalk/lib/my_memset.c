/*
** my_memset.c for lib in /home/meuric_a/Project/BSQ/V4_NORME/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sun Jan 18 16:57:39 2015 alban meurice
** Last update Thu Mar 19 01:54:53 2015 Alban Meurice
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

void	my_memset_int(int *str, int c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      i = i + 1;
    }
}
