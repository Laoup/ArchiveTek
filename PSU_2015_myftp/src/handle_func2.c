/*
** handle_func2.c for handle_func in /home/meuric_a/Projet_T2_Test/FTP/include
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed May 11 21:33:26 2016 Alban Meurice
** Last update Sun May 15 23:27:08 2016 Alban Meurice
*/

#include "../inc/ftp.h"
#include "../inc/my_epurstr.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	quit(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  write(fd_SockClient, "221 Goodbye.\n", 13);
  return (1);
}

int	delete_file(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  char	*arg;

  if (status->log == 1)
    {
      if ((arg = my_epurstr(cmd->arg)) == NULL)
	return (-1);
      if (remove(arg) == -1)
	return (-1);
      write(fd_SockClient, "250 Requested file action okay, completed.\n", 43);
      return (0);
    }
  write(fd_SockClient, "550 Permission denied.\n", 23);
  return (-1);
}

int	print_directory(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  char	*str;
  int	size;

  str = NULL;
  size = 1;
  if (status->log == 1 && cmd->arg == NULL)
    {
      if ((str = malloc(size * sizeof(char))) == NULL)
	return (-1);
      while (getcwd(str, size) == NULL)
	{
	  size = size + 1;
	  if ((str = malloc(size * sizeof(char))) == NULL)
	    return (-1);
	}
      write(fd_SockClient, "257 \"", 5);//all in 1 write !!
      write(fd_SockClient, str, strlen(str));
      write(fd_SockClient, "\"\n", 2);
      return (0);
    }
  write(fd_SockClient, "550 Permission denied.\n", 23);
  return (-1);
}

int	do_nothing(t_cmd *cmd, int fd_SockClient)
{
  if (cmd->arg != NULL)    
    {
        write(fd_SockClient, "500 Syntax error, command unrecognized.\n", 40);
      return (-1);
    }
  write(fd_SockClient, "200 Command okay\n", 17);
  return (0);
}

int	help_function(t_cmd *cmd, int fd_SockClient)
{
  return (0);
}