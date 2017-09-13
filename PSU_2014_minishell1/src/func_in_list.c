/*
** func_in_list.c for Minishell1 in /home/meuric_a/Project/Minishell1/V1.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Jan 21 12:15:00 2015 alban meurice
** Last update Thu Jan 29 15:42:52 2015 alban meurice
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

int	add_in_list(t_env **my_env, char *env)
{
  t_env	*new_elem;
  t_env	*tmp;

  tmp = (*my_env);
  if ((new_elem = malloc(sizeof(t_env *))) == NULL)
    return (-1);
  new_elem->str = env;
  new_elem->next = NULL;
  if ((*my_env) == NULL)
    (*my_env) = new_elem;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_elem;
    }
  return (0);
}

void	my_show_list(t_env *my_env)
{
  t_env	*tmp;

  tmp = my_env;
  while (tmp != NULL)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

int	search_var(char *str, t_env *my_env)
{
  t_env	*tmp;
  int	count;

  count = 0;
  tmp = my_env;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->str, str) == 0)
	{
	  my_putchar('a');
	  my_put_nbr(count);
	  return (count);
	}
      count = count + 1;
      tmp = tmp->next;
    }
  return (-1);
}

int	supr_in_list(int count, t_env **my_env)
{
  int	i;
  t_env	*tmp;

  i = 0;
  tmp = (*my_env);
  while (i <= count)
    {
      if (i == (count - 1))
	{
	  tmp->next = tmp->next->next;
	  return (0);
	}
      tmp = tmp->next;
    }
  return (-1);
}
