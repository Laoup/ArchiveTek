/*
** gere_path.c for Minishell 1 in /home/meuric_a/Project/Minishell1/V1.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Jan 21 16:38:52 2015 alban meurice
** Last update Wed Jan 21 22:54:00 2015 alban meurice
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"

int	stock_path(t_env **my_path, char *str)
{
  char	*str2;
  int	j;
  int	k;

  j = 0;
  while (str[j] != '\0')
    {
      k = j;
      while ((str[j] != ':') && (str[j] != '\0'))
	j = j + 1;
      if ((str2 = malloc((j + 1) * sizeof(char))) == NULL)
	return (-1);
      j = k;
      k = 0;
      while ((str[j] != ':') && (str[j] != '\0'))
	str2[k++] = str[j++];
      str2[k] = '\0';
      if (add_in_list(my_path, str2) == -1)
	return (-1);
      j = j + 1;
    }
  return (0);
}
