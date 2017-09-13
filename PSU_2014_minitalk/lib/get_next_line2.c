/*
** get_next_line.c for BSQ in /home/meuric_a/Project/BSQ/V3.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jan 16 09:58:42 2015 alban meurice
** Last update Fri Mar 13 22:58:28 2015 Alban Meurice
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line2.h"
#include "my.h"

char		*my_strcpy2(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}

char		*text_copy(char *str, t_struct *count)
{
  char		*str2;

  if (count->j != 0)
    {
      if ((str2 = malloc(sizeof(char) * (count->j + 1))) == NULL)
	return (NULL);
      my_memset(str2, 0, (count->j + 1));
      str2 = my_strcpy2(str2, str);
    }
  if ((str = malloc(sizeof(char) * ((SIZE * count->i) + 1))) == NULL)
    return (NULL);
  my_memset(str, 0, ((SIZE * count->i) + 1));
  if (count->j != 0)
    str = my_strcpy2(str, str2);
  return (str);
}

char		*get_all_text(const int fd, t_struct *count)
{
  char		*str;
  
  count->a = 1;
  count->i = 1;
  count->j = 0;
  while (count->a > 0)
    {
      if ((count->a = read(fd, count->buffer, SIZE)) == -1)
	return (NULL);
      count->buffer[count->a] = '\0';
      if (count->i > 1)
	count->j = my_strlen(str);
      str = text_copy(str, count);
      count->w = 0;
      while (count->buffer[count->w] != '\0')
	str[count->j++] = count->buffer[count->w++];
      count->i = count->i + 1;
    }
  if (count->a == 0 && count->i == 1)
    return (NULL);
  str[count->j] = '\0';
  return (str);
}

char		*get_next_line2(const int fd)
{
  t_struct	count;
  char		*str;
  static char	*str2;
  int		j;
  static int	i = 0;
  
  if (i == 0)
    str2 = get_all_text(fd, &count);
  if (i != 0 && str2[i - 1] == '\0')
    return (NULL);
  j = i;
  while (str2[i] != '\n' && str2[i] != '\0')
    i++;
  if ((str = malloc(((i - j) + 1) * sizeof(char))) == NULL)
    return (NULL);
  my_memset(str, 0, ((i - j) + 1));
  i = j;
  j = 0;
  while (str2[i] != '\n' && str2[i] != '\0')
    str[j++] = str2[i++];
  i++;
  str[j] = '\0';
  return (str);
}
