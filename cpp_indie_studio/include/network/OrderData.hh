//
// OrderData.hh for indie-studio in /home/grosso_a/Workspace/indie-studio/include/
//
// Made by Arthur Grosso
// Login   <grosso_a@epitech.eu>
//
// Started on  Wed May 25 00:50:00 2016 Arthur Grosso
// Last update Sun Jun  5 15:44:56 2016 Nicolas Giannelos
//

#ifndef ORDERDATA_HH_
# define ORDERDATA_HH_

# include <string>
# include <string.h>

# define	ROOM_NAME_LEN	128
# define	PATH_LEN	128

struct		NewRoom
{
  NewRoom(const std::string &name = "default_name", int size = 4)
    : size(size)
  {
    strncpy(this->name, name.c_str(), ROOM_NAME_LEN);
  };

  char		name[ROOM_NAME_LEN];
  int		size;
};

struct	NodePosition
{
  NodePosition(int id, float x, float y, float z, float a, float b, float c)
    : id(id), x(x), y(y), z(z), a(a), b(b), c(c) 
  {};
  int		id;
  float		x;
  float		y;
  float		z;
  float		a;
  float		b;
  float		c;
};

enum CharacterType
  {
    WARRIOR,
    BOWMAN,
    ELF,
    MAGE,
    ENEMY_1,
    ENEMY_2
  };

struct NewCharacter
{
  NewCharacter(int id, CharacterType type, int x, int y, int z, int a, int b, int c)
    : id(id), type(type), x(x), y(y), z(z), a(a), b(b), c(c) 
  {};
  int           id; // id is fd + node id
  CharacterType type;
  float         x;
  float         y;
  float         z;
  float         a;
  float         b;
  float         c;
};

struct	ClientStatus
{
  ClientStatus(const std::string &name, const int status)
    : status(status)
  {
    strncpy(this->name, name.c_str(), PATH_LEN);
  };

  char		name[PATH_LEN];
  int		status;
};

struct	UpdatePv
{
  UpdatePv(int id_enemy, int id_player, size_t damage)
    : id_enemy(id_enemy), id_player(id_player), damage(damage)
  {
  };

  int		id_enemy;
  int		id_player;
  size_t	damage;
};

#endif /* !ORDERDATA_HH_ */
