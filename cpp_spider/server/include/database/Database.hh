#pragma once

#include <list>
#include <map>
#include <boost/any.hpp>

enum class Db_type {INT, STRING, BOOL};

typedef std::map<int, boost::any>		Db_field;
typedef std::map<std::string, boost::any>	Db_data;
typedef std::map<std::string, Db_type>		Db_fieldlist;

class		Database
{
public:
  Database(const std::string & filename, const Db_fieldlist & fields);
  ~Database();

  void	addData(const Db_data & data);
  const std::map<int, Db_data> &	getDatabase();

  template<typename T>
  std::map<int, Db_data>	getData(const std::string & field, const T & data)
  {
    std::map<int, Db_data>	ret_datas;

    for (const auto & pair:_datasField[field])
      {
	if (boost::any_cast<T>(pair.second) == data)
	  ret_datas.insert(std::make_pair(pair.first, _datasId[pair.first]));
      }
    return (ret_datas);
  }

  Db_data	getData(int id);

  template<typename T>
  T	getData(int id, const std::string & field)
  {
    return (boost::any_cast<T>(_datasId[id][field]));
    }

  template<typename T>
  void			deleteData(const std::string & field, const T & data)
  {
    std::list<int>      ids;

    for (const auto & pair:_datasField[field])
      {
	if (boost::any_cast<T>(pair.second) == data)
	  ids.push_back(pair.first);
     }
    for (int id:ids)
      deleteData(id);
  }

  void	deleteData(int id);
  void	setData(int id, const std::string & field, const boost::any & data);
  void	setData(int id, const Db_data & data);

  template<typename T>
  void	setData(const std::string & field, T curData, T newData)
  {
    for (auto & pair:_datasField[field])
      {
	if (boost::any_cast<T>(pair.second) == curData)
	  {
	    pair.second = newData;
	    _datasId[pair.first][field] = newData;
	  }
      }
  }

  void	clear();
  void	save();
  void	save(const std::string & filename);
  void	load();
  void	load(const std::string & filename);

private:
  std::string				_filename;
  int					_id;
  Db_fieldlist				_fields;
  std::map<std::string, Db_field>	_datasField;
  std::map<int, Db_data>		_datasId;

  void	_loadData(char *line);
};
