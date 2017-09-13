/*
** errors2.c for errors2 in /home/chaint_c/rendu/B2/C/cpe_2014_lemin/cpe_2014_lemin/src
** 
** Made by Chaintreuil Clovis
** Login   <chaint_c@epitech.net>
** 
** Started on  Fri May  1 16:50:55 2015 Chaintreuil Clovis
** Last update Sun May  3 22:33:56 2015 Arthur Grosso
*/

#include <stdlib.h>
#include "parser.h"

int	tubes_to_room(t_data *data)
{
  int	i;
  int	x;
  char	*str;

  x = 0;
  while (data->tubes[x] != NULL)
    {
      i = 0;
      while (data->tubes[x][i] != ';')
        i++;
      if ((str = malloc(i + 1 * sizeof(char))) == NULL)
        return (-1);
      i = 0;
      if ((i = tubes_to_room2(data, x, i, &str)) == -1)
        return (-1);
      str[i] = '\0';
      if (tubes_to_room3(data, str) == -1)
        return (-1);
      i++;
      if (tubes_to_room4(data, i, x, str) == -1)
        return (-1);
      x++;
    }
  return (0);
}

int	tubes_to_room2(t_data *data, int x, int i, char **str)
{
  while (data->tubes[x][i] != ';')
    {
      *str[i] = data->tubes[x][i];
      i++;
    }
  return (i);
}

int	tubes_to_room3(t_data *data, char *str)
{
  int	x;

  x = 0;
  while (data->name_room[x] != NULL)
    {
      if (my_strcmp(str, data->name_room[x]) == 0)
        return (0);
      x++;
    }
  return (-1);
}

int	tubes_to_room4(t_data *data, int i, int x, char *str)
{
  int	j;

  j = 0;
  while (data->tubes[x][i] != '\0')
    {
      i++;
      j++;
    }
  if ((str = malloc(j + 1 * sizeof(char))) == NULL)
    return (-1);
  i = i - j;
  j = 0;
  while (data->tubes[x][i] != '\0')
    str[j++] = data->tubes[x][i++];
  str[j] = '\0';
  if (tubes_to_room3(data, str) == -1)
    return (-1);
  return (0);
}
