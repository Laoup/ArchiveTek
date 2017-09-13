//
// StringTLS.hpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Tue Feb 23 11:27:44 2016 AceyT
// Last update Tue Feb 23 11:55:23 2016 AceyT
//


#ifndef STRING_TLS_HPP_
# define STRING_TLS_HPP_

# include <string>
# include <sstream>

namespace tls
{
  
  template <typename T>
  std::string	NumToStr(T nbr)
  {
    std::stringstream converter;
  
    converter << nbr;
    return (converter.str());
  }
  
  template <typename T>
  T		StrToNum(const std::string &Text)
  {
    std::stringstream converter(Text);
    T result;
  
    return ((converter >> result) ? result : 0);
  }
  
  bool		EndsWith(const std::string &str, const std::string &end)
  {
    size_t	end_s;
    size_t	str_s;

    end_s = end.length();
    str_s = str.length();
    if ( end_s <= str_s )
      {
	return ( str.compare(str_s - end_s, end_s, end) == 0 );
      }
    else
      return false;
  }

}

#endif //STRING_TLS_HPP_
