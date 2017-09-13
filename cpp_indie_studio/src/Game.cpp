//
// Game.cpp for Game in /home/gianne_n/Coding/tek2/indie-studio_NEW
// 
// Made by Nicolas Giannelos
// Login   <gianne_n@epitech.net>
// 
// Started on  Sat Jun  4 02:54:39 2016 Nicolas Giannelos
// Last update Sun Jun  5 22:57:16 2016 Karine Aknin
//

#include "Client.hh"
#include "Character.hh"

bool Client::beforeReady()
{
  ClientStatus					*clientStatus;
  
  // network control
  orderControler.addOrder(PROTOCOLE::CommandType::SET, (OrderFunction)&Client::receiveCharacterPos, this);
  orderControler.addOrder(PROTOCOLE::CommandType::NEW_MESH, (OrderFunction)&Client::newCharacter, this);
  orderControler.addOrder(PROTOCOLE::CommandType::DELETE_MESH, (OrderFunction)&Client::deleteMesh, this);
  orderControler.addOrder(PROTOCOLE::CommandType::UPDATE_PV, (OrderFunction)&Client::updatePv, this);
  orderControler.addOrder(PROTOCOLE::CommandType::PAS2PLACE, (OrderFunction)&Client::pas2place, this);

  // irrlicht init
  if (!(device = createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480),
			      16, false, false, false, &commandControler)))
    return false;
  if (!(driver = device->getVideoDriver()))
    return false;
  if (!(smgr = device->getSceneManager()))
    return false;

  // load the map
  std::cout << "Loading map..." << std::endl;
  if (!(smgr->loadScene("map/firstLevel.irr")))
    {
      std::cerr << "loadScene failed" << std::endl;
      return false;
    }
  
  std::cout << "Awaiting other players to join the room..." << std::endl;
  for (int i = 0; i < 11; i++)
    {
      std::cout << "--- " << 10 - i << " ---" << std::endl;
      sleep(1);
    }
  std::cout << "The room is now closed!" << std::endl;

  clientStatus = new ClientStatus(this->room.name, 1);
  orderControler.sendOrder(NewOrder(id, PROTOCOLE::CommandType::CLIENT_STATUS, sizeof(struct ClientStatus), clientStatus));
  return (true);
}

bool						Client::afterReady()
{
  ClientStatus					*clientStatus;
  irr::scene::ILightSceneNode			*light;
  irr::scene::IAnimatedMeshSceneNode		*player;
  irr::core::vector3df				radius;
  size_t					timer;
    
  for (size_t i = 0; i < NB_ENEMY; ++i)
    this->enemies[i] = NULL;
  if ((player = loadMyCharacter()) == NULL)
    return false;
  if ((loadEnemies()) == false)
    return false;
  clientStatus = new ClientStatus(this->room.name, 2);
  orderControler.sendOrder(NewOrder(id, PROTOCOLE::CommandType::CLIENT_STATUS, sizeof(struct ClientStatus), clientStatus));

  timer = 0;
  while (!ready)
    {
      if (timer > READY_TIMEOUT)
	exit(EXIT_FAILURE);
      ++timer;
      usleep(1000);
    }

  commandControler.addKeyEvent(irr::KEY_UP, (CommandFunction)&Client::moveUP, this);
  commandControler.addKeyEvent(irr::KEY_DOWN, (CommandFunction)&Client::moveDOWN, this);
  commandControler.addKeyEvent(irr::KEY_LEFT, (CommandFunction)&Client::moveLEFT, this);
  commandControler.addKeyEvent(irr::KEY_RIGHT, (CommandFunction)&Client::moveRIGHT, this);
  commandControler.addKeyEvent(irr::KEY_ESCAPE, (CommandFunction)&Client::exitClient, this);
  commandControler.addKeyEvent(irr::KEY_SPACE, (CommandFunction)&Client::attackEnemy, this);

  device->getCursorControl()->setVisible(false);
  camera.addToSceneManager(this->smgr, irr::core::vector3df(players[this->id]->getNode()->getPosition()));
  Character::startTime = device->getTimer()->getTime();

  
  const irr::core::aabbox3d<irr::f32>& box = player->getBoundingBox();
  radius = box.MaxEdge - box.getCenter();
  setColissions(player, radius);

  if (!(attribs = device->getFileSystem()->createEmptyAttributes()))
    return false;
  return true;
}

bool						Client::initGame()
{
  if(!beforeReady())
    return (false);
  else if(!afterReady())
    return (false);
  else
    return (true);
}

