//
// CTrue.cpp for CTrue.cpp in /home/meuric_a/Projet_T2/nanotekspice/cpp_nanotekspice/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Tue Feb 23 14:02:26 2016 Alban Meurice
// Last update Tue Feb 23 18:42:17 2016 Alban Meurice
//

#include "comp/IComp.hpp"
#include "comp/component_spe.hpp"
#include <iostream>
#include <cstdlib>

nts::Tristate	False::Compute(size_t pin_num_this)
{
  if (pin_num_this <= this->pins.size())
    return (this->pins[pin_num_this - 1].stat);
}

void		False::SetLink(size_t pin_num_this, nts::IComponent &component,
				size_t pin_num_target)
{
}

void		False::Dump() const
{
  std::cout << "False" << std::endl;
  std::cout << this->pins[0].stat << std::endl;
}
