/*
** prend.c for prend.c in /home/masson_q/Rendu/PSU_2015_zappy/client
** 
** Made by masson mathieu
** Login   <masson_q@epitech.net>
** 
** Started on  Fri Jun 24 18:17:24 2016 masson mathieu
** Last update Fri Jun 24 22:33:34 2016 masson mathieu
*/

#include "my.h"

int     prend_line(t_list *my)
{
  if (write_socket(my, "prend linemate\n") == 0)
    {
      if (read_socket(my) != 0)
	if (my_compare_tab(my->env.buff, "ok\n") == 1)
	  {
	    add_to_invent(my, "linemate");
	    my->player.life -= 7;
	    return (0);
	  }
    }
  return (1);
}

int     prend_derau(t_list *my)
{
  if (write_socket(my, "prend deraumere\n") == 0)
    {
      if (read_socket(my) != 0)
	if (my_compare_tab(my->env.buff, "ok\n") == 1)
	  {
	    my->player.life -= 7;
	    add_to_invent(my, "deraumere");
	    return (0);
	  }
    }
  return (1);
}

int     prend_sib(t_list *my)
{
  if (write_socket(my, "prend sibur\n") == 0)
    {
      if (read_socket(my) != 0)
        {
          if (my_compare_tab(my->env.buff, "ok\n") == 1)
	    {
	      add_to_invent(my, "sibur");                                  
	      my->player.life -= 7;
	      return (0);
	    }
        }
    }
  return (1);
}
