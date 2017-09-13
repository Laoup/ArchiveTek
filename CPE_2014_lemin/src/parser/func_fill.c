/*
** func_fill.c for lem-in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Apr 20 18:01:57 2015 Alban Meurice
** Last update Sat May  2 22:04:45 2015 pierre jallut
*/

#include <stdlib.h>
#include "parser.h"

int	get_cmd(char *line)
{
  char	*word;
  int	y;
  int	y2;

  y = 2;
  y2 = 0;
  while (line[y] != '\0')
    y = y + 1;
  if ((word = malloc((y - 1) * sizeof(char))) == NULL)
    return (-1);
  y = 2;
  while (line[y] != '\0')
    word[y2++] = line[y++];
  word[y2] = '\0';
  if (my_strcmp(word, "start") == 0)
    {
      free(word);
      return (0);
    }
  if (my_strcmp(word, "end") == 0)
    return (1);
  free(word);
  return (2);
}

int	get_room(t_data *data, char *line_file)
{
  char	*get_word;
  int	y;

  y = 0;
  while (line_file[y] != ' ' && line_file[y] != '\0')
    y = y + 1;
  if ((get_word = malloc((y + 1) * sizeof(char))) == NULL)
    return (-1);
  y = 0;
  while (line_file[y] != ' ' && line_file[y] != '\0')
    {
      get_word[y] = line_file[y];
      y = y + 1;
    }
  get_word[y] = '\0';
  if (put_word_in_tab(data, get_word) == -1)
    return (-1);
  if ((y = put_pos_in_tab(data, get_word, line_file, y)) == -1)
    return (-1);
  if (put_pos_in_tab(data, get_word, line_file, y) == -1)
    return (-1);
  free(get_word);
  return (0);
}

int	get_start_room(t_data *data, t_tools *tools, int x)
{
  char	*get_word;
  int	y;

  y = 0;
  while (tools->file[x][y] != ' ' && tools->file[x][y] != '\0')
    y = y + 1;
  if ((get_word = malloc((y + 1) * sizeof(char))) == NULL)
    return (-1);
  y = 0;
  while (tools->file[x][y] != ' ' && tools->file[x][y] != '\0')
    {
      get_word[y] = tools->file[x][y];
      y = y + 1;
    }
  get_word[y] = '\0';
  if (put_words_in_tab(data, get_word) == -1)
    return (-1);
  if ((y = put_poss_in_tab(data, get_word, tools->file[x], y)) == -1)
    return (-1);
  if (put_poss_in_tab(data, get_word, tools->file[x], y) == -1)
    return (-1);
  free(get_word);
  return (0);
}

int	get_end_room(t_data *data, t_tools *tools, int x)
{
  char	*get_word;
  int	y;

  y = 0;
  while (tools->file[x][y] != ' ' && tools->file[x][y] != '\0')
    y = y + 1;
  if ((get_word = malloc((y + 1) * sizeof(char))) == NULL)
    return (-1);
  y = 0;
  while (tools->file[x][y] != ' ' && tools->file[x][y] != '\0')
    {
      get_word[y] = tools->file[x][y];
      y = y + 1;
    }
  get_word[y] = '\0';
  if (put_worde_in_tab(data, get_word) == -1)
    return (-1);
  if ((y = put_pose_in_tab(data, get_word, tools->file[x], y)) == -1)
    return (-1);
  if (put_pose_in_tab(data, get_word, tools->file[x], y) == -1)
    return (-1);
  free(get_word);
  return (0);
}
