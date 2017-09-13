/*
** my_epur_str.c for my_epur_str in /Users/guzman_y/prog/rendu/systeme_unix/PSU_2014_minishell1/lib
**
** Made by yoann guzman
** Login   <guzman_y@epitech.eu>
**
** Started on  Tue Jan 27 05:40:55 2015 yoann guzman
** Last update Sun Apr 12 22:16:55 2015 Moisset Raphael
*/

#include <stdlib.h>
#include "my.h"

char	*my_epur_str_2(char *str, t_count *count, char *str2)
{
  while (str[count->i])
    {
      str2[count->j] = str[count->i];
      if (str[count->i] == ' ' && str[count->i])
	{
	  count->k = count->i;
	  while (str[count->k] == ' ')
	    {
	      count->k++;
	      if (str[count->k] == '\0')
		return (str2);
	    }
	  while (str[count->i] == ' ' && str[count->i])
	    count->i++;
	  count->i--;
	}
      count->i++;
      count->j++;
    }
  return (str2);
}

char	*my_epur_str_1(char *str, t_count count, int nb_word, int nb_space)
{
  char	*str2;

  if ((str2 = malloc(sizeof(char) *
		     (my_strlen(str) - nb_space + nb_word))) == NULL)
    {
      my_put_error("malloc fail in function epur_str", 0);
      return (NULL);
    }
  count.i = 0;
  count.j = 0;
  while (str[count.i] && str[count.i] == ' ')
    count.i++;
  str2 = my_epur_str_2(str, &count, str2);
  str2[count.j] = '\0';
  return (str2);
}

char		*my_epur_str(char *str)
{
  t_count	count;
  int		nb_word;
  int		nb_space;

  nb_space = 0;
  count.i = 0;
  nb_word = 0;
  while (str[count.i])
    {
      if (str[count.i] != ' ')
	nb_word++;
      while (str[count.i] != ' ' && str[count.i])
	  count.i++;
      count.i++;
    }
  count.i = 0;
  while (str[count.i])
    {
      if (str[count.i] == ' ')
	nb_space++;
      count.i++;
    }
  if ((str = my_epur_str_1(str, count, nb_word, nb_space)) == NULL)
    return (NULL);
  return (str);
}
