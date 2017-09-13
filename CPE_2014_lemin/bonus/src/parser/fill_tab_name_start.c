/*
** fill_tab_name.c for lem_in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Apr 21 16:34:56 2015 Alban Meurice
** Last update Sun May  3 22:39:59 2015 Arthur Grosso
*/

#include <stdlib.h>
#include "nest.h"
#include "parser.h"

int		put_words_in_tab(t_data *data, char *word)
{
  if (data->name_room == NULL)
    {
      if ((data->name_room = malloc(3 * sizeof(char *))) == NULL)
	return (-1);
      if ((data->name_room[0] = my_strdup(word)) == NULL)
	return (-1);
      data->name_room[1] = NULL;
      data->name_room[2] = NULL;
      return (0);
    }
  if ((data->name_room[0] = my_strdup(word)) == NULL)
    return (-1);
  return (0);
}

int		put_poss_in_tab(t_data *data, char *word, char *line_file, int y)
{
  int		i;

  while (line_file[y] != '\0' && line_file[y] == ' ')
    y = y + 1;
  i = y;
  if (line_file[y] >= '0' && line_file[y] <= '9')
    {
      while (line_file[y] >= '0' && line_file[y] <= '9')
	y = y + 1;
      if ((word = malloc((y - i) + 1 * sizeof(char))) == NULL)
	return (-1);
      y = i;
      i = 0;
      while (line_file[y] >= '0' && line_file[y] <= '9')
	word[i++] = line_file[y++];
      word[i] = '\0';
      if (putnbr_in_poss_tab(data, word) == -1)
	return (-1);
      return (y);
    }
  return (-1);
}

int		putnbr_in_poss_tab(t_data *data, char *word)
{
  static int	x = 2;
  static int	y;

  if (y == 2)
    {
      x = x + 1;
      y = 0;
    }
  if (data->pos_room == NULL)
    {
      data->pos_room = ver_maloc("error_malloc", malloc(3 * sizeof(int *)));
      data->pos_room[1] = NULL;
      if ((data->pos_room[0] = malloc(2 * sizeof(int))) == NULL)
	return (-1);
      if ((data->pos_room[0][y++] = my_getnbr(word)) == -1)
	return (-1);
      data->pos_room[2] = NULL;
      return (0);
    }
  if (data->pos_room[0] == NULL)
    if ((data->pos_room[0] = malloc(2 * sizeof(int))) == NULL)
      return (-1);
  if ((data->pos_room[0][y++] = my_getnbr(word)) == -1)
    return (-1);
  return (0);
}
