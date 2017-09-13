/*
** my_strcpy.c for my_strcpy in /home/jallut_p/git_repos/Piscine/Piscine_C_J06
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Mon Oct  6 09:32:02 2014 pierre jallut
** Last update Tue Apr 28 15:07:29 2015 pierre jallut
*/

#include "nest.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
