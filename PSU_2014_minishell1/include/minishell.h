/*
** minishell.h for Minishell 1 in /home/meuric_a/Project/Minishell1/V1.0/include
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Jan 20 23:43:49 2015 alban meurice
** Last update Fri Jan 30 18:35:58 2015 alban meurice
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

typedef struct		s_my_env
{
  char			*str;
  struct s_my_env	*next;
}			t_env;

int	minishell(t_env *, t_env *, char **);
int	func_fork(char *, char **, char **);
char	*my_test_path(char *, t_env *);
char	*my_strcat_path(char *, char *);
int	my_strcmp(char *, char *);
char	*my_realloc(char *, char);
int	search_variable(char *, char **);
char	*my_get_env(char *, char *);
char	*my_getenv(char *, char **);
int	copy_env(t_env **, char **);
int	add_in_list(t_env **, char *);
int	supr_in_list(int , t_env **);
int	search_var(char *, t_env *);
void	my_show_list(t_env *);
int	stock_path(t_env **, char *);
int	my_built(char **, t_env **);
void	built_exit(char **);
int	built_env(char *, t_env **);
int	built_setenv(char **, t_env **);
int	built_cd(char **);

#endif /* !MINISHELL_H_ */
