//
// Client.cpp for Client in /home/aknin_k/rendu/tek2/cpp/indie/project/indie-studio/src
// 
// Made by Karine Aknin
// Login   <aknin_k@epitech.net>
// 
// Started on  Sun Jun  5 15:22:35 2016 Karine Aknin
// Last update Sun Jun  5 21:51:25 2016 christophe lucas
//

#include "Client.hh"

ErrorControler	error = ErrorControler();

Client::Client(const std::string &ip, int port, const std::string &name
	       , const CharacterType &type)
  : commandControler(),
    orderControler(ip, port),
    camera(),
    room("Principale", NB_PLAYER),
    device(NULL),
    driver(NULL),
    smgr(NULL),
    attribs(NULL),
    name(name),
    character_type(type),
    ready(false),
    win(false),
    fail(false)
{
  NewRoom	*roomOrder = new NewRoom(room.name, room.size);

  for (size_t i = 0; i < NB_PLAYER; ++i)
    this->players[i] = NULL;
  id = orderControler.getProtocole()->getId();
  orderControler.run();
  orderControler.sendOrder(NewOrder(id, PROTOCOLE::CommandType::JOIN_ROOM, sizeof(struct NewRoom), roomOrder));
  orderControler.addOrder(PROTOCOLE::CommandType::DISCONNECT, (OrderFunction)&Client::disconnectServer, this);
  orderControler.addOrder(PROTOCOLE::CommandType::START_GAME, (OrderFunction)&Client::startGame, this);
  orderControler.addOrder(PROTOCOLE::CommandType::DELETE_MESH, (OrderFunction)&Client::deleteMesh, this);
}

Client::~Client()
{
  NewRoom	*roomOrder = new NewRoom(room.name, room.size);
  NewCharacter	*newMesh =
    new NewCharacter(id, this->players[this->id]->getCharacterType(), 0, 0, 0, 0, 0, 0);

  device->drop();
  attribs->drop();
  orderControler.sendOrder(NewOrder(id, PROTOCOLE::CommandType::QUIT_ROOM, sizeof(struct NewRoom), roomOrder));
  orderControler.sendOrder(NewOrder(id, PROTOCOLE::CommandType::DELETE_MESH, sizeof(struct NewCharacter), newMesh));
  sleep(1);
}

int	Client::disconnectServer(void *staticdata, Order *orderdata)
{
  (void)staticdata;
  delete orderdata;
  throw Error("disconnect", 0);
  return 0;
}

int	Client::listRoom(void *staticdata, Order *orderdata)
{
  static_cast<void>(staticdata);
  delete orderdata;
  throw Error("disconnect", 0);
  return 0;
}


int		Client::exitClient(void *data, std::vector<struct CommandSet *> *commands, unsigned int rep)
{
  NewCharacter	*newMesh;
  Client	*client;

  client = (Client *)data;
  newMesh = new NewCharacter(client->id, MAGE, 0, 0, 0, 0, 0, 0);
  client->orderControler.sendOrder
    (NewOrder(client->id, PROTOCOLE::CommandType::DELETE_MESH, sizeof(struct NewCharacter), newMesh));
  exit(EXIT_FAILURE);
  (void)commands;
  (void)rep;
}

int	Client::attackEnemy(void *data,
			    std::vector<struct CommandSet *> *commands,
			    unsigned int rep)
{
  Client	*client;

  client = (Client *)data;
  if (!(client->players[client->id]->getPv()))
    return 0;
  client->players[client->id]->attackEnemyPlayer(client->enemies);
  return 0;
}

const OrderControler	&Client::getControler(void) const
{
  return this->orderControler;
}

static bool	checkIpAddressPart(std::string ipPart,
				   const size_t length)
{
  int		number;

  ipPart = ipPart.substr(0, length);
  if ((number = std::atoi(ipPart.c_str())) >= 0
      && number <= 255)
    return (true);
  return (false);
}

static bool	checkIpAddress(const char *line)
{
  size_t	posx = 0;
  size_t	counter = 0;
  size_t	i;

  i = 0;
  if (!line)
    return (false);
  while (line[i] && ISSPACE(line[i]))
    ++i;
  while (counter < 4)
    {
      posx = i;
      while (line[i] && ISDIGIT(line[i]))
        ++i;
      if (!((i - posx) && (i - posx) <= 3))
	return (false);
      if (!checkIpAddressPart(line + posx, i - posx))
	return (false);
      ++i;
      if (++counter < 4 && line[i - 1] != '.')
	return (false);
    }
  if (line[i - 1] == '.')
    return (false);
  return (true);
}

static bool	checkPort(const std::string &line)
{
  int		number;
  size_t	i;

  i = 0;
  if (!(line.size() < 5))
    return (false);
  number = std::atoi(line.c_str());
  while (line.c_str()[i])
    {
      if (!ISDIGIT(line.c_str()[i]))
	return (false);
      ++i;
    }
  return (number >= 0 && number <= 65535);
}

static bool	validNetAddress(Game_opt *opt)
{
  if (!opt)
    return (false);
  return (checkIpAddress(opt->net.ip.c_str()) && checkPort(opt->net.port.c_str()));
}

static Game_opt	*handleMenu(Menu &menu)
{
  Game_opt	*opt;

  opt = NULL;
  try
    {
      while (true)
	{
	  if (menu.renderMenu() == 1)
	    return NULL;
	  if (menu.getQuit())
	    return NULL;
	  opt = menu.getGameOpt();
	  if (validNetAddress(menu.getGameOpt()))
	    break;
	}
    }
  catch(std::exception const& e)
    {
      std::cerr << "ERREUR : " << e.what() << std::endl;
    }
  return (opt);
}

static bool	handleGame(Game_opt *opt)
{
  Client	client(opt->net.ip, stoi(opt->net.port),
		       opt->player_name, opt->character);

  if (!client.initGame() || !client.runGame())
    return (false);
  return (true);
}

int		main()
{
  Menu		menu;
  Game_opt	*opt;

  if ((opt = handleMenu(menu)) == NULL)
    return (EXIT_FAILURE);
  if (handleGame(opt) == false)
    return (EXIT_FAILURE);

  return (EXIT_SUCCESS);
}
