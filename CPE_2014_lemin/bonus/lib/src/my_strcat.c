/*
** my_strcat.c for my_strcat.c in /home/meuric_a/Project/Minishell2/V3.0/lib
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Mar  3 01:45:08 2015 Alban Meurice
** Last update Sun May  3 21:41:43 2015 Arthur Grosso
*/

#include <stdlib.h>
#include "nest.h"

char	*my_strcat(char *dest, char *src)
{
  char	*str;
  int	i;
  int	i2;

  i = 0;
  if ((str = malloc(my_strlen(dest) + my_strlen(src) + 2
		   * sizeof(char))) == NULL)
    return (NULL);
  while (dest[i] != '\0')
    {
      str[i] = dest[i];
      i = i + 1;
    }
  i2 = 0;
  while (src[i2] != '\0')
    str[i++] = src[i2++];
  str[i] = '\0';
  return (str);
}
