/*
** print.c for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin_master
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Sat May  2 17:05:30 2015 pierre jallut
** Last update Sun May  3 22:34:12 2015 pierre jallut
*/

#include <stdio.h>
#include "nest.h"

/*
** Print the text of the ants movements
*/
int		print_result(t_1001 **ants, t_fourmiz ***paths)
{
  int		i;
  t_fourmiz	*path;
  int		end;
  int		ants_nb;

  i = 0;
  end = 1;
  ants_nb = 0;
  while (ants[i])
    {
      if (ants[i]->printed == 1)
	{
	  path = search_room_by_nb(ants[i], paths[ants[i]->path]);
	  if (path && ants_nb)
	    my_printf(" P%d-%s", ants[i]->id, path->id);
	  else if (path && !ants_nb)
	    my_printf("P%d-%s", ants[i]->id, path->id);
	  (path ? ants_nb++ : 0);
	  end = 0;
	}
      i++;
    }
  if (!end && path)
    my_printf("\n");
  return (end);
}

void	do_turn(int nb_paths, t_fourmiz ***paths,
		t_1001 **ants)
{
  int	i;
  int	b;

  i = 0;
  while (ants[i])
    {
      if (ants[i]->which_path_room == my_dblenf(paths[ants[i]->path]))
	ants[i]->printed = -1;
      else if (ants[i]->printed == 1)
	ants[i]->which_path_room++;
      i++;
    }
  i = 0;
  while (i < nb_paths)
    {
      b = 0;
      while (ants[b] && (ants[b]->printed || ants[b]->path != i))
	b++;
      if (ants[b])
	{
	  ants[b]->which_path_room++;
	  ants[b]->printed = 1;
	}
      i++;
    }
}

/*
** Print the turn of the ants movements
*/
int		print_turn(t_fourmiz *root, t_1001 **ants)
{
  int		end;
  int		nb_paths;
  t_fourmiz	***paths;

  end = 0;
  paths = src_path(root->nest_copy->next, root->nest_copy->prev);
  nb_paths = 0;
  while (paths[nb_paths])
    nb_paths++;
  if (!nb_paths)
    {
      printf("No path available !\n");
      return (-1);
    }
  repart_ants(paths, ants);
  while (!end)
    {
      do_turn(nb_paths, paths, ants);
      end = print_result(ants, paths);
    }
  return (1);
}
