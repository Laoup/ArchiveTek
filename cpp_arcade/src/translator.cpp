#include "Translator.hh"
#include "games/IGames.hh"
#include <unistd.h>
#include <stdio.h>
#include <iostream>

extern "C" void Play()
{
  IGames *game = creatGame(NULL);
  arcade::CommandType cmd;

  while (42)
  {
    read(0, &cmd, sizeof(arcade::CommandType));
    switch (cmd) {
      case arcade::CommandType::WHERE_AM_I:
        game->where_am_i();
      break;
      case arcade::CommandType::GET_MAP:
        game->get_map();
      break;
      case arcade::CommandType::PLAY:
        game->move();
      break;
      case arcade::CommandType::SHOOT:
        game->setCmd(game->convertCmd(cmd));
        game->move();
      break;
      default:
        game->setCmd(game->convertCmd(cmd));
      break;
    }
  }
}

Translator::~Translator()
{
  this->clearTileTypeLink();
}

games::CommandType  Translator::convertCmd(arcade::CommandType cmd)
{
  switch (cmd) {
    case arcade::CommandType::GO_UP:
      return games::GO_UP;
      break;
    case arcade::CommandType::GO_DOWN:
      return games::GO_DOWN;
      break;
    case arcade::CommandType::GO_LEFT:
      return games::GO_LEFT;
      break;
    case arcade::CommandType::GO_RIGHT:
      return games::GO_RIGHT;
      break;
    case arcade::CommandType::GO_FORWARD:
      return games::GO_FORWARD;
      break;
    case arcade::CommandType::SHOOT:
      return games::SHOOT;
      break;
    default:
      return games::ILLEGAL;
      break;
  }
}

void  Translator::insertTileTypeLink(games::TileType left, arcade::TileType right)
{
  TileTypeLink link;

  link.left = left;
  link.right = right;
  this->listTileType.push_front(link);
}

void  Translator::clearTileTypeLink()
{
  this->listTileType.clear();
}

arcade::TileType  Translator::convertToArcade(games::TileType toconvert)
{
  std::list<TileTypeLink>::iterator it;

  for (it=this->listTileType.begin(); it != this->listTileType.end(); it++)
    if ((*it).left == toconvert)
      return (*it).right;
  return arcade::TileType::OTHER;
}

games::TileType   Translator::convertToGames(arcade::TileType toconvert)
{
  std::list<TileTypeLink>::iterator it;

  for (it=this->listTileType.begin(); it != this->listTileType.end(); it++)
    if ((*it).right == toconvert)
      return (*it).left;
  return games::OTHER;
}
