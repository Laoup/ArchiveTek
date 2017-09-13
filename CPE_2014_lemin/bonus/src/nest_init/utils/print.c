/*
** print.c for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin_master
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Sat May  2 17:05:30 2015 pierre jallut
** Last update Sun May  3 22:21:23 2015 Arthur Grosso
*/

#include "nest_graph.h"
#include "nest.h"

/*
** Print the text of the ants movements
*/
int		print_result(t_1001 **ants, t_fourmiz ***paths,
			     SDL_Surface *screen, t_fourmiz *root)
{
  int		i;
  t_fourmiz	*path;
  int		end;

  i = -1;
  end = 1;
  while (ants[++i])
    {
      handle_events();
      if (ants[i]->printed == 1)
	{
	  end = 0;
	  path = search_room_by_nb(ants[i], paths[ants[i]->path]);
	  if (path && screen)
	    {
	      ants[i]->pos = path->pos;
	      refresh_screen(screen, ants, root);
	    }
	  else if (path)
	    my_printf("P%d-%s ", ants[i]->id, path->id);
	}
    }
  if (!screen)
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

void	move_ants(t_fourmiz *root, t_1001 **ants,
		  SDL_Surface *screen, t_fourmiz ***paths)
{
  int	cur_time;
  int	prev_time;
  int	end;
  int	nb_paths;

  end = 0;
  nb_paths = -1;
  while (paths[++nb_paths]);
  prev_time = 0;
  while (!end)
    {
      do_turn(nb_paths, paths, ants);
      cur_time = SDL_GetTicks();
      if (screen && (cur_time - prev_time) > 30)
	{
	  end = print_result(ants, paths, screen, root);
	  SDL_Delay(1000);
	  prev_time = cur_time;
	}
      else if (!screen)
	  end = print_result(ants, paths, screen, root);
    }
}

/*
** Print the turn of the ants movements
*/
int		print_turn(t_fourmiz *root, t_1001 **ants, SDL_Surface *screen)
{
  int		nb_paths;
  t_fourmiz	***paths;

  paths = src_path(root->nest_copy->next, root->nest_copy->prev);
  nb_paths = -1;
  while (paths[++nb_paths]);
  if (!nb_paths)
    {
      my_printf("No path available !\n");
      return (-1);
    }
  repart_ants(paths, ants);
  move_ants(root, ants, screen, paths);
  return (1);
}
