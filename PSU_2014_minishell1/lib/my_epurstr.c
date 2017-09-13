/*
** my_epurstr.c for lib in /home/meuric_a/Project/Minishell1/V4.0/lib
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sun Jan 25 18:18:54 2015 alban meurice
** Last update Tue Jan 27 03:04:04 2015 alban meurice
*/

#include <stdlib.h>
#include "my.h"
#include "my_epurstr.h"

void	count(char *str, t_struct *var)
{
  var->i = 0;
  var->j = 0;
  while ((str[var->i] != '\0') && (str[var->i] == ' '))
    var->i = var->i + 1;
  var->k = var->i;
  while ((str[var->i] != '\0')/* && (str[i - 1] != '\0')*/)
    {
      if ((str[var->i + 1] == ' ') && (str[var->i] == ' '))
	var->i++;
      else
	{
	  var->j = var->j + 1;
	  var->i = var->i + 1;
	}
    }
  //var->j++;
  //my_put_nbr(var->j);
}

char		*my_epurstr(char *str)
{
  char		*str2;
  t_struct	var;

  count(str, &var);
  if ((str2 = malloc(var.j * sizeof(char))) == NULL)
    return (NULL);
  var.i = var.k;
  var.j = 0;
  while (str[var.i] != '\0')
    {
      if ((str[var.i] == ' ') && (str[var.i + 1] == ' '))
	var.i++;
      else
	str2[var.j++] = str[var.i++];
    }
  str2[var.j] = '\0';
  return (str2);
}