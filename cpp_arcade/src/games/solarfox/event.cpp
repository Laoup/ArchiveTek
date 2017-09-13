#include "games/SolarFox.hh"

void SolarFox::go_left(void *dt)
{
  static_cast<SolarFox *>(dt)->cmd = games::GO_LEFT;
}

void SolarFox::go_right(void *dt)
{
  static_cast<SolarFox *>(dt)->cmd = games::GO_RIGHT;
}

void SolarFox::go_up(void *dt)
{
  static_cast<SolarFox *>(dt)->cmd = games::GO_UP;
}

void SolarFox::go_down(void *dt)
{
  static_cast<SolarFox *>(dt)->cmd = games::GO_DOWN;
}

void SolarFox::quit_game(void *dt)
{
  static_cast<SolarFox *>(dt)->quit = 1;
}

void SolarFox::restart_game(void *dt)
{
  SolarFox *data = static_cast<SolarFox *>(dt);

  data->initMap();
  data->cmd = games::GO_UP;
}

void SolarFox::fire(void *dt)
{
  static_cast<SolarFox *>(dt)->cmd = games::SHOOT;
}
