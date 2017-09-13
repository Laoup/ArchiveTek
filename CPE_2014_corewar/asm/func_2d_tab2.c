/*
** func_2d_tab2.c for asm corewar in /home/meuric_a/CPE_2014_corewar_ODD/asm
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Thu Apr  2 10:12:29 2015 Alban Meurice
** Last update Sun Apr 12 21:45:36 2015 Moisset Raphael
*/

#include <stdlib.h>
#include <op.h>
#include "asm.h"
#include "my.h"

char	**put_label_in_tab(char **cpy_tab, int x_ref, char *label)
{
  char	**new_tab;
  int	x;

  x = 0;
  if ((new_tab = malloc((x_ref + 1) * sizeof(char *))) == NULL)
    return (my_put_error_null("Can't perform malloc\n"));
  while (cpy_tab[x] != NULL)
    {
      if ((new_tab[x] = my_strdup(cpy_tab[x])) == NULL)
	return (NULL);
      x = x + 1;
    }
  if ((new_tab[x] = my_strdup(label)) == NULL)
    return (NULL);
  x = x + 1;
  new_tab[x] = NULL;
  return (new_tab);
}

int	*put_cmd_in_line(t_hex_t *stru_hex, t_locl *line_stut, char **tab)
{
  t_pc	pc;

  pc.size = size_malloc(stru_hex);
  pc.res_w = 0;
  if ((stru_hex->hexa_line = malloc((pc.size + 1) * sizeof(int))) == NULL)
    return (my_put_error_null("Can't perform malloc\n"));
  stru_hex->hexa_line[0] = 0x00 + stru_hex->nb;
  if (stru_hex->nb != 1)
    {
      stru_hex->hexa_line[1] = 0x00 + convert_bin_in_dec(stru_hex);
      pc.rep = 2;
    }
  else
    pc.rep = 1;
  pc.ver = 0;
  pc.k = 0;
  while (pc.ver == 0 && pc.k <= 7)
    if (put_cmd_inline1(stru_hex, line_stut, tab, &pc) == -1)
      return (NULL);
  return (stru_hex->hexa_line);
}

int	size_malloc(t_hex_t *stru_hex)
{
  int	size;
  int	x;

  size = 0;
  while (stru_hex->nb_r != 0)
    {
      stru_hex->nb_r = stru_hex->nb_r - 1;
      size = size + 1;
    }
  x = 0;
  while (stru_hex->nb_dir != 0 && x++)
    stru_hex->nb_dir = stru_hex->nb_dir - 1;
  size = size + (x * DIR_SIZE);
  x = 0;
  while (stru_hex->nb_ind != 0)
    {
      stru_hex->nb_ind = stru_hex->nb_ind - 1;
      x = x + 1;
    }
  size = size + (x * IND_SIZE);
  if (stru_hex->nb != 1)
    return (size + 2);
  else
    return (size + 1);
}

int	*put_in_bin_line(int *bin_line, int *w_bin, int end)
{
  static int	n;

  if (end == 0)
    n = 0;
  else
    {
      bin_line[n++] = w_bin[0];
      bin_line[n++] = w_bin[1];
    }
  return (bin_line);
}

char	**clear_tab(char **tab)
{
  int	x;

  x = 0;
  while (tab[x] != NULL)
    {
      if (line_null(tab, x) == 0)
	tab[x][0] = '\0';
      x = x + 1;
    }
  return (tab);
}
