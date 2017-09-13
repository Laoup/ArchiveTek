/*
** my_putchar.c for my_putchar in /home/jallut_p/git_repos/Piscine/Piscine_C_J04/tests
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Thu Oct  2 11:05:07 2014 pierre jallut
** Last update Wed Apr 22 14:10:19 2015 pierre jallut
*/

#include <unistd.h>
#include "nest.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
