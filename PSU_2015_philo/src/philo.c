/*
** philo.c for philo in /home/meuric_a/Projet_T2/Philosophe/PSU_2015_philo/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Mar  3 23:44:25 2016 Alban Meurice
** Last update Sun Mar 13 18:36:02 2016 Alban Meurice
*/

#include "philo.h"
#include "extern.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void		*life_philo(void *arg)
{
  t_philo_l	*list;

  list = (t_philo_l *)arg;
  while (list->eat_oc != 0)
    {
      if (list->food == 0 || list->think == 0)
	{
	  if (list->food == 0 &&
	      i_can_graille(list, list->next) == 0)
	    eat_action(list);
	  else if (list->think == 0 &&
		   i_can_think(list) == 0)
	    think_action(list);
	  else if (list->sleep == 0 &&
		   i_can_sleep(list) == 0)
	    sleep_action(list);
	}
      else if (list->sleep == 0 &&
	       i_can_sleep(list) == 0)
	sleep_action(list);
    }
  pthread_exit(0);
}

int		philo(int nb_philo, int eat_oc)
{
  t_philo_l	*list;
  t_philo_l	*tmp;
  int		i;

  i = 0;
  list = NULL;
  while (i != nb_philo)
    {
      if (init_list(&list, eat_oc) != 0)
	return (-1);
      i = i + 1;
    }
  tmp = list;
  while (tmp->next != list)
    {
      pthread_create(&tmp->core_philo, NULL, life_philo, tmp);
      tmp = tmp->next;
    }
  pthread_create(&tmp->core_philo, NULL, life_philo, tmp);
  tmp = list;
  while (tmp->next != list)
    {
      pthread_join(tmp->core_philo, NULL);
      tmp = tmp->next;
    }
  pthread_join(tmp->core_philo, NULL);
  return (0);
}
