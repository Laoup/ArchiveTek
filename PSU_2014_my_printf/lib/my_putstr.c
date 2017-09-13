/*
** my_putstr.c for lib in /home/meuric_a/re_code
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Oct 31 18:46:20 2014 alban meurice
** Last update Fri Oct 31 19:04:15 2014 alban meurice
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (*str);
}
