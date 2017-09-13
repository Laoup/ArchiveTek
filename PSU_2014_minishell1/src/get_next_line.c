/*
** get_next_line.c for Minishell in /home/meuric_a/Project/BSQ/V3.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jan 16 09:58:42 2015 alban meurice
** Last update Thu Jan 22 18:17:19 2015 alban meurice
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"

char		*my_strcpy(char *dest, char *src)
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

int		init_struct(t_ss **ss)
{
  if ((*ss = malloc(sizeof(t_ss))) == NULL)
    return (-1);
  (*ss)->length = 0;
  (*ss)->head = NULL;
  (*ss)->tail = NULL;
  return (0);
}

int		my_put_end_list(t_ss **ss, char buff)
{
  t_list	*new_elem;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return (-1);
  new_elem->car = buff;
  new_elem->next = NULL;
  if ((*ss)->head == NULL)
    {
      (*ss)->head = new_elem;
      (*ss)->tail = new_elem;
    }
  else
    {
      (*ss)->tail->next = new_elem;
      (*ss)->tail = (*ss)->tail->next;
    }
  (*ss)->length = (*ss)->length + 1;
  return (0);
}

char		*fill_buff(t_ss *ss)
{
  char		*buff;
  int		i;

  i = 0;
  if ((buff = malloc(sizeof(char) * ss->length + 1)) == NULL)
    return (NULL);
  if (ss->length > 0)
    {
      while (ss->head->next != NULL)
	{
	  buff[i] = ss->head->car;
	  ss->head = ss->head->next;
	  i = i + 1;
	}
      buff[i] = ss->head->car;
      buff[i + 1] = '\0';
    }
  else
    {
      buff[i] = '\0';
      return ("\n");
    }
  return (buff);
}
 
char		*get_next_line(const int fd)
{
  t_var		variables;
  t_ss		*ss;
  char		buff[SIZE + 1];

  if (init_struct(&ss) == -1)
    return (NULL);
  while ((variables.a = read(fd, buff, SIZE)) > 0)
    {
      buff[variables.a] = '\0';
      variables.i = 0;
      while (buff[variables.i])
	{
	  if (buff[variables.i] == '\n')
	    {
	      if ((variables.buffer = fill_buff(ss)) == NULL)
		return (NULL);
	      if (variables.buffer[0] == '\n')
		return ("\0");
	      return (variables.buffer);
	    }
	  if (my_put_end_list(&ss, buff[variables.i++]) == -1)
	    return (NULL);
	}
    }
  return (NULL);
}
