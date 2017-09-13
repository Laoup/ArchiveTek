/*
** utils.c for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Tue Apr 21 17:34:57 2015 pierre jallut
** Last update Sun May  3 22:35:27 2015 pierre jallut
*/

#include <string.h>
#include <stdlib.h>
#include "nest.h"

/*
** Return size of a char * array
*/
int		my_dblen(char **dbtab)
{
  int		i;

  i = -1;
  while (dbtab[++i]);
  return (i);
}

int		my_dblenf(t_fourmiz **dbtab)
{
  int		i;

  i = -1;
  while (dbtab[++i]);
  return (i);
}

/*
** Return size of a char * array
*/
int		morgan_freeman(t_data *test)
{
  int		i;

  i = -1;
  while (test->tubes[++i])
    free(test->tubes[i]);
  i = -1;
  while (test->name_room[++i])
    {
      free(test->name_room[i]);
      free(test->pos_room[i]);
    }
  free(test->pos_room);
  return (0);
}

t_fourmiz	*search_room_by_nb(t_1001 *ants, t_fourmiz **path)
{
  int		i;

  i  = 0;
  while (path[i] && i != ants->which_path_room)
    i++;
  return (path[i]);
}

int		check_doublon(char **tab_str)
{
  int		i;
  int		j;

  i = 0;
  while (tab_str[i] != NULL)
    {
      j = 0;
      while (tab_str[j] != NULL)
	{
	  if (i != j && strcmp(tab_str[i], tab_str[j]) == 0)
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}
