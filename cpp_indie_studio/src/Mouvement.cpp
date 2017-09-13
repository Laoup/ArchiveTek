//
// Mouvement.cpp for Mouvement in /home/aknin_k/rendu/tek2/cpp/indie/project/indie-studio/src
// 
// Made by Karine Aknin
// Login   <aknin_k@epitech.net>
// 
// Started on  Sun Jun  5 15:42:53 2016 Karine Aknin
// Last update Sun Jun  5 18:06:09 2016 christophe lucas
//

#include "Client.hh"
#include "Character.hh"

int	Client::moveLEFT(void *data, std::vector<struct
			 CommandSet *> *commands,
			 unsigned int rep)
{
  Client		*client;
  irr::core::vector3df	nodePosition;
  irr::core::vector3df	nodeRotation;

  client = (Client *)data;
  if (!client->players[client->id]->getIsDead())
    {
      nodePosition =
	client->players[client->id]->getNode()->getPosition();
      nodePosition.Z += MOVEMENT_SPEED_DEF * Character::deltaTime;
      nodeRotation =
	client->players[client->id]->getNode()->getRotation();
      nodeRotation.Y = -120.0f;
      client->players[client->id]->getNode()->setRotation(nodeRotation);
      client->players[client->id]->getNode()->setPosition(nodePosition);
      client->sendCharacterPos(nodePosition, nodeRotation);
      client->camera.updateTargetPosition(nodePosition);
    }
  return 0;
  (void)commands;
  (void)rep;
}

int	Client::moveRIGHT(void *data, std::vector<struct
			  CommandSet *> *commands,
			  unsigned int rep)
{
  Client		*client;
  irr::core::vector3df	nodePosition;
  irr::core::vector3df	nodeRotation;

  client = (Client *)data;
  if (!client->players[client->id]->getIsDead())
    {
      nodePosition = client->players[client->id]->getNode()->getPosition();
      nodePosition.Z -= MOVEMENT_SPEED_DEF * Character::deltaTime;
      nodeRotation = client->players[client->id]->getNode()->getRotation();
      nodeRotation.Y = 60.0f;
      client->players[client->id]->getNode()->setRotation(nodeRotation);
      client->players[client->id]->getNode()->setPosition(nodePosition);
      client->sendCharacterPos(nodePosition, nodeRotation);
      client->camera.updateTargetPosition(nodePosition);
    }
  return 0;
  (void)commands;
  (void)rep;
}

int			Client::moveDOWN(void *data, std::vector<struct
					 CommandSet *> *commands,
					 unsigned int rep)
{
  Client		*client;
  irr::core::vector3df	nodePosition;
  irr::core::vector3df	nodeRotation;

  client = (Client *)data;
  if (!client->players[client->id]->getIsDead())
    {
      nodePosition = client->players[client->id]->getNode()->getPosition();
      nodePosition.X -= MOVEMENT_SPEED_DEF * Character::deltaTime;
      nodeRotation = client->players[client->id]->getNode()->getRotation();
      nodeRotation.Y = 150.0f;
      client->players[client->id]->getNode()->setRotation(nodeRotation);
      client->players[client->id]->getNode()->setPosition(nodePosition);
      client->sendCharacterPos(nodePosition, nodeRotation);
      client->camera.updateTargetPosition(nodePosition);
    }      
  return 0;
  (void)commands;
  (void)rep;
}

int			Client::moveUP(void *data, std::vector<struct
				       CommandSet *> *commands,
				       unsigned int rep)
{
  Client		*client;
  irr::core::vector3df	nodePosition;
  irr::core::vector3df	nodeRotation;

  client = (Client *)data;
  if (!client->players[client->id]->getIsDead())
    {
      nodePosition = client->players[client->id]->getNode()->getPosition();
      nodePosition.X += MOVEMENT_SPEED_DEF * Character::deltaTime;
      nodeRotation = client->players[client->id]->getNode()->getRotation();
      nodeRotation.Y = -30.0f;
      client->players[client->id]->getNode()->setRotation(nodeRotation);
      client->players[client->id]->getNode()->setPosition(nodePosition);
      client->sendCharacterPos(nodePosition, nodeRotation);
      client->camera.updateTargetPosition(nodePosition);
    }
  return 0;
  (void)commands;
  (void)rep;
}
