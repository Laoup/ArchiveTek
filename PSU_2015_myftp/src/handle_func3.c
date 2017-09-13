/*
** handle_func3.c for handle_func3 in /home/meuric_a/Projet_T2_Test/FTP/include
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu May 12 15:25:37 2016 Alban Meurice
** Last update Sun May 15 23:28:04 2016 Alban Meurice
*/

#include "../inc/ftp.h"
#include "../inc/my_epurstr.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

int	download_file(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  char	*buff;
  char	*arg;
  int	size;

  if (status->open_pass == 1)
    {
      write(fd_SockClient, "150 File status okay.\n", 22);
      if (cmd->arg != NULL)
	{
	  if ((arg = my_epurstr(cmd->arg)) == NULL)
	    return (-1);
	  if ((size = size_file(arg)) == -1)
	    return (-1);
	  if ((buff = read_file(size, arg)) == NULL)
	    return (-1);
	  //write(status->data.fd_SocketData, buff, strlen(buff));
	  write(fd_SockClient, "226 Closing data connection.\n", 29);
	  close(status->data.fd_SocketData);//close the data socket
	  status->open_pass = 0;//close the data socket
	  return (0);
	}
      write(fd_SockClient, "500 Syntax error, command unrecognized.\n", 40);
      return (-1);
    }
  write(fd_SockClient, "425 Use PORT or PASV first.\n", 28);
  return (-1);
}

int	passive_mode(t_cmd *cmd, int fd_SockClient, t_statserv *status)
{
  char	*ip_msg;
  char	*port_msg;

  if (cmd->arg == NULL)
    {
      if (creating_data_socket(status) == -1)
	return (-1);
      if ((ip_msg = convert_ip(status->data.ip)) == NULL)
	return (-1);
      if ((port_msg = convert_port(status->data.P1,
				   status->data.P2)) == NULL)
	return (-1);
      write(fd_SockClient, "227 Entering Passive Mode (", 27);//all in 1 write!!
      write(fd_SockClient, ip_msg, strlen(ip_msg));
      write(fd_SockClient, ",", 1);
      write(fd_SockClient, port_msg, strlen(port_msg));
      write(fd_SockClient, ")\n", 2);
      return (0);
    }
  write(fd_SockClient, "500 Syntax error, command unrecognized.\n", 40);
  return (-1);
}

char	*convert_port(int port1, int port2)
{
  char	*str;
  char	*p1;
  char	*p2;

  str = p1 = p2 = NULL;
  if ((p1 = convert_nbr(port1)) == NULL)
    return (NULL);
  if ((p2 = convert_nbr(port2)) == NULL)
    return (NULL);
  if ((str = malloc((strlen(p1) + strlen(p2) + 2)
		    * sizeof(char))) == NULL)//+2 for \0 && ,?
    return (NULL);
  strcat(str, p1);
  strcat(str, ",");
  strcat(str, p2);
  return (str);
}

char	*convert_nbr(int nb)
{
  char	*rep;
  int	d;
  int	i;

  d = i = 1;
  while (nb / d > 9)
    {
      d = d * 10;
      i = i + 1;
    }
  if ((rep = malloc((i + 1) * sizeof(char))) == NULL)//+1 for \0?
    return (NULL);
  i = 0;
  while (d > 0)
    {
      rep[i] = ((nb / d) % 10 + 48);
      i = i + 1;
      d = d / 10;
    }
  rep[i] = '\0';
  return (rep);
}

char	*convert_ip(char *ip)
{
  char	*ip_msg;
  int	i;

  if ((ip_msg = malloc((1 + strlen(ip))
		       * sizeof(char))) == NULL)//+1 for \0 ?
    return (NULL);
  i = 0;
  while (ip[i] != '\0')
    {
      if (ip[i] == '.')
	ip_msg[i] = ',';
      else
	ip_msg[i] = ip[i];
      i = i + 1;
    }
  ip_msg[i] = '\0';
  return (ip_msg);
}
