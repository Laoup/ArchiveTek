//
// main.cpp for main in /home/aknin_k/rendu/tek2/cpp/indie/menu
//
// Made by Karine Aknin
// Login   <aknin_k@epitech.net>
//
// Started on  Fri May 20 18:29:58 2016 Karine Aknin
// Last update Sun Jun  5 22:48:02 2016 Karine Aknin
//

#include <irrlicht.h>
#include <unistd.h>
#include "menu/Menu.hh"

Menu::Menu()
  : new_game()
{
}

Menu::~Menu()
{
}

void				Menu::run_begin()
{
  irr::gui::IGUIEnvironment     *gui = scene.getGuienv();
  int				i = 0;

  gui->addImage(scene.getDriver()->getTexture("media/Gauntlet_splash.jpg"),
                irr::core::position2d<int>(0,0));
  while (scene.getDevice()->run() && scene.getDriver() && i < 500)
    {
      if (scene.getDevice()->isWindowActive())
        {
          scene.getDriver()->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
          scene.getGuienv()->drawAll();
          scene.getSmgr()->drawAll();
          scene.getDriver()->endScene();
	  i++;
        }
    }
}

int		Menu::renderMenu()
{
  if (this->scene.init_all() == 1)
    return (1);
  run_begin();
  add_buttons();
  MyEventReceiver receiver(this->scene.getDevice(), this->new_game, this->edit_box);
  this->scene.getDevice()->setEventReceiver(&receiver);
  while (scene.getDevice()->run() && scene.getDriver())
    {
      if (scene.getDevice()->isWindowActive())
  	{
  	  scene.getDriver()->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
  	  scene.getGuienv()->drawAll();
	  scene.getSmgr()->drawAll();
  	  scene.getDriver()->endScene();
  	}
    }
  scene.drop_device();
  return 0;
}

void	Menu::add_background(irr::gui::IGUIEnvironment *gui)
{
  gui->addImage(scene.getDriver()->getTexture("media/background.jpg"),
		irr::core::position2d<int>(0,0));
  gui->addImage(scene.getDriver()->getTexture("media/logo-preview.png"),
                irr::core::position2d<int>(600,50));
}

void				Menu::add_characters_choices(irr::gui::IGUIEnvironment *gui)
{
  irr::gui::IGUIButton          *button;

  button = gui->addButton(irr::core::rect<irr::s32>(550,1000,700,1000 + 50), 0, GUI_ID_BOWMAN_BUTTON,
			  L"Bowman", L"Choose Bowman character");
  if (button)
    button->setImage(scene.getDriver()->getTexture("media/bouton.jpg"));
  button = gui->addButton(irr::core::rect<irr::s32>(750,1000,900,1000 + 50), 0, GUI_ID_ELF_BUTTON,
			  L"Elf", L"Choose Elf character");
  if (button)
    button->setImage(scene.getDriver()->getTexture("media/bouton.jpg"));
  button = gui->addButton(irr::core::rect<irr::s32>(950,1000,1100,1000 + 50), 0, GUI_ID_MAGE_BUTTON,
                          L"Mage", L"Choose Mage character");
  if (button)
    button->setImage(scene.getDriver()->getTexture("media/bouton.jpg"));
  button = gui->addButton(irr::core::rect<irr::s32>(1150,1000,1300,1000 + 50), 0, GUI_ID_WARRIOR_BUTTON,
                          L"Warrior", L"Choose Warrior character");
  if (button)
    button->setImage(scene.getDriver()->getTexture("media/bouton.jpg"));
}

void				Menu::add_managers(irr::gui::IGUIEnvironment *gui)
{
  irr::gui::IGUIButton          *button;

  button = gui->addButton(irr::core::rect<irr::s32>(1750,1000,1900,1000 + 50), 0, GUI_ID_PLAY_BUTTON,
                          L"PLAY", L"Play a new game");
  if (button)
    button->setImage(scene.getDriver()->getTexture("media/bouton.jpg"));
  button = gui->addButton(irr::core::rect<irr::s32>(1750,930,1900,930 + 50), 0, GUI_ID_DEMO_BUTTON,
                          L"DEMO", L"Play Guauntlet Demo");
  if (button)
    button->setImage(scene.getDriver()->getTexture("media/bouton.jpg"));
  button = gui->addButton(irr::core::rect<irr::s32>(10,1000,150,1000 + 50), 0, GUI_ID_QUIT_BUTTON,
                          L"QUIT", L"Exits Guauntlet");
  if (button)
    button->setImage(scene.getDriver()->getTexture("media/bouton.jpg"));
}

void				Menu::add_buttons()
{
  irr::gui::IGUIEnvironment	*gui = scene.getGuienv();
  //  irr::gui::IGUIButton		*bouton;

  add_background(gui);
  add_characters_choices(gui);
  add_managers(gui);
  edit_box.id_name = gui->addEditBox(L"PLAYER 1", irr::core::rect<irr::s32>(10, 80, 150, 80 + 50),
				     true, 0, 1);
  edit_box.id_ip = gui->addEditBox(L"127.0.0.1", irr::core::rect<irr::s32>(10, 150, 150, 150 + 50),
				   true, 0, 2);
  edit_box.id_port = gui->addEditBox(L"4242", irr::core::rect<irr::s32>(10, 220, 150, 220 + 50),
				     true, 0, 3);
}

