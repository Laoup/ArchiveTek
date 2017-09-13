/*
** execute.c for  in /home/dossan_a/rendu/PSU_2015_zappy
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Wed Jun 22 16:02:19 2016 Jaime Dossantos
** Last update Sat Jun 25 00:39:41 2016 Jaime Dossantos
*/

#include "my.h"

int		free_order(t_client *client)
{
  t_order	*order;

  order = client->order;
  while (order->next)
    order = order->next;
  if (order->prev != NULL)
    order->prev->next = order->next;
  if (order->sentence)
    free(order->sentence);
  if (order->prev == NULL)
    client->order = order->next;
  free(order);
  return (0);
}

int		new_msg(t_client *client, char *rep)
{
  t_msg		*elem;

  if ((elem = malloc(sizeof(t_msg))) == NULL)
    return (-1);
  elem->msg = rep;
  elem->next = client->send;
  elem->prev = NULL;
  if (client->send != NULL)
    client->send->prev = elem;
  client->send = elem;
  return (0);
}

char		*exect(t_order *order, t_param *param, t_client *client)
{
  char		*rep;

  rep = order->fct(order->ressource, order->sentence, param, client);
  return (rep);
}

int		execute(t_client **list, t_param *param)
{
  t_client	*tmp;
  t_order	*ord;
  char		*rep;

  tmp = *list;
  while (tmp)
    {
      ord = tmp->order;
      while (ord != NULL && ord->next != NULL)
	ord = ord->next;
      if (ord != NULL && it_time(ord, param) == 0)
	{
	  rep = exect(ord, param, tmp);
	  if (rep != NULL)
	    new_msg(tmp, rep);
	  free_order(tmp);
	}
      tmp = tmp->next;
    }
  return (0);
}
