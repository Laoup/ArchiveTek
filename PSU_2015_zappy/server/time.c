/*
** time.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Sat Jun 25 00:16:01 2016 Jaime Dossantos
** Last update Sun Jun 26 23:00:47 2016 Avel Docquin
*/

#include "my.h"

void		gettime_exec(t_order *order, t_infos const *info)
{
  if (info->order < 9)
    order->milliseconds = 7000;
  else if (info->order == 9)
    order->milliseconds = 300000;
  else
    order->milliseconds = 42000;
  order->exec = 0;
}

int			it_time(t_order *order, t_param *param)
{
  struct timeval	mda;

  gettimeofday(&mda, 0);
  if ((((mda.tv_usec / 1000) + (mda.tv_sec * 1000)) -
       ((order->before.tv_usec / 1000) + (order->before.tv_sec * 1000)))
      >= (order->milliseconds / param->delai))
    return (0);
  return (1);
}
