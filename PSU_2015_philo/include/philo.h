/*
** philo.h for philosophe in /home/meuric_a/Projet_T2/Philosophe/PSU_2015_philo/include
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sun Mar  6 18:32:51 2016 Alban Meurice
** Last update Sun Mar 13 18:54:00 2016 Alban Meurice
*/

#ifndef PHILO_H_
# define PHILO_H_

#include <pthread.h>

typedef	struct		s_1philo_l
{
  pthread_t	       	core_philo;
  pthread_mutex_t	chopstick;
  int			use;
  int			food;
  int			sleep;
  int			think;
  int			eat_oc;
  struct s_1philo_l	*next;
}			t_philo_l;

int	opt1(int, char **);
int	opt2(int, char **);

int	philo(int, int);
int	is_nbr(char *);
int	i_can_graille(t_philo_l *, t_philo_l *);
int	i_can_think(t_philo_l *);
int	i_can_sleep(t_philo_l *);

int	init_list(t_philo_l **, int);

void	*life_philo(void *);
void	eat_action(t_philo_l *);
void	think_action(t_philo_l *);
void	sleep_action(t_philo_l *);

#endif /* PHILO_H_ */
