/*
** fonctions2.c for fonctions2.c in /home/masson_q/rendu/PSU_2015_zappy/src
**
** Made by masson mathieu
** Login   <masson_q@epitech.net>
**
** Started on  Thu Jun 16 11:33:41 2016 masson mathieu
** Last update Sun Jun 26 22:05:10 2016 Avel Docquin
*/

#include "my.h"

int	fct_pickup_obj(t_list *my)
{
  if (prend_line(my) == 0)
    return (0);
  if (prend_derau(my) == 0)
    return (0);
  if (prend_sib(my) == 0)
    return (0);
  return (1);
}

int	fct_put_obj(t_list *my)
{

  if (write_socket(my, "pose objet\n") == 0)
    {
      if (read_socket(my) != 0)
	{
	  if (my_compare_tab(my->env.buff, "ok\n") == 0)
	    rem_from_invent(my, "deraumere");
	  my->player.life -= 7;
	  return (0);
	}
    }
  return (0);
}

int	fct_expls_ply(t_list *my)
{
  if (write_socket(my, "expulse\n") == 0)
    {
      if (read_socket(my) != 0)
        {
          if (my_compare_tab(my->env.buff, "ok\n") == 0)
            my->player.life -= 7;
          return (0);
        }
    }
  return (1);
}

int	fct_broadcast()
{
  return (0);
}

int	fct_incant(t_list *my)
{
  if (write_socket(my, "incantation\n") == 0)
    {
      if (read_socket(my) != 0)
	{
	  if (my_compare_tab(my->env.buff, "ko\n") == 0)
	    return (1);
	  my->player.life -= 300;
	  my->player.level += 1;
	  return (0);
	}
    }
  return (1);
}
