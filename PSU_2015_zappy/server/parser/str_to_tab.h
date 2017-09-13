/*
** str_to_tab.h for zappy in /home/docqui_a/PSU_2015_zappy
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Mon Jun 20 21:52:37 2016 Avel Docquin
** Last update Sun Jun 26 22:12:02 2016 Avel Docquin
*/

#ifndef _PARSER_H_
# define _PARSER_H_

# include <stdlib.h>
# include "../misc.h"
# include "../my.h"

typedef struct	s_parser
{
  int		pos;
}		t_parser;

void	free_2d_tab(char **tab);
char**	command_to_tab(const char* cmd, char** tab, t_parser *parser);

#endif /* !_PARSER_H_ */
