/*
** signal.c for my_select.c in /home/meuric_a/Project/my_select/V5.0_NORME/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sun Jan 11 14:40:01 2015 alban meurice
** Last update Sun Jan 11 16:26:36 2015 alban meurice
*/

#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <sys/ioctl.h>
#include <signal.h>
#include "../include/my_select.h"
#include "../include/my.h"
#include "../include/my_glob.h"

void			catch_resize(int a)
{
  struct winsize	size_term;

  (void)a;
  go_head(&curs_glob, &repere_glob);
  ioctl(0, TIOCGWINSZ, &size_term);
  end_soulignement(&curs_glob, &repere_glob);
  my_clear_screen();
  my_show_list_next(repere_glob, term_glob);
  go_head(&curs_glob, &repere_glob);
}
