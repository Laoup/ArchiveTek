/*
** my_strdup.c for lib in /home/meuric_a/Project/Minishell1/V5.0/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Jan 27 18:34:37 2015 alban meurice
** Last update Tue Jan 27 18:45:09 2015 alban meurice
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*str;
  int	i;

  i = 0;
  if ((str = malloc((my_strlen(src) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i++;
    }
  return (str);
}
