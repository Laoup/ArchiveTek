/*
** hexa_code.c for asm corewar in /home/meuric_a/CPE_2014_corewar_ODD/asm
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Wed Apr  1 10:35:01 2015 Alban Meurice
** Last update Sun Apr 12 20:39:02 2015 Moisset Raphael
*/

#include <stdlib.h>
#include "asm.h"

#include "my.h"

int		**write_hex_code(char **tab)
{
  int		**hexa_file;
  t_locl	line_stut;

  hexa_file = NULL;
  line_stut.tab_label = NULL;
  line_stut.x = 0;
  line_stut.y = 0;
  line_stut.loc = 0;
  search_first_line(tab, &line_stut);
  if ((hexa_file = convert_block(tab, &line_stut)) == NULL)
    return (NULL);
  return (hexa_file);
}

int		convert_block1(char **tab, t_locl *line_stut, int **hexa_line)
{
  line_stut->y = 0;
  if (line_stut->loc == 1)
    if ((line_stut = begining_instruction(tab, line_stut)) == NULL)
      return (-1);
  if ((*hexa_line = convert_line_hexa(tab, line_stut)) == NULL)
    return (-1);
  return (0);
}

int		**convert_block(char **tab, t_locl *line_stut)
{
  int		*hexa_line;
  int		**hexa_file;
  int		ok;

  hexa_file = NULL;
  hexa_line = NULL;
  if (line_stut->loc == 1)
    if ((line_stut = begining_instruction(tab, line_stut)) == NULL)
      return (NULL);
  ok = check_is_next_instruction(tab, line_stut);
  while (ok != -1)
    {
      if ((ok = check_is_next_instruction(tab, line_stut)) == 1)
	line_stut->x = line_stut->x + 1;
      if (ok != -1)
	{
	  if (convert_block1(tab, line_stut, &hexa_line) == -1)
	    return (NULL);
	  if ((hexa_file = put_in_hexa_tab(hexa_line, hexa_file)) == NULL)
	    return (NULL);
	  line_stut->x = line_stut->x + 1;
	}
    }
  return (hexa_file);
}
