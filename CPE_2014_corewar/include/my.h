/*
** my.h for my_include in /home/guzman_y/rendu/Piscine_C_J09/include
**
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
**
** Started on  Fri Oct 10 15:38:00 2014 yoann guzman
** Last update Sun Apr 12 21:48:46 2015 Moisset Raphael
*/

#ifndef MY_INCLUDE_
# define MY_INCLUDE_

# include <stdarg.h>

# define BUFF_SIZE (4096)
# define GREEN "\033[32m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define END "\033[0m"

typedef struct	s_count
{
  int		i;
  int		j;
  int		k;
  int		l;
}		t_count;

void		my_putchar(char c);
void		my_putchar_color(char c, char *COLOR);
void		my_putchar_error(char c);
int		my_put_nbr(int nb);
int		my_put_nbr_color(int nb, char *COLOR);
char		my_putstr(char *str);
int		my_put_error(char *str, int return_value);
void		*my_put_error_null(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		is_neg(char *str, int i, int neg);
char		*my_strdup(char *src);
int		my_putnbr_base(int nb, char *base);
char		*my_strcpy(char *dest, char *src);
char		*my_strcat(char *dest, char *src);
char		*get_next_line(int fd);
int		my_strncmp(char *str, char *str1, int len);
int		my_strcmp(char *str, char *str1);
char		*my_get_env(char *name, char *env[]);
void		my_putstr_color(char *str, char *COLOR);
char		**my_str_to_word_tab(char *str, char flag);
char		*my_epur_str(char *str);
int		my_put_nbr_color(int nb, char *COLOR);
void		my_putchar_color(char c, char *COLOR);
void		my_putstr_color(char *str, char *COLOR);
int		match(char nb, char *base);
void		my_atoi_base1(t_count *i, int *ba_se, char *str);
int		my_atoi_base(char *str, char *base);

#endif /* !MY_INCLUDE_ */
