/*
** main.cpp for cpp_spider in /home/tarkick/repos/cpp_spider/src/server
**
** Made by tarkick
** Login   <tarkick@epitech.net>
**
** Started on  Sat Nov 05 19:28:48 2016 tarkick
// Last update Sat Nov 12 19:41:13 2016 Pierrick Garcia
*/

#include <exception>
#include <cstdlib>
#include "Server.hh"
#include "Database.hh"

void	testDatabase()
{
  Db_fieldlist	fields({{"username", Db_type::STRING}, {"public_key", Db_type::INT}, {"test", Db_type::BOOL}});
  Database	users("users.txt", fields);
  Db_data	user1 =
  {
    {"username", std::string("11:11:11:11:11:11")},
    {"public_key", int(3457654)},
    {"test", true}
  };
  Db_data	user2 =
  {
    {"username", std::string("25:22:AE:5E:2F:2F")},
    {"public_key", int(99999994)},
    {"test", false}
  };
  Db_data	user3 =
  {
    {"username", std::string("12:34:56:78:2F:2F")},
    {"public_key", int(99999994)},
    {"test", false}
  };
  Db_data	user4 =
  {
    {"username", std::string("AA:BB:CC:78:2F:2F")},
    {"public_key", int(987654321)},
    {"test", true}
  };
  users.addData(user1);
  users.addData(user2);
  users.addData(user3);
  users.addData(user4);

  std::map<int, Db_data> ret_users;
  ret_users = users.getData<int>("public_key", 99999994);
  for (auto user:ret_users)
    {
      std::cout << boost::any_cast<std::string>(user.second["username"]) << std::endl;;
    }
  std::cout << endl;
  std::cout << boost::any_cast<int>(users.getData(2)["public_key"]) << std::endl;
  std::cout << users.getData<std::string>(1, "username") << std::endl;
  std::cout << endl;

  users.deleteData<std::string>("username", "25:22:AE:5E:2F:2F");
  users.deleteData(4);
  users.setData(1, "public_key", (int)1234);
  users.setData(3, user4);
  users.setData<int>("public_key", 1234, (int)5678);
  users.addData(user2);

  ret_users = users.getDatabase();
  for (auto user:ret_users)
    {
      std::cout << boost::any_cast<std::string>(user.second["username"]) << "   /   "
		<< boost::any_cast<int>(user.second["public_key"]) << "   /   "
		<< boost::any_cast<bool>(user.second["test"]) << std::endl;
    }
  users.save();

  users.clear();
  ret_users = users.getDatabase();
  for (auto user:ret_users)
    {
      std::cout << boost::any_cast<std::string>(user.second["username"]) << "   /   "
		<< boost::any_cast<int>(user.second["public_key"]) << "   /   "
		<< boost::any_cast<bool>(user.second["test"]) << std::endl;
    }

  std::cout << std::endl;
  users.load();
  ret_users = users.getDatabase();
  for (auto user:ret_users)
    {
      std::cout << boost::any_cast<std::string>(user.second["username"]) << "   /   "
		<< boost::any_cast<int>(user.second["public_key"]) << "   /   "
		<< boost::any_cast<bool>(user.second["test"]) << std::endl;
    }
}

int		main(int ac, char **av)
{
  testDatabase();

  try
    {
      if (ac >= 2)
	Server	server(atoi(av[1]));
      else
	std::cerr << "Usage: ./spider_server [port]" << std::endl;
    }
  catch (std::exception &error)
    {
      std::cerr << "Spider_server: " << error.what() << std::endl;
    }
  return	0;
}
