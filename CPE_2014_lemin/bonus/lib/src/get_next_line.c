/*
** get_next_line.c for get_next_line in /home/jallut_p/git_repos/Piscine/CPE_2014_get_next_line
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Mon Nov 17 01:56:18 2014 pierre jallut
** Last update Sun May  3 21:39:48 2015 Arthur Grosso
*/

#include <unistd.h>
#include <stdlib.h>
#include "nest.h"

int		set_line(int fd, char *buffer, char *line,
			 int *cur_pos_line)
{
  static int	i = 0;

  if (fd == -1)
    i = 0;
  while (buffer[i] != 0 && buffer[i] != '\n')
    {
      line[*cur_pos_line] = buffer[i];
      (*cur_pos_line)++;
      i++;
    }
  if (buffer[i] && buffer[i] == '\n')
    {
      line[*cur_pos_line] = 0;
      *cur_pos_line = 0;
      i++;
      return (0);
    }
  line[*cur_pos_line] = 0;
  i = 0;
  return (1);
}

void	reset_vars(int fd, char *buffer, int *pos, int *end)
{
  if (fd == -1)
    {
      buffer[0] = 0;
      *pos = 0;
      *end = 0;
    }
}

char		*get_next_line(const int fd)
{
  static char	buffer[TO_READ + 1];
  static int	cur_pos_line = 0;
  static int	end = 0;
  int		len;
  char		*get_line;

  reset_vars(fd, buffer, &cur_pos_line, &end);
  if (!(get_line = malloc(sizeof(char) * (TO_READ + 1))))
    return (0);
  while (fd >= 0 && set_line(fd, buffer, get_line, &cur_pos_line) && !end)
    {
      len = read(fd, buffer, TO_READ);
      buffer[len] = '\0';
      get_line = my_realloc(get_line, sizeof(char) * (my_strlen(get_line) +
						      TO_READ + 1));
      if (!get_line || len < 0)
	return (NULL);
      end = (!len ? 1 : 0);
    }
  if (fd < 0 || end || !get_line || !TO_READ)
    {
      free(get_line);
      return (NULL);
    }
  return (get_line);
}
