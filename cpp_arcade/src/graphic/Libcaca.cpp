#include "graphic/Libcaca.hh"
#include <iostream>

IGraph  *creatLib()
{
  return new Libcaca(false);
}

void Libcaca::initDraw()
{
  this->tileDraw.resize(games::TTSIZE);
  /* up, down, left, right */
  this->tileDraw[games::EMPTY] = "\x20\x20\x20\x20";
  this->tileDraw[games::SPACESHIP] = "\x21\x23\x24\x22";
  this->tileDraw[games::MY_SHOOT] = "\x2c\x2c\x2d\x2d";
  this->tileDraw[games::ENEMY_SHOOT] = "\x2a\x2a\x2b\x2b";
  this->tileDraw[games::SFX_HENEMY] = "\x26\x27\x26\x26";
  this->tileDraw[games::SFX_VENEMY] = "\x27\x27\x28\x29";
  this->tileDraw[games::BORDER] = "\x32\x33\x34\x35";
  this->tileDraw[games::POWERUP] = "\x25\x25\x25\x25";
  this->tileDraw[games::OBSTACLE] = "\x4F\x4F\x4F\x4F";

  this->tileDraw[games::SNK_HEAD] = "\x41\x42\x44\x43";
  this->tileDraw[games::SNK_BODY] = "\x47\x48\x45\x46";
  this->tileDraw[games::SNK_TAIL] = "\x4C\x4B\x49\x4A";
  this->tileDraw[games::SNK_FOOD] = "\x40\x40\x40\x40";
  /* up_left, down_left, up_right, down_right */
  this->tileDraw[games::CORNER] = "\x30\x2e\x31\x2f";
}

void Libcaca::initEvent()
{
  unsigned int   itr;

  this->events.resize(games::CTSIZE);
  for (itr=0;itr<this->events.size();itr++)
    this->events[itr].fct = NULL;
  this->events[games::RGAME].key = '8';
  this->events[games::PLIB].key = '2';
  this->events[games::NLIB].key = '3';
  this->events[games::PGAME].key = '4';
  this->events[games::NGAME].key = '5';
  this->events[games::QUIT].key = CACA_KEY_ESCAPE;
  this->events[games::PLAY].key = 'p';
  this->events[games::MENU].key = '9';
  this->events[games::GO_UP].key = CACA_KEY_UP;
  this->events[games::GO_DOWN].key = CACA_KEY_DOWN;
  this->events[games::GO_LEFT].key = CACA_KEY_LEFT;
  this->events[games::GO_RIGHT].key = CACA_KEY_RIGHT;
  this->events[games::GO_FORWARD].key = CACA_KEY_UNKNOWN;
  this->events[games::SHOOT].key = ' ';
  this->events[games::ILLEGAL].key = CACA_KEY_UNKNOWN;
}

Libcaca::Libcaca(bool grid)
{
  this->initEvent();
  this->initDraw();
  this->grid = grid;
  this->cv = NULL;
  this->dp = NULL;
}

Libcaca::~Libcaca()
{
  this->events.clear();
  this->tileDraw.clear();
  if (this->cv)
    caca_free_canvas(this->cv);
  if (this->dp)
    caca_free_display(this->dp);
}

bool  Libcaca::openWindow(int xSize, int ySize, std::string name)
{
  this->xSize = xSize;
  this->ySize = ySize;
  this->cv = caca_create_canvas(xSize+1,ySize+1);
  if (!this->cv)
    return false;
  this->dp = caca_create_display(this->cv);
  if (!this->dp)
    return false;
  caca_set_display_title(this->dp, name.c_str());
  caca_set_display_time(this->dp, 50000);
  return true;
}

bool  Libcaca::closeWindow()
{
  caca_free_display(this->dp);
  return true;
}

bool  Libcaca::setBox(int x, int y, games::TileType status, games::TileDirection direction)
{
  std::string buf;

  buf = this->tileDraw[status][direction];
  caca_put_str(this->cv, x, y, buf.c_str());
  return true;
}

bool  Libcaca::setEvent(games::CommandType key, void(*fct)(void *data))
{
  this->events[key].fct = fct;
  return true;
}

bool  Libcaca::checkEvent(void *data)
{
  unsigned int i;

  if (!caca_get_event(this->dp, CACA_EVENT_KEY_PRESS, &this->ev, DELAY))
    return false;
  for (i=0; i<this->events.size();i++)
    {
      if (this->events[i].fct && this->events[i].key != CACA_KEY_UNKNOWN
      && this->events[i].key ==  caca_get_event_key_ch(&this->ev))
        (this->events[i].fct)(data);
    }
  return true;
}

bool  Libcaca::refreshScreen()
{
  caca_refresh_display(this->dp);
  caca_clear_canvas(this->cv);
  return true;
}

bool  Libcaca::printStr(int x, int y, std::string str)
{
  std::string   buf;
  unsigned int  itr;

  for (itr = 0; itr < str.size(); itr++)
  {
    buf = " ";
    switch (str[itr]) {
      case '0' ... '9':
        buf[0] = str[itr] - '0' + 54; break;
      case 'A' ... 'Z':
        buf[0] = str[itr] - 'A' + 97; break;
      case 'a' ... 'z':
        buf[0] = str[itr] - 'a' + 97; break;
      case '_':
        buf[0] = 123; break;
      case ':':
        buf[0] = 96; break;
      case '.':
        buf[0] = 124; break;
    }
    caca_put_str(this->cv, x+itr, y, buf.c_str());
  }
  return true;
}
