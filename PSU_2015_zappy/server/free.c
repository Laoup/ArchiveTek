/*
** free.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Wed Jun 22 17:47:50 2016 Jaime Dossantos
** Last update Thu Jun 23 15:31:11 2016 Jaime Dossantos
*/

#include "my.h"

void		free_messages(t_msg *msg)
{
  t_msg		*tmp;

  while (msg)
    {
      tmp = msg;
      msg = msg->next;
      if (tmp->msg)
	free(tmp->msg);
      free(tmp);
    }
}

void		free_orders(t_order *order)
{
  t_order	*tmp;

  while (order)
    {
      tmp = order;
      order = order->next;
      if (tmp->sentence != NULL)
	free(tmp->sentence);
      free(tmp);
    }
}
