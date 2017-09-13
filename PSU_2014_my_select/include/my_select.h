/*
** my_select.h for my_select.h in /home/meuric_a/Project/my_select/V2.0
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Dec 30 02:19:02 2014 alban meurice
** Last update Sun Jan 11 23:19:42 2015 alban meurice
*/

#include <termios.h>

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

typedef	struct	s_list
{
  char		*str;
  int		reverse;
  struct s_list *next;
  struct s_list *prev;
}		t_list;

typedef struct	s_repere
{
  int		lenght;
  struct s_list	*head;
  struct s_list	*tail;
  struct s_list *cursor;
}		t_rep;

typedef struct	s_cursor_position
{
  int		x;
  int		y;
}		t_pos;

char	*my_getenv(char *, char **);
void	exit_prog(struct termios *, t_pos **, t_rep *);
void	my_select(t_rep *, struct termios *);
int	gere_key(char *, t_rep *, t_pos **, struct termios *);
void	init_glob(t_rep *, t_pos *, struct termios *);
int	first_init(struct termios *, t_rep **, char **);
int	back_list(t_pos **, t_rep **, struct termios *);
int	init_struct(struct termios *, char **);
int	back_param(struct termios *);
int	my_clear_screen();
int	start_soulignement();
int	end_soulignement(t_pos **,t_rep **);
int	start_rev_video();
int	end_rev_video();
int	my_put(int);
void	my_show_list_prev(t_rep *);
void	my_show_list_next(t_rep *, struct termios *);
void	my_show_list_elem(t_rep *);
void	my_put_end_list_first(t_rep **, t_list *);
int	*my_put_end_list(t_rep **, char *);
int	init_list(t_rep **);
int	init_pos(t_pos **);
int	go_head(t_pos **, t_rep **);
int	low_curs(t_pos **, t_rep **);
int	move_head(t_pos **, t_rep **);
int	move_low(t_pos **, t_rep **);
int	select_curs(t_pos **, t_rep **);
int	end_prog(t_rep **, struct termios *);
int	supr_elem(t_pos **, t_rep **, struct termios *);
void	supr_elem_in_list(t_pos **, t_rep **);
void	supr_head_list(t_rep **);
void	supr_tail_list(t_rep **);
void	supr_elem_list(t_rep **, t_rep *, t_list *);
int	my_strcmp(char *, char *);
char	*my_realloc(char *, char);
int	search_variable(char *, char **);
void	catch_resize(int);

#endif /* MY_SELECT_H_ */
