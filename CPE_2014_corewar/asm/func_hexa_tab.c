/*
** func_hexa_tab.c for corewar asm in /home/meuric_a/CPE_2014_corewar_ODD/asm
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Tue Apr  7 12:04:16 2015 Alban Meurice
** Last update Sun Apr 12 21:51:23 2015 Moisset Raphael
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

int	**put_in_hexa_tab(int *hexa_line, int **hexa_file)
{
  int	**cpy;
  int	x;

  x = 0;
  if (hexa_file == NULL)
    {
      if ((hexa_file = malloc(2 * sizeof(int *))) == NULL)
	return (my_put_error_null("Can't perform malloc\n"));
      hexa_file[0] = hexa_line;
      hexa_file[1] = NULL;
      return (hexa_file);
    }
  while (hexa_file[x] != NULL)
    x = x + 1;
  if ((cpy = malloc((x + 2) * sizeof(int *))) == NULL)
    return (my_put_error_null("Can't perform malloc\n"));
  x = 0;
  while (hexa_file[x] != NULL)
    {
      cpy[x] = hexa_file[x];
      x = x + 1;
    }
  cpy[x] = hexa_line;
  cpy[x + 1] = NULL;
  return (cpy);
}
