/*
** my_strcmp.c for my_strcmp in /Users/guzman_y/prog/rendu/projet/systeme Unix/PSU_2014_my_select/lib
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Wed Jan  7 01:56:17 2015 yoann guzman
** Last update Wed Jan  7 03:15:59 2015 yoann guzman
*/

int	my_strncmp(char *str, char *str1, int len)
{
  int	i;

  i = 0;
  while (str[i] && str1[i] && i <= len)
    {
      if (str[i] != str1[i])
	return (-1);
      i = i + 1;
    }
  return (0);
}
