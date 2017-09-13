/*
** search_line.c for asm corewar in /home/meuric_a/CPE_2014_corewar_ODD/asm
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Wed Apr  1 10:36:40 2015 Alban Meurice
** Last update Sun Apr 12 21:54:37 2015 Moisset Raphael
*/

#include <stdlib.h>
#include "asm.h"

void		search_first_line(char **tab, t_locl *line_stut)
{
  while (its_my_line(tab, line_stut) == -1)
    line_stut->x = line_stut->x + 1;
  if (tab[line_stut->x][line_stut->y] == ' ')
    {
      if (check_is_cmd(tab, line_stut->x, line_stut->y) == -1)
	exit(-1);
    }
  else if (tab[line_stut->x][line_stut->y] >= 'a' &&
	   tab[line_stut->x][line_stut->y] <= 'z')
    {
      line_stut->loc = 1;
      if (check_is_label(tab, line_stut->x, line_stut->y) == -1)
	exit(-1);
    }
}

int	its_my_line(char **tab, t_locl *line_stut)
{
  int	lock;

  lock = -1;
  if (tab[line_stut->x][line_stut->y] >= 'a' &&
      tab[line_stut->x][line_stut->y] <= 'z')
    lock = 0;
  else if (tab[line_stut->x][line_stut->y] == ' ')
    lock = 0;
  return (lock);
}

t_locl		*begining_instruction(char **tab, t_locl *line_stut)
{
  char		*label_str;

  line_stut->y = 0;
  while (tab[line_stut->x][line_stut->y] != ':')
    line_stut->y = line_stut->y + 1;
  if ((label_str = malloc((line_stut->y + 1) * sizeof(char))) == NULL)
    return (NULL);
  line_stut->y = 0;
  while (tab[line_stut->x][line_stut->y] != ':')
    {
      label_str[line_stut->y] = tab[line_stut->x][line_stut->y];
      line_stut->y = line_stut->y + 1;
    }
  label_str[line_stut->y] = '\0';
  if ((line_stut = put_in_tab_label(label_str, line_stut)) == NULL)
    return (NULL);
  while ((tab[line_stut->x][line_stut->y] < 'a' || tab[line_stut->x]
	  [line_stut->y] > 'z') && (tab[line_stut->x][line_stut->y] < 'A' &&
				    tab[line_stut->x][line_stut->y] > 'Z'))
    line_stut->y = line_stut->y + 1;
  return (line_stut);
}
