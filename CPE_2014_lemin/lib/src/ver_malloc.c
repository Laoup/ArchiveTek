/*
** ver_malloc.c for lib in /home/meuric_a/Project/Minishell1/V3.0/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jan 23 17:35:16 2015 alban meurice
** Last update Fri May  1 16:28:12 2015 pierre jallut
*/

#include <stdlib.h>
#include "nest.h"

void	*ver_maloc(char *str, void *val_malloc)
{
  if (val_malloc == 0)
    {
      my_puterror(str);
      my_putchar('\n');
      exit(-1);
    }
  return (val_malloc);
}
