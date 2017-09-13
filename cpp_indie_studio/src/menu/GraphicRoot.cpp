//
// GraphicRoot.cpp for GraphicRoot in /home/aknin_k/rendu/tek2/cpp/indie/menu/src
//
// Made by Karine Aknin
// Login   <aknin_k@epitech.net>
//
// Started on  Fri May 20 18:45:10 2016 Karine Aknin
// Last update Sun Jun  5 18:21:52 2016 christophe lucas
//

#include "menu/GraphicRoot.hh"

GraphicRoot::GraphicRoot()
{
}

GraphicRoot::~GraphicRoot()
{
}

int		GraphicRoot::init_all()
{
  if (!(this->device = irr::createDevice(irr::video::EDT_OPENGL,
					 irr::core::dimension2d<irr::u32>(1920,1080))))
    {
      std::cerr << "[-] ERROR : createDevice failed" << std::endl;
      return 1;
    }
  device->setWindowCaption(L"INDIE STUDIO - GAUNTLET");
  this->driver = device->getVideoDriver();
  this->guienv = device->getGUIEnvironment();
  this->smgr = device->getSceneManager();
  this->skin = guienv->getSkin();
  this->font = guienv->getFont("media/fonthaettenschweiler.bmp");
  if (this->font)
    this->skin->setFont(this->font);
  this->skin->setFont(this->guienv->getBuiltInFont(),
		      irr::gui::EGDF_TOOLTIP);
  return 0;
}

void			GraphicRoot::drop_device()
{
  this->device->drop();
}

irr::IrrlichtDevice        *GraphicRoot::getDevice() const
{
  return this->device;
}

irr::video::IVideoDriver          *GraphicRoot::getDriver() const
{
  return this->driver;
}

irr::scene::ISceneManager         *GraphicRoot::getSmgr() const
{
  return this->smgr;
}

irr::gui::IGUIEnvironment       *GraphicRoot::getGuienv() const
{
  return this->guienv;
}

irr::gui::IGUISkin              *GraphicRoot::getSkin() const
{
  return this->skin;
}

irr::gui::IGUIFont              *GraphicRoot::getFont() const
{
  return this->font;
}
