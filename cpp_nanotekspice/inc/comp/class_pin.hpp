//
// class_pin.hpp for class_pin in /home/meuric_a/Projet_T2/nanotekspice/cpp_nanotekspice/inc/comp
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Tue Feb 23 11:41:51 2016 Alban Meurice
// Last update Tue Feb 23 19:10:05 2016 Alban Meurice
//

#ifndef CLASS_PIN_HPP_
# define CLASS_PIN_HPP_

#include "comp/IComp.hpp"
#include <iostream>
#include <vector>

class	Pin
{
public:
  Pin(){}
  Pin(nts::Tristate m_stat) : stat(m_stat)
  {}
  ~Pin() {}

  nts::Tristate	stat;
  std::vector<Pin *>		linked_Pin;
};

#endif /* CLASS_PIN_HPP_ */
