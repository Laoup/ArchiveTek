/*
** get_next_line.h for get_next_line in /home/meuric_a/Project/BSQ/V3.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jan 16 10:10:31 2015 alban meurice
** Last update Thu Jan 22 18:20:47 2015 alban meurice
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define SIZE	(1)


typedef struct	s_list
{
  char		car;
  struct s_list	*next;
}		t_list;

typedef struct	s_super_struct
{
  int		length;
  t_list	*head;
  t_list	*tail;
}		t_ss;

typedef struct	s_my_variables
{
  char		*buffer;
  int		a;
  int		i;
}		t_var;

char	*get_next_line(const int);
char	*my_strcpy(char *, char *);
int	my_put_end_list(t_ss **, char);
int	init_struct(t_ss **);
char	*fill_buff(t_ss *);

#endif /* !GET_NEXT_LINE_H_ */
