/*
** main.c for my_getenv.c in /home/meuric_a/Entrainement/Variables_Env/my_getenv
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Jan  6 10:12:52 2015 alban meurice
** Last update Sun Jan 11 13:34:36 2015 alban meurice
*/

#include <stdlib.h>
#include "../include/my_select.h"
#include "../include/my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] > s2[i])
	return (-1);
      else if (s1[i] < s2[i])
	return (-1);
      else
	  i = i + 1;
    }
  return (0);
}

char	*my_realloc(char *str, char add_str)
{
  char	*new;
  int	i;

  i = 0;
  if (str == NULL)
    {
      if ((new = malloc(sizeof(char) * 2)) == NULL)
	return (NULL);
      new[0] = add_str;
      new[1] = '\0';
      return (new);
    }
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (i < my_strlen(str))
    {
      new[i] = str[i];
      i = i + 1;
    }
  free(str);
  new[i] = add_str;
  new[i + 1] = '\0';
  return (new);
}

int	search_variable(char *str, char **env)
{
  char	*var;
  int	size;
  int	x;
  int	i;

  x = 0;
  size = my_strlen(str);
  while (env[x] != NULL)
    {
      i = 1;
      if ((var = malloc(size * sizeof(char))) == NULL)
	return (-1);
      var[0] = env[x][0];
      while ((my_strcmp(var, str) == 0) && (i != size))
	var = my_realloc(var, env[x][i++]);
      if ((my_strcmp(var, str) == 0) && (i == size))
	{
	  free(var);
	  return (x);
	}
      x = x + 1;
    }
  return (-1);
}

char	*my_getenv(char *str, char **env)
{
  char	*var;
  int	size;
  int	i;
  int	j;
  int	x;

  i = 0;
  j = 0;
  x = search_variable(str, env);
  while (env[x][i] != '=')
    i = i + 1;
  i = i + 1;														     
  size = my_strlen(env[x]);
  if ((var = malloc(sizeof(char) * ((size - i) + 1))) == NULL)
    return (NULL);
  while (i <= size)
    {
      var[j] = env[x][i];
      i = i + 1;
      j = j + 1;
    }
  return (var);
}
