/*
** main.c for My JetPack in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Jul  7 19:23:56 2016 Alban Meurice
** Last update Wed Jul 13 22:03:12 2016 Alban Meurice
*/

#include "../include/my.h"
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

int		initClientTab(t_info **clientTab, int hauteur)
{
  if (((*clientTab) = malloc(2 * sizeof(t_info))) == NULL)
    return (-1);
  (*clientTab)[0].fdClient = -1;
  (*clientTab)[1].fdClient = -1;
  (*clientTab)[0].idClient = 1;
  (*clientTab)[1].idClient = 2;
  (*clientTab)[0].fire = 0;
  (*clientTab)[1].fire = 0;
  (*clientTab)[0].ready = 0;
  (*clientTab)[1].ready = 0;
  (*clientTab)[0].x = 0;
  (*clientTab)[1].x = 0;
  /*  (*clientTab)[0].y = hauteur / 2 + ((*clientTab)[0].idClient - 1);
      (*clientTab)[1].y = hauteur / 2 + ((*clientTab)[1].idClient - 1);*/
  (*clientTab)[0].y = hauteur / 2;
  (*clientTab)[1].y = hauteur / 2;
  (*clientTab)[0].score = 0;
  (*clientTab)[1].score = 0;
  (*clientTab)[0].start = 0;
  (*clientTab)[1].start = 0;
  (*clientTab)[0].coin = 0;
  (*clientTab)[1].coin = 0;
  (*clientTab)[0].winner = 0;
  (*clientTab)[1].winner = 0;
  memset((*clientTab)[0].msg[0], 0, 10);
  memset((*clientTab)[0].msg[1], 0, 10);
  memset((*clientTab)[1].msg[0], 0, 10);
  memset((*clientTab)[1].msg[1], 0, 10);
  return (0);
}

int		initParam(char **args, t_param *param)
{
  char		*file;

  if ((param->port = search(args, "-p")) < 0)
    return (-1);
  if ((param->gravity = search(args, "-g")) < 0)
    return (-1);
  if ((file = fileMap(args, "-m")) == NULL)
    return (-1);
  if (getMap(file, &param->map) == -1)
    return (-1);
  if (infoMap(param->map, param) == -1)
    return (-1);
  return (0);
}

int		initTabCmd(t_param *param)
{
  int		i;

  param->fct[0] = getId;
  param->fct[1] = sendMap;
  param->fct[2] = readyReceive;
  param->fct[3] = fireReceive;
  param->fct[4] = sendStart;
  param->fct[5] = sendPlayer;
  param->fct[6] = sendFinish;
  param->fct[7] = sendCoin;
  i = 0;
  while (i != NBR_CMD)
    {
      if ((param->tabCmd[i] = malloc(6 * sizeof(char))) == NULL)
	return (-1);
      i = i + 1;
    }
  param->tabCmd[0] = "ID\n";
  param->tabCmd[1] = "MAP\n";
  param->tabCmd[2] = "READY\n";
  param->tabCmd[3] = "FIRE\n";
  param->tabCmd[4] = "";
  param->tabCmd[5] = "";
  param->tabCmd[6] = "";
  param->tabCmd[7] = "";
  return (0);
}

int		returnFct(int val, int fd)
{
  close(fd);
  return (val);
}

int		main(int argc, char **argv)
{
  t_param	param;
  t_info       	*clientTab;

  (void)argc;
  if (initParam(argv, &param) < 0)
    return (84);
  if (initTabCmd(&param) == -1)
    return (84);
  if (initClientTab(&clientTab, param.hauteur) == -1)
    return (84);
  if ((param.fdServer = createSocket(param.port)) == -1)
    return (returnFct(84, param.fdServer));
  if (selectManager(&param, clientTab) == -1)
    return (returnFct(84, param.fdServer));
  close(param.fdServer);
  return (0);
}
