/*
** func_2d_tab.c for asm corewar in /home/meuric_a/CPE_2014_corewar/asm
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Thu Mar 26 15:59:24 2015 Alban Meurice
** Last update Sun Apr 12 21:43:39 2015 Moisset Raphael
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "asm.h"

char	**copy_tab(char **tab, int x_ref)
{
  char	**cpy_tab;
  int	x;

  x = 0;
  if ((cpy_tab = malloc(x_ref * sizeof(char *))) == NULL)
    return (my_put_error_null("Can't perform malloc\n"));
  while (x < (x_ref - 1))
    {
      if ((cpy_tab[x] = my_strdup(tab[x])) == NULL)
	return (NULL);
      x = x + 1;
    }
  cpy_tab[x] = NULL;
  return (cpy_tab);
}

char	**put_line_in_tab(char *buff, char **tab, char **cpy_tab, int x_ref)
{
  int	x;

  x = 0;
  if ((tab = malloc((x_ref + 1) * sizeof(char *))) == NULL)
    return (my_put_error_null("Can't perform malloc\n"));
  if (x_ref == 1)
    {
      tab[0] = my_strdup(buff);
      tab[1] = NULL;
      return (tab);
    }
  while (x < (x_ref - 1))
    {
      if ((tab[x] = my_strdup(cpy_tab[x])) == NULL)
	return (NULL);
      x = x + 1;
    }
  if ((tab[x] = my_strdup(buff)) == NULL)
    return (NULL);
  x = x + 1;
  tab[x] = NULL;
  return (tab);
}

char	**copy_file_in_tab(int fd)
{
  char	**tab;
  char	**cpy_tab;
  char	*buff;
  int	x;

  x = 0;
  tab = NULL;
  cpy_tab = NULL;
  while ((buff = get_next_line(fd)) != NULL)
    {
      if (buff[0] == '#')
	x = x;
      else
	{
	  if (tab != NULL)
	    if ((cpy_tab = copy_tab(tab, x + 1)) == NULL)
	      return (NULL);
	  if ((tab = put_line_in_tab(buff, tab, cpy_tab, x + 1)) == NULL)
	    return (NULL);
	  x = x + 1;
	}
    }
  tab = clear_tab(tab);
  return (tab);
}

t_locl	*put_in_tab_label(char *label, t_locl *line_stut)
{
  char	**cpy_tab;
  int	x;

  if (line_stut->tab_label == NULL)
    {
      if ((line_stut->tab_label = malloc(2 * sizeof(char *))) == NULL)
	return (my_put_error_null("Can't perform malloc\n"));
      if ((line_stut->tab_label[0] = my_strdup(label)) == NULL)
	return (NULL);
      line_stut->tab_label[1] = NULL;
      return (line_stut);
    }
  x = 0;
  while (line_stut->tab_label[x] != NULL)
    x = x + 1;
  if ((cpy_tab = copy_tab_label(line_stut, x)) == NULL)
    return (NULL);
  x = x + 1;
  if ((line_stut->tab_label = put_label_in_tab(cpy_tab, x, label)) == NULL)
    return (NULL);
  return (line_stut);
}

char	**copy_tab_label(t_locl *line_stut, int x_ref)
{
  char	**cpy_tab;
  int	x;

  x = 0;
  if ((cpy_tab = malloc((x_ref + 1) * sizeof(char *))) == NULL)
    return (my_put_error_null("Can't perform malloc\n"));
  while (x < x_ref)
    {
      if ((cpy_tab[x] = my_strdup(line_stut->tab_label[x])) == NULL)
	return (NULL);
      x = x + 1;
    }
  cpy_tab[x] = NULL;
  return (cpy_tab);
}
