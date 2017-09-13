/*
** manager.c for manager.c in /home/naji_m/rendu/PSU_2015_zappy/client
** 
** Made by naji moncef
** Login   <naji_m@epitech.net>
** 
** Started on  Wed Jun 22 16:16:32 2016 naji moncef
** Last update Wed Jun 22 16:43:07 2016 masson mathieu
*/

#include "my.h"

int     while_connected(t_list *my)
{
  char  buff[BUFF_SIZE];
  int   nb;

  nb = 0;
  if ((nb = read(my->env.fd, buff, BUFF_SIZE)) == -1)
    return (-1);
  buff[nb] = '\0';
  printf("%s", buff);
  return (0);
}
