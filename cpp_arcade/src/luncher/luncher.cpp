#include "Luncher.hh"

Luncher::Luncher()
{
  this->Play = NULL;
  this->creatLib = NULL;
  this->creatGame = NULL;
  this->handle_game = NULL;
  this->handle_graphic = NULL;
  this->graphic = NULL;
  this->game = NULL;
}

Luncher::~Luncher()
{
  resetGame();
  resetGraphic();
}

void *Luncher::getHandle(handleType type)
{
  if (type==GRAPHIC)
    return this->handle_graphic;
  else if (type==GAME)
    return this->handle_game;
  else
    return NULL;
}

bool Luncher::setHandle(handleType type,const char *path)
{
  if (type==GRAPHIC)
  {
    this->handle_graphic = dlopen(path, RTLD_LAZY);
    if (!this->handle_graphic)
      return false;
  }
  else if (type==GAME)
  {
    this->handle_game = dlopen(path, RTLD_LAZY);
    if (!this->handle_game)
      return false;
  }
  else
    return false;
  return true;
}

bool Luncher::resetHandle(handleType type)
{
  if (type==GRAPHIC)
  {
    if (!this->handle_graphic)
      return false;
    dlclose(this->handle_graphic);
  }
  else if (type==GAME)
  {
    if (!this->handle_game)
      return false;
    dlclose(this->handle_game);
  }
  else
    return false;
  return true;
}

void *Luncher::getFunc(handleType type, const char *name)
{
  void *handle = getHandle(type);
  char *error;

  void *fct = dlsym(handle, name);
  if ((error = dlerror()) != NULL)  {
      fputs(error, stderr);
      return NULL;
  }
  return fct;
}

IGraph  *Luncher::getGraphic()
{
  return this->graphic;
}

bool    Luncher::setGraphic(const char *path)
{
  if (this->getHandle(GRAPHIC))
    this->resetHandle(GRAPHIC);
  if (!this->setHandle(GRAPHIC, path))
    return false;
  if (!(this->creatLib = (creatLib_t)this->getFunc(GRAPHIC,"creatLib")))
    return false;
  if (!(this->graphic = this->creatLib()))
    return false;
  return true;
}

void  Luncher::resetGraphic()
{
  if (this->graphic)
    {
      delete this->graphic;
      this->graphic = NULL;
    }
  this->resetHandle(GRAPHIC);
  this->creatLib = NULL;
}

IGames  *Luncher::getGame()
{
  return this->game;
}

bool    Luncher::setGame(const char *path)
{
  if (this->getHandle(GAME))
    this->resetHandle(GAME);
  if (!(this->setHandle(GAME, path)))
    return false;
  if (!(this->creatGame = (creatGame_t)this->getFunc(GAME,"creatGame")))
    return false;
  if (!(this->Play = (Play_t)this->getFunc(GAME,"Play")))
    return false;
  if (!(this->graphic))
    return false;
  if (!(this->game = this->creatGame(this->graphic)))
    return false;
  return true;
}

void   Luncher::resetGame()
{
  if (this->game)
    delete this->game;
  this->resetHandle(GAME);
  this->creatGame = NULL;
}

int  Luncher::runGame()
{
  if (!this->game || !this->graphic)
    return 0;
  return this->game->run();
}

std::vector<std::string> getdir(std::string dir)
{
    std::vector<std::string> files;
    struct dirent *dirp;
    DIR *dp;

    if((dp  = opendir(dir.c_str())) == NULL)
      return files;
    while ((dirp = readdir(dp)) != NULL)
      if (dirp->d_name[0] != '.')
        files.push_back(dirp->d_name);
    closedir(dp);
    return files;
}

bool Luncher::initLuncher()
{
  this->selectedGames = 0;
  this->selectedGraphic = 0;
  this->quit = false;
  this->graphic->openWindow(100,100, "Luncher !!");
  this->graphic->setEvent(games::QUIT, quit_game);
  this->graphic->setEvent(games::NGAME, next_game);
  this->graphic->setEvent(games::PGAME, prev_game);
  this->graphic->setEvent(games::NLIB, next_lib);
  this->graphic->setEvent(games::PLIB, prev_lib);
  this->graphic->setEvent(games::PLAY, run_graphic_game);
  this->listGames = getdir("./games/");
  this->listGraphic = getdir("./lib/");
  return true;
}
