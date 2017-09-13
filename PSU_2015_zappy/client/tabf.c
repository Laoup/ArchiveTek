/*
** tabf.c for tabf.c in /home/masson_q/rendu/PSU_2015_zappy/src/mtmas
** 
** Made by masson mathieu
** Login   <masson_q@epitech.net>
** 
** Started on  Wed Jun 15 14:24:04 2016 masson mathieu
** Last update Fri Jun 24 20:03:29 2016 masson mathieu
*/

#include "my.h"

void	init_tabf(int (*tabf[])(t_list *my))
{
  tabf[0] = fct_ahed;
  tabf[1] = fct_right;
  tabf[2] = fct_left;
  tabf[3] = fct_see;
  tabf[4] = fct_inventory;
  tabf[5] = fct_pickup_obj;
  tabf[6] = fct_put_obj;
  tabf[7] = fct_expls_ply;
  tabf[8] = fct_broadcast;
  tabf[9] = fct_incant;
  tabf[10] = fct_fork_ply;
  tabf[11] = fct_connect_nbr;
}

int	fct_fork_ply(t_list *my)
{
  if (write_socket(my,"fork\n") == 0)
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

int	fct_connect_nbr(t_list *my)
{
  if (write_socket(my,"connect_nbr\n") == 0)
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
