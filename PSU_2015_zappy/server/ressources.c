/*
** ressources.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Fri Jun 10 11:07:14 2016 Jaime Dossantos
** Last update Fri Jun 24 16:32:57 2016 Jaime Dossantos
*/

#include "my.h"

int	putstrr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(2, str, i);
  return (-1);
}

int	search_team(t_param *param, char **arg, char *flag, int i)
{
  int	nbr_t;

  while (arg[i] != NULL)
    {
      if (arg[i][0] == '-' && arg[i][1] == flag[1] && arg[i + 1] != NULL)
	{
	  nbr_t = 1;
	  while (arg[i + nbr_t] != NULL && arg[i + nbr_t][0] != '-')
	    nbr_t++;
	  if ((param->equipe = malloc((nbr_t + 1) * sizeof(char *))) == NULL)
	    return (-1);
	  param->equipe[nbr_t] = NULL;
	  nbr_t = 0;
	  while (arg[i + 1 + nbr_t] != NULL && arg[i + 1 + nbr_t][0] != '-')
	    {
	      param->equipe[nbr_t] = arg[i + nbr_t + 1];
	      nbr_t++;
	    }
	  param->equipe[nbr_t] = NULL;
	  return (nbr_t);
	}
      i++;
    }
  return (-1);
}

int	search(char **arg, char *flag)
{
  int	i;

  i = 0;
  while (arg[i])
    {
      if (arg[i][0] == '-' && arg[i][1] == flag[1])
	if (arg[i + 1] != NULL)
	  if (arg[i + 1][0] != '-')
	    return (atoi(arg[i + 1]));
      i++;
    }
  return (-1);
}

int		list_size(t_order *order)
{
  t_order	*tmp;
  int		i;

  i = 0;
  tmp = order;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

void		feed(int **tab, int nbr, int st)
{
  int		i;

  i = 0;
  while (i != st)
    {
      (*tab)[i] = nbr;
      i++;
    }
}
