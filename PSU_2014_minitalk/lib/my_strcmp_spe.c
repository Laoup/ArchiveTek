/*
** my_strcmp_spe.c for Minishell2 in /home/meuric_a/Project/Minishell2/V3.0/lib
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Mar  3 16:36:03 2015 Alban Meurice
** Last update Thu Mar  5 16:00:11 2015 Alban Meurice
*/

#include "my.h"
#include <stdlib.h>

int	my_strlen_spe(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '=')
    {
      if (str[i] == '\0')
	return (-1);
      i = i + 1;
    }
  return (i);
}

char	*malloc_strcmp_spe(char *s1)
{
  char	*search_str;
  int	i;
  int	size;

  i = 0;
  if ((size = my_strlen_spe(s1)) == -1)
    return (NULL);
  if ((search_str = malloc(size + 1 * sizeof(char))) == NULL)
    return(NULL);
  while (i != size)
    {
      search_str[i] = s1[i];
      i = i + 1;
    }
  search_str[i] = '\0';
  return (search_str);
}

int	my_strcmp_spe(char *s1, char *s2)
{
  char	*search_str;
  int	i;

  i = 0;
  if ((search_str = malloc_strcmp_spe(s1)) == NULL)
    return (-1);
  if (my_strlen(search_str) == (my_strlen(s2) - 1))
    {
      while (search_str[i] && s2[i])
	{
	  if ((search_str[i] > s2[i]) || (search_str[i] < s2[i]))
	    return (-1);
	  else
	    i = i + 1;
	}
      return (0);
    }
  return (-1);
}
