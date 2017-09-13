/*
** my_conv_bin.c for Minitalk client in /home/meuric_a/Project/Minitalk/V1.0/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Mar 17 22:09:54 2015 Alban Meurice
** Last update Thu Mar 19 01:56:27 2015 Alban Meurice
*/

#include <stdlib.h>
#include "my.h"
#include "minitalk.h"

int	*conv_bin(char letter)
{
  int	i;
  int	*my_bin;
  int	res;

  if ((my_bin = malloc(8 * sizeof(int))) == NULL)
    return (NULL);
  my_memset_int(my_bin, 0, 8);
  i = 0;
  while (letter != 0)
    {
      res = letter % 2;
      letter = letter / 2; 
      my_bin[i] = res;
      i = i + 1;
    }
  if (i != 7)
    while (i <= 7)
      {
	my_bin[i] = 0;
	i = i + 1;
      }
  return (my_bin);
}
