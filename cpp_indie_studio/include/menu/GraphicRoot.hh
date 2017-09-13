//
// GraphicRoot.hh for GraphicRoot in /home/aknin_k/rendu/tek2/cpp/indie/menu/include
//
// Made by Karine Aknin
// Login   <aknin_k@epitech.net>
//
// Started on  Fri May 20 18:35:32 2016 Karine Aknin
// Last update Sun Jun  5 17:30:44 2016 christophe lucas
//

#ifndef GraphicRoot_HH_
# define GraphicRoot_HH_

# include <irrlicht.h>
# include <string>
# include <iostream>

#ifdef _IRR_WINDOWS_
# pragma comment(lib, "Irrlicht.lib")
# pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif


class				GraphicRoot
{
public :
  GraphicRoot();
  ~GraphicRoot();

  int				init_all();
  void				drop_device();
  irr::IrrlichtDevice		*getDevice() const;
  irr::video::IVideoDriver      *getDriver() const;
  irr::scene::ISceneManager     *getSmgr() const;
  irr::gui::IGUIEnvironment     *getGuienv() const;
  irr::gui::IGUISkin		*getSkin() const;
  irr::gui::IGUIFont		*getFont() const;

private:
  irr::IrrlichtDevice		*device;
  irr::video::IVideoDriver	*driver;
  irr::scene::ISceneManager	*smgr;
  irr::gui::IGUIEnvironment	*guienv;
  irr::gui::IGUISkin		*skin;
  irr::gui::IGUIFont		*font;
};

#endif /* ! GraphicRoot_HH_ */
