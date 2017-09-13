/*
** fill_tab_name.c for lem_in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Apr 21 16:34:56 2015 Alban Meurice
** Last update Sun May  3 21:27:38 2015 Arthur Grosso
*/

#include <stdlib.h>
#include "parser.h"

int		put_word_in_tab(t_data *data, char *word)
{
  static int	x = 2;

  if (data->name_room == NULL)
    {
      if ((data->name_room = malloc(4 * sizeof(char *))) == NULL)
	return (-1);
      data->name_room[0] = NULL;
      data->name_room[1] = NULL;
      if ((data->name_room[x++] = my_strdup(word)) == NULL)
	return (-1);
      data->name_room[3] = NULL;
      return (0);
    }
  if (put_word_in_tab_part2(data, word, x) == -1)
    return (-1);
  x = x + 1;
  return (0);
}

int		put_word_in_tab_part2(t_data *data, char *word, int x)
{
  char		**cpy_tab;
  int		x_cpy;

  cpy_tab = ver_maloc("error_malloc", malloc((x + 1) * sizeof(char *)));
  x_cpy = 0;
  while (x_cpy != x)
    {
      if ((cpy_tab = while_func(cpy_tab,
 					data->name_room, x_cpy)) == NULL)
	return (-1);
      x_cpy = x_cpy + 1;
    }
  data->name_room = ver_maloc("error_malloc", malloc((x + 2) * sizeof(char *)));
  x_cpy = 0;
  while (x_cpy != x)
    {
      if ((data->name_room = while_func(data->name_room,
					cpy_tab, x_cpy)) == NULL)
	return (-1);
      x_cpy = x_cpy + 1;
    }
  if ((data->name_room[x] = my_strdup(word)) == NULL)
    return (-1);
  data->name_room[x + 1] = NULL;
  return (0);
}

char		**while_func(char **tab, char **cpy_tab, int x)
{
  if (cpy_tab[x] == NULL)
    tab[x] = NULL;
  else
    if ((tab[x] = my_strdup(cpy_tab[x])) == NULL)
      return (NULL);
  return (tab);
}

int		put_pos_in_tab(t_data *data, char *word, char *line_file, int y)
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
      if (putnbr_in_pos_tab(data, word) == -1)
	return (-1);
      return (y);
    }
  return (-1);
}

int		putnbr_in_pos_tab(t_data *data, char *word)
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
      if ((data->pos_room = malloc(4 * sizeof(int *))) == NULL)
	return (-1);
      data->pos_room[0] = NULL;
      data->pos_room[1] = NULL;
      if ((data->pos_room[2] = malloc(2 * sizeof(int))) == NULL)
	return (-1);
      if ((data->pos_room[2][y++] = my_getnbr(word)) == -1)
	return (-1);
      data->pos_room[3] = NULL;
      return (0);
    }
  if (putnbr_in_pos_tab2(data, word, x, y) == -1)
    return (-1);
  y++;
  return (0);
}
