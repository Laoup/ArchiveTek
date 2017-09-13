/*
** line_cmd_is_true_next.c for asm in /home/guzman_y/save_corewar_meuric_a/asm
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Sun Apr 12 09:27:27 2015 yoann guzman
** Last update Sun Apr 12 11:23:01 2015 yoann guzman
*/

#include "asm.h"

int	line_cmd_istrue3(char **tab, t_hex_t *stru_hex, t_locl *line_stut, t_lc *lc)
{
  stru_hex->nb_dir = stru_hex->nb_dir + 1;
  lc->tru_e = 1;
  if (check_op_tab(lc->n_elem, stru_hex->nb - 1, T_DIR) == -1)
    return (-1);
  lc->w_bin[0] = 1;
  lc->w_bin[1] = 0;
  stru_hex->bin_line = put_in_bin_line(stru_hex->bin_line, lc->w_bin, 1);
  lc->n_elem = lc->n_elem + 1;
  while ((tab[line_stut->x][line_stut->y] != ',') &&
	 (tab[line_stut->x][line_stut->y] != '\0'))
    line_stut->y = line_stut->y + 1;
  return (0);
}

int	line_cmd_istrue2(char **tab, t_hex_t *stru_hex, t_locl *line_stut, t_lc *lc)
{
  stru_hex->nb_ind = stru_hex->nb_ind + 1;
  lc->tru_e = 1;
  if (check_op_tab(lc->n_elem, stru_hex->nb - 1, T_IND) == -1)
    return (-1);
  lc->w_bin[0] = 1;
  lc->w_bin[1] = 1;
  stru_hex->bin_line = put_in_bin_line(stru_hex->bin_line, lc->w_bin, 1);
  lc->n_elem = lc->n_elem + 1;
  while ((tab[line_stut->x][line_stut->y] != ',') &&
	 (tab[line_stut->x][line_stut->y] != '\0'))
    line_stut->y = line_stut->y + 1;
  return (0);
}

int	line_cmd_istrue1(char **tab, t_hex_t *stru_hex, t_locl *line_stut, t_lc *lc)
{
  if (tab[line_stut->x][line_stut->y] == '\0')
    lc ->tru_e = 1;
  if (tab[line_stut->x][line_stut->y] == 'r')
    {
      stru_hex->nb_r = stru_hex->nb_r + 1;
      lc->tru_e = 1;
      if (check_op_tab(lc->n_elem, stru_hex->nb - 1, T_REG) == -1)
	return (-1);
      lc->w_bin[0] = 0;
      lc->w_bin[1] = 1;
      stru_hex->bin_line = put_in_bin_line(stru_hex->bin_line, lc->w_bin, 1);
      lc->n_elem = lc->n_elem + 1;
      while ((tab[line_stut->x][line_stut->y] != ',') &&
	     (tab[line_stut->x][line_stut->y++] != '\0'));
    }
  else if (tab[line_stut->x][line_stut->y] == '%')
    {
      if (line_cmd_istrue3(tab, stru_hex, line_stut, lc) == -1)
	return (-1);
    }
  else if (tab[line_stut->x][line_stut->y] >= '0' &&
	   tab[line_stut->x][line_stut->y] <= '9')
    if (line_cmd_istrue3(tab, stru_hex, line_stut, lc) == -1)
      return (-1);
  return (0);
}
