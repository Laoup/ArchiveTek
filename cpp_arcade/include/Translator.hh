#ifndef TRANSLATOR_HH_
# define TRANSLATOR_HH_

#include "Protocol.hpp"
#include "Arcade.hh"
#include <list>

struct TileTypeLink
{
  games::TileType  left;
  arcade::TileType right;
};

class Translator
{
private:
    std::list<TileTypeLink> listTileType;

  public:
    /* destrutor */
    ~Translator();
    /* TileType Translator */
    void  insertTileTypeLink(games::TileType left, arcade::TileType right);
    void  clearTileTypeLink();
    arcade::TileType  convertToArcade(games::TileType toconvert);
    games::TileType   convertToGames(arcade::TileType toconvert);
    games::CommandType  convertCmd(arcade::CommandType cmd);

    virtual void  setCmd(games::CommandType) = 0;
    virtual void  where_am_i() = 0;
    virtual void  get_map() = 0;
};

extern "C" void Play();

#endif /* !TRANSLATOR_HH_ */
