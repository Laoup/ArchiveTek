//
// LoadCharacter.cpp for LoadCharacter in /home/aknin_k/rendu/tek2/cpp/indie/project/indie-studio/src
// 
// Made by Karine Aknin
// Login   <aknin_k@epitech.net>
// 
// Started on  Sun Jun  5 15:36:45 2016 Karine Aknin
// Last update Sun Jun  5 23:15:06 2016 Karine Aknin
//

#include "Client.hh"

# define NB_LIZARD	9
# define NB_SQUELETTE	20

static irr::core::vector3df lizardPos[] = {
  irr::core::vector3df(-380.122, 41.7961, 14.8436),
  irr::core::vector3df(-472.641, 41.7961, 64.8437),
  irr::core::vector3df(-489.141, 41.7961, -135.656),
  irr::core::vector3df(-552.49, 41.7961, -234.656),
  irr::core::vector3df(99.0213, 42.7553, 126.664),
  irr::core::vector3df(94.6393, 23.7928, -13.5845),
  irr::core::vector3df(12.1393, 23.7928, -13.5845),
  irr::core::vector3df(301.811, 42.0306, 411.849),
  irr::core::vector3df(-114.548, 41.6984, 258.084)
};

static irr::core::vector3df squelettePos[] = {
 irr::core::vector3df(-187.122, 41.7961, -274.124),
 irr::core::vector3df(-269.622, 41.7961, -294.124),
 irr::core::vector3df(-270.122, 41.7961, -396.156),
 irr::core::vector3df(-128.141, 41.7961, -286.156),
 irr::core::vector3df(-327.49, 41.7961, -132.001),
 irr::core::vector3df(29.0101, 42.3578, 514.013),
 irr::core::vector3df(145.51, 42.3578, 430.013),
 irr::core::vector3df(229.51, 42.3578, 512.013),
 irr::core::vector3df(229.51, 42.3578, 345.513),
 irr::core::vector3df(113.51, 42.3578, 294.424),
 irr::core::vector3df(-151.991, 42.1499, -244.995),
 irr::core::vector3df(-283.992, 42.1499, -228.495),
 irr::core::vector3df(-300.491, 42.1499, -161.995),
 irr::core::vector3df(-300.491, 42.1499, -392.995),
 irr::core::vector3df(-342.578, 42.1499, -314.495),
 irr::core::vector3df(-62.622, 42.1393, 266.107),
 irr::core::vector3df(20.2882, 42.3578, 332.107),
 irr::core::vector3df(104.288, 42.3578, 397.107),
 irr::core::vector3df(187.288, 42.3578, 414.107),
 irr::core::vector3df(154.788, 42.3578, 531.107)
};

void	Client::loadPath(CharacterType type, std::string &meshPath, std::string &texturePath)
{
  switch (type)
    {
    case WARRIOR:
      meshPath = "media/characters/Samourai.md2";
      texturePath = "media/characters/Samourai.jpg";
      break;
    case MAGE:
      meshPath = "media/characters/drfreak.md2";
      texturePath = "media/characters/drfreak.jpg";
      break;
    case BOWMAN:
      meshPath = "media/characters/gijoe.MD2";
      texturePath = "media/characters/gijoe.MD2_r.jpg";
      break;
    case ELF:
      meshPath = "media/characters/faerie.md2";
      texturePath = "media/characters/Faerie5.BMP";
      break;
    case ENEMY_1:
      meshPath = "media/enemies/Lezard.md2";
      texturePath = "media/enemies/Lezard.jpg";
      break;
    case ENEMY_2:
      meshPath = "media/enemies/Squelette.md2";
      texturePath = "media/enemies/Squelette.jpg";
      break;
    default:
      meshPath = "media/characters/Samourai.md2";
      texturePath = "media/characters/Samourai.jpg";
      break;
    };
}

irr::scene::IAnimatedMeshSceneNode    *Client::loadMyCharacter()
{
  irr::video::ITexture                 *texture;
  irr::scene::IAnimatedMesh             *mesh;
  irr::scene::IAnimatedMeshSceneNode    *node;
  std::string                           meshPath;
  std::string                           texturePath;
  NewCharacter                          *perso;

  loadPath(character_type, meshPath, texturePath);
  if (!(mesh = smgr->getMesh(meshPath.c_str())))
    {
      std::cerr << "Could not load mesh" << std::endl;
      exit(EXIT_FAILURE);
    }
  if ((node =
       smgr->addAnimatedMeshSceneNode(mesh, 0, -1, irr::core::vector3df(-187.122, 41.8887, -58.124), irr::core::vector3df(0, 90, 0))))
    {
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      node->setMD2Animation(irr::scene::EMAT_STAND);
      node->setScale(irr::core::vector3df(0.5f));
      if (!(texture = driver->getTexture(texturePath.c_str())))
        std::cerr << "Could not load texture" << std::endl;
      node->setMaterialTexture(0, texture);
      this->players[id] = new Player(node, &orderControler,character_type, 20, 2, this->id);
    }
  perso = new NewCharacter(this->id, character_type, -187.122, 41.8887, -58.124, 0, 90, 0);
  orderControler.sendOrder(NewOrder(id, PROTOCOLE::CommandType::NEW_MESH, sizeof(struct NewCharacter), perso));
  return node;
}

