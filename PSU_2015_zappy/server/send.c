/*
** send.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Thu Jun 16 17:41:48 2016 Jaime Dossantos
** Last update Fri Jun 24 15:57:14 2016 Jaime Dossantos
*/

#include "my.h"
#include "map.h"

int	first_dial(t_client *client, char *buff, t_param *param, t_client **list)
{
  if (client->equipe == NULL)
    check_team(client, buff, param);
  if (client->equipe != NULL)
    hello_or_gb(param, client->equipe, list, client);
  return (0);
}

void	avance_bis(t_client *client, t_param *param)
{
  if (client->direction == NORD)
    {
      if ((client->y + 1) < param->hauteur)
	client->y++;
      else
	client->y = 0;
    }
  else if (client->direction == SUD)
    {
      if (client->y != 0)
	client->y--;
      else
	client->y = param->hauteur - 1;
    }
  else if (client->direction == OUEST)
    {
      if ((client->x + 1) < param->largeur)
	client->x++;
      else
	client->x = 0;
    }
}

char	*avance(int ressource, char *msg, t_param *param, t_client *client)
{
  char	*rep;

  ressource = ressource;
  msg = msg;
  if ((rep = malloc(4)) == NULL)
    return (NULL);
  rep = strcpy(rep, "ok\n");
  if (client->direction == NORD || client->direction == SUD ||
      client->direction == OUEST)
    avance_bis(client, param);
  else if (client->direction == EST)
    {
      if (client->x != 0)
	client->x--;
      else
	client->x = param->largeur - 1;
    }
  return (rep);
}

char	*droite(int ressource, char *msg, t_param *param, t_client *client)
{
  char	*rep;

  ressource = ressource;
  msg = msg;
  param = param;
  if ((rep = malloc(4)) == NULL)
    return (NULL);
  rep = strcpy(rep, "ok\n");
  client->direction++;
  if (client->direction == 4)
    client->direction = NORD;
  return (rep);
}

char	*gauche(int ressource, char *msg, t_param *param, t_client *client)
{
  char	*rep;

  ressource = ressource;
  msg = msg;
  param = param;
  if ((rep = malloc(4)) == NULL)
    return (NULL);
  rep = strcpy(rep, "ok\n");
  client->direction--;
  if (client->direction == -1)
    client->direction = EST;
  return (rep);
}
