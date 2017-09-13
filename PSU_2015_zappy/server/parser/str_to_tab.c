/*
** str_to_tab.c for zappy in /home/docqui_a/PSU_2015_zappy
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Mon Jun 20 21:52:19 2016 Avel Docquin
** Last update Sun Jun 26 22:54:11 2016 Avel Docquin
*/

#include "str_to_tab.h"

void		free_2d_tab(char **tab)
{
  unsigned int	i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	{
	  free(tab[i]);
	  ++i;
	}
      free(tab);
    }
}

static unsigned int	count_word(const char cmd[], unsigned int i)
{
  unsigned int		word;
  int			c;

  word = 0;
  while (cmd[i] && cmd[i] != '\n')
    {
      if (cmd[i] == 32 && cmd[i] != '\n')
	{
	  c = i + 1;
	  if (cmd[c] != 32 && cmd[i] != '\n')
	    ++word;
	}
      ++i;
    }
  ++word;
  return (word);
}

static char*	command_word(const char cmd[], unsigned int pos)
{
  unsigned int	c;
  unsigned int	i;
  char*		word;

  c = 0;
  i = pos;
  while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\n')
    {
      ++c;
      ++i;
    }
  if (!(word = (char*)malloc(sizeof(char) * (c + 1))))
    {
      perror("malloc");
      return (NULL);
    }
  word[c] = '\0';
  i = 0;
  while (cmd[pos] && cmd[pos] != ' ' && cmd[pos] != '\n')
    {
      word[i] = cmd[pos];
      ++i;
      ++pos;
    }
  return (word);
}

char**		command_to_tab(const char* cmd, char** tab, t_parser *parser)
{
  unsigned int	i;
  unsigned int	tmp;

  if (my_strlen(cmd) == 0)
    return (0);
  i = count_word(cmd, parser->pos);
  if (!(tab = malloc(sizeof(char*) * (i + 1))))
    {
      perror("malloc");
      return (NULL);
    }
  tab[i] = NULL;
  tmp = 0;
  while (tmp < i)
    {
      while (cmd[parser->pos] == ' ' || cmd[parser->pos] == '\n')
	++parser->pos;
      if (!(tab[tmp] = command_word(cmd, parser->pos)))
	return (NULL);
      parser->pos += my_strlen(tab[tmp]) + 1;
      ++tmp;
    }
  tab[tmp] = NULL;
  return (tab);
}
