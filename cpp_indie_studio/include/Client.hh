//
// Client.hh for indie-studio in /home/grosso_a/Workspace/indie-studio/include/
//
// Made by Arthur Grosso
// Login   <grosso_a@epitech.eu>
//
// Started on  Wed May 25 09:08:16 2016 Arthur Grosso
// Last update Sun Jun  5 23:23:08 2016 Karine Aknin
//

#ifndef CLIENT_HH_
# define CLIENT_HH_

# include "Player.hh"
# include "Enemy.hh"
# include "OrderControler.hh"
# include "OrderData.hh"
# include "CommandControler.hh"
# include "Camera.hh"
# include "GraphicRoot.hh"
# include "Menu.hh"
# include "Character.hh"
# include <iostream>
# include <unistd.h>
# include <string.h>
# include <irrlicht.h>
# include "driverChoice.h"

# define	ISSPACE(x) ((x == ' ') || (x == '\t'))
# define	ISDIGIT(x) ((x >= '0') && (x <= '9'))
# define	READY_TIMEOUT		30000
# define	MOVEMENT_SPEED_DEF	250.f

class					Client
{
public:
					Client(const std::string &, int, const std::string &, const CharacterType &);
					~Client();
  bool					initGame();
  bool					runGame();
  const OrderControler			&getControler() const;
  void					handleEnemies(irr::gui::IGUIEnvironment	*);
  void					handlePlayers(irr::gui::IGUIEnvironment	*);

private:
  CommandControler			commandControler;
  OrderControler			orderControler;
  Camera				camera;
  NewRoom				room;

  // irrlicht data
  irr::IrrlichtDevice			*device;
  irr::video::IVideoDriver		*driver;
  irr::scene::ISceneManager		*smgr;
  irr::io::IAttributes			*attribs;

  // player data
  const std::string		        &name;
  CharacterType				character_type;
  int					id;
  volatile bool				ready;
  bool					win;
  bool					fail;

  Player				*players[NB_PLAYER];
  Enemy					*enemies[NB_ENEMY];

  //event
  static int				moveUP(void *, std::vector<struct CommandSet *> *, unsigned int);
  static int				moveDOWN(void *, std::vector<struct CommandSet *> *, unsigned int);
  static int			        moveLEFT(void *, std::vector<struct CommandSet *> *, unsigned int);
  static int				moveRIGHT(void *, std::vector<struct CommandSet *> *, unsigned int);
  static int				exitClient(void *, std::vector<struct CommandSet *> *, unsigned int);
  static int				attackEnemy(void *, std::vector<struct CommandSet *> *, unsigned int);
  static int				startGame(void *, std::vector<struct CommandSet *> *, unsigned int);

  //network
  static int				receiveCharacterPos(void *, Order *);
  static int				listRoom(void *, Order *);
  static int				disconnectServer(void *, Order *);
  static int				newCharacter(void *, Order *);
  static int				deleteMesh(void *, Order *);
  static int				updatePv(void *, Order *);
  static int				pas2place(void *, Order *);
  
  int					sendCharacterPos(const irr::core::vector3df &, const irr::core::vector3df &);
  void					setColissions(irr::scene::IAnimatedMeshSceneNode *, const irr::core::vector3df &);
  irr::scene::IAnimatedMeshSceneNode    *loadMyCharacter();
  bool					loadEnemies();
  void					loadPath(CharacterType, std::string &, std::string &);
  bool					beforeReady();
  bool					afterReady();
};

#endif /* !CLIENT_HH_ */
