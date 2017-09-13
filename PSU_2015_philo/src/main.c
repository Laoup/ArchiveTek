/*
** main.c for philo in /home/meuric_a/Projet_T2/Philosophe/PSU_2015_philo/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Mar  3 23:07:50 2016 Alban Meurice
** Last update Sun Mar 13 19:00:41 2016 Alban Meurice
*/

#include "philo.h"
#include "extern.h"
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
  if (argc == 5)
    {
      if (strcmp(argv[1], "-p") == 0 && strcmp(argv[3], "-e") == 0)
	{
	  if (opt1(argc, argv) != 0)
	    return (-1);
	}
      else if (strcmp(argv[1], "-e") == 0 && strcmp(argv[3], "-p") == 0)
	{
	  if (opt2(argc, argv) != 0)
	    return (-1);
	}
      else
	return (-1);
      return (0);
    }
  return (-1);
}

int	opt1(int argc, char **argv)
{
  int	arg1;
  int	arg2;

  if (is_nbr(argv[2]) != 0 || is_nbr(argv[4]) != 0)
    return (-1);
  arg1 = atoi(argv[2]);
  arg2 = atoi(argv[4]);
  if (arg1 <= 1 || arg2 <= 0)
    return (-1);
  RCFStartup(argc, argv);
  philo(atoi(argv[2]), atoi(argv[4]));
  RCFCleanup();
  return (0);
}

int	opt2(int argc, char **argv)
{
  int	arg1;
  int	arg2;

  if (is_nbr(argv[2]) != 0 || is_nbr(argv[4]) != 0)
    return (-1);
  arg1 = atoi(argv[2]);
  arg2 = atoi(argv[4]);
  if (arg1 <= 0 || arg2 <= 1)
    return (-1);
  RCFStartup(argc, argv);
  philo(atoi(argv[4]), atoi(argv[2]));
  RCFCleanup();
  return (0);
}
