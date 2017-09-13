/*
** my_strcmp.c for lib in /home/meuric_a/Project/Minishell1/V5.0/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Jan 27 17:20:38 2015 alban meurice
** Last update Wed Jan 28 18:56:37 2015 alban meurice
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) == my_strlen(s2))
    {
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
  return (-1);
}
