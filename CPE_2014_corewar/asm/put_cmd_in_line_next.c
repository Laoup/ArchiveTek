/*
** put_cmd_in_line_next.c for asm in /home/guzman_y/save_corewar_meuric_a/asm
**
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
**
** Started on  Sun Apr 12 10:05:55 2015 yoann guzman
** Last update Sun Apr 12 22:12:44 2015 Moisset Raphael
*/

#include <stdlib.h>
#include "asm.h"

int	put_cmd_inline2(t_hex_t *stru_hex, t_pc *pc)
{
  pc->i = 0;
  pc->count = 0;
  if ((pc->w_int = malloc(2 * sizeof(int))) == NULL)
    return (-1);
  while (pc->i <= 1)
    pc->w_int[pc->i++] = stru_hex->bin_line[pc->k++];
  pc->res_w = convert_bin_in_dec_by2(pc->w_int);
  pc->i = 0;
  return (0);
}

int		put_cmd_inline1(t_hex_t *stru_hex, t_locl *line_stut, char **tab, t_pc *pc)
{
  if (put_cmd_inline2(stru_hex, pc) == -1)
    return (-1);
  if (pc->res_w == 0)
    pc->ver = 1;
  else if (pc->res_w == 1)
    stru_hex->hexa_line[pc->rep++] = 0x00 + val(line_stut, tab, pc->count++);
  else if (pc->res_w == 2)
    {
      while (pc->i < DIR_SIZE - 1)
	{
	  stru_hex->hexa_line[pc->rep++] = 0x00;
	  pc->i = pc->i + 1;
	}
      stru_hex->hexa_line[pc->rep++] = 0x00 + val(line_stut, tab, pc->count++);
    }
  else if (pc->res_w == 3)
    {
      while (pc->i < IND_SIZE - 1)
	{
	  stru_hex->hexa_line[pc->rep++] = 0x00;
	  pc->i = pc->i + 1;
	}
      stru_hex->hexa_line[pc->rep++] = 0x00 + val(line_stut, tab, pc->count++);
    }
  return (0);
}
