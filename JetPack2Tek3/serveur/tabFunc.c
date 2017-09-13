/*
** tabFunc.c for My JETPACK in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jul  8 16:04:53 2016 Alban Meurice
** Last update Wed Jul 13 21:22:25 2016 Alban Meurice
*/

#include "../include/my.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#include <stdio.h>

void			my_check()
{
  int	i;

  i = 0;
  while (i != 1)
    i = i + 1;
}

int			addClient(t_info *tabClient, int fdServ)
{
  struct sockaddr_in	sin;
  socklen_t		sinSize;
  int			ret;

  sinSize = sizeof(sin);
  if ((ret = accept(fdServ, (struct sockaddr *)&sin, &sinSize)) > 0)
    {
      if (tabClient[0].fdClient == -1)
	tabClient[0].fdClient = ret;
      else if (tabClient[1].fdClient == -1)
	tabClient[1].fdClient = ret;
      else
	return (-1);
      return (0);
    }
  return (-1);
}

char		**initTabMsg()
{
  char		**tab;
  int		i;

  i = 0;
  if ((tab = malloc(2 * sizeof(char *))) == NULL)
    return (NULL);
  while (i != 2)
    {
      if ((tab[i] = malloc(8 * sizeof(char))) == NULL)
	return (NULL);
      tab[i] = NULL;
      i = i + 1;
    }
  return (tab);
}

static	void	sig_handler(int sig)
{
  if (sig == SIGSEGV)
    exit(-84);
}

int		manipTabClient(t_param *param, t_info *tabClient, char *buff)
{
  signal(SIGSEGV, sig_handler);
  if (FD_ISSET(param->fdServer, &param->fdRead))
    addClient(tabClient, param->fdServer);
  if (tabClient[0].fdClient != -1)
    if (FD_ISSET(tabClient[0].fdClient, &param->fdRead))
      {
	if (read(tabClient[0].fdClient, buff, BUFFSIZE) == -1)
	  return (-1);
	cutBuff(&tabClient[0], buff);
	/*if ((tabMsg[0] = strdup(buff)) == NULL)
	  return (-1);*/
	/*strcpy(tabClient[0].msg, buff);*/
	printf("tabMSG1[0] = %s\n", tabClient[0].msg[0]);
	printf("tabMSG1[1] = %s\n", tabClient[0].msg[1]);
      }
  if (tabClient[1].fdClient != -1)
    {
      if (FD_ISSET(tabClient[1].fdClient, &param->fdRead))
	{
	  if (read(tabClient[1].fdClient, buff, BUFFSIZE) == -1)
	    return (-1);
	  cutBuff(&tabClient[1], buff);
	  printf("tabMSG2[0] = %s\n", tabClient[1].msg[0]);
	  printf("tabMSG2[1] = %s\n", tabClient[1].msg[1]);
	  my_check();
	  /*	if ((tabMsg[1] = strdup(buff)) == NULL)
		return (-1);*/
	  /*strcpy(tabClient[1].msg, buff);*/
	}
    }
  return (0);
}