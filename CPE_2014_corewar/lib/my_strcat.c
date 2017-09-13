/*
** my_strcat.c for my_strcat in /home/guzman_y/rendu/Piscine_C_J07/ex_01
**
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
**
** Started on  Wed Oct  8 16:20:02 2014 yoann guzman
** Last update Sun Apr 12 22:19:26 2015 Moisset Raphael
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(dest);
  while (src[j])
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}
