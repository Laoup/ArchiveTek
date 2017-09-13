//
// CommandControler.cpp for CommandControler.cpp in /home/meuric_a/Projet_T2/Indie/indie-studio/src_command/src
//
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
//
// Started on  Sun May 22 22:01:45 2016 Alban Meurice
// Last update Sun Jun  5 15:28:39 2016 Karine Aknin
//

#include "CommandControler.hh"
#include <iostream>
#include <algorithm>

CommandControler::CommandControler()
{
}

CommandControler::~CommandControler()
{
  std::vector<struct CommandSet *>::iterator itr;
  
  for (itr = cmd.begin(); itr != cmd.end(); itr++)
    delete (*itr);
}

bool	CommandControler::OnEvent(const irr::SEvent &event)
{
  std::vector<unsigned int>	list_cmd;
  unsigned int		       	it;
  unsigned int			it2;

  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    {
      list_cmd = this->ifCommandConfig(event);
      if (list_cmd.empty() == true)
        return (false);
      for (it = 0; it < list_cmd.size(); it++)
      {
        this->cmd[list_cmd[it]]->isPressPrec =
	  this->cmd[list_cmd[it]]->isPress;
        if (event.KeyInput.PressedDown == true)
          this->cmd[list_cmd[it]]->isPress = true;
        else
          this->cmd[list_cmd[it]]->isPress = false;
      }
    }
    for (it = 0; it < this->cmd.size(); it++)
    {
      for (it2 = 0; it2 < list_cmd.size(); it2++)
        if (list_cmd[it2] == it && this->cmd[it]->isPress
	    == false)
          if (this->cmd[it]->ptr(this->cmd[it]->staticdata,
				 &this->cmd, it) == -1)
            return (false);
      if (this->cmd[it]->isPress == true)
        if (this->cmd[it]->ptr(this->cmd[it]->staticdata,
			       &this->cmd, it) == -1)
          return (false);
    }
  return (true);
}

std::vector<unsigned int>	CommandControler::ifCommandConfig(const irr::SEvent &event)
{
  std::vector<unsigned int>	list_cmd;
  unsigned int	it;

  for(it = 0; it < this->cmd.size(); it++)
    {
      if (this->cmd[it]->type == CommandControler::type::KEY)
	if (this->cmd[it]->cmd.KeyInput.Key == event.KeyInput.Key)
	  list_cmd.push_back(it);
	else if (this->cmd[it]->type ==
		 CommandControler::type::MOUSE)
	  if (this->cmd[it]->cmd.MouseInput.Event ==
	      event.MouseInput.Event)
	    list_cmd.push_back(it);
    }
  return (list_cmd);
}

bool	CommandControler::addKeyEvent(irr::EKEY_CODE key,
				      CommandFunction fct,
				      void *data)
{
  CommandSet	*newCommand;

  newCommand = new CommandSet;
  newCommand->cmd.KeyInput.Key = key;
  newCommand->type = CommandControler::type::KEY;
  newCommand->ptr = fct;
  newCommand->isPress = false;
  newCommand->isPressPrec = false;
  newCommand->staticdata = data;
  this->cmd.push_back(newCommand);
}

bool	CommandControler::addMouseEvent(irr::EMOUSE_INPUT_EVENT
					key, CommandFunction fct)
{
  CommandSet	*newCommand;

  newCommand = new CommandSet;
  newCommand->cmd.MouseInput.Event = key;
  newCommand->type = CommandControler::type::MOUSE;
  newCommand->ptr = fct;
  newCommand->isPress = false;
  newCommand->isPressPrec = false;
  this->cmd.push_back(newCommand);
}

bool	CommandControler::addButtonEvent(irr::s32 id,
					 CommandFunction fct)
{
  CommandSet	*newCommand;

  newCommand = new CommandSet;
  newCommand->cmd.GUIEvent.Caller->setID(id);
  newCommand->type = CommandControler::type::BUTTON;
  newCommand->ptr = fct;
  newCommand->isPress = false;
  newCommand->isPressPrec = false;
  this->cmd.push_back(newCommand);
}
