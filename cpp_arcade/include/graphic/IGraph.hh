#ifndef IGRAPH_HH_
#define IGRAPH_HH_

#include "Arcade.hh"
#include <string>

/*
** Graphic interface for all lib
*/
class IGraph
{
public:
  virtual ~IGraph() {};
  /* open window with parameter name and size */
  virtual bool    openWindow(int xSize, int ysize, std::string name) = 0;
  /* close window */
  virtual bool    closeWindow() = 0;
  /* set map box at status */
  virtual bool    setBox(int x, int y, games::TileType status, games::TileDirection direction) = 0;
  /* redirect press to void function */
  virtual bool    setEvent(games::CommandType key, void (*fct)(void *)) = 0;
  /* check press key */
  virtual bool    checkEvent(void *data) = 0;
  /* refresh screeen */
  virtual bool    refreshScreen() = 0;
  /* aff string */
  virtual bool    printStr(int x, int y, std::string str) = 0;
};

extern "C" IGraph  *creatLib();

#endif /* !IGRAPH_HH_ */
