/*
** my_getnbrr.c for my_getnbrr in /home/guzman_y/test
**
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
**
** Started on  Thu Oct 23 18:07:59 2014 yoann guzman
** Last update Fri Apr  3 17:47:34 2015 Moisset Raphael
*/


int	is_neg(char *str, int i, int neg)
{
  if (str[i] == '-')
    neg = neg * -1;
  return (neg);
}

int	my_getnbr(char *str)
{
  int	c;
  int	res;
  int	i;
  int	neg;

  neg = 1;
  res = 0;
  i = 0;
  c = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      neg = is_neg(str, i, neg) ;
      i = i + 1;
    }
  while (str[c] != '\0')
    {
      if (str[c] >= '0' && str[c] <= '9')
	res = (res * 10) + (str[c] - '0');
      c = c + 1;
    }
  res = res * neg;
  return (res);
}
