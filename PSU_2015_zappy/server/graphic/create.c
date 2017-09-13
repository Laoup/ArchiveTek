/*
** window.c for window.h in /home/meuric_a/Projet_T2_Test/ZAPPY/server/graphic
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Mon Jun 13 22:44:43 2016 Alban Meurice
** Last update Wed Jun 15 15:54:09 2016 Alban Meurice
*/

#include "graphic.h"
#include <SDL2/SDL.h>
#include <errno.h>
#include <stdio.h>


int	createWindow(t_graph *data/*SDL_Window *window*/, int xSize, int ySize)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return (-1);
  if ((data->window = SDL_CreateWindow("Graphic_Map", SDL_WINDOWPOS_CENTERED,
				 SDL_WINDOWPOS_CENTERED, xSize, ySize,
				 SDL_WINDOW_SHOWN)) == NULL)
    return (-1);
  return (0);
}

int	createRenderer(t_graph *data/*SDL_Renderer *renderer, SDL_Window *window*/)
{
  SDL_CreateRenderer(data->window, -1, SDL_RENDERER_ACCELERATED);
    /*errno = 0;
  if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
    {
      printf("%s\n%d\n", strerror(errno), errno);
      return (-1);
      }*/
  return (0);
}

