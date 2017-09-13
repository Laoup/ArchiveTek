/*
** end.c for my_select.c in /home/meuric_a/Project/my_select/V5.0_NORME/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sun Jan 11 12:03:33 2015 alban meurice
** Last update Sun Jan 11 23:35:57 2015 alban meurice
*/

#include <termios.h>
#include <stdlib.h>
#include "../include/my_select.h"
#include "../include/my.h"

void	exit_prog(struct termios *term, t_pos **curs_position, t_rep *repere)
{
  end_soulignement(curs_position, &repere);
  end_rev_video();
  my_clear_screen();
  back_param(term);
  exit(0);
}
