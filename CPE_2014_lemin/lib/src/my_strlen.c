/*
** my_strlen.c for my_strlen in /home/jallut_p/git_repos/Piscine/Piscine_C_J04
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Thu Oct  2 12:29:44 2014 pierre jallut
** Last update Wed Apr 22 14:21:07 2015 pierre jallut
*/

#include "nest.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
