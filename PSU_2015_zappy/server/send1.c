/*
** send1.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Wed Jun 22 15:43:05 2016 Jaime Dossantos
** Last update Sun Jun 26 22:51:45 2016 Avel Docquin
*/

#include "my.h"

void	init_joueur(t_client *client)
{
  int	i;
  char	*bvn;

  bvn = malloc(11);
  bvn = strcpy(bvn, "BIENVENUE\n");
  client->lvl = 0;
  i = 0;
  while (i < 8)
    {
      client->inventaire[i] = 0;
      i++;
    }
  new_msg(client, bvn);
}

char	*voir()
{
  return (0);
}

char	*incantation()
{
  return (0);
}

char	*forking(int ressource, char *msg, t_param *param, t_client *client)
{
  char	*rep;
  int	i;

  i = 0;
  ressource = ressource;
  msg = msg;
  while (param->equipe[i])
    {
      if (strcmp(client->equipe, param->equipe[i]) == 0)
	{
	  param->free_slot[i]++;
	  break;
	}
      i++;
    }
  rep = malloc(4);
  rep = strcpy(rep, "ok\n");
  return (rep);
}
