/*
** conv_list_tab.c for Minishell1 in /home/meuric_a/Project/Minishell1/V5.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Jan 27 17:59:43 2015 alban meurice
** Last update Tue Jan 27 18:50:42 2015 alban meurice
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"

char	**conv_list_tab(t_env **my_env)
{
  t_env	*tmp;
  char	**env;
  int	lenght;
  int	x;

  tmp = (*my_env);
  lenght = 0;
  x = 0;
  while (tmp != NULL)
    {
      lenght = lenght + 1;
      tmp = tmp->next;
    }
  env = ver_maloc("malloc fail\n", malloc((lenght + 1) * sizeof(char)));
  while ((*my_env) != NULL)
    {
      env[x++] = my_strdup((*my_env)->str);
      (*my_env) = (*my_env)->next;
    }
  env[x] = NULL;
  return (env);
}
