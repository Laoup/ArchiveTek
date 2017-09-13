#pragma once

namespace	Database
{
  template	<typename T>
  class		Data
  {
  public:
    Data(int id, T data) :
      _id(id), _data(data)
    {

    }
    ~Data()
    {

    }

    int	getID()
    {
      return _id;
    }

    T	getData()
    {
      return _data;
    }

  private:
    int	_id;
    T	_data;

  };
}
