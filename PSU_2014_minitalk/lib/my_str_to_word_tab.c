/*
** my_str_to_word_tab.c for lib in /home/meuric_a/Project/Minishell1/V3.0/include
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Fri Jan 23 14:08:54 2015 alban meurice
** Last update Sun Mar 15 22:30:27 2015 Alban Meurice
*/

#include <stdlib.h>
#include "my.h"
#include "my_str_to_word_tab.h"

int		count_word(char *str)
{
  int		i;
  int		nb;

  nb = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (check_func(str, i) == 0)
	nb++;
      i = i + 1;
    }
  nb++;
  return (nb);
}

void		init_val(t_vars *var)
{
  var->i = 0;
  var->x = 0;
  var->j = 0;
}

int		check_func(char *str, int j)
{
  if (j == 0)
    return (-1);
  if (str[j - 1] == ';' || str[j - 1] == '>')
    return (0);
  return (1);
}

char		**my_str_to_word_tab(char *str)
{
  t_vars	var;

  init_val(&var);
  var.tab = ver_maloc("bug malloc", malloc((count_word(str) + 1) 
					   * sizeof(char *)));
  while (var.x != count_word(str))
    {
      var.y = 0;
      while (str[var.j] != '\0' && check_func(str, var.j) != 0)
	{
	  var.y++;
	  var.j++;
	}
      var.tab[var.x] = ver_maloc("bug malloc", malloc(var.y + 2 
						      * sizeof(char)));
      func_var(&var);
      while (var.y != var.j)
	var.tab[var.x][var.y++] = str[var.i++];
      var.tab[var.x++][var.y] = '\0';
      if (str[var.i + 1] == ' ' || str[var.i + 1] == '\0')
	var.i++;
      var.j = var.i;
    }
  end_str_to_word_tab(&var, str);
  return (var.tab);
}

void	end_str_to_word_tab(t_vars *var, char *str)
{
  var->tab[var->x - 1][var->y++] = str[var->i - 1];
  var->tab[var->x - 1][var->y++] = '\0';
  var->tab[var->x] = NULL;
}
