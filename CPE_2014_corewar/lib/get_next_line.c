/*
** get_next_line.c for get_next_line in /home/guzman_y/rendu/projet/prog elem/CPE_2014_allum1/lib
**
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
**
** Started on  Sun Feb 22 21:37:06 2015 yoann guzman
** Last update Thu Mar 26 23:47:26 2015 Moisset Raphael
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char		*my_add_cpy(char *dest, char *before, char *src)
{
  int		i;
  int		idx;

  i = 0;
  idx = 0;
  if (before != NULL)
    while (before[i] != '\0' && before[i] != '\n')
      {
	dest[i] = before[i];
	++i;
      }
  while (src[idx] != '\0' && src[idx] != '\n')
    {
      dest[i] = src[idx];
      ++i;
      ++idx;
    }
  dest[i] = '\0';
  return (dest);
}

char		*my_add_line(char *dest, char *src)
{
  char		*s;
  int		len;
  int		pos;

  len = 0;
  if (dest != NULL)
    while (dest[len] != '\0' && dest[len] != '\n')
      ++len;
  pos = 0;
  while (src[pos] != '\0' && src[pos] != '\n')
    ++pos;
  if ((s = malloc(sizeof(char) * (len + pos + 1))) != NULL)
    s = my_add_cpy(s, dest, src);
  if (dest != NULL)
    free(dest);
  return (s);
}

char	*next_get(char *buff, char *s, int i)
{
  buff[i] = '\0';
  s = my_add_line(s, buff);
  if (buff[0] == '\n')
    return (NULL);
  return (s);
}

char		*get_next_line(int fd)
{
  static char	buff[BUFF_SIZE + 1];
  static int	i;
  char		*s;

  s = NULL;
  if (i && buff[i] != '\0')
    {
      s = my_add_line(s, buff + i);
      if (buff[0] == '\n')
	return ("\n");
      while (buff[i] != '\0')
	if (buff[i++] == '\n')
	  return (s);
    }
  while ((i = read(fd, buff, BUFF_SIZE)) > 0)
    {
      if ((s = next_get(buff, s, i)) == NULL)
	return ("\n");
      i = 0;
      while (buff[i] != '\0')
	if (buff[i++] == '\n')
	  return (s);
    }
  i = 0;
  return (s);
}
