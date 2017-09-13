/*
** data_socket.c for data_socket in /home/meuric_a/Projet_T2_Test/FTP/include
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu May 12 15:33:18 2016 Alban Meurice
** Last update Sun May 15 23:25:18 2016 Alban Meurice
*/

#include "../inc/ftp.h"
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

int			creating_data_socket(t_statserv *status)//!! 29 lines
{
  int			fd_SocketData;
  int			port_DataSocket;
  struct protoent	*proto;
  struct sockaddr_in	si_SockData;
  socklen_t		size_data;

  if ((proto = getprotobyname("TCP")) == NULL)
    return (-1);
  si_SockData.sin_family = AF_INET;
  si_SockData.sin_addr.s_addr = status->si_SockClient.sin_addr.s_addr;//?
  size_data = sizeof(si_SockData);
  if ((fd_SocketData = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      close(fd_SocketData);
      return (-1);
    }
  if (bind(fd_SocketData, (const struct sockaddr *)&si_SockData,
	   size_data) == -1)
    {
      close(fd_SocketData);
      return (-1);
    }
  getsockname(fd_SocketData, (struct sockaddr *)&si_SockData, &size_data);
  status->data.P1 = htons(si_SockData.sin_port) / 256;
  status->data.P2 = htons(si_SockData.sin_port) % 256;
  status->data.si_SockData = si_SockData;
  status->data.ip = inet_ntoa(si_SockData.sin_addr);
  status->data.fd_SocketData = fd_SocketData;
  status->open_pass = 1;
  return (0);
}
