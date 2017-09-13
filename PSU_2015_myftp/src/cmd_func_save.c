/*
** cmd_func.c for cmd_func in /home/meuric_a/Projet_T2_Test/FTP/include
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue May 10 18:38:55 2016 Alban Meurice
** Last update Thu May 12 12:09:30 2016 Alban Meurice
*/

#include "../inc/ftp.h"
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

t_cmd	*read_cmd(char *msg)
{
  t_cmd	*s_cmd;
  char	*cmd_arg;
  int	i;
  int	i2;

  i = 0;
  i2 = 0;
  if (((cmd_arg = malloc(101 * sizeof(char))) == NULL) ||
      ((s_cmd = malloc(1 * sizeof(t_cmd)))) == NULL)//+1 for \0 ?
    return (NULL);
  s_cmd->arg = NULL;
  write(1, "X1\n", 3);
  while (i != 100 && (msg[i] != '<' && msg[i] != ' '))
    {
      cmd_arg[i2] = msg[i];
      i = i + 1;
      i2 = i2 + 1;
    }
  cmd_arg[i2] = '\0';
  if ((s_cmd->key_cmd = key_cmd_ok(cmd_arg)) == -1)//search table CMD
    return (NULL);

  if (msg[i] != '<')
    while (i != 100 && msg[i] != '<')
      i = i + 1;
  i2 = 0;
  memset(cmd_arg, 0, 101);
  i = i + 1;
  while (i < 100 && msg[i] != '>')
    {
      cmd_arg[i2] = msg[i];
      i = i + 1;
      i2 = i2 + 1;
    }
  cmd_arg[i2] = '\0';
  if (strcmp(cmd_arg, "CRLF\0") == 0)
    return (s_cmd);
  else if (strcmp(cmd_arg, "SP\0") == 0)
    {
      i = i + 1;
      i2 = 0;
      memset(cmd_arg, 0, 101);
      while (i != 100 && msg[i] != '<')
	{
	  cmd_arg[i2] = msg[i];
	  i2 = i2 + 1;
	  i = i + 1;
	}
      cmd_arg[i2] = '\0';
      if ((s_cmd->arg = strdup(cmd_arg)) == NULL || i > 94)
	return (NULL);
      i = i + 1;
      i2 = 0;
      memset(cmd_arg, 0, 101);
      while (i != 100 && msg[i] != '>')
	{
	  cmd_arg[i2] = msg[i];
	  i2 = i2 + 1;
	  i = i + 1;
	}
      cmd_arg[i2] = '\0';
      if (strcmp(cmd_arg, "CRLF\0") != 0)
	return (NULL);
      return (s_cmd);
    }
  return (NULL);
}

#include <stdio.h>

int	key_cmd_ok(char *cmd)
{
  int	count;

  count = 0;
  while (count != NB_CMD)
    {
      if (strcmp(cmd, tab_cmd[count]) == 0)
	{
	  return (count);
	}
      count = count + 1;
    }
  return (-1);
}
