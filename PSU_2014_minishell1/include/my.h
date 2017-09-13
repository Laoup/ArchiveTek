/*
** my.h for lib3.0 in /home/meuric_a/Project/push_swap/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Dec 11 22:46:15 2014 alban meurice
** Last update Tue Jan 27 18:44:02 2015 alban meurice
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
char	*my_strdup(char *);

#endif /* !MY_H_ */
