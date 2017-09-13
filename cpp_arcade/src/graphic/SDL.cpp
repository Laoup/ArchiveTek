#include "graphic/SDL.hh"
#include <iostream>

IGraph  *creatLib()
{
  return new Sdl();
}

Sdl::Sdl()
{
  this->initEvent();
}

Sdl::~Sdl()
{

}

bool	Sdl::openWindow(int xSize, int ySize, std::string name)
{
  SDL_Init(SDL_INIT_VIDEO);

  this->MAX_TILE_X = xSize;
  this->MAX_TILE_Y = ySize;

  this->MAX_X_PX = xSize * TILE_SIZE;
  this->MAX_Y_PX = ySize * TILE_SIZE;

  if ((this->window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				       this->MAX_X_PX, this->MAX_Y_PX, SDL_WINDOW_SHOWN)) == NULL)
    return (false);

  if ((this->pRenderer = SDL_CreateRenderer(this->window, -1,
					    SDL_RENDERER_ACCELERATED)) == NULL)
    return (false);

  this->position_sprite.w = TILE_SIZE;
  this->position_sprite.h = TILE_SIZE;

  this->initTexture();

  return (true);
}

bool	Sdl::closeWindow()
{
  SDL_DestroyWindow(this->window);
  SDL_Quit();
  return (true);
}

bool	Sdl::setBox(int x, int y, games::TileType status, games::TileDirection direction)
{
  SDL_Texture		*img_tmp;
  SDL_Point		center = {TILE_SIZE / 2, TILE_SIZE / 2};
  SDL_RendererFlip	flip;
  float			angle;

  img_tmp = this->textures[status];

  this->position_sprite.x = x * TILE_SIZE;
  this->position_sprite.y = y * TILE_SIZE;

  //ROTATION

  flip = SDL_FLIP_NONE;

  if (direction == games::UP || direction == games::UNDEFINE)
    angle = 0;
  else if (direction == games::RIGHT)
    angle = 90;
  else if (direction == games::DOWN)
    angle = 180;
  else if (direction == games::LEFT)
    angle = 270;

  if (img_tmp != NULL)
    {
      if ((SDL_RenderCopyEx(this->pRenderer, img_tmp, NULL , &this->position_sprite, angle, &center, flip) != 0))
	return (false);
    }
  else
    return (false);

  return (true);
}

bool	Sdl::refreshScreen()
{
  SDL_RenderPresent(this->pRenderer);//affiche le renderer

  SDL_SetRenderDrawColor(this->pRenderer, 0, 0, 0, 255);
  SDL_RenderClear(this->pRenderer);//Nettoie le Renderer

  SDL_Delay(35);
  return true;
}

bool	Sdl::setEvent(games::CommandType key, EventFunction fct)
{
  this->events[key].fct = fct;
  return (true);
}

bool	Sdl::checkEvent(void *data)
{
  unsigned int	i;

  SDL_WaitEventTimeout(&this->event,10);
  if (this->event.type == SDL_KEYDOWN)
    {
      for (i = 0; i < this->events.size(); i++)
	{
	  if (this->events[i].fct && this->events[i].key == this->event.key.keysym.sym)
	    {
	      (this->events[i].fct)(data);
	    }
	}
    }
  return (true);
}

bool	Sdl::printStr(int x, int y, std::string str)
{
  TTF_Font	*police = NULL;
  SDL_Color	White = {255, 255, 255, 0};
  SDL_Surface	*surfaceMessage;
  SDL_Texture	*message;
  int		nb_letters;

  if (TTF_Init() == -1)
    return (false);

  nb_letters = 0;
  police = TTF_OpenFont("src/graphic/font/skrybylr.ttf", 30);
  surfaceMessage = TTF_RenderText_Solid(police, str.c_str(), White);

  message = SDL_CreateTextureFromSurface(this->pRenderer, surfaceMessage);

  nb_letters = str.length();

  this->dest.x = x * TILE_SIZE;
  this->dest.y = y * TILE_SIZE;
  this->dest.w = 35 * nb_letters;//size zone texte
  this->dest.h = 35;
  SDL_RenderCopy(this->pRenderer, message, NULL, &this->dest);

  TTF_CloseFont(police);
  TTF_Quit();
  return (true);
}

void	Sdl::initEvent()
{
  unsigned int	itr;

  this->events.resize(games::CTSIZE);
  for (itr = 0; itr < this->events.size(); itr++)
    this->events[itr].fct = NULL;
  this->events[games::QUIT].key = SDLK_ESCAPE;
  this->events[games::SHOOT].key = SDLK_SPACE;
  this->events[games::GO_UP].key = SDLK_UP;
  this->events[games::GO_DOWN].key = SDLK_DOWN;
  this->events[games::GO_LEFT].key = SDLK_LEFT;
  this->events[games::GO_RIGHT].key = SDLK_RIGHT;
  this->events[games::PLAY].key = SDLK_KP_ENTER;
  this->events[games::RGAME].key = SDLK_8;
  this->events[games::PLIB].key = SDLK_2;
  this->events[games::NLIB].key = SDLK_3;
  this->events[games::PGAME].key = SDLK_4;
  this->events[games::NGAME].key = SDLK_5;
  this->events[games::PLAY].key = SDLK_p;
  this->events[games::MENU].key = SDLK_9;
  this->events[games::GO_FORWARD].key = SDLK_UNKNOWN;
  this->events[games::ILLEGAL].key = SDLK_UNKNOWN;
}

SDL_Texture	*loadTexture(std::string name, SDL_Renderer *renderer)
{
  SDL_Texture	*texture = NULL;
  SDL_Surface	*image = NULL;

  image = SDL_LoadBMP(name.c_str());

  if (!image)
    return (NULL);

  texture = SDL_CreateTextureFromSurface(renderer, image);
  if (texture == NULL)
    return (NULL);

  SDL_FreeSurface(image);
  if (!texture)
    return (NULL);

  return (texture);
}

void	Sdl::initTexture()
{
  unsigned int	i;

  this->textures.resize(games::TTSIZE);

  for (i = 0; i < this->textures.size(); i++)
    this->textures[i] = NULL;

  this->textures[games::SPACESHIP] = loadTexture("src/graphic/bmp/SPACESHIP.bmp", this->pRenderer);
  this->textures[games::SNK_HEAD] = loadTexture("src/graphic/bmp/HEAD.bmp", this->pRenderer);
  this->textures[games::SNK_BODY] = loadTexture("src/graphic/bmp/BODY.bmp", this->pRenderer);
  this->textures[games::SNK_TAIL] = loadTexture("src/graphic/bmp/BODY.bmp", this->pRenderer);
  this->textures[games::SFX_HENEMY] = loadTexture("src/graphic/bmp/SPI_ENNEMY.bmp", this->pRenderer);
  this->textures[games::SFX_VENEMY] = loadTexture("src/graphic/bmp/SPI_ENNEMY.bmp", this->pRenderer);
  this->textures[games::ENEMY_SHOOT] = loadTexture("src/graphic/bmp/ENNEMY_SHOOT.bmp", this->pRenderer);
  this->textures[games::MY_SHOOT] = loadTexture("src/graphic/bmp/MY_SHOOT.bmp", this->pRenderer);
  this->textures[games::SNK_FOOD] = loadTexture("src/graphic/bmp/FOOD.bmp", this->pRenderer);
}