void						Client::setColissions(irr::scene::IAnimatedMeshSceneNode *player1,
								      const irr::core::vector3df &radius)
{
  irr::scene::IMetaTriangleSelector		*meta = smgr->createMetaTriangleSelector();
  irr::core::array<irr::scene::ISceneNode *>	nodes;
  irr::scene::ISceneNode			*node;
  irr::scene::ITriangleSelector			*selector;
  irr::scene::ISceneNodeAnimator		*anim;

  smgr->getSceneNodesFromType(irr::scene::ESNT_ANY, nodes);
  for (irr::u32 i = 0; i < nodes.size(); ++i)
    {
      node = nodes[i];
      selector = 0;
      switch (node->getType())
        {
	case irr::scene::ESNT_MESH:
       	  selector = smgr->createTriangleSelector(((irr::scene::IMeshSceneNode*)node)->getMesh(), node);
       	  break;
        case irr::scene::ESNT_TERRAIN:
       	  selector = smgr->createTerrainTriangleSelector((irr::scene::ITerrainSceneNode*)node);
       	  break;
        case irr::scene::ESNT_OCTREE:
       	  selector = smgr->createOctreeTriangleSelector(((irr::scene::IMeshSceneNode*)node)->getMesh(), node);
       	  break;
	}
      if (selector)
        {
	  meta->addTriangleSelector(selector);
	  selector->drop();
        }
    }
  anim = smgr->createCollisionResponseAnimator(meta, player1, radius * 0.5f,
					       irr::core::vector3df(0, -10.0f, 0), 
					       irr::core::vector3df(0.0f, 10.0f, 0.0f));
  player1->addAnimator(anim);
  meta->drop();
  anim->drop();
}

int		Client::startGame(void *data, std::vector<struct CommandSet *> *commands, unsigned int rep)
{
  Client	*client;

  client = (Client *)data;
  client->ready = true;
  return 0;
  (void)commands;
  (void)rep;
}

void				Client::handleEnemies(irr::gui::IGUIEnvironment	*guienv)
{
  int				remaining;

  remaining = NB_ENEMY;
  for (size_t i = 0; i < NB_ENEMY; ++i)
    {
      if (this->enemies[i] != NULL)
	{
	  if (!this->enemies[i]->getPv())
	    {
	      this->enemies[i]->getNode()->setMD2Animation(irr::scene::EMAT_BOOM);
	      this->enemies[i] = NULL;
	      --remaining;
	    }
	  else
	    this->enemies[i]->Ai(this->players);
	}
      else
	{
	  --remaining;
	}
    }
  if (!remaining)
    {
      win = true;
      guienv->addImage(this->driver->getTexture("media/gauntlet_bg_win.jpg"),
		       irr::core::position2d<int>(150,0));
    }
}

void				Client::handlePlayers(irr::gui::IGUIEnvironment	*guienv)
{
  int				remaining;

  remaining = NB_PLAYER;
  for (size_t i = 0; i < NB_PLAYER; ++i)
    {
      if (!this->players[i])
	{
	  --remaining;
	}
      else if (!this->players[i]->getPv())
	{
	  this->players[i]->getNode()->setMD2Animation(irr::scene::EMAT_BOOM);
	  this->players[i]->setIsDead(true);
	  --remaining;
	}
    }
  if (!remaining)
    {
      fail = true;
      guienv->addImage(this->driver->getTexture("media/gauntlet_bg_fail.jpg"),
		       irr::core::position2d<int>(150,0));
    }
}

bool				Client::runGame()
{
  int				lastFPS = -1;
  float				action;
  irr::gui::IGUIEnvironment	*guienv = device->getGUIEnvironment();
  int				fps;
  irr::gui::IGUIButton          *button;
  irr::gui::IGUISkin            *skin;
  irr::gui::IGUIFont            *font;

  
  action = 0;
  skin = guienv->getSkin();
  font = guienv->getFont("media/fonthaettenschweiler.bmp");
  if (font)
    skin->setFont(font);
  skin->setFont(guienv->getBuiltInFont(),
                      irr::gui::EGDF_TOOLTIP);
  while (device->run())
    {
      Character::deltaTime = (irr::f32)(device->getTimer()->getTime() - Character::startTime) / 1000.f; // Temps en secondes
      Character::startTime =  device->getTimer()->getTime();

      action += Character::deltaTime;
      if (action > 0.1)
	{
	  action = 0;
	  if (!fail && !win)
	    {
	      handleEnemies(guienv);
	      handlePlayers(guienv);
	    }
	}     
      driver->beginScene(true, true, irr::video::SColor(0,0,0,0));
      smgr->drawAll();
      guienv->drawAll();
      driver->endScene();
      
      fps = driver->getFPS();
      if (lastFPS != fps)
	{
	  irr::core::stringw tmp(L"Indie Studio - Gauntlet [");
	  tmp += driver->getName();
	  tmp += L"] fps: ";
	  tmp += fps;
	  device->setWindowCaption(tmp.c_str());
	  lastFPS = fps;

	  irr::core::stringw tmp_score(L"SCORE : ");
	  tmp_score += players[id]->getScore();
	  button = guienv->addButton(irr::core::rect<irr::s32>(1300,1000,1450,1000 + 50),0, 0,
				     tmp_score.c_str(), L"Your Score !");
	  if (button)
	    button->setImage(driver->getTexture("media/bouton.jpg"));

	  irr::core::stringw tmp_pv(L"PV : ");
          tmp_pv += players[id]->getPv();
          button = guienv->addButton(irr::core::rect<irr::s32>(850,1000,1000,1000 + 50),0, 0,
				     tmp_pv.c_str(), L"Your PV !");
          if (button)
            button->setImage(driver->getTexture("media/bouton.jpg"));

	  irr::core::stringw tmp_name(L"NAME : ");
          tmp_name += name.c_str();
          button = guienv->addButton(irr::core::rect<irr::s32>(400,1000,550,1000 + 50),0, 0,
				     tmp_name.c_str(), L"Your Name !");
          if (button)
            button->setImage(driver->getTexture("media/bouton.jpg"));
	}
    }
  return true;
}
