/*
** my_get_env.c for my_get_env in /Users/guzman_y/prog/rendu/projet/systeme Unix/PSU_2014_my_select/lib
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Wed Jan  7 01:24:22 2015 yoann guzman
** Last update Wed Jan  7 03:23:31 2015 yoann guzman
*/

#include <stdlib.h>
#include "my.h"

char	*my_get_env(char *name, char *env[])
{
  int	i;

  i = 0;
  while (env[i])
    {
      if (!my_strncmp(name, env[i], my_strlen(name)))
	if (env[i][my_strlen(name)] == '=')
	  return (env[i] + my_strlen(name) + 1);
      i = i + 1;
    }
  return (NULL);
}
