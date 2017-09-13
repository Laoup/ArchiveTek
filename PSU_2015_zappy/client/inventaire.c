/*
** inventaire.c for inventaire.c in /home/masson_q/Rendu/PSU_2015_zappy/client
** 
** Made by masson mathieu
** Login   <masson_q@epitech.net>
** 
** Started on  Fri Jun 24 17:19:48 2016 masson mathieu
** Last update Fri Jun 24 22:36:01 2016 masson mathieu
*/

#include "my.h"

void	add_to_invent(t_list *my, char *obj)
{
  if (strcmp(obj, "linemate") == 0)
    my->player.inventaire[LINEMATE] += 1;
  if (strcmp(obj, "deraumere") == 0)
    my->player.inventaire[DERAUMERE]++;
  if (strcmp(obj, "sibur") == 0)
      my->player.inventaire[SIBUR]++;
  if (strcmp(obj, "mendiane") == 0)
      my->player.inventaire[MENDIANE]++;
  if (strcmp(obj, "phiras") == 0)
      my->player.inventaire[PHIRAS]++;
  if (strcmp(obj, "thystame") == 0)
      my->player.inventaire[THYSTAME]++;
}

void	rem_from_invent(t_list *my, char *obj)
{
  if (strcmp(obj, "linemate") == 0)
      my->player.inventaire[LINEMATE]--;
  if (strcmp(obj, "dereaumere") == 0)
    my->player.inventaire[DERAUMERE]--;
  if (strcmp(obj, "sibur") == 0)
      my->player.inventaire[SIBUR]--;
  if (strcmp(obj, "mendiane") == 0)
      my->player.inventaire[MENDIANE]--;
  if (strcmp(obj, "phiras") == 0)
      my->player.inventaire[PHIRAS]--;
  if (strcmp(obj, "thystame") == 0)
      my->player.inventaire[THYSTAME]--;
}
