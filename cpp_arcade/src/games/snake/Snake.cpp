//
// Snake.cpp for arcade in /home/tarkick/repos/cpp_arcade/src/games/snake
// 
// Made by Pierre Jallut
// Login   <jallut_p@epitech.eu>
// 
// Started on  Sun Apr  3 17:59:21 2016 Pierre Jallut
// Last update Mon Apr  4 00:27:45 2016 Pierre Jallut
//

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include "games/Snake.hh"

IGames *creatGame(IGraph *graphicLib)
{
  return new Snake(graphicLib);
}

Snake::Snake(IGraph *graphicLib) : lib(graphicLib)
{
  xSize = 100;
  ySize = 50; 
  cmd = games::GO_DOWN;
  snakesHead = new Body(3, 3);
  food = new Food(xSize / 2, ySize / 2);
  map.resize(xSize * ySize);
  initMap();
  initTranslator();
}

Snake::~Snake()
{  
}

void	Snake::writeScreen()
{
  if (cmd == games::GO_UP && snakesHead->y > 1)
    lib->setBox(snakesHead->x, snakesHead->y, games::SNK_HEAD, games::UP);
  else if (cmd == games::GO_RIGHT && snakesHead->x < xSize)
    lib->setBox(snakesHead->x, snakesHead->y, games::SNK_HEAD, games::RIGHT);
  else if (cmd == games::GO_LEFT && snakesHead->x > 1)
    lib->setBox(snakesHead->x, snakesHead->y, games::SNK_HEAD, games::LEFT);
  else if (cmd == games::GO_DOWN && snakesHead->y < ySize)
    lib->setBox(snakesHead->x, snakesHead->y, games::SNK_HEAD, games::DOWN);
  for (int i = 0;i < (int) snakesBody.size(); ++i)
    lib->setBox(snakesBody.at(i)->x, snakesBody.at(i)->y, games::SNK_BODY, games::UP);
  usleep(speed);
}

void	Snake::createFood()
{
  srand (time(NULL));

  if (food && food->getIsAte())
    {
      lib->setBox(food->x, food->y, games::EMPTY, games::DOWN);
      food->x = rand() % xSize + 1;
      food->y = rand() % ySize + 1;
      food->setIsAte(false);
    }
  lib->setBox(food->x, food->y, games::SNK_FOOD, games::DOWN);
}

void	Snake::eatFood()
{
  if (snakesHead->x== food->x &&
      snakesHead->y == food->y)
    {
      food->setIsAte(true);
      createFood();
      // if (snakesBody.empty())
      // 	snakesBody.push_back(new Body(snakesHead->x, snakesHead->y));
      // else
      // 	snakesBody.push_back(new Body(snakesBody.back()->x, snakesBody.back()->y));
      if ((speed - 50000) > 0)
	speed -= 50000;
    }
}

int	Snake::run()
{
  speed = 100200;
  endGame = 0;
  lib->setEvent(games::GO_UP, snakesHead->go_up);
  lib->setEvent(games::GO_LEFT, snakesHead->go_left);
  lib->setEvent(games::GO_DOWN, snakesHead->go_down);
  lib->setEvent(games::GO_RIGHT, snakesHead->go_right);
  lib->openWindow(xSize, ySize, "Snake");
  while (!endGame)
    {
      for (int i = 0; i < xSize;++i)
	lib->setBox(i, 0, games::BORDER, games::UP);
      for (int i = 0; i < xSize;++i)
	lib->setBox(i, ySize, games::BORDER, games::UP);
      for (int i = 0; i < ySize;++i)
	lib->setBox(0, i, games::BORDER, games::LEFT);
      for (int i = 0; i < ySize;++i)
	lib->setBox(xSize, i, games::BORDER, games::LEFT);
      lib->checkEvent(this);
      lib->setBox(snakesHead->x, snakesHead->y, games::EMPTY, games::UP);
      move();
      writeScreen();
      createFood();
      eatFood();
      this->lib->refreshScreen();
    }
  return 0;
}

