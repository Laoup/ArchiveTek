/*
** send0.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Wed Jun 22 15:41:19 2016 Jaime Dossantos
** Last update Fri Jun 24 18:27:24 2016 Jaime Dossantos
*/

#include "my.h"

char	*inventaire()
{

  return (0);
}

char	*prend(int ressource, char *msg, t_param *param, t_client *client)
{
  char	*rep;

  msg = msg;
  if ((rep = malloc(4)) == NULL)
    return (NULL);
  if (param->map[client->x][client->y][ressource] > 0)
    {
      client->inventaire[ressource]++;
      param->map[client->x][client->y][ressource]--;
      rep = strcpy(rep, "ok\n");
    }
  else
    rep = strcpy(rep, "ko\n");
  return (rep);
}

char	*pose(int ressource, char *msg, t_param *param, t_client *client)
{
  char	*rep;

  msg = msg;
  if ((rep = malloc(4)) == NULL)
    return (NULL);
  if (client->inventaire[ressource] > 0)
    {
      client->inventaire[ressource]--;
      param->map[client->x][client->y][ressource]++;
      rep = strcpy(rep, "ok\n");
    }
  else
    rep = strcpy(rep, "ko\n");
  return (rep);

}

char	*expulse()
{
  return (0);
}

char	*broadcast()
{
   return (0);
}
