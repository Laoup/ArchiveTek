/*
** get_tube.c for lem_in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Apr 24 12:10:39 2015 Alban Meurice
** Last update Sat May  2 21:59:45 2015 pierre jallut
*/

#include <stdlib.h>
#include "parser.h"
#include "nest.h"

char	*get_word_one2(char *line)
{
  char	*word;
  int	y;

  y = 0;
  while (line[y] != ';')
    y = y + 1;
  if ((word = malloc((y + 1) * sizeof (char))) == NULL)
    return (NULL);
  y = 0;
  while (line[y] != ';')
    {
      word[y] = line[y];
      y = y + 1;
    }
  word[y] = '\0';
  return (word);
}

char	*get_word_two2(char *line)
{
  char	*word;
  int	y;
  int	i;

   i = 0;
   y = 0;
   while (line[y] != ';')
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

char	*fmt_line2(char *word1, char *word2)
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
  line[i++] = ';';
  line[i] = '\0';
  if ((line = my_strcat(line, word2)) == NULL)
    return (NULL);
  return (line);
}
