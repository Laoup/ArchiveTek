/*
** parsing.c for Corewar_asm in /home/meuric_a/Project/Corewar
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Thu Mar 26 10:53:47 2015 Alban Meurice
** Last update Sun Apr  5 21:21:18 2015 Moisset Raphael
*/

#include <op.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"

int	my_pars(char *file)
{
  int	i;
  int	fd;
  int	l;

  i = 0;
  while (file[i] != '\0')
    i = i + 1;
  i = i - 2;
  if (file[i] != '.')
    return (-1);
  i = i + 1;
  if (file[i] != 's')
    return (-1);
  if (file[i + 1] != '\0')
    return (-1);
  l = i;
  while (i != 0 && file[i] != '/')
    i = i - 1;
  if (file[i] == '/')
    i++;
  l = l - i;
  if ((fd = my_read_av(file, l, i)) == -1)
    return (-1);
  return (fd);
}
