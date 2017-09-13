#ifndef SDL_HH_
# define SDL_HH_

#include "IGraph.hh"
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define TILE_SIZE (16)

typedef void (*EventFunction)(void *);

struct	event_t
{
  EventFunction	fct;
  SDL_Keycode	key;
};

class	Sdl: public IGraph
{
private:
  //Tile Size
  int		MAX_TILE_X;
  int		MAX_TILE_Y;
  int		TILE_MAX;
  // Pixels Size
  int		MAX_X_PX;
  int		MAX_Y_PX;
  int		last_body;

  SDL_Rect	     position_sprite;
  SDL_Rect	     dest;//For write in printSTR
  SDL_Window	   *window;
  SDL_Event	     event;
  SDL_Renderer	 *pRenderer;

  std::vector<games::TileType>	map;
  std::vector<event_t>	        events;
  std::vector<SDL_Texture *>	  textures;

  void	initEvent();
  void	initTexture();

public:
  /* constructor and destructor */
  Sdl();
  virtual ~Sdl();
  /* functions interface */
  virtual bool  openWindow(int xSize, int ysize, std::string name);
  virtual bool  closeWindow();
  virtual bool  setBox(int x, int y, games::TileType status, games::TileDirection direction);
  virtual bool  setEvent(games::CommandType key, EventFunction);
  virtual bool  checkEvent(void *data);
  virtual bool  refreshScreen();
  virtual bool  printStr(int x, int y, std::string str);
};

#endif /* SDL_HH_ */
