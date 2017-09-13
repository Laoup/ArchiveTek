/*
** func_pars.c for client minitalk in /home/meuric_a/Project/Minitalk/V1.0/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Mar 17 20:20:38 2015 Alban Meurice
** Last update Tue Mar 17 20:30:32 2015 Alban Meurice
*/

#include "minitalk.h"

int	check_string(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'a' && str[i] > 'z')
	if (str[i] < 'A' && str[i] > 'Z')
	  return (-1);
      i = i + 1;
    }
  return (0);
}
