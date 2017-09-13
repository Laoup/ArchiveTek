/*
** func_list.c for func_list in /home/meuric_a/Projet_T2/Philosophe/PSU_2015_philo/src
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Fri Mar 11 00:19:49 2016 Alban Meurice
** Last update Sun Mar 13 17:17:08 2016 Alban Meurice
*/

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

int	init_list(t_philo_l **list, int eat_oc)
{
  t_philo_l	*tmp;
  t_philo_l	*n_elem;

  tmp = (*list);
  n_elem = NULL;
  if ((n_elem = malloc(sizeof(t_philo_l))) == NULL)
    return (-1);
  if (pthread_mutex_init(&n_elem->chopstick, NULL) != 0)
    return (-1);
  n_elem->use = 0;
  n_elem->food = 0;
  n_elem->sleep = 0;
  n_elem->think = 0;
  n_elem->eat_oc = eat_oc;
  if ((*list) == NULL)
    {
      n_elem->next = n_elem;
      (*list) = n_elem;
      return (0);
    }
  while (tmp->next != (*list))
    tmp = tmp->next;
  n_elem->next = (*list);
  tmp->next = n_elem;
  return (0);
}
