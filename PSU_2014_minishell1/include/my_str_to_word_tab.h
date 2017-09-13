/*
** my_str_to_word_tab.h for lib in /home/meuric_a/Project/Minishell1/V3.0/include
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jan 23 14:23:04 2015 alban meurice
** Last update Tue Jan 27 03:37:22 2015 alban meurice
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

char	**my_str_to_word_tab(char *);
int	count_word(char *);
void	init_val(t_vars *);

#endif /* !MY_STR_TO_WORD_TAB */
