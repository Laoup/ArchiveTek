/*
** my_epurstr.h for epurstr in /home/meuric_a/Project/Minishell1/V4.0/include
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Jan 27 00:27:49 2015 alban meurice
** Last update Tue Jan 27 01:35:26 2015 alban meurice
*/

#ifndef MY_EPURSTR_H_
# define MY_EPURSTR_H_

typedef struct	s_struct
{
  int		i;
  int		j;
  int		k;
}		t_struct;

char	*my_epurstr(char *);
void	count(char *, t_struct *);

#endif /* !MY_EPURSTR_H_ */
