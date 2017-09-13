/*
** elevation.c for elevation.c in /home/masson_q/Rendu/PSU_2015_zappy/client/ia
**
** Made by masson mathieu
** Login   <masson_q@epitech.net>
**
** Started on  Tue Jun 21 21:54:57 2016 masson mathieu
** Last update Sun Jun 26 21:56:27 2016 Avel Docquin
*/

#include "my.h"

int	first_elev(t_list *my)
{
  if (my->player.inventaire[LINEMATE] >= 1)
    if (my->env.buff[8] == ',')
      return (0);
  return (1);
}

int	sec_elev(t_list *my)
{
  if (my->player.inventaire[LINEMATE] >= 1 &&
      my->player.inventaire[LINEMATE] >= 1 &&
      my->player.inventaire[LINEMATE] >= 1)
    if (my->env.buff[9] == 'j' && my->env.buff[15] == ',')
      return (0);
  return (1);
}

void	pose_for_elev(t_list *my)
{
  if (write_socket(my, "pose linemate\n") == 0)
    {
      if (read_socket(my) != 0)
	{
	  if (my_compare_tab(my->env.buff, "ok\n") == 0)
	    {
	      my->player.life -= 7;
	      rem_from_invent(my, "linemate");
	    }
	}
    }
  if (write_socket(my, "pose deraumere\n") == 0)
    {
      if (read_socket(my) != 0)
	{
	  if (my_compare_tab(my->env.buff, "ok\n") == 0)
	    {
	      my->player.life -= 7;
	      rem_from_invent(my, "deraumere");
	    }
	}
    }
  if (write_socket(my, "pose sibur\n") == 0)
    {
      if (read_socket(my) != 0)
	{
	  if (my_compare_tab(my->env.buff, "ok\n") == 0)
	    {
	      my->player.life -= 7;
	      rem_from_invent(my, "sibur");
	    }
	}
    }
}
