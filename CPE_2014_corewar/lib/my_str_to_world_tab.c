/*
** my_str_to_world_tab.c for my_str_to_world_tab in /Users/guzman_y/prog/rendu/systeme_unix/PSU_2014_minishell1/lib
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Sat Jan 24 09:25:28 2015 yoann guzman
** Last update Sat Mar  7 18:30:28 2015 yoann guzman
*/

#include <stdlib.h>
#include "my.h"

char		**fill_str2_1(t_count *count, char *str, char **str2, char flag)
{
  if (str[count->i] == flag)
    {
      if (count->k > 0)
	count->k = count->k + 1;
      if ((str2[count->j] =
	   malloc(sizeof(char) * ((count->i + 1) - count->k))) == NULL)
	{
	  my_put_error("malloc fail in function my_str_to_world_tab", 0);
	  return (NULL);
	}
      while (count->k < count->i)
	str2[count->j][count->l++] = str[count->k++];
      str2[count->j][count->l] = '\0';
      count->j = count->j + 1;
      count->l = 0;
    }
  count->i = count->i + 1;
  return (str2);
}

char		**fill_str2(char **str2, char *str, char flag)
{
  t_count	count;

  count.i = 0;
  count.j = 0;
  count.l = 0;
  count.k = 0;
  while (str[count.i])
    {
      if ((str2 = fill_str2_1(&count, str, str2, flag)) == NULL)
	return (NULL);
    }
  if (count.k > 0)
    count.k = count.k + 1;
  if ((str2[count.j] =
       malloc(sizeof(char) * ((count.i + 1) - count.k))) == NULL)
    {
      my_put_error("malloc fail in function my_str_to_world_tab", 0);
      return (NULL);
    }
  while (count.k < count.i)
    str2[count.j][count.l++] = str[count.k++];
  str2[count.j][count.l] = '\0';
  count.j = count.j + 1;
  str2[count.j] = NULL;
  return (str2);
}

char		**my_str_to_word_tab(char *str, char flag)
{
  char		**str2;
  int		i;
  int		nb_flag;

  nb_flag = 1;
  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i])
    {
      if (str[i] == flag)
	nb_flag = nb_flag + 1;
      i = i + 1;
    }
  if ((str2 = malloc(sizeof(char *) * (nb_flag + 1))) == NULL)
    {
      my_put_error("malloc fail in function my_str_to_world_tab", 0);
      return (NULL);
    }
  if ((str2 = fill_str2(str2, str, flag)) == NULL)
    return (NULL);
  return (str2);
}
