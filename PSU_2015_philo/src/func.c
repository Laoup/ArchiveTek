/*
** func.c for philo in /home/meuric_a/Projet_T2/Philosophe/PSU_2015_philo/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sun Mar  6 20:17:18 2016 Alban Meurice
** Last update Sun Mar 13 17:55:59 2016 Alban Meurice
*/

#include "philo.h"
#include "extern.h"
#include <pthread.h>
#include <unistd.h>

void	eat_action(t_philo_l *list)
{
  list->use = 1;
  list->next->use = 1;
  pthread_mutex_trylock(&list->chopstick);
  lphilo_take_chopstick(&list->chopstick);
  pthread_mutex_trylock(&list->next->chopstick);
  lphilo_take_chopstick(&list->next->chopstick);
  lphilo_eat();
  list->food = 1;
  list->sleep = 0;
  usleep(500);
  list->eat_oc -= 1;
  lphilo_release_chopstick(&list->chopstick);
  pthread_mutex_unlock(&list->chopstick);
  list->use = 0;
  lphilo_release_chopstick(&list->next->chopstick);
  pthread_mutex_unlock(&list->next->chopstick);
  list->next->use = 0;
}

void	think_action(t_philo_l *list)
{
  if (pthread_mutex_trylock(&list->chopstick) == 0)
    {
      list->use = 1;
      lphilo_take_chopstick(&list->chopstick);
      lphilo_think();
      list->think = 1;
      usleep(500);
      lphilo_release_chopstick(&list->chopstick);
      pthread_mutex_unlock(&list->chopstick);
      list->use = 0;
    }
}

void	sleep_action(t_philo_l *list)
{
  lphilo_sleep();
  list->think = 0;
  list->food = 0;
  list->sleep = 1;
  usleep(500);
}
