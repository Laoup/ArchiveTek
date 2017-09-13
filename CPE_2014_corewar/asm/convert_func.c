/*
** convert_func.c for asm corewar in /home/meuric_a/CPE_2014_corewar_ODD/asm
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Thu Apr  2 13:45:17 2015 Alban Meurice
** Last update Sun Apr 12 20:20:25 2015 Moisset Raphael
*/

#include <stdlib.h>
#include <op.h>
#include "asm.h"
#include "my.h"

static	const	t_cmd	tab_cmd[17] =
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

int		*convert_line_hexa(char **tab, t_locl *line_stut)
{
  t_hex_t	stru_hex;

  stru_hex.hexa_line = NULL;
  if ((stru_hex.bin_line = malloc(5 * sizeof(int *))) == NULL)
    {
      my_putstr("Can't perform malloc\n");
      return (NULL);
    }
  stru_hex.word = NULL;
  stru_hex.nb = 0;
  stru_hex.nb_r = 0;
  stru_hex.nb_dir = 0;
  stru_hex.nb_ind = 0;
  if ((stru_hex.word = recup_first_word(tab, line_stut)) == NULL)
    return (NULL);
  if ((stru_hex.nb = cmd_is_true(stru_hex.word)) == -1)
    return (NULL);
  if (line_cmd_is_true(tab, &stru_hex, line_stut) == -1)
    return (NULL);
  if ((stru_hex.hexa_line = put_cmd_in_line(&stru_hex, line_stut, tab)) == NULL)
    return (NULL);
  return (stru_hex.hexa_line);
}

char		*recup_first_word(char **tab, t_locl *line_stut)
{
  char		*word;
  int		k;
  int		i;

  word = NULL;
  if (line_stut->loc == 1)
    if ((line_stut = begining_instruction(tab, line_stut)) == NULL)
      return (NULL);
  while (tab[line_stut->x][line_stut->y] < 'a' ||
	 tab[line_stut->x][line_stut->y] > 'z')
    line_stut->y = line_stut->y + 1;
  k = line_stut->y;
  while (tab[line_stut->x][line_stut->y] != ' ' &&
	 tab[line_stut->x][line_stut->y] != '\t')
    line_stut->y = line_stut->y + 1;
  if ((word = malloc(((line_stut->y - k) + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (k != line_stut->y)
    word[i++] = tab[line_stut->x][k++];
  word[i] = '\0';
  line_stut->loc = 0;
  return (word);
}

int	convert_bin_in_dec(t_hex_t *stru_hex)
{
  int	res;
  int	i;
  int	i2;
  int	pui;

  i = 0;
  i2 = 7;
  pui = 1;
  res = 0;
  while (i <= 7)
    {
      pui = 1 << i;
      res = res + (pui * stru_hex->bin_line[i2--]);
      i = i + 1;
    }
  return (res);
}

int	convert_bin_in_dec_by2(int *w_int)
{
  int	res;
  int	i;
  int	i2;
  int	pui;

  i = 0;
  i2 = 1;
  pui = 1;
  res = 0;
  while (i <= 1)
    {
      pui = 1 << i;
      res = res + (pui * w_int[i2--]);
      i = i + 1;
    }
  return (res);
}
