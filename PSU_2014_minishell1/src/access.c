/*
** access.c for Minishell in /home/meuric_a/Project/Minishell1/V2.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jan 23 08:24:07 2015 alban meurice
** Last update Fri Jan 30 17:41:33 2015 alban meurice
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "my.h"

char	*my_strcat_path(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  j = 0;
  if ((str = malloc((my_strlen(dest) + my_strlen(src)) + 2*
		    sizeof(char))) == NULL)
    return (NULL);
  my_memset(str, 0, (my_strlen(dest) + my_strlen(src) + 2));
  while (i < my_strlen(dest))
    str[j++] = dest[i++];
  i = 0;
  str[j++] = '/';
  while (src[i] == ' ')
    i++;
  while (i < my_strlen(src))
    str[j++] = src[i++];
  str[j] = '\0';
  return (str);
}

char	*my_test_path(char *buffer, t_env *my_path)
{
  t_env	*tmp;
  char	*cmd;

  tmp = my_path;
  if ((buffer == NULL) || (tmp == NULL))
    return (NULL);
  while (tmp->next != NULL)
    {
      cmd = my_strcat_path(tmp->str, buffer);
      if (access(cmd, F_OK | X_OK) == 0)
	return (cmd);
      tmp = tmp->next;
    }
  return (NULL);
}
