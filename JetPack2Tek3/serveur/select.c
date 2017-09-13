/*
** select.c for MY JETPACK in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jul  8 12:48:10 2016 Alban Meurice
** Last update Wed Jul 13 21:09:41 2016 Alban Meurice
*/

#include "../include/my.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <unistd.h>

static	int	end = 0;

int	initFd(t_param *param, t_info *clientTab/*, rajouter l'order a envoyer */)
{
  int	ret;
  int	i;

  ret = param->fdServer;
  FD_ZERO(&param->fdRead);
  FD_ZERO(&param->fdWrite);
  FD_SET(param->fdServer, &param->fdRead);
  if (clientTab != NULL)
    {
      i = 0;
      while (i != 2)
	{
	  FD_SET(clientTab[i].fdClient, &param->fdRead);
	  FD_SET(clientTab[i].fdClient, &param->fdWrite);
	  if (clientTab[i].fdClient > ret)
	    ret = clientTab[i].fdClient;
	  i = i + 1;
	}
    }
  return (ret);
}

int	selectManager(t_param *param, t_info *clientTab)
{
  char	buffer[BUFFSIZE];

  while (end < 1)
    {
      memset(buffer, 0, BUFFSIZE);
      param->fdMax = initFd(param, clientTab);
      if (select(param->fdMax + 1, &param->fdRead, &param->fdWrite, NULL, NULL) == -1)
	break;
      if (manipTabClient(param, clientTab, buffer) == -1)
	return (returnCloseClient(-1, clientTab));
      if (clientTab[0].msg[0][0] != '\0' || clientTab[1].msg[0][0] != '\0')
	{
	  write(1, "A", 1);
	  if (executeCmd(param, clientTab) == -1)
	    return (returnCloseClient(-1, clientTab));
	  write(1, "E", 1);
	}
      memset(clientTab[0].msg[0], 0, 10);
      memset(clientTab[0].msg[1], 0, 10);
      memset(clientTab[1].msg[0], 0, 10);
      memset(clientTab[1].msg[1], 0, 10);
      if (clientTab[0].start == 1 && clientTab[1].start == 1)
	if ((end = execMap(param, clientTab)) == -1)
	  return (returnCloseClient(-1, clientTab));
      if (answer(param, clientTab, end) == -1)
	return (returnCloseClient(-1, clientTab));
      usleep(750000);
    }
  return (0);
}
