/*
** my.h for lib3.0 in /home/meuric_a/Project/push_swap/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Dec 11 22:46:15 2014 alban meurice
** Last update Thu Mar 19 01:54:39 2015 Alban Meurice
*/

#ifndef MY_H_
# define MY_H_

int	my_getnbr(char *);
int	my_put_nbr(int);
int	my_putchar(char);
int	my_putstr(char *);
int	my_strlen(char *);
int	my_puterror(char *);
int	my_putchar_error(char);
int	my_strcmp(char *, char *);
void	*ver_maloc(char *, void *);
void	my_memset(char *, char, int);
void	my_memset_int(int *, int, int);
char	*my_strdup(char *);
char	*my_strcat(char *, char *);
char	*my_strcat_spe(char *, char *);
int	my_strcmp_spe(char *, char *);
char	*malloc_strcmp_spe(char *);
int	my_strlen_spe(char *);
int	check_func(char *, int);

#endif /* !MY_H_ */
