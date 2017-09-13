/*
** handle_func.c for handle_func in /home/meuric_a/Projet_T2_Test/FTP/include
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed May 11 14:20:11 2016 Alban Meurice
** Last update Sun May 15 23:30:11 2016 Alban Meurice
*/

#include "../inc/ftp.h"
#include "../inc/my_epurstr.h"
#include <string.h>
#include <unistd.h>

#include <stdio.h>

int	call_function(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  if (cmd->key_cmd == 0)
    return (user_verif(cmd, fd_SockClient, status));
  else if (cmd->key_cmd == 4)
    return (quit(cmd, fd_SockClient, status));
  else if (cmd->key_cmd == 1)
    {
      if (status->info.name_usr != NULL)
	return (pass_verif(cmd, fd_SockClient, status));
      else
	write(fd_SockClient, "503 Login with USER first.\n", 27);
    }
  else if (status->auth == 1) 
    {
      if (cmd->key_cmd == 2)
	return (swap_directory(cmd, fd_SockClient, status));
      else if (cmd->key_cmd == 3)
	return (parent_directory(cmd, fd_SockClient, status));
      else if (cmd->key_cmd == 5)
	return (delete_file(cmd, fd_SockClient, status));
      else if (cmd->key_cmd == 6)
	return (print_directory(cmd, fd_SockClient, status));
      else if (cmd->key_cmd == 7)
	return (do_nothing(cmd, fd_SockClient));
      else if (cmd->key_cmd == 8)
	return (help_function(cmd, fd_SockClient));
      else if (cmd->key_cmd == 9)
	return (passive_mode(cmd, fd_SockClient, status));
      else if (cmd->key_cmd == 10)
	return (download_file(cmd, fd_SockClient, status));
      else if (cmd->key_cmd == 11)
	return (upload_file(cmd, fd_SockClient, status));
      else if (cmd->key_cmd == 12)
	return (list_file(cmd, fd_SockClient, status));
    }
  else
    write(fd_SockClient, "530 Please login with USER and PASS.\n", 37);
  return (-1);
}

int	parent_directory(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  char	*arg;

  if (status->log == 1 && cmd->arg == NULL)
    {
      if (chdir("..") == -1)
	return (-1);
      write(fd_SockClient, "250 Directory successfully changed.\n", 36);
      return (0);
    }
  write(fd_SockClient, "550 Failed to change directory.\n", 32);
  return (-1);
}

int	swap_directory(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  char	*arg;

  if ((arg = my_epurstr(cmd->arg)) == NULL)
    return (-1);
  if (status->log == 1)
    {
      if (chdir(arg) == -1)
	return (-1);
      write(fd_SockClient, "250 Directory successfully changed.\n", 36);
      return (0);
    }
  write(fd_SockClient, "550 Failed to change directory.\n", 32);
  return (-1);
}

int	user_verif(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  char	*arg;

  if (cmd->arg == NULL)
    {
      status->log = 0;
      write(fd_SockClient, "530 Permission denied.\n", 23);
    }
  else
    {
      if ((arg = my_epurstr(cmd->arg)) == NULL)
	return (-1);
      if ((status->info.name_usr = strdup(arg)) == NULL)
	return (-1);
      if (strcmp(arg, "Anonymous\n") == 0 || strcmp(arg, "Anonymous \n") == 0)
	status->log = 1;
      write(fd_SockClient, "331 Please specify the password.\n", 33);
    }
  return (0);
}

int	pass_verif(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  char	*arg;

  if (cmd->arg != NULL)
    if ((arg = my_epurstr(cmd->arg)) == NULL)
      return (-1);
  if (strcmp(arg, "") == 0 || cmd->arg == NULL && status->auth == 0 && status->log == 1)
    {
      status->auth = 1;
      write(fd_SockClient, "230 Login successful.\n", 22);
    }
  else
    {
      status->log = 0;
      write(fd_SockClient, "530 Login incorrect.\n", 21);
      return (-1);
    }
  return (0);
}
