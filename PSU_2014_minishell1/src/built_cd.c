/*
** built_cd.c for Minishell1 in /home/meuric_a/Project/Minishell1/V5.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Jan 28 17:39:56 2015 alban meurice
** Last update Wed Jan 28 17:44:02 2015 alban meurice
*/

#include <unistd.h>
#include "minishell.h"
#include "my.h"

int	built_cd(char **line_cmd)
{
  if (my_strcmp(line_cmd[0], "cd") == 0)
    {
      if (chdir(line_cmd[1]) == 0)
	return (0);
    }
  return (1);
}
