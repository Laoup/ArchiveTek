//
// menu.hh for menu in /home/aknin_k/rendu/tek2/cpp/indie/menu/include
//
// Made by Karine Aknin
// Login   <aknin_k@epitech.net>
//
// Started on  Sun May 22 23:21:38 2016 Karine Aknin
// Last update Sun Jun  5 17:32:00 2016 christophe lucas
//

#ifndef MENU_HH_
# define MENU_HH_

# include "GraphicRoot.hh"
# include "OrderData.hh"

enum
  {
    GUI_ID_QUIT_BUTTON = 101,
    GUI_ID_LEVEL1_BUTTON,
    GUI_ID_MAGE_BUTTON,
    GUI_ID_WARRIOR_BUTTON,
    GUI_ID_BOWMAN_BUTTON,
    GUI_ID_ELF_BUTTON,
    GUI_ID_PLAY_BUTTON,
    GUI_ID_DEMO_BUTTON,
  };



struct			SAppContext
{
  irr::IrrlichtDevice	*device;
  irr::s32		counter;
  irr::gui::IGUIListBox	*listbox;
};



struct			Network
{
  Network(const std::string &ip, const std::string &port)
    : set(false),
      ip(ip),
      port(port)
  {
  }

  bool			set;
  std::string		ip;
  std::string		port;
};



struct			Game_opt
{
  Game_opt(const std::string &name = "Player1", size_t level = 1, size_t score = 0,
	   CharacterType character = WARRIOR, const std::string &ip = "127.0.0.1",
	   const std::string &port = "4242")
    : player_name(name),
      level(level),
      score(score),
      character(character),
      net(ip, port),
      quit(false)
  {
  }

  std::string		player_name;
  int			level;
  size_t		score;
  CharacterType		character;
  Network		net;
  bool			quit;
};



struct			EditBox
{
  irr::gui::IGUIEditBox	*id_name;
  irr::gui::IGUIEditBox	*id_ip;
  irr::gui::IGUIEditBox	*id_port;
};

class				MyEventReceiver : public irr::IEventReceiver
{
public:
  MyEventReceiver(irr::IrrlichtDevice *, Game_opt &, EditBox &);
  ~MyEventReceiver();

  bool				OnEvent(const irr::SEvent &event);
  int				add_mesh(CharacterType);
  void				get_text_boxes();
  void				run_demo();
  void				get_texture(irr::scene::IAnimatedMeshSceneNode *,
					    CharacterType);
  irr::scene::IAnimatedMesh	*get_my_mesh(CharacterType);

private:
  irr::IrrlichtDevice		*device;
  Game_opt			&game;
  struct EditBox		&edit_box;
};

class			Menu
{
public:
  Menu();
  ~Menu();

  int			renderMenu();
  Game_opt		*getGameOpt();
  GraphicRoot		&getScene();
  bool			getQuit();
  void			add_buttons();
  void			run_begin();
  void			add_background(irr::gui::IGUIEnvironment *);
  void			add_characters_choices(irr::gui::IGUIEnvironment *);
  void			add_managers(irr::gui::IGUIEnvironment *);

private:
  GraphicRoot		scene;
  Game_opt		new_game;
  EditBox		edit_box;
};

#endif /* ! MENU_HH_ */
