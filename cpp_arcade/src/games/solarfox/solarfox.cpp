#include "games/SolarFox.hh"
#include "games/solarfox/SFXVEnemy.hh"
#include "games/solarfox/SFXHEnemy.hh"
#include "games/solarfox/SpaceShip.hh"
#include "games/solarfox/PowerUp.hh"
#include "games/solarfox/Obstacle.hh"

#define NB_POWERUP 20
#define NB_OBSTACLE 1

IGames *creatGame(IGraph *graphicLib)
{
  return new SolarFox(graphicLib);
}

void SolarFox::writeScreen()
{
  unsigned int i;

  for (i=0; i < this->map.size(); i++)
    this->graphic->setBox(i % this->xSize + 1, i / this->xSize + 1, this->map[i].t, this->map[i].d);
  write_backend();
}

void SolarFox::initMap()
{
  unsigned int i;

  srand(time(NULL));
  for (i=0; i < this->map.size(); i++)
  {
    this->map[i].t = games::EMPTY;
    this->map[i].d = games::UNDEFINE;
  }
  /* enemy up */
  this->perso.push_front(new SFXHEnemy(0,0, games::UP));
  this->perso.front()->setMinPos(0,0);
  this->perso.front()->setMaxPos(this->xSize-1,this->ySize-1);
  /* enemy down */
  this->perso.push_front(new SFXHEnemy(this->xSize-1,this->ySize-1, games::DOWN));
  this->perso.front()->setMinPos(0,0);
  this->perso.front()->setMaxPos(this->xSize-1,this->ySize-1);
  /* enemy left */
  this->perso.push_front(new SFXVEnemy(0,0, games::LEFT));
  this->perso.front()->setMinPos(0,0);
  this->perso.front()->setMaxPos(this->xSize-1,this->ySize-1);
  /* enemy right */
  this->perso.push_front(new SFXVEnemy(this->xSize-1,this->ySize-1, games::RIGHT));
  this->perso.front()->setMinPos(0,0);
  this->perso.front()->setMaxPos(this->xSize-1,this->ySize-1);
  /* spaceship */
  this->perso.push_front(new SpaceShip(this->xSize/2,this->ySize/2, games::UP));
  this->perso.front()->setMinPos(0,0);
  this->perso.front()->setMaxPos(this->xSize-1,this->ySize-1);
  /* POWERUP */
  for (i = 0;i < NB_POWERUP; i++)
    this->perso.push_front(new PowerUp(rand() % this->xSize-2,
                                       rand() % this->ySize-2));
   /* OBSTACLE */
   for (i = 0;i < NB_OBSTACLE; i++)
     this->perso.push_front(new Obstacle(rand() % this->xSize-2,
                                        rand() % this->ySize-2));
 }

void SolarFox::initTranslator()
{
  this->insertTileTypeLink(games::SPACESHIP, arcade::TileType::BLOCK);
  this->insertTileTypeLink(games::EMPTY, arcade::TileType::EMPTY);
  this->insertTileTypeLink(games::MY_SHOOT, arcade::TileType::MY_SHOOT);
  this->insertTileTypeLink(games::OBSTACLE, arcade::TileType::OBSTACLE);
  this->insertTileTypeLink(games::SFX_HENEMY, arcade::TileType::EVIL_DUDE);
  this->insertTileTypeLink(games::SFX_VENEMY, arcade::TileType::EVIL_DUDE);
  this->insertTileTypeLink(games::ENEMY_SHOOT, arcade::TileType::EVIL_SHOOT);
  this->insertTileTypeLink(games::POWERUP, arcade::TileType::POWERUP);
}

SolarFox::SolarFox(IGraph *graphicLib)
{
  this->point = 0;
  this->life = LIFE;
  this->quit = 0;
  this->xSize = 64;
  this->ySize = 64;
  this->map.resize(64*64);
  this->initMap();
  this->initTranslator();
  if (graphicLib)
  {
    this->graphic = graphicLib;
    this->graphic->setEvent(games::QUIT, quit_game);
    this->graphic->setEvent(games::MENU, quit_game);
    this->graphic->setEvent(games::GO_LEFT, go_left);
    this->graphic->setEvent(games::GO_RIGHT, go_right);
    this->graphic->setEvent(games::GO_UP, go_up);
    this->graphic->setEvent(games::GO_DOWN, go_down);
    this->graphic->setEvent(games::SHOOT, fire);
    this->graphic->setEvent(games::RGAME, restart_game);
  }
  this->cmd = games::GO_UP;
}

SolarFox::~SolarFox()
{
  this->map.clear();
}

void SolarFox::write_backend()
{
  int i;
  /* up, down, left, right */
  this->graphic->setBox(0,0, games::CORNER, games::UP);
  this->graphic->setBox(this->xSize+1,0, games::CORNER, games::LEFT);
  this->graphic->setBox(0,this->ySize+1, games::CORNER, games::DOWN);
  this->graphic->setBox(this->xSize+1,this->ySize+1, games::CORNER, games::RIGHT);
  for (i=1;i<ySize+1;i++)
  {
    this->graphic->setBox(0,i, games::BORDER, games::LEFT);
    this->graphic->setBox(this->xSize+1,i, games::BORDER, games::RIGHT);
  }
  for (i=1;i<xSize+1;i++)
  {
    this->graphic->setBox(i,0, games::BORDER, games::UP);
    this->graphic->setBox(i,this->ySize+1, games::BORDER, games::DOWN);
  }
}

#include <iostream>

int SolarFox::run()
{
  this->quit = 0;
  this->graphic->openWindow(66,66,"Solar Fox !");
  this->writeScreen();
  this->graphic->refreshScreen();
  while (!this->quit && this->life > 0)
  {
    this->graphic->checkEvent(this);
    this->move();
    this->writeScreen();
    this->graphic->refreshScreen();
  }
  std::cerr << "point=" << this->point << std::endl;
  return this->quit;
}

std::string SolarFox::getName()
{
  return "solarfox";
}
