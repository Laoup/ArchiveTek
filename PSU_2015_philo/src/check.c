/*
** check.c for philo in /home/meuric_a/Projet_T2/Philosophe/PSU_2015_philo/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Mar  3 23:34:10 2016 Alban Meurice
** Last update Fri Mar 11 01:09:19 2016 Alban Meurice
*/

#include "philo.h"
#include <pthread.h>

#include <unistd.h>

int	is_nbr(char *s_nb)
{
  int	i;

  if (s_nb == NULL)
    return (-1);
  i = 0;
  while (s_nb[i] != '\0')
    {
      if ((s_nb[i] >= '0') && (s_nb[i] <= '9') && (s_nb))
	i = i + 1;
      else
	return (-1);
    }
  return (0);
}

int	i_can_graille(t_philo_l *my_phil, t_philo_l *right_philo)
{
  if (my_phil->eat_oc != 0)
    if (my_phil->use == 0 && right_philo->use == 0)
      {
	my_phil->use = 1;
	right_philo->use = 1;
	return (0);
      }
  return (-1);
}

int	i_can_think(t_philo_l *my_phil)
{
  if (my_phil->use == 0)
    {
      my_phil->use = 1;
      return (0);
    }
  return (-1);
}

int	i_can_sleep(t_philo_l *my_phil)
{
  if (my_phil->food == 1)
    return (0);
  return (-1);
}
