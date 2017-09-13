/*
** check_funcV2_1.c for asm corewar in /home/meuric_a/CPE_2014_corewar_ODD/asm
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Apr  3 10:22:36 2015 Alban Meurice
** Last update Sun Apr 12 09:20:28 2015 yoann guzman
*/

#include <op.h>
#include "asm.h"

int	check_op_tab(int n_elem, int nb, args_type_t type)
{
  if (op_tab[nb].type[n_elem] == 3)
    {
      if (type == 1 || type == 2)
	return (0);
    }
  else if (op_tab[nb].type[n_elem] == 5)
    {
      if (type == 1 || type == 4)
	return (0);
    }
  else if (op_tab[nb].type[n_elem] == 6)
    {
      if (type == 2 || type == 4)
	return (0);
    }
  else if (op_tab[nb].type[n_elem] == 7)
    {
      if (type == 2 || type == 4 || type == 1)
	return (0);
    }
  else if (op_tab[nb].type[n_elem] == type)
    return (0);
  return (-1);
}

int	bad_caractere(char **tab, t_locl *line_stut)
{
  if (tab[line_stut->x][line_stut->y] == '\0')
    return (0);
  else if (tab[line_stut->x][line_stut->y] == '\t')
    return (0);
  else if (tab[line_stut->x][line_stut->y] == ' ')
    return (0);
  return (-1);
}

int	jump_line2(char **tab, t_locl *line_stut)
{
  line_stut->loc = 1;
  while (tab[line_stut->x][line_stut->y] != ':')
    {
      if (bad_caractere(tab, line_stut) == 0)
	return (-1);
      line_stut->y = line_stut->y + 1;
    }
  return (0);
}

int	jump_line(char **tab, t_locl *line_stut)
{
  line_stut->x = line_stut->x + 1;
  line_stut->y = 0;
  if (tab[line_stut->x][0] == ' ' || tab[line_stut->x][0] == '\t')
    {
      while (tab[line_stut->x][line_stut->y] != '\0')
	{
	  if (tab[line_stut->x][line_stut->y] != ' ' ||
	      tab[line_stut->x][line_stut->y] != '\t')
	    {
	      line_stut->x = line_stut->x - 1;
	      return (0);
	    }
	  line_stut->y = line_stut->y + 1;
	}
    }
  else if ((tab[line_stut->x][0] >= 'a' && tab[line_stut->x][0] <= 'z')
           || (tab[line_stut->x][0] >= 'A' && tab[line_stut->x][0] <= 'Z'))
    {
      if (jump_line2(tab, line_stut) == -1)
	return (-1);
    }
  else
    return (-1);
  line_stut->x = line_stut->x - 1;
  return (0);
}

int	line_null(char **tab, int x)
{
  int	y;

  y = 0;
  if (tab[x][0] != '\0')
    {
      while (tab[x][y] != '\0')
	{
	  if (tab[x][y] != ' ' && tab[x][y] != '\t')
	    return (-1);
	  y = y + 1;
	}
      return (0);
    }
  else
    return (0);
}
