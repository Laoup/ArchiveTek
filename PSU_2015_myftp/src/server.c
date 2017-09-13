/*
** server.c for server in /home/meuric_a/Projet_T2_Test/FTP/include
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue May 10 14:33:07 2016 Alban Meurice
** Last update Sun May 15 23:31:02 2016 Alban Meurice
*/

#include "../inc/ftp.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>

int			server(int port)
{
  int			fd_SockServ;
  struct protoent	*proto;
  struct sockaddr_in	si_SockServ;

  char			*rep;

  if ((proto = getprotobyname("TCP")) == NULL)
    return (-1);
  si_SockServ.sin_family = AF_INET;
  si_SockServ.sin_port = htons(port);
  si_SockServ.sin_addr.s_addr = INADDR_ANY;

  if (init_SockServ(&fd_SockServ, &si_SockServ) == -1)
    return (-1);
  
  while (42)
    {
      if (loop_Serv(fd_SockServ, port) == -1)
	return (-1);
    }
}

int			loop_Serv(int fd_SockServ, int port)
{
  int			fd_SockClient;
  t_statserv		status;
  struct sockaddr_in	si_SockClient;
  socklen_t		size_SockClient;

  int			pid;
  t_cmd			*cmd;
  char			*msg;

  init_status(&status);
  size_SockClient = sizeof(si_SockClient);
  if ((fd_SockClient = accept(fd_SockServ, (struct sockaddr *)&si_SockClient,
			      &size_SockClient)) == -1)
    {
      close(fd_SockClient);
      return(-1);
    }
  if ((pid = fork()) == -1)
    {
      close(fd_SockClient);
      return(-1);
    }
  if (pid == 0)
    {
      write(fd_SockClient, "220 Connection Establishment\n", 29);
      status.si_SockClient = si_SockClient;
      while (42)
	{
	  if ((msg = malloc(100 * sizeof(char))) == NULL ||
	      read(fd_SockClient, msg, 100) == -1)
	    {
	      close(fd_SockClient);
	      return (-1);
	    }
	  if ((cmd = read_cmd(msg)) == NULL)
	    write(fd_SockClient, "\n",1);
	  if (call_function(cmd, fd_SockClient, &status) == 1)
	    {
	      shutdown(fd_SockClient, SHUT_RDWR);
	      shutdown(fd_SockServ, SHUT_RDWR);
	      close(fd_SockClient);
	      close(fd_SockServ);
	      return (-1);
	    }
	}
    }
  return (0);
}

int			init_SockServ(int *fd_SockServ, struct sockaddr_in *si_SockServ)
{
  if ((*fd_SockServ = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      close(*fd_SockServ);
      return (-1);
    }
  if (bind(*fd_SockServ, (const struct sockaddr *)si_SockServ,
	   sizeof(*si_SockServ)) == -1)
    {
      close(*fd_SockServ);
      return (-1);
    }
  if (listen(*fd_SockServ, 10) == -1)
    {
      close(*fd_SockServ);
      return (-1);
    }
  return (0);
}

void			init_status(t_statserv *status)
{
  status->log = 0;
  status->auth = 0;
  status->info.name_usr = NULL;
  status->info.passwd_usr = NULL;
}
