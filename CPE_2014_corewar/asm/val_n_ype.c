/*
** val_n_ype.c for corewar asm in /home/meuric_a/CPE_2014_corewar_ODD/asm
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Tue Apr  7 10:23:27 2015 Alban Meurice
** Last update Sun Apr 12 22:12:56 2015 Moisset Raphael
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

void	val_n_arg1(t_locl *line_stut, char **tab, int *n)
{
  if ((tab[line_stut->x][line_stut->y] == 'r') ||
      (tab[line_stut->x][line_stut->y] == '%'))
    *n = *n + 1;
  else if (tab[line_stut->x][line_stut->y - 1] == ',' && (tab[line_stut->x]
							  [line_stut->y] >= '0' && tab[line_stut->x][line_stut->y] <= '9'))
    *n = *n + 1;
  line_stut->y = line_stut->y + 1;
}

int	val(t_locl *line_stut, char **tab, int count)
{
  int	n;

  n = 0;
  while (tab[line_stut->x][line_stut->y] != '\0')
    {
      if (n == count)
	{
	  if (n == 0)
	    {
	      while (tab[line_stut->x][line_stut->y] == ' ' ||
		     tab[line_stut->x][line_stut->y] == '\t')
		line_stut->y = line_stut->y + 1;
	      line_stut->y = line_stut->y + 1;
	    }
	  if (tab[line_stut->x][line_stut->y] < '0' &&
	      tab[line_stut->x][line_stut->y] > '9')
	    return (-1);
	  return (return_val_type(line_stut, tab));
	}
      val_n_arg1(line_stut, tab, &n);
    }
  return (-1);
}

int	return_val_type(t_locl *line_stut, char **tab)
{
  char	*nb_str;
  int	c;
  int	i;

  nb_str = NULL;
  i = line_stut->y;
  c = 0;
  while (tab[line_stut->x][line_stut->y] >= '0' &&
	 tab[line_stut->x][line_stut->y] <= '9')
    {
      line_stut->y = line_stut->y + 1;
      c = c + 1;
    }
  if ((nb_str = malloc((c + 1) * sizeof(char))) == NULL)
    exit(-1);
  line_stut->y = i;
  i = 0;
  while (i != c)
    nb_str[i++] = tab[line_stut->x][line_stut->y++];
  nb_str[i] = '\0';
  return (my_getnbr(nb_str));
}
