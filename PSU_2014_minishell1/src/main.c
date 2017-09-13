/*
** main.c for Minishell 1 in /home/meuric_a/Project/Minishell1/V1.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Jan 20 23:40:45 2015 alban meurice
** Last update Fri Jan 30 19:20:48 2015 alban meurice
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"
#include "my.h"
#include "get_next_line.h"
#include "my_str_to_word_tab.h"
#include "my_epurstr.h"
#include "my_conv_list_tab.h"

int	func_fork(char *path, char **line_cmd, char **env)
{
  int	a;
  pid_t	status;

  if ((a = fork()) == -1)
    my_putstr("fork failled\n");
  if (a == 0)
    {
      if (execve(path, line_cmd, env) == -1)
	exit(-1);
    }
  else
    {
      wait(&status);
      if (WEXITSTATUS(status) != 0)
	return (-1);
      return (0);
    }
  return (-1);
}

void	catch_ctrl_c(int a)
{
  (void)a;
  my_putstr("\n$>");
}

int	minishell(t_env *my_env, t_env *my_path, char **env)
{
  char	**line_cmd;
  char	*buffer;
  char	*path;

  while (43)
    {
      signal(SIGINT, &catch_ctrl_c);
      my_putstr("$>");
      if ((buffer = get_next_line(0)) == NULL)
	return (-1);
      buffer = my_epurstr(buffer);
      if ((line_cmd = my_str_to_word_tab(buffer)) != NULL)
	{
	  free(buffer);
	  if (line_cmd[0][0] != '\0')
	    if (my_built(line_cmd, &my_env) != 0)
	      {
		if ((path = my_test_path(line_cmd[0], my_path)) != NULL)
		  func_fork(path, line_cmd, conv_list_tab(&my_env));
		else
		  my_putstr("La commande demandée n'existe pas\n");
	      }
	}
    }
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  char	*str;
  t_env	*my_env;
  t_env	*my_path;

  my_env = NULL;
  my_path = NULL;
  if ((str = my_getenv("PATH", env)) == NULL)
    {
      if (copy_env(&my_env, env) == -1)
	return (-1);
      minishell(my_env, my_path, env);
    }
  if (copy_env(&my_env, env) == -1)
    return (-1);
  if (stock_path(&my_path, str) == -1)
    return (-1);
  minishell(my_env, my_path, env);
  return (0);
}
