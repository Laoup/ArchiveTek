#include "Luncher.hh"

void Luncher::quit_game(void *dt)
{
  static_cast<Luncher *>(dt)->quit = 1;
}

void Luncher::run_graphic_game(void *dt)
{
  Luncher *data = static_cast<Luncher *>(dt);
  Luncher *arcade = new Luncher();

  if (arcade->setGraphic(("./lib/" + data->listGraphic[data->selectedGraphic]).c_str()) &&
      arcade->setGame(("./games/" + data->listGames[data->selectedGames]).c_str()))
    arcade->runGame();
  delete arcade;
}

void Luncher::next_game(void *dt)
{
  Luncher *data = static_cast<Luncher *>(dt);
  if (data->selectedGames < data->listGames.size()-1)
    data->selectedGames += 1;
}

void Luncher::prev_game(void *dt)
{
  Luncher *data = static_cast<Luncher *>(dt);
  if (data->selectedGames > 0)
    data->selectedGames -= 1;
}

void Luncher::next_lib(void *dt)
{
  Luncher *data = static_cast<Luncher *>(dt);
  if (data->selectedGraphic < data->listGraphic.size()-1)
    data->selectedGraphic += 1;
}

void Luncher::prev_lib(void *dt)
{
  Luncher *data = static_cast<Luncher *>(dt);
  if (data->selectedGraphic > 0)
    data->selectedGraphic -= 1;
}
