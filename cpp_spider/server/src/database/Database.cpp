#include <boost/lexical_cast.hpp>
#include <fstream>
#include <string.h>
#include "Database.hh"

Database::Database(const std::string & filename, const Db_fieldlist & fields) :
  _filename(filename), _id(1), _fields(fields), _datasField(), _datasId()
{
  for (const auto & field:fields)
    {
      _datasField.insert(std::make_pair(field.first, Db_field()));
    }
}

Database::~Database()
{

}

void	Database::addData(const Db_data & data)
{
  for (const auto & field:data)
    {
      _datasField[field.first].insert(std::make_pair(_id, field.second));
    }
  _datasId.insert(std::make_pair(_id, data));
  _id += 1;
}

const std::map<int, Db_data> &	Database::getDatabase()
{
  return (_datasId);
}

Db_data	Database::getData(int id)
{
  return (_datasId[id]);
}

void	Database::deleteData(int id)
{
  for (auto & field:_datasField)
    field.second.erase(id);
  _datasId.erase(id);
}

void	Database::setData(int id, const std::string & field, const boost::any & data)
{
  _datasField[field][id] = data;
  _datasId[id][field] = data;
}

void	Database::setData(int id, const Db_data & data)
{
  for (auto & field:data)
    _datasField[field.first][id] = field.second;
  _datasId[id] = data;
}

void	Database::clear()
{
  _id = 1;
  _datasField.clear();
  _datasId.clear();
}

void	Database::save()
{
  std::ofstream	file(_filename, std::ofstream::trunc);

  if (file.good())
    {
      for (const auto & data:_datasId)
	{
	  file << data.first;
	  for (const auto & field:data.second)
	    {
	      file << ';' << field.first << ';';
	      switch(_fields[field.first])
		{
		case Db_type::INT: file << boost::any_cast<int>(field.second); break;
		case Db_type::STRING: file << boost::any_cast<std::string>(field.second); break;
		case Db_type::BOOL: file << boost::any_cast<bool>(field.second); break;
		}
	    }
	  file << std::endl;
	}
      file.close();
    }
}

void	Database::save(const std::string & filename)
{
  _filename = filename;
  this->save();
}

void		Database::_loadData(char *line)
{
  char		*token;
  char		*value;
  int		id;
  Db_data	data;

  token = strtok(line, ";");
  id = atoi(token);
  token = strtok(NULL, ";");
  while (token)
    {
      value = strtok(NULL, ";");
      switch (_fields[token])
	{
	case Db_type::INT: data.insert({token, atoi(value)}); break;
	case Db_type::STRING: data.insert({token, std::string(value)}); break;
	case Db_type::BOOL: data.insert({token, boost::lexical_cast<bool>(value)}); break;
	}
      token = strtok(NULL, ";");
    }
  _datasId.insert({id, data});
  for (const auto & field:data)
    {
      _datasField[field.first].insert({id, field.second});
    }
  free(line);
}

void	Database::load()
{
  std::ifstream	file(_filename);
  std::string	line;

  if (file.good())
    {
      this->clear();
      _id = 1;
      for (const auto & field:_fields)
	{
	  _datasField.insert({field.first, Db_field()});
	}
      while (getline(file, line))
	{
	  _loadData(strdup(line.c_str()));
	}
      _id += 1;
      file.close();
    }
}

void	Database::load(const std::string & filename)
{
  _filename = filename;
  this->load();
}
