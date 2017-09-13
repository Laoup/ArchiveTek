/*
** ia.c for ia.c in /home/masson_q/Rendu/PSU_2015_zappy/client/ia
**
** Made by masson mathieu
** Login   <masson_q@epitech.net>
**
** Started on  Tue Jun 21 21:36:50 2016 masson mathieu
** Last update Sun Jun 26 23:35:10 2016 Avel Docquin
*/

#include "my.h"

int	first_step(int (*tabf[])(t_list *my), t_list *my)
{
  int	i;

  i = 0;
  tabf[INVENT](my);
  if (my->player.life > 0 && my->env.fd != 1)
    while (my->player.life > 0 && i == 0)
      {
	if (my->player.life > 378)
	  i = fct_alive(tabf, my);
	else if (my->player.life <= 378)
	  i = fct_needtoeat(tabf, my);
      }
  return (0);
}

int	fct_alive(int (*tabf[])(t_list *my), t_list *my)
{
  tabf[SEE](my);
  if (my->player.level == 1)
    if (first_elev(my) == 0)
      {
	if (write_socket(my, "pose linemate\n") != 0
	    || read_socket(my) == 0)
	  return (-1);
	else
          {
	    if (my_compare_tab(my->env.buff, "ok\n") == 0)
	      {
		my->player.life -= 7;
		rem_from_invent(my, "linemate");
	      }
          }
	tabf[INCANT](my);
      }
  if (my->player.level == 2)
    if (sec_elev(my) == 0)
      tabf[INCANT](my);
  tabf[PICKUP](my);
  tabf[AHED](my);
  return (0);
}

int	fct_needtoeat(int (*tabf[])(t_list *my), t_list *my)
{
  if (write_socket(my, "prend nourriture\n") != 0)
    return (-1);
  else
    {
      if (read_socket(my) != 0)
	{
	  if (my_compare_tab(my->env.buff, "ok\n") == 0)
	    my->player.life += 126;
	}
    }
  tabf[LEFT](my);
  tabf[AHED](my);
  return (0);
}
