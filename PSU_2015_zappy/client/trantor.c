/*
** trantor.c for trantor.c in /home/masson_q/Rendu/PSU_2015_zappy/client/ia
** 
** Made by masson mathieu
** Login   <masson_q@epitech.net>
** 
** Started on  Wed Jun 22 16:51:02 2016 masson mathieu
** Last update Fri Jun 24 20:18:57 2016 masson mathieu
*/

#include "my.h"

void	init_trantor(t_list *my)
{
  int	i;

  i = 0;
  my->player.life = 1260;
  my->player.view_size = 1;
  my->player.level = 1;
  while (i < INVENTSIZE)
    my->player.inventaire[i++] = 0;
}