Game_opt	*Menu::getGameOpt()
{
  return &this->new_game;
}

GraphicRoot	&Menu::getScene()
{
  return this->scene;
}

bool		Menu::getQuit()
{
  return this->new_game.quit;
}

MyEventReceiver::MyEventReceiver(irr::IrrlichtDevice *dev, Game_opt &new_game,
				 EditBox &box)
  : device(dev), game(new_game), edit_box(box)
{
}

MyEventReceiver::~MyEventReceiver()
{
}

bool			MyEventReceiver::OnEvent(const irr::SEvent &event)
{
  irr::s32		id;

  if (event.EventType == irr::EET_GUI_EVENT)
    {
      id = event.GUIEvent.Caller->getID();
      switch (event.GUIEvent.EventType)
	{
	case irr::gui::EGET_BUTTON_CLICKED :
	  switch(id)
	    {
	    case GUI_ID_QUIT_BUTTON :
	      device->closeDevice();
	      game.quit = true;
	      return true;
	    case GUI_ID_PLAY_BUTTON :
	      get_text_boxes();
	      device->closeDevice();
	      return true;
	    case GUI_ID_DEMO_BUTTON :
	      run_demo();
	      return true;
	    case GUI_ID_MAGE_BUTTON :
	      game.character = MAGE;
	      add_mesh(MAGE);
	      return true;
	    case GUI_ID_WARRIOR_BUTTON :
	      game.character = WARRIOR;
	      add_mesh(WARRIOR);
	      return true;
	    case GUI_ID_BOWMAN_BUTTON :
	      game.character = BOWMAN;
	      add_mesh(BOWMAN);
	      return true;
	    case GUI_ID_ELF_BUTTON :
	      game.character = ELF;
	      add_mesh(ELF);
	      return true;
	    default:
	      return false;
	    }
	default:
	  break;
	}
    }
  return false;
}

void				MyEventReceiver::run_demo()
{
  std::cout << "running demo" << std::endl;
}

void				MyEventReceiver::get_text_boxes()
{
  irr::gui::IGUIEnvironment	*env;
  irr::gui::IGUIElement		*found;
  const char			*tmp;
  irr::core::stringc		data;

  env = this->device->getGUIEnvironment();
  found = env->getRootGUIElement()->getElementFromId(1, true);
  if (found)
    {
      data = found->getText();
      if (data.size())
	{
	  tmp = data.c_str();
	  game.player_name = static_cast<std::string>(tmp);
	}
    }
  found = env->getRootGUIElement()->getElementFromId(2, true);
  if (found)
    {
      data = found->getText();
      if (data.size())
        {
          tmp = data.c_str();
          game.net.ip = static_cast<std::string>(tmp);
        }
    }
  found = env->getRootGUIElement()->getElementFromId(3, true);
  if (found)
    {
      data = found->getText();
      if (data.size())
        {
          tmp = data.c_str();
          game.net.port = static_cast<std::string>(tmp);
        }
    }
}

irr::scene::IAnimatedMesh		*MyEventReceiver::get_my_mesh(CharacterType character)
{
  irr::scene::IAnimatedMesh             *mesh;
  irr::scene::ISceneManager             *smgr = device->getSceneManager();

  if (character == ELF)
    mesh = smgr->getMesh("media/characters/faerie.md2");
  if (character == WARRIOR)
    mesh = smgr->getMesh("media/characters/Samourai.md2");
  if (character == MAGE)
    mesh = smgr->getMesh("media/characters/drfreak.md2");
  if (character == BOWMAN)
    mesh = smgr->getMesh("media/characters/gijoe.MD2");
  return mesh;
}

void				MyEventReceiver::get_texture(irr::scene::IAnimatedMeshSceneNode
							     *node,
							     CharacterType character)
{
  irr::video::IVideoDriver	*driver = device->getVideoDriver();

  if (character == ELF)
    node->setMaterialTexture(0, driver->getTexture("media/characters/Faerie5.BMP"));
  if (character == WARRIOR)
    node->setMaterialTexture(0, driver->getTexture("media/characters/Samourai.jpg"));
  if (character == MAGE)
    node->setMaterialTexture(0, driver->getTexture("media/characters/drfreak.jpg"));
  if (character == BOWMAN)
    node->setMaterialTexture(0, driver->getTexture("media/characters/gijoe.MD2_r.jpg"));
}

int					MyEventReceiver::add_mesh(CharacterType character)
{
  irr::video::IVideoDriver		*driver = device->getVideoDriver();
  irr::scene::ISceneManager		*smgr = device->getSceneManager();
  irr::scene::IAnimatedMesh		*mesh;
  irr::scene::IAnimatedMeshSceneNode	*node;

  smgr->clear();
  mesh = get_my_mesh(character);
  if (!mesh)
    return 1;
  node = smgr->addAnimatedMeshSceneNode(mesh);
  if (node)
    {
      node->setPosition(irr::core::vector3df(0,-15,10));
      node->setRotation(irr::core::vector3df(0,90,0));
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      node->setMD2Animation(irr::scene::EMAT_STAND);
      get_texture(node, character);
    }
  smgr->addCameraSceneNode(0, irr::core::vector3df(0,30,-60), irr::core::vector3df(0,5,0));
  return 0;
}
