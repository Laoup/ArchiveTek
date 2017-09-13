//
// Position.cpp for Position in /home/aknin_k/rendu/tek2/cpp/indie/project/indie-studio/src
// 
// Made by Karine Aknin
// Login   <aknin_k@epitech.net>
// 
// Started on  Sun Jun  5 15:49:23 2016 Karine Aknin
// Last update Sun Jun  5 22:00:33 2016 christophe lucas
//

#include "Client.hh"

int	Client::sendCharacterPos(const irr::core::vector3df
				 &position, const irr::core::vector3df
				 &rotation)
{
  NodePosition	*pos = new NodePosition(this->id,
					position.X,
					position.Y,
					position.Z,
					rotation.X,
					rotation.Y,
					rotation.Z);
  orderControler.sendOrder(this->id, PROTOCOLE::CommandType::SET, sizeof(struct NodePosition), pos);
  return 0;
}

int		Client::receiveCharacterPos(void *staticdata,
					    Order *orderdata)
{
  Client	*client;
  NodePosition	*pos;

  client = (Client *)staticdata;
  pos = ((NodePosition*)orderdata->data);
  client->players[pos->id]->getNode()->setPosition(irr::core::vector3df(pos->x, pos->y, pos->z));
  client->players[pos->id]->getNode()->setRotation(irr::core::vector3df(pos->a, pos->b, pos->c));
  return 0;
}