bool					Client::loadEnemies()
{
  irr::video::ITexture			*texture;
  irr::scene::IAnimatedMesh             *mesh;
  irr::scene::IAnimatedMeshSceneNode    *node;
  std::string                           meshPath;
  std::string                           texturePath;

  for (size_t i = 0; i < NB_LIZARD; ++i)
    {
      loadPath(ENEMY_1, meshPath, texturePath);
      if (!(mesh = smgr->getMesh(meshPath.c_str())))
	{
	  std::cerr << "Could not load mesh" << std::endl;
	  exit(EXIT_FAILURE);
	}
      if ((node = smgr->addAnimatedMeshSceneNode(mesh, 0, -1, lizardPos[i],
						 irr::core::vector3df(0, 90, 0))))
	{
	  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  node->setMD2Animation(irr::scene::EMAT_STAND);
	  node->setScale(irr::core::vector3df(0.5f));
	  if (!(texture = driver->getTexture(texturePath.c_str())))
	    std::cerr << "Could not load texture" << std::endl;
	  node->setMaterialTexture(0, texture);
	  enemies[i] = new Enemy(node, ENEMY_1, 2, 1);
	}
    }
  for (size_t i = 0; i < NB_SQUELETTE; ++i)
    {
      loadPath(ENEMY_2, meshPath, texturePath);
      if (!(mesh = smgr->getMesh(meshPath.c_str())))
	{
	  std::cerr << "Could not load mesh" << std::endl;
	  exit(EXIT_FAILURE);
	}
      if ((node = smgr->addAnimatedMeshSceneNode(mesh, 0, -1, squelettePos[i],
						 irr::core::vector3df(0, 90, 0))))
	{
	  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  node->setMD2Animation(irr::scene::EMAT_STAND);
	  node->setScale(irr::core::vector3df(0.5f));
	  if (!(texture = driver->getTexture(texturePath.c_str())))
	    std::cerr << "Could not load texture" << std::endl;
	  node->setMaterialTexture(0, texture);
	  enemies[NB_LIZARD + i] = new Enemy(node,ENEMY_2, 2, 1);
	}
    }
  return true;
}

int Client::newCharacter(void *staticdata, Order *orderdata)
{
  Client                                *client;
  NewCharacter                          *perso;
  irr::scene::IAnimatedMesh             *mesh;
  irr::scene::IAnimatedMeshSceneNode    *node;
  irr::video::ITexture                 *texture;
  std::string                           meshPath;
  std::string                           texturePath;

  client = (Client *)staticdata;
  perso = ((NewCharacter *)orderdata->data);
  client->loadPath(perso->type, meshPath, texturePath);
  if (!(mesh = client->smgr->getMesh(meshPath.c_str())))
    {
      std::cerr << "Could not load mesh" << std::endl;
      exit(EXIT_FAILURE);
    }
  if ((node = client->smgr->addAnimatedMeshSceneNode
       (mesh, 0, -1, irr::core::vector3df(perso->x, perso->y, perso->y),
	irr::core::vector3df(perso->a, perso->b, perso->c))))
    {
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      node->setMD2Animation(irr::scene::EMAT_STAND);
      node->setScale(irr::core::vector3df(0.5f));
      if (!(texture = client->driver->getTexture(texturePath.c_str())))
        std::cerr << "Could not load texture" << std::endl;
      node->setMaterialTexture(0, texture);
      client->players[perso->id] = new Player(node, perso->type, 20, 1);
    }
  return 0;
}

int		Client::deleteMesh(void *staticdata,
				   Order *orderdata)
{
  Client        *client;
  NewCharacter  *perso;

  client = (Client *)staticdata;
  perso = (NewCharacter *)orderdata->data;
  client->players[perso->id]->setIsDead(true);
  client->players[perso->id]->setPv(client->players[perso->id]->getPv());
  return 0;
}

int		Client::updatePv(void *staticdata,
				 Order *orderdata)
{
  Client	*client;
  UpdatePv	*update;

  client = (Client *)staticdata;
  update = (UpdatePv *)orderdata->data;
  if (update->id_enemy < NB_ENEMY &&
      client->enemies[update->id_enemy])
    {
      client->enemies[update->id_enemy]->setPv(update->damage);
      if (client->enemies[update->id_enemy] &&
	  !client->enemies[update->id_enemy]->getPv())
	client->players[update->id_player]->setScore(42);
    }
}

int			Client::pas2place(void *staticdata, Order *orderdata)
{
  Client		*client;
  UpdatePv		*update;

  std::cout << "Forced to leave the room" << std::endl;
  exit(EXIT_SUCCESS);
}
