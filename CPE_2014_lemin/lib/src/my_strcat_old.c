/*
** my_strcat.c for my_strcat in /home/jallut_p/git_repos/Piscine/Piscine_C_J07
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Tue Oct  7 10:50:53 2014 pierre jallut
** Last update Fri May  1 18:27:21 2015 pierre jallut
*/

#include "nest.h"

char	*my_strcat2(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i++;
  while (src[j] != '\0')
    {
      dest[i + j] = src[j];
      j++;
    }
  dest[i + j] = '\0';
  return (dest);
}
