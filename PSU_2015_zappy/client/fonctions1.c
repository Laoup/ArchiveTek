/*
** fonctions1.c for fonctions1.c in /home/masson_q/rendu/PSU_2015_zappy/src
**
** Made by masson mathieu
** Login   <masson_q@epitech.net>
**
** Started on  Thu Jun 16 11:13:46 2016 masson mathieu
** Last update Sun Jun 26 22:23:46 2016 Avel Docquin
*/

#include "my.h"

int	fct_ahed(t_list *my)
{
  if (write_socket(my,"avance\n") == 0)
    {
      if (read_socket(my) != 0)
	if (my_compare_tab(my->env.buff, "ok\n") == 1)
	  {
	    my->player.life -= 7;
	    return (0);
	  }
    }
  return (1);
}

int	fct_right(t_list *my)
{
  if (write_socket(my, "droite\n") == 0)
    {
      if (read_socket(my) != 0)
	{
	  if (my_compare_tab(my->env.buff, "ok\n") == 0)
	    my->player.life -= 7;
	  return (0);
	}
      if (read_socket(my) != 0)
	if (my_compare_tab(my->env.buff, "ok\n") == 0)
	  my->player.life -= 7;
    }
  return (1);
}

int	fct_left(t_list *my)
{
  if (write_socket(my, "gauche\n") == 0)
    if (read_socket(my) != 0)
      {
	if (my_compare_tab(my->env.buff, "ok\n") == 0)
	  my->player.life -= 7;
	return (0);
      }
  return (1);
}

int	fct_see(t_list *my)
{
  if (write_socket(my, "voir\n") == 0)
    {
      if (read_socket(my) != 0)
	{
	  if (my->env.buff)
	    my->player.life -= 7;
	  return (0);
	}
    }
  return (1);
}

int	fct_inventory(t_list *my)
{
  if (write_socket(my, "inventaire\n") == 0)
    {
      if (read_socket(my) != 0)
	{
	  if (my->env.buff)
	    my->player.life -= 7;
	  return (0);
	}
    }
  return (1);
}
