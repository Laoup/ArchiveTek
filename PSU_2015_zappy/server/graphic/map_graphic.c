/*
** map_graphic.c for map_graphic in /home/meuric_a/Projet_T2_Test/ZAPPY/server/graphic
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Mon Jun 13 22:30:05 2016 Alban Meurice
** Last update Mon Jun 20 19:44:43 2016 Jaime Dossantos
*/

#include "../my.h"
#include "graphic.h"
#include <SDL2/SDL.h>
#include <stdlib.h>

#include <unistd.h>

t_graph			*initGraphicMap(int xSize, int ySize)
{
  t_graph		*data;

  data = malloc(1 * sizeof(t_graph));
  data->nbYCases = ySize / TILE_SIZE_Y;
  data->nbXCases = xSize / TILE_SIZE_X;
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return (NULL);
  if ((data->window = SDL_CreateWindow("Graphic_Map", SDL_WINDOWPOS_CENTERED,
				       SDL_WINDOWPOS_CENTERED, xSize, ySize,
				       SDL_WINDOW_SHOWN)) == NULL)
    return (NULL);
  data->renderer = SDL_CreateRenderer(data->window, -1,
				      SDL_RENDERER_ACCELERATED);
  return (data);
}

void			selectPrint(t_graph *data, int *ressCase, int x, int y)
{
  SDL_Rect		caseAff;
  int			numberTile;

  (void)ressCase;
  numberTile = (y * 160) + x;/* attention a ce calcul */
  caseAff.x = (numberTile % data->nbXCases) * TILE_SIZE_X;
  caseAff.y = (numberTile % data->nbXCases/*nbYCases?*/) * TILE_SIZE_X;
  SDL_SetRenderDrawColor(data->renderer, 100, 100, 100, 255);
  SDL_RenderFillRect(data->renderer, &caseAff);
}

void			playersPrint(t_graph *data,/* t_client *tmp,*/ int x, int y)
{
  SDL_Rect		caseAff;
  int			numberTile;

  numberTile = (y * 160) + x;/* attention a ce calcul */
  caseAff.x = (numberTile % data->nbXCases) * TILE_SIZE_X;
  caseAff.y = (numberTile % data->nbXCases/*nbYCases?*/) * TILE_SIZE_X;
  SDL_SetRenderDrawColor(data->renderer, 100, 100, 100, 255);
  SDL_RenderFillRect(data->renderer, &caseAff);
}

int			majGraphicMap(t_graph *data, int ***map,
				      t_client *list)
{
  /*t_client		*tmp;*/
  int			*ressCase;
  unsigned int		x;
  unsigned int		y;

  SDL_SetRenderDrawColor(data->renderer, 0, 0, 0, 255);
  SDL_RenderClear(data->renderer);
  x = 0;
  while (map[x] != NULL)
    {
      y = 0;
      while (map[x][y] != NULL)
	{
	  ressCase = map[x][y];
	  if (/*(tmp = */itsPlayer(list, x, y)/*)*/ != NULL)
	    playersPrint(data/*, tmp*/, x, y);
	  else
	    selectPrint(data, ressCase, x, y);
	  y = y + 1;
	}
      x = x + 1;
    }
  SDL_RenderPresent(data->renderer);
  SDL_Delay(10);
  return (0);
}
