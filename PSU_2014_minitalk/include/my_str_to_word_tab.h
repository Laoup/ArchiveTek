/*
** my_str_to_word_tab.h for lib in /home/meuric_a/Project/Minishell1/V3.0/include
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jan 23 14:23:04 2015 alban meurice
** Last update Sun Mar 15 22:25:08 2015 Alban Meurice
*/

#ifndef MY_STR_TO_WORD_TAB_H_
# define MY_STR_TO_WORD_TAB_H_

typedef struct	s_variables
{
  char		**tab;
  int		i;
  int		x;
  int		y;
  int		j;
}		t_vars;

int	count_word(char *);
int	count_word2(char *);
void	init_val(t_vars *);
int	check_func(char	*, int);
void	end_str_to_word_tab(t_vars *, char *);
void	func_var(t_vars *);
char	**my_str_to_word_tab(char *);
char	**my_str_to_word_tab2(char *);

#endif /* !MY_STR_TO_WORD_TAB */
