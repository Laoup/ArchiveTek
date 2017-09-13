/*
** map.c for MY JETPACK in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Jul 11 18:29:30 2016 Alban Meurice
** Last update Wed Jul 13 21:39:23 2016 Alban Meurice
*/

#include "../include/my.h"
#include <stdio.h>

#include <unistd.h>

int	execMap(t_param *param, t_info *clientTab)
{
  int	ret;

  ret = movePlayer(param, &clientTab[0], clientTab[1].y);
  ret = movePlayer(param, &clientTab[1], clientTab[0].y);
  return (ret);
}

int	movePlayer(t_param *param, t_info *client, int otherY)
{
  int	posCase;

  (void)otherY;
  client->x = client->x + 1;
  if (client->fire == 1)
    {
      if (client->y != 1)
	client->y = client->y - 1;
    }
  else if (client->fire == 0)
    {
      if (client->y != param->hauteur)
	client->y = client->y + 1;
      printf("y = %d, hauteur = %d \n", client->y, param->hauteur);
    }
  posCase = ((client->y - 1) * param->largeur) + (client->x + (client->y - 2));
  /*posCase = (((client->y - 10) * -1) * param->largeur) + (client->x + 8);*/
  my_check();
  if (client->x == param->largeur || param->map[posCase] == 'e')
    return (1);
  if (param->map[posCase] == 'c')
    {
      write(1, "COIN\n", 5);
      param->map[posCase] = '_';
      client->score = client->score + 1;
      client->coin = 1;
    }
  return (0);
}

void	setWinner(t_info *clientTab)
{
  if (clientTab[0].score > clientTab[1].score)
    clientTab[0].winner = 1;
  else if (clientTab[1].score > clientTab[0].score)
    clientTab[1].winner = 1;
  if (clientTab[0].score == clientTab[1].score)
    {
      clientTab[1].winner = -1;
      clientTab[1].winner = -1;
    }
}