//
// Body.cpp for arcade in /home/tarkick/repos/cpp_arcade
// 
// Made by Pierre Jallut
// Login   <jallut_p@epitech.eu>
// 
// Started on  Sun Apr  3 19:20:25 2016 Pierre Jallut
// Last update Sun Apr  3 20:48:00 2016 Pierre Jallut
//

#include "games/snake/items/Body.hh"
#include "games/Snake.hh"

void	Body::go_left(void *snake)
{
  static_cast<Snake *>(snake)->setCmd(games::GO_LEFT);
}

void	Body::go_down(void *snake)
{
  static_cast<Snake *>(snake)->setCmd(games::GO_DOWN);
}

void	Body::go_right(void *snake)
{
  static_cast<Snake *>(snake)->setCmd(games::GO_RIGHT);
}

void	Body::go_up(void *snake)
{
  static_cast<Snake *>(snake)->setCmd(games::GO_UP);
}