void	Snake::move()
{
  int	oldX, oldY;
  
  // for (int i = 0; i < snakesBody.size();++i)
  //   {
  //     if (i == 0)
  // 	{
  // 	  snakesBody.at(i)->x = snakesHead->x;
  // 	  snakesBody.at(i)->y = snakesHead->y;
  // 	}
  //     else
  // 	{
  // 	  snakesBody.at(i)->x = oldX;
  // 	  snakesBody.at(i)->y = oldY;	
  // 	}
  //   }
  if (cmd == games::GO_UP && snakesHead->y > 1)
    --snakesHead->y;
  else if (cmd == games::GO_RIGHT && snakesHead->x < xSize)
    ++snakesHead->x;
  else if (cmd == games::GO_LEFT && snakesHead->x > 1)
    --snakesHead->x;
  else if (cmd == games::GO_DOWN && snakesHead->y < ySize)
    ++snakesHead->y;
  else
    endGame = 1;
  writeMap();
}

void		Snake::initTranslator()
{
  this->insertTileTypeLink(games::SNK_FOOD, arcade::TileType::BLOCK);
  this->insertTileTypeLink(games::SNK_HEAD, arcade::TileType::BLOCK);
  this->insertTileTypeLink(games::SNK_BODY, arcade::TileType::BLOCK);
  this->insertTileTypeLink(games::EMPTY, arcade::TileType::EMPTY);
}

void		Snake::writeMap()
{
  std::vector<Body *>::const_iterator itr;
  unsigned int i;

  for (i=0; i < this->map.size(); i++)
  {
    this->map[i].t = games::EMPTY;
    this->map[i].d = games::UNDEFINE;
  }
  this->map[snakesHead->x + snakesHead->y * this->xSize].t = games::SNK_HEAD;
  this->map[snakesHead->x + snakesHead->y * this->xSize].d = games::UP;
  this->map[food->x + food->y * this->xSize].t = games::SNK_FOOD;
  this->map[food->x + food->y * this->xSize].d = games::UP;
  for (itr = this->snakesBody.begin();itr != this->snakesBody.end(); itr++)
    {
      this->map[(*itr)->x + (*itr)->y * this->xSize].t = games::SNK_BODY;
      this->map[(*itr)->x + (*itr)->y * this->xSize].d = games::UP;
    }
}

void			Snake::where_am_i()
{
  size_t                sizeStruct;
  arcade::WhereAmI      *myPos;
  int                   itrPos = 0;
  int                   itr;

  this->writeMap();
  sizeStruct = sizeof(arcade::WhereAmI) + sizeof(arcade::Position) * (snakesBody.size() + 1);
  if ((myPos = static_cast<arcade::WhereAmI *>(malloc(sizeStruct))))
  {
    myPos->type = arcade::CommandType::WHERE_AM_I;
    myPos->lenght = (snakesBody.size() + 1);
    for (itr = 0; itr < this->xSize * this->ySize; itr++)
    {
      if (this->map[itr].t == games::SNK_HEAD ||
	  this->map[itr].t == games::SNK_BODY)
        {
          myPos->position[itrPos].x = itr % this->xSize;
          myPos->position[itrPos].y = itr / this->xSize;
          itrPos++;
          break;
        }
      }
    write(1, myPos, sizeStruct);
  }
}

void			Snake::get_map()
{
  size_t		size;
  arcade::GetMap        *map;
  int			itr;

  this->writeMap();
  size = sizeof(arcade::GetMap) + (sizeof(arcade::TileType) * this->xSize * this->ySize);
  if ((map = static_cast<arcade::GetMap *>(malloc(size))))
  {
    map->type = arcade::CommandType::GET_MAP;
    map->width = this->xSize;
    map->height = this->ySize;
    for (itr = 0; itr < this->xSize*this->ySize; itr++)
      map->tile[itr] = this->convertToArcade(this->map[itr].t);
    write(1, map, size);
  }
}

void			Snake::initMap()
{
  unsigned int		i;
  
  for (i=0; i < this->map.size(); i++)
  {
    this->map[i].t = games::EMPTY;
    this->map[i].d = games::UNDEFINE;
  }
}