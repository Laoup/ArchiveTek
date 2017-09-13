#ifndef LIBCACA_HH_
# define LIBCACA_HH_

#include <caca.h>
#include <vector>
#include "IGraph.hh"

#define DELAY 10000

typedef void (*EventFunction)(void *);

struct CacaEvent
{
  EventFunction       fct;
  int                 key;
};

class Libcaca: public IGraph
{
private:
  caca_canvas_t             *cv;
  caca_display_t            *dp;
  caca_event_t              ev;
  int                       xSize;
  int                       ySize;
  bool                      grid;
  std::vector<std::string>  tileDraw;
  std::vector<CacaEvent>    events;
  void  initDraw();
  void  initEvent();

public:
  /* constructor and destructor */
  Libcaca(bool);
  virtual ~Libcaca();
  /* functions interface */
  virtual bool  openWindow(int xSize, int ysize, std::string name);
  virtual bool  closeWindow();
  virtual bool  setBox(int x, int y, games::TileType status, games::TileDirection direction);
  virtual bool  setEvent(games::CommandType key, EventFunction);
  virtual bool  checkEvent(void *data);
  virtual bool  refreshScreen();
  virtual bool  printStr(int x, int y, std::string str);
};

#endif /* !LIBCACA_HH_ */
