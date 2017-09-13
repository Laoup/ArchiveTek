/*
** fct.c for MY JETPACK in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sat Jul  9 13:16:25 2016 Alban Meurice
** Last update Wed Jul 13 15:34:00 2016 Alban Meurice
*/

#include "../include/my.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	getId(t_info *client, t_param *param)
{
  char	*str;
  char	*strId;

  (void)param;
  if ((strId = convertNbr(client->idClient)) == NULL)
    return (-1);
  if ((str = strdup("ID \0")) == NULL)
    return (-1);
  if ((str = realloc(str, strlen(str) + strlen(strId) + 2 * sizeof(char))) == NULL)
    return (-1);
  strcat(str, strId);
  strcat(str, "\n");
  if (write(client->fdClient, str, strlen(str)) == -1)
    return (-1);
  return (0);
}

int	sendMap(t_info *client, t_param *param)/* error Norme */
{
  char	*str;
  char	*strNbr;

  if ((strNbr = convertNbr(param->largeur)) == NULL)
    return (-1);
  if ((str = strdup("MAP \0")) == NULL)
    return (-1);
  if ((str = realloc(str, strlen(str) + strlen(strNbr) + 2 * sizeof(char))) == NULL)
    return (-1);
  strcat(str, strNbr);
  strcat(str, " ");
  if ((strNbr = convertNbr(param->hauteur)) == NULL)
    return (-1);
  if ((str = realloc(str, strlen(str) + strlen(strNbr) + 2 * sizeof(char))) == NULL)
    return (-1);
  strcat(str, strNbr);
  strcat(str, " ");
  if ((strNbr = readMap(param->map, param->largeur, param->hauteur)) == NULL)
    return (-1);
  if ((str = realloc(str, strlen(str) + strlen(strNbr) + 2 * sizeof(char))) == NULL)
    return (-1);
  /*if ((strNbr = revStr(strNbr)) == NULL)
    return (-1);*/
  strcat(str, strNbr);
  strcat(str, "\n");
  /*  write(1, str, strlen(str));*/
  if (write(client->fdClient, str, strlen(str)) == -1)
    return (-1);
  return (0);
}

int	readyReceive(t_info *client, t_param *param)
{
  (void)param;
  if (client->start == 0)
    client->ready = 1;
  else
    return (-1);
  return (0);
}

int	fireReceive(t_info *client, t_param *param)
{
  (void)param;
  client->fire = 1;
  return (0);
}
