/*
** parsing.c for lem_in in /home/meuric_a/cpe_2014_lemin/src
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sat Apr 18 15:59:49 2015 Alban Meurice
** Last update Sun May  3 22:44:00 2015 Arthur Grosso
*/

#include <stdlib.h>
#include "parser.h"

void		my_check()
{
  int		x;

  x = 0;
  while (x != 1)
    x = x + 1;
}

int		parsing(t_data *data)
{
  t_tools	tools;

  tools.file = NULL;
  tools.line_start = 0;
  tools.line_end = 0;
  if ((tools.file = get_file(tools.file)) == NULL)
    return (-1);
  if (search_start_and_end(&tools) == -1)
    return (-1);
  data->nb_ants = get_first_line(tools.file);
  if (get_first_part(data, &tools) == -1)
    return (-1);
  if (get_second_part(data, &tools) == -1)
    return (-1);
  get_data_for_graphpart(data);
  my_check();
  return (0);
}
