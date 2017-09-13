/*
** check_funcV2.c for asm corewar in /home/meuric_a/CPE_2014_corewar_ODD/asm
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Wed Apr  1 10:45:19 2015 Alban Meurice
** Last update Sun Apr 12 20:41:05 2015 Moisset Raphael
*/

#include <stdlib.h>
#include <op.h>
#include "my.h"
#include "asm.h"

static const	t_cmd	tab_cmd[17] =
  {
    {"live"},
    {"ld"},
    {"st"},
    {"add"},
    {"sub"},
    {"and"},
    {"or"},
    {"xor"},
    {"zjmp"},
    {"ldi"},
    {"sti"},
    {"fork"},
    {"lld"},
    {"lldi"},
    {"lfork"},
    {"aff"},
    {NULL},
  };

int	check_is_cmd(char **tab, int x, int y)
{
  int	k;
  int	l;
  char	*cmd;

  while ((tab[x][y] < 'a' || tab[x][y] > 'z'))
    if (tab[x][y++] == '\0')
      return (-1);
  k = y;
  while (check_is_cmd_search_separation(tab, x, y) != 0)
    y = y + 1;
  if ((cmd = malloc(((y - k) + 1) * sizeof(char))) == NULL)
    return (my_put_error("Can't perform malloc\n", -1));
  l = 0;
  while (k != y)
    cmd[l++] = tab[x][k++];
  cmd[l] = '\0';
  k = 0;
  while (tab_cmd[k].str != NULL)
    if (my_strcmp(tab_cmd[k++].str, cmd) == 0)
      return (0);
  my_putstr("Syntax error line ");
  my_put_nbr(x + 1);
  return (my_put_error("\n", -1));
}

int	check_is_label(char **tab, int x, int y)
{
  while (tab[x][y] != ':')
    {
      if (tab[x][y] == '\0')
	{
	  my_putstr("Syntax error line ");
	  my_put_nbr(x + 1);
	  return (my_put_error("\n", -1));
	}
      y = y + 1;
    }
  if (tab[x][y - 1] == ' ')
    {
      my_putstr("Syntax error line ");
      my_put_nbr(x + 1);
      return (my_put_error("\n", -1));
    }
  if (check_is_cmd(tab, x, y) == -1)
    {
      my_putstr("Syntax error line ");
      my_put_nbr(x + 1);
      return (my_put_error("\n", -1));
    }
  return (0);
}

int	check_is_next_instruction(char **tab, t_locl *line_stut)
{
  line_stut->y = 0;
  if (tab[line_stut->x][0] == ' ' || tab[line_stut->x][0] == '\t')
    while (tab[line_stut->x][line_stut->y] != '\0')
      {
	if (tab[line_stut->x][line_stut->y] != ' ' ||
	    tab[line_stut->x][line_stut->y] != '\t')
	  return (0);
	line_stut->y = line_stut->y + 1;
      }
  else if ((tab[line_stut->x][0] >= 'a' && tab[line_stut->x][0] <= 'z')
	   || (tab[line_stut->x][0] >= 'A' && tab[line_stut->x][0] <= 'Z'))
    {
      line_stut->loc = 1;
      while (tab[line_stut->x][line_stut->y++] != ':')
	if (bad_caractere(tab, line_stut) == 0)
	  return (-1);
    }
  else
    {
      if (jump_line(tab, line_stut) == 0)
	return (1);
      return (-1);
    }
  return (0);
}

int	cmd_is_true(char *str)
{
  int	x;

  x = 0;
  while (op_tab[x].mnemonique != 0)
    {
      if (my_strcmp(op_tab[x].mnemonique, str) == 0)
	return (x + 1);
      x = x + 1;
    }
  return (-1);
}

int	line_cmd_is_true(char **tab, t_hex_t *stru_hex, t_locl *line_stut)
{
  t_lc	lc;

  lc.y_pos_save = line_stut->y;
  lc.n_elem = 0;
  if ((lc.w_bin = malloc(2 * sizeof(int))) == NULL)
    return (my_put_error("Can't perform malloc\n", -1));
  while (tab[line_stut->x][line_stut->y] != '\0')
    {
      lc.tru_e = 0;
      while (lc.tru_e == 0)
	{
	  if (line_cmd_istrue1(tab, stru_hex, line_stut, &lc) == -1)
	    return (-1);
	  if (lc.tru_e == 0)
	    line_stut->y = line_stut->y + 1;
	}
      if (tab[line_stut->x][line_stut->y] != '\0')
	line_stut->y = line_stut->y + 1;
    }
  put_in_bin_line(stru_hex->bin_line, lc.w_bin, 0);
  line_stut->y = lc.y_pos_save;
  return (0);
}
