/*
** graph_init.c for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin/src/bonus
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Wed Apr 22 15:39:30 2015 pierre jallut
** Last update Sun May  3 22:26:01 2015 pierre jallut
*/

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_gfxPrimitives.h>
#include "nest_graph.h"
#include "nest.h"

int	load_sprite_node(t_fourmiz *tmp, t_fourmiz *root)
{
  char	*pwd;

  pwd = getenv("PWD");
  pwd = my_realloc(pwd, 30);
  if (tmp->prev == root)
    {
      pwd = my_strcat(pwd, "/res/img/node_enter.png");
      tmp->sprite = IMG_Load(pwd);
    }
  else if (tmp->next == root)
    {
      pwd = my_strcat(pwd, "/res/img/node_exit.png");
      tmp->sprite = IMG_Load(pwd);
    }
   else
     {
       pwd = my_strcat(pwd, "/res/img/node.png");
       tmp->sprite = IMG_Load(pwd);
     }
  return (0);
}

int		init_nodes(t_fourmiz *root)
{
  t_fourmiz	*tmp;

  tmp = root->next;
  while (tmp != root)
    {
      load_sprite_node(tmp, root);
      tmp = tmp->next;
    }
  return (0);
}

int		launch_game(t_fourmiz *root, SDL_Surface *screen, t_1001 **ants)
{
  int		end;
  int		already_moved;

  end = 0;
  if (init_nodes(root) == -1 ||
      prepare_graphic_ants(root, ants) == -1)
    return (-1);
  already_moved = 0;
  while (!end)
    {
      refresh_screen(screen, ants, root);
      if (!already_moved)
	already_moved = print_turn(root, ants, screen);
      handle_events();
    }
  return (0);
}

int		graphic_init(t_fourmiz *root, t_1001 **ants)
{
  SDL_Surface	*screen;

  srand(time(NULL));
  if (root->nb_ants > 100)
    {
      printf("Too much ants for the graphic part!\n");
      return (EXIT_FAILURE);
    }
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1)
    {
      my_printf("Can't init SDL:  %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  if (!(screen = SDL_SetVideoMode(WIN_SIZE_W, WIN_SIZE_H, 32, SDL_HWSURFACE)))
    {
      my_printf("Can't init SDLVideomode:  %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  SDL_WM_SetCaption("Visualisateur Lem-in (Les Teks)", NULL);
  if (launch_game(root, screen, ants) == -1)
    return (EXIT_FAILURE);
  if (system("rm res/img/logins/*") == -1)
    return (EXIT_FAILURE);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
