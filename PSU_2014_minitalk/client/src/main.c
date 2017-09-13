/*
** main.c for client Minitalk in /home/meuric_a/Project/Minitalk/V1.0/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Mar 17 20:08:55 2015 Alban Meurice
** Last update Thu Mar 19 13:13:28 2015 Alban Meurice
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "my_glob.h"
#include "minitalk.h"
#include "my.h"

int	send_letter(int *my_bin, int pid)
{
  int	i;

  i = 7;
  while (i >= 0)
    {
      if (my_bin[i] == 0)
	{
	  if (kill(pid, 10) == -1)
	    return (-1);
	}
      else if (my_bin[i] == 1)
	{
	  if (kill(pid, 12) == -1)
	    return (-1);
	}
      else
	return (-1);
      i = i - 1;
      usleep(2000);
    }
  return (0);
}

int	client(int pid, char *str)
{
  int	*my_bin;
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((my_bin = conv_bin(str[i])) == NULL)
	return (-1);
      if (send_letter(my_bin, pid) == -1)
	return (-1);
      i = i + 1;
    }
  if ((my_bin = conv_bin('\0')) == NULL)
    return (-1);
  if (send_letter(my_bin, pid) == -1)
    return (-1);
  return (0);
}

int	main(int argc, char **argv)
{
  int	pid;

  if (argc == 3)
    {
      if ((pid = my_getnbr(argv[1])) == -1)
	return (-1);
      if (check_string(argv[2]) == -1)
	return (-1);
      if (client(pid, argv[2]) == -1)
	return (-1);
      return (0);
    }
  else
    {
      my_putstr(
		"Veuilliez entrer le PID du serveur puis le message a envoyer");
      my_putchar('\n');
      return (-1);
    }
}
