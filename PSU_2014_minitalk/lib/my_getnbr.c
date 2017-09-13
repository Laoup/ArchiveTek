/*
** my_getnbr.c for lib3.0 in /home/meuric_a/Ressources/lib3.O
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Dec 11 13:00:15 2014 alban meurice
** Last update Tue Jan 13 12:54:54 2015 alban meurice
*/

int		my_getnbr(char *str)
{
  unsigned int	result;
  int		i;
  int		resultat;

  i = 0;
  result = 0;
  resultat = 0;
  while (str[i] >= '0'&& str[i] <= '9')
    {
      result = (result * 10) + (str[i] - 48);
      i = i + 1;
    }
  if (result < 32767)
    {
      resultat = result;
      return (resultat);
    }
  else
    return (-1);
}
