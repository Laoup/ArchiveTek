/*
** parse_order.c for zappy in /home/docqui_a/PSU_2015_zappy/server/parser/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Mon Jun 20 21:56:14 2016 Avel Docquin
** Last update Sun Jun 26 22:10:50 2016 Avel Docquin
*/

#include "../my.h"

int	detect_order(const char* const order)
{
  if (my_compare_tab(order, "avance") == 0)
    return (0);
  if (my_compare_tab(order, "droite") == 0)
    return (1);
  if (my_compare_tab(order, "gauche") == 0)
    return (2);
  if (my_compare_tab(order, "voir") == 0)
    return (3);
  if (my_compare_tab(order, "inventaire") == 0)
    return (4);
  if (my_compare_tab(order, "prend") == 0)
    return (5);
  if (my_compare_tab(order, "pose") == 0)
    return (6);
  if (my_compare_tab(order, "expulse") == 0)
    return (7);
  if (my_compare_tab(order, "broadcast") == 0)
    return (8);
  if (my_compare_tab(order, "incantation") == 0)
    return (9);
  if (my_compare_tab(order, "fork") == 0)
    return (10);
  return (-1);
}

static void	init_infos(t_infos *infos)
{
  infos->order = -1;
  infos->str = NULL;
  infos->ressource = -1;
}

int		wat_ressource(char const *arg)
{
  if (my_compare_tab(arg, "nourriture") == 0)
    return (0);
  if (my_compare_tab(arg, "linemate") == 0)
    return (1);
  if (my_compare_tab(arg, "deraumere") == 0)
    return (2);
  if (my_compare_tab(arg, "sibur") == 0)
    return (3);
  if (my_compare_tab(arg, "mendiane") == 0)
    return (4);
  if (my_compare_tab(arg, "phiras") == 0)
    return (5);
  if (my_compare_tab(arg, "thystame") == 0)
    return (6);
  return (-1);
}

static int	handle_order(t_client* const elem, char** const cmd)
{
  int		order;
  t_infos	infos;

  init_infos(&infos);
  if ((order = detect_order(cmd[0])) == -1)
    return (0);
  if (order != -1)
    {
      infos.order = order;
      if ((order == 5 || order == 6) && cmd[1])
	if ((infos.ressource = wat_ressource(cmd[1])) == -1)
	  return (0);
      if (order == 8 && cmd[1])
	infos.str = cmd[1];
      if ((order == 5 || order == 6 || order == 8) && !cmd[1])
	return (0);
      if (add_an_order(elem, &infos) == -1)
	return (-1);
    }
  return (0);
}

int		parse_order(t_client* const elem, char* buf)
{
  char**	cmd;
  t_parser	parser;

  parser.pos = 0;
  cmd = NULL;
  while (parser.pos >= 0)
    {
      if (!(cmd = command_to_tab(buf, cmd, &parser)))
	return (-1);
      if (cmd[0] && handle_order(elem, cmd) == -1)
	return (-1);
      if (!buf[parser.pos])
	parser.pos = -1;
      free_2d_tab(cmd);
    }
  return (0);
}
