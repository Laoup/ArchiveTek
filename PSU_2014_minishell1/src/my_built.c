/*
** my_built.c for Minishell1 in /home/meuric_a/Project/Minishell1/V5.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Jan 27 17:42:02 2015 alban meurice
** Last update Fri Jan 30 18:35:42 2015 alban meurice
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

void	built_exit(char **line_cmd)
{
  int	i;

  i = 0;
  if (my_strcmp(line_cmd[0], "exit") == 0)
    {
      while (line_cmd[i] != NULL)
	{
	  free(line_cmd[i]);
	  i = i + 1;
	}
      exit(0);
    }
}

int	built_env(char *str, t_env **my_env)
{
  if (my_strcmp(str, "env") == 0)
    {
      my_show_list(*my_env);
      return (0);
    }
  return (1);
}

int	built_setenv(char **line_cmd, t_env **my_env)
{
  if (my_strcmp(line_cmd[0], "setenv") == 0 && line_cmd[1] != NULL)
    {
      add_in_list(my_env, line_cmd[1]);
      return (0);
    }
  return (1);
}

int	my_built(char **line_cmd, t_env **my_env)
{
  built_exit(line_cmd);
  if (built_env(line_cmd[0], my_env) == 0)
    return (0);
  if (built_setenv(line_cmd, my_env) == 0)
    return (0);
  if (built_cd(line_cmd) == 0)
    return (0);
  return (-1);
}
