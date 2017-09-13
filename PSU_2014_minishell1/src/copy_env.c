/*
** copy_env.c for Minishell1 in /home/meuric_a/Project/Minishell1/V1.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Jan 21 12:09:10 2015 alban meurice
** Last update Wed Jan 21 16:37:13 2015 alban meurice
*/

#include <stdlib.h>
#include "minishell.h"

int	copy_env(t_env **my_env, char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    if (add_in_list(my_env, env[i++]) == -1)
      return (-1);
  return (0);
}
