/*
** graphic.h for graphic.h in /home/meuric_a/Projet_T2_Test/ZAPPY/server/graphic
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Jun 13 22:07:10 2016 Alban Meurice
** Last update Mon Jun 20 19:36:47 2016 Alban Meurice
*/

#ifndef GRAPHIC_H_
# define GRAPHIC_H_

#include "../my.h"
#include "../map.h"
#include <SDL2/SDL.h>

#define	TILE_SIZE_X (5)
#define	TILE_SIZE_Y (5)

typedef	struct	s_infoGraphic
{
  SDL_Window	*window;
  SDL_Renderer	*renderer;
  int		nbYCases;
  int		nbXCases;
}		t_graph;

t_graph		*initGraphicMap(int , int);
int		createWindow(t_graph *, int, int);
int		createRenderer(t_graph *);

int		majGraphicMap(t_graph *, int ***, t_client *);
t_client	*itsPlayer(t_client *, unsigned int, unsigned int);

void		selectPrint(t_graph *, int */*, t_client **/, int, int); 
void		playersPrint(t_graph *,/* t_client *,*/ int, int);

#endif /* GRAPHIC_H_ */
