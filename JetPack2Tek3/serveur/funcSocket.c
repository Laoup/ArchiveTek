/*
** funcSocket.c for MY JETPACK in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jul  8 11:26:14 2016 Alban Meurice
** Last update Wed Jul 13 16:24:20 2016 Alban Meurice
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int			createSocket(int port)
{
  int			fd;
  struct sockaddr_in	s_in;

  if ((fd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    return (-1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (struct sockaddr *)&s_in, sizeof(struct sockaddr_in)) < 0)
    return (-1);
  if (listen(fd, 2) < 0)
    return (-1);
  return (fd);
}

int			returnCloseClient(int val, t_info *clientTab)
{
  if (clientTab[0].fdClient != -1)
    close(clientTab[0].fdClient);
  if (clientTab[1].fdClient != -1)
    close(clientTab[1].fdClient);
  return (val);
}
