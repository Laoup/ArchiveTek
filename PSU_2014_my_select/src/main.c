/*
** main.c for my_select in /home/meuric_a/Project/my_select/V2.0
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Dec 30 02:18:38 2014 alban meurice
** Last update Sun Jan 11 23:30:40 2015 alban meurice
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <ncurses/curses.h>
#include <signal.h>
#include "../include/my_select.h"
#include "../include/my_glob.h"

int			back_list(t_pos **curs_position, t_rep **repere, struct termios *term)
{
  if (end_soulignement(curs_position, repere) == -1)
    return (-1);
  if (my_clear_screen() == -1)
    return (-1);
  if (init_pos(curs_position) == -1)
    return (-1);
  my_show_list_next(*repere, term);
  if (go_head(curs_position, repere) == -1)
    return (-1);
  return (0);
}

void			init_glob(t_rep *repere, t_pos *curs_position, struct termios *term)
{
  repere_glob = repere;
  curs_glob = curs_position;
  term_glob = term;
}

void			my_select(t_rep *repere, struct termios *term)
{
  t_pos			*curs_position;
  char			buffer[3];

  my_show_list_next(repere, term);
  if (init_pos(&curs_position) == -1)
    exit_prog(term, &curs_position, repere);
  if (go_head(&curs_position, &repere) == -1)
    exit_prog(term, &curs_position, repere);
  init_glob(repere, curs_position, term);
  while (read(0, buffer, 3) > 0)
    {
      init_glob(repere, curs_position, term);
      if (gere_key(buffer, repere, &curs_position, term) == -1)
	exit_prog(term, &curs_position, repere);
      buffer[0] = 0;
      buffer[1] = 0;
      buffer[2] = 0;
    }
}

int			first_init(struct termios *term, t_rep **repere, char **env)
{
  char			*res;

  signal(SIGWINCH, &catch_resize);
  if (init_struct(term, env) == -1)
    return (-1);
  if (init_list(repere) == -1)
    return (-1);
  if (my_clear_screen() == -1)
    return (-1);
  if ((res = tgetstr("vi", NULL)) == NULL)
    return (-1);
  tputs(res, 0, &my_put);
  return (0);
}

int			main(int argc, char **argv, char **env)
{
  struct termios	term;
  t_rep			*repere;
  int			i;

  repere = NULL;
  i = 1;
  if (first_init(&term, &repere, env) == -1)
    return (-1);
  if (argc > 1)
    {
      while (argv[i])
	{
	  if ((my_put_end_list(&repere, argv[i])) == 0)
	    i = i + 1;
	  else
	    return (-1);
	}
      my_select(repere, &term);
    }
  back_param(&term);
  return (0);
}
