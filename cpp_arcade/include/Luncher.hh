#ifndef LUNCHER_HH_
# define  LUNCHER_HH_

#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "games/SolarFox.hh"
#include "Protocol.hpp"

enum handleType
{
  GRAPHIC,
  GAME
};

typedef IGraph *(*creatLib_t)();
typedef IGames *(*creatGame_t)(IGraph *);
typedef void   (*Play_t)(void);

class Luncher
{
  private:
    // functions
    creatLib_t  creatLib;
    creatGame_t creatGame;
    // data
    void                      *handle_graphic;
    void                      *handle_game;
    IGraph                    *graphic;
    IGames                    *game;
    std::vector<std::string>  listGames;
    std::vector<std::string>  listGraphic;
    unsigned int              selectedGames;
    unsigned int              selectedGraphic;

    void *getHandle(handleType type);
    bool setHandle(handleType type, const char *path);
    bool resetHandle(handleType type);
    void *getFunc(handleType type, const char *name);

    static void run_graphic_game(void *dt);
    static void quit_game(void *dt);
    static void next_game(void *dt);
    static void prev_game(void *dt);
    static void next_lib(void *dt);
    static void prev_lib(void *dt);

  public:
    int      xSize;
    int      ySize;
    bool     quit;
    /* construtor and destructor */
    Luncher();
    ~Luncher();
    bool initLuncher();
    /* setters and getters */
    std::vector<std::string> getListGames() {return this->listGames;};
    std::vector<std::string> getListGraphic() {return this->listGraphic;};
    int                      getGamesSelected() {return this->selectedGames;};
    int                      getGraphicSelected() {return this->selectedGraphic;};

    IGraph  *getGraphic();
    bool    setGraphic(const char *path);
    void    resetGraphic();
    IGames  *getGame();
    bool    setGame(const char *path);
    void    resetGame();
    int     runGame();
    /* Play for moulinette */
    Play_t      Play;
};

#endif /* !LUNCHER_HH_ */
