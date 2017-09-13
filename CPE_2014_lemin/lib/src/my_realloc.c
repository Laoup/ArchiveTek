/*
** my_realloc.c for Ãmy_realloc in /home/jallut_p/git_repos/Piscine/PSU_2014_minishell1/lib/my
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Sat Jan 31 17:39:05 2015 pierre jallut
** Last update Sun May  3 22:02:12 2015 Arthur Grosso
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "nest.h"

char	**my_realloc_db(char **old, int size)
{
  int	i;
  char	**new;

  i = 0;
  if (!(new = malloc(sizeof(char *) * (my_dblen(old) + size))))
    return (NULL);
  while (old[i])
    {
      if (!(new[i] = malloc(sizeof(char) * (my_strlen(old[i]) + 1))))
	return (0);
      new[i] = my_strcpy(new[i], old[i]);
      free(old[i]);
      i++;
    }
  new[i] = 0;
  return (new);
}

char	*my_realloc(char *old, int size)
{
  int	i;
  char	*new;

  i = 0;
  if (!(new = malloc(sizeof(char) * (my_strlen(old) + size))))
    return (NULL);
  while (old[i])
    {
      new[i] = old[i];
      i++;
    }
  new[i] = 0;
  return (new);
}

