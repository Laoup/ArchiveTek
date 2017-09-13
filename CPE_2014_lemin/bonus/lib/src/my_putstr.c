/*
** my_putstr.c for my_putstr in /home/jallut_p/git_repos/Piscine/Piscine_C_J03
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Thu Oct  2 11:27:37 2014 pierre jallut
** Last update Wed Apr 22 14:10:27 2015 pierre jallut
*/

#include <unistd.h>
#include "nest.h"

void	 my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
