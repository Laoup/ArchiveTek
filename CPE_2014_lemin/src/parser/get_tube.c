/*
** get_tube.c for lem_in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Apr 24 12:10:39 2015 Alban Meurice
** Last update Sun May  3 03:28:45 2015 pierre jallut
*/

#include <stdlib.h>
#include "parser.h"

int	get_tube(char *line, t_data *data, int x)
{
  char	*w_1;
  char	*w_2;

  (void) x;
  w_1 = NULL;
  w_2 = NULL;
  if ((w_1 = get_word_one(line)) == NULL)
    return (-1);
  if ((w_2 = get_word_two(line)) == NULL)
    return (-1);
  if ((w_1 = fmt_line(w_1, w_2)) == NULL)
    return (-1);
  if (new_tube(w_1, data) == -1)
    return (-1);
  free(w_1);
  free(w_2);
  return (0);
}

int	new_tube(char *line, t_data *data)
{
  char	**cpy_tab;
  int	size;

  if (data->tubes == NULL)
    {
      if ((data->tubes = malloc(2 * sizeof(char *))) == NULL)
	return (-1);
      if ((data->tubes[0] = my_strdup(line)) == NULL)
	return (-1);
      data->tubes[1] = NULL;
      return (0);
    }
  if ((cpy_tab = copy_tubes_tab(data->tubes)) == NULL)
    return (-1);
  size = count_tubes(data->tubes);
  if ((add_ligne_tab(data, cpy_tab, line, size)) == -1)
    return (-1);
  return (0);
}

char	*get_word_one(char *line)
{
  char	*word;
  int	y;

  y = 0;
  while (line[y] != '-')
    y = y + 1;
  if ((word = malloc((y + 1) * sizeof (char))) == NULL)
    return (NULL);
  y = 0;
  while (line[y] != '-')
    {
      word[y] = line[y];
      y = y + 1;
    }
  word[y] = '\0';
  return (word);
}

char	*get_word_two(char *line)
{
  char	*word;
  int	y;
  int	i;

   i = 0;
   y = 0;
   while (line[y] != '-')
     y = y + 1;
   y = y + 1;
   i = y;
   while (line[y] != '\0')
     y = y + 1;
   if ((word = malloc(((y - i) + 1) * sizeof (char))) == NULL)
     return (NULL);
   y = 0;
   while (line[i] != '\0')
     word[y++] = line[i++];
   word[y] = '\0';
   return (word);
}

char	*fmt_line(char *word1, char *word2)
{
  char	*line;
  int	i;

  i = 0;
  if ((line = malloc((my_strlen(word1) + my_strlen(word2)
		      + 2 * sizeof(char)))) == NULL)
    return (NULL);
  while (word1[i] != '\0')
    {
      line[i] = word1[i];
      i = i + 1;
    }
  free(word1);
  line[i++] = ';';
  line[i] = '\0';
  if ((line = my_strcat(line, word2)) == NULL)
    return (NULL);
  return (line);
}
