/*
** my_strcat.c for my_strcat.c in /home/meuric_a/Project/Minishell2/V3.0/lib
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Mar  3 01:45:08 2015 Alban Meurice
** Last update Fri Mar 13 22:30:08 2015 Alban Meurice
*/

#include <my.h>
#include <stdlib.h>

char	*my_strcat_spe(char *dest, char *src)
{
  char	*str;
  int	i;
  int	i2;

  i = 0;
  if (dest == NULL)
    {
      dest = src;
      return (dest);
    }
  if ((str = malloc(my_strlen(dest) + my_strlen(src) + 3 
		   * sizeof(char))) == NULL)
    return (NULL);
  while (dest[i] != '\0')
    {
      str[i] = dest[i];
      i = i + 1;
    }
  str[i++] = '\n';
  i2 = 0;
  while (src[i2] != '\0')
    str[i++] = src[i2++];
  str[i] = '\0';
  return (str);
}
