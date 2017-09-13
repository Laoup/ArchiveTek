/*
** my_atoi_base.c for my_atoi_base in /home/exam/rendu/ex_4
** 
** Made by Exam User
** Login   <exam@epitech.net>
** 
** Started on  Wed Jan 21 19:19:51 2015 Exam User
** Last update Thu Mar 19 04:40:15 2015 yoann guzman
*/

#include "my.h"

int	match_base(char nb, char *base)
{
  int	count;

  count = 0;
  while (base[count])
    {
      if (nb == base[count])
	return (count);
      count = count + 1;
    }
  return (0);
}

void	my_atoi_base1(t_count *i, int *ba_se, char *str)
{
  while (str[i->i])
    {
      if (str[i->j] == '-' && i->i == 0)
	{
	  i->j = 1;
	  i->i = i->i + 1;
	}
      if ((i->i > 0 && i->j == 0) || (i->j == 1 && i->i > 1))
	i->k = i->k * *ba_se;
      i->i = i->i + 1;
    }
  i->i = 0;
  if (i->j == 1)
    i->i = i->i + 1;
}

int		my_atoi_base(char *str, char *base)
{
  int		nb;
  t_count	i;
  int		ba_se;
  int		count;

  count = 0;
  i.j = 0;
  i.k = 1;
  i.i = 0;
  nb = 0;
  ba_se = my_strlen(base);
  my_atoi_base1(&i, &ba_se, str);
  while (str[i.i])
    {
      count = match_base(str[i.i], base);
      nb = nb + (count * i.k);
      i.i = i.i + 1;
      i.k = i.k / ba_se;
    }
  if (i.j == 1)
    nb = nb * -1;
  return (nb);
}
