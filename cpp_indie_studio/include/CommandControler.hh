//
// CommandControler.hh for Command.hh in /home/meuric_a/Projet_T2/Indie/indie-studio/src_command/include
//
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
//
// Started on  Sun May 22 21:42:24 2016 Alban Meurice
// Last update Sun Jun  5 17:19:19 2016 christophe lucas
//

#ifndef COMMANDCONTROLER_HH_
# define COMMANDCONTROLER_HH_

# include "Protocole.hh"
# include <irrlicht.h>
# include <vector>

typedef	int (*CommandFunction)(void *, std::vector<struct CommandSet *> *, unsigned int rep);

class					CommandControler : public irr::IEventReceiver
{
  std::vector<unsigned int>		ifCommandConfig(const irr::SEvent &event);

public:
					CommandControler();
					~CommandControler();
  virtual bool				OnEvent(const irr::SEvent &);
  bool					addKeyEvent(irr::EKEY_CODE, CommandFunction, void *);
  bool					addMouseEvent(irr::EMOUSE_INPUT_EVENT, CommandFunction);
  bool					addButtonEvent(irr::s32, CommandFunction);

  std::vector<struct CommandSet *>	cmd;
  enum					type
    {
      KEY,
      MOUSE,
      BUTTON,
    };
};

struct	CommandSet
{
  CommandControler::type	type;
  irr::SEvent			cmd;
  CommandFunction		ptr;
  bool				isPress;
  bool				isPressPrec;
  void				*staticdata;
};

#endif /* COMMANDCONTROLER_HH_ */
