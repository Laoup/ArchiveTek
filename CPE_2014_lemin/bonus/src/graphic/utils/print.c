/*
** print.c for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Thu Apr 30 15:15:29 2015 pierre jallut
** Last update Sun May  3 21:35:28 2015 Arthur Grosso
*/

#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include "nest_graph.h"

int		print_ants(SDL_Surface *screen, t_1001 **ants)
{
  int		i;
  char		*path_img;

  path_img = getenv("PWD");
  path_img = my_strcat(path_img, "/res/img/ant.png");
  i = -1;
  while (ants[++i])
    {
      if (ants[i]->printed == 1)
	{
	  if (!ants[i]->sprite)
	    ants[i]->sprite = IMG_Load(path_img);
	  else
	    {
	      SDL_BlitSurface(ants[i]->sprite, NULL, screen, &(ants[i]->pos));
	      stringRGBA(screen, ants[i]->pos.x - 10, (ants[i]->pos.y + 40),
	    		 ants[i]->login, 255, 255, 255, 255);
	    }
	}
  }
  return (0);
}

int		print_tubes(SDL_Surface *screen, t_fourmiz *tmp)
{
  int		b;

  b = -1;
  while (tmp->links[++b])
    aalineRGBA(screen, tmp->pos.x + 12.5, tmp->pos.y + 12.5,
	       tmp->links[b]->pos.x + 12.5, tmp->links[b]->pos.y + 12.5,
	       0, 255, 0, 255);
  return (0);
}

void		print_nodes(t_fourmiz *root, SDL_Surface *screen)
{
  t_fourmiz	*tmp;

  tmp = root->next;
  while (tmp != root)
    {
      stringRGBA(screen,  tmp->pos.x - 10, tmp->pos.y - 10,
      		 tmp->id, 255, 255, 255, 255);
      print_tubes(screen, tmp);
      SDL_BlitSurface(tmp->sprite, NULL, screen, &(tmp->pos));
      tmp = tmp->next;
    }
}

void		print_authors(SDL_Surface *screen)
{
  SDL_Rect      pos;
  SDL_Surface	*meurice_a;

  stringRGBA(screen, WIN_SIZE_W / 2 - 305, 10,
	     "Made BY grosso_a, chaint_c, meurice_a, jallut_p", 255, 255, 255, 255);
  meurice_a = IMG_Load("res/img/node_enter.png");
  pos.y = 30;
  pos.x = WIN_SIZE_W / 2 - 200;
  SDL_BlitSurface(meurice_a, NULL, screen, &(pos));
  pos.x = WIN_SIZE_W / 2 - 150;
  SDL_BlitSurface(meurice_a, NULL, screen, &(pos));
  pos.x = WIN_SIZE_W / 2 - 100;
  SDL_BlitSurface(meurice_a, NULL, screen, &(pos));
  pos.x = WIN_SIZE_W / 2 - 50;
  SDL_BlitSurface(meurice_a, NULL, screen, &(pos));
}

int	refresh_screen(SDL_Surface *screen, t_1001 **ants,
		       t_fourmiz *nest)
{
  int	ants_out;
  char	*sentence;
  char	ants_nb[50];
  int	i;

  if (!(sentence = malloc(sizeof(char) * 50)))
    return (-1);
  sentence = "Fourmis sorties: ";
  ants_out = 0;
  i = -1;
  while (ants[++i])
    if (ants[i]->printed == -1)
      ants_out++;
  sprintf(ants_nb, "%d", ants_out);
  sentence = my_strcat(sentence, ants_nb);
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 50, 50, 50));
  print_nodes(nest, screen);
  print_ants(screen, ants);
  stringRGBA(screen, 15, 15,
	     sentence, 255, 0, 0, 255);
  SDL_Flip(screen);
  return (0);
}
