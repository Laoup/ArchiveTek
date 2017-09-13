/*
** execute.c for MY JETPACK in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sat Jul  9 12:25:09 2016 Alban Meurice
** Last update Wed Jul 13 13:42:38 2016 Alban Meurice
*/

#include "../include/my.h"
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <stdio.h>

int	searchFunc(t_param *param, char *msg)
{
  int	i;

  i = 0;
  while (i != NBR_CMD)
    {
      if (strcmp(msg, "FIRE 0\n") == 0 || strcmp(msg, "FIRE 1\n") == 0)
	{
	  if (strcmp(msg, "FIRE 0\n") == 0)
	    return (NBR_CMD + 10);
	  if (strcmp(msg, "FIRE 1\n") == 0)
	    return (NBR_CMD + 20);
	}
      else if (strcmp(param->tabCmd[i], msg) == 0)
	return (i);
      i = i + 1;
    }
  return (-1);
}

int	executeCmd(t_param *param, t_info *clientTab/*, char **order*/)
{
  int	i;
  int	idOrder;

  i = 0;
  while (i != 2)
    {
      idOrder = 0;
      if (clientTab[i].msg[0][0] != '\0')
	{
	  if ((idOrder = searchFunc(param, clientTab[i].msg[0])) == -1)
	    return (1);
	  if (idOrder == NBR_CMD + 10)
	    clientTab[i].fire = 0;
	  else if (idOrder == NBR_CMD + 20)
	    clientTab[i].fire = 1;
	  else
	    if (param->fct[idOrder](&clientTab[i], param) == -1)
	      return (-1);
	}
      if (clientTab[i].msg[1][0] != '\0')
	{
	  if ((idOrder = searchFunc(param, clientTab[i].msg[1])) == -1)
	    return (1);
	  if (idOrder == NBR_CMD + 10)
	    clientTab[i].fire = 0;
	  else if (idOrder == NBR_CMD + 20)
	    clientTab[i].fire = 1;
	  else
	    if (param->fct[idOrder](&clientTab[i], param) == -1)
	      return (-1);
	}
      i = i + 1;
    }
  return (0);
}
