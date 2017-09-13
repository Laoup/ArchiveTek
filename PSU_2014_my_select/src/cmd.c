/*
** cmd.c for my_select in /home/meuric_a/Project/my_select/V5.0_NORME/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sun Jan 11 22:23:04 2015 alban meurice
** Last update Sun Jan 11 23:27:11 2015 alban meurice
*/

#include "../include/my_select.h"

int	gere_key(char *buffer, t_rep *repere, t_pos **curs_position,
		  struct termios *term)
{
  if ((buffer[0] == 27) && (buffer[2] == 66))
    low_curs(curs_position, &repere);
  if (buffer[0] == ' ')
    if (select_curs(curs_position, &repere) == -1)
      return (-1);
  if (buffer[0] == 10)
    end_prog(&repere, term);
  if (buffer[0] == 127)
    if (supr_elem(curs_position, &repere, term) == -1)
      return (-1);
  if ((buffer[0] == 27) && (buffer[2] == 0))
    exit_prog(term, curs_position, repere);
  return (0);
}
