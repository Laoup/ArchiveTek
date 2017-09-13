/*
** handle_func3.c for handle_func3 in /home/meuric_a/Projet_T2_Test/FTP/include
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu May 12 15:25:37 2016 Alban Meurice
** Last update Sun May 15 23:28:26 2016 Alban Meurice
*/

#include "../inc/ftp.h"
#include "../inc/my_epurstr.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

int	upload_file(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  char	*buff;
  char	*arg;
  int	fd;

  if (status->open_pass == 1)
    {
      write(fd_SockClient, "150 File status okay.\n", 22);
      if (cmd->arg != NULL)
	{
	  if ((arg = my_epurstr(cmd->arg)) == NULL)
	    return (-1);
	  if ((buff = get_file(status)) == NULL)
	    return (-1);
	  if ((fd = open(arg, O_WRONLY)) == -1)
	    return (-1);
	  write(fd, buff, strlen(buff));
	  write(fd_SockClient, "226 Closing data connection.\n", 29);
	  close(fd);
	  close(status->data.fd_SocketData);
	  status->open_pass = 0;
	  return (0);
	}
      write(fd_SockClient, "500 Syntax error, command unrecognized.\n", 40);
      return (-1);
    }
  write(fd_SockClient, "425 Use PORT or PASV first.\n", 28);
  return (-1);
}

int	list_file(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  struct diren_t	*dir;
  DIR			*rep;
  char			*current;

  if (status->open_pass == 1)
    {
      write(fd_SockClient, "150 File status okay.\n", 22);
      if (read_all_files(cmd->arg, fd_SockClient) == -1)
	return (-1);
      write(fd_SockClient, "226 Closing data connection.\n", 29);
      close(status->data.fd_SocketData);
      status->open_pass = 0;
      return (0);
    }
  write(fd_SockClient, "425 Use PORT or PASV first.\n", 28);
  return (-1);
}
