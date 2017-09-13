/*
** check.c for check for ZAPPY GRAPHIC PART in /home/meuric_a/Projet_T2_Test/ZAPPY/server/graphic
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Jun 16 21:40:13 2016 Alban Meurice
** Last update Mon Jun 20 19:37:02 2016 Alban Meurice
*/

#include "graphic.h"
#include "../my.h"

t_client	*itsPlayer(t_client *list, unsigned int x, unsigned int y)
{
  t_client	*tmp;

  tmp = list;
  while (tmp->next != NULL)
    {
      if (tmp->x == x)
	if (tmp->y == y)
	  return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
