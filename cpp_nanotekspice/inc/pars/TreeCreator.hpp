//
// TreeCreator.hpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Thu Feb 25 02:47:58 2016 AceyT
// Last update Thu Feb 25 04:11:16 2016 AceyT
//

#ifndef PARS_TREE_CREATOR_HPP_
# define PARS_TREE_CREATOR_HPP_

# include "ParsDef.hpp"

class TreeCreator
{
public:
  static void		EvalStream(nts::Node *pRoot, const std::string &sStream);

private:
  static nts::Node *   	LinkSection(std::string::const_iterator &cit);
  static nts::Node *   	Link(std::string::const_iterator &cit);
  static nts::Node *   	ChipsetSection(std::string::const_iterator &cit);
  static nts::Node *   	Component(std::string::const_iterator &cit);
  static void		Comment(std::string::const_iterator &cit);
  static void		Separator(std::string::const_iterator &cit);
  static std::string	String(std::string::const_iterator &cit);
  static std::string    Num(std::string::const_iterator &cit);
  static void		EndLine(std::string::const_iterator &cit);
};


#endif //PARS_TREE_CREATOR_HPP_
