/*
** fctAnswer.c for MY JETPACK in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Jul 11 10:37:08 2016 Alban Meurice
** Last update Wed Jul 13 21:53:06 2016 Alban Meurice
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	answer(t_param *param, t_info *clientTab, int end)
{
  if (clientTab[0].ready == 1 && clientTab[1].ready == 1)
    {
      write(1, "F", 1);
      if (param->fct[4](&clientTab[0], param) != 0 ||
	  param->fct[4](&clientTab[1], param) != 0)
	return (-1);
    }
  if (clientTab[0].coin == 1)
    {
      if (param->fct[7](&clientTab[0], param) == -1)
	return (-1);
    }
  /*else */if (clientTab[1].coin == 1)
    {
      write(1, "e", 1);
      if (param->fct[7](&clientTab[1], param) == -1)
	return (-1);
    }
  if (end == 1)
    {
      setWinner(clientTab);
      if (clientTab[0].winner == 1)
	{
	  if (param->fct[6](&clientTab[0], param) != 0)
	    return (-1);
	}
      else if (clientTab[1].winner == 1)
	if (param->fct[6](&clientTab[0], param) != 0)
	  return (-1);
    }
  if (clientTab[0].start == 1 && clientTab[1].start == 1)
    if (param->fct[5](&clientTab[0], param) != 0 ||
	param->fct[5](&clientTab[1], param) != 0)
      return (-1);
  return (0);
}

int	sendCoin(t_info *client, t_param *param)
{
  char	*str;
  char	*strTmp;

  client->coin = 0;
  if ((str = strdup("COIN ")) == NULL)
    return (-1);
  if ((strTmp = convertNbr(client->idClient)) == NULL)
    return (-1);
  if ((str = realloc(str, (strlen(str) + strlen(strTmp) + 3) * sizeof(char)))
      == NULL)
    return (-1);
  strcat(str, strTmp);
  strcat(str, " ");
  if ((strTmp = convertNbr(client->x)) == NULL)
    return (-1);
  if ((str = realloc(str, (strlen(str) + strlen(strTmp) + 3) * sizeof(char)))
      == NULL)
    return (-1);
  strcat(str, strTmp);
  strcat(str, " ");
  if ((strTmp = convertNbr((client->y - param->hauteur))) == NULL)
    return (-1);
  if ((str = realloc(str, (strlen(str) + strlen(strTmp) + 3) * sizeof(char)))
      == NULL)
    return (-1);
  strcat(str, strTmp);
  strcat(str, "\n");
  /*  strcat(str, " ");
  if ((strTmp = convertNbr(client->score)) == NULL)
    return (-1);
  if ((str = realloc(str, (strlen(str) + strlen(strTmp) + 2) * sizeof(char)))
      == NULL)
    return (-1);
    strcat(str, strTmp);*/
  if (write(client->fdClient, str, strlen(str)) == -1)
    return (-1);
  return (0);
}

int	sendStart(t_info *client, t_param *param)
{
  (void)param;
  if (write(client->fdClient, "START\n", 6) == -1)
    return (-1);
  client->start = 1;
  client->ready = 0;
  return (0);
}

int	sendPlayer(t_info *client, t_param *param)
{
  char	*str;
  char	*strTmp;

  (void)param;
  if ((strTmp = convertNbr(client->idClient)) == NULL)
    return (-1);
  str = strdup("PLAYER ");
  if ((str = realloc(str, (strlen(str) + strlen(strTmp) + 3) * sizeof(char)))
      == NULL)
    return (-1);
  strcat(str, strTmp);
  strcat(str, " ");
  if ((strTmp = convertNbr(client->x)) == NULL)
    return (-1);
  if ((str = realloc(str, (strlen(str) + strlen(strTmp) + 3) * sizeof(char)))
      == NULL)
    return (-1);
  strcat(str, strTmp);
  strcat(str, " ");
  if ((strTmp = convertNbr(client->y - 10)) == NULL)
    return (-1);
  if ((str = realloc(str, (strlen(str) + strlen(strTmp) + 3) * sizeof(char)))
      == NULL)
    return (-1);
  strcat(str, strTmp);
  strcat(str, " ");
  if ((strTmp = convertNbr(client->score)) == NULL)
    return (-1);
  if ((str = realloc(str, (strlen(str) + strlen(strTmp) + 3) * sizeof(char)))
      == NULL)
    return (-1);
  strcat(str, strTmp);
  strcat(str, "\n");
  if (write(client->fdClient, str, strlen(str)) == -1)
    return (-1);;
  return (0);
}

int	sendFinish(t_info *client, t_param *param)
{
  char	*str;
  char	*strTmp;

  (void)param;
  write(1, "V", 1);
  if ((str = malloc(7 * sizeof(char))) == NULL)
    return (-1);
  if ((str = strdup("FINISH ")) == NULL)
    return (-1);
  if ((strTmp = convertNbr(client->idClient)) == NULL)
    return (-1);
  if ((str = realloc(str, (strlen(str) + strlen(strTmp) + 3) * sizeof(char)))
      == NULL)
    return (-1);
  strcat(str, strTmp);
  strcat(str, "\n");
  if (write(client->fdClient, str, strlen(str)) == -1)
    return (-1);
  return (0);
}
