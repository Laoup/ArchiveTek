//
// main.cpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Thu Feb 11 11:22:23 2016 AceyT
// Last update Tue Feb 23 18:49:30 2016 Alban Meurice
//

#include "comp/IComp.hpp"
#include "comp/class_pin.hpp"
#include "comp/component.hpp"
#include "comp/component_spe.hpp"
#include <iostream>
#include <list>

int	main(void)
{
  std::list<nts::IComponent *>	comp;
  std::list<nts::IComponent *>::iterator	it;

  comp.push_back(new False());
  comp.push_back(new True());
  std::cout << "Hello world !" << std::endl;
  std::cout << "This is a base start with 2 directory and a Makefile" << std::endl;
  std::cout << "It's dangerous to go alone ! Take it" << std::endl;

  it = comp.begin();
  if ((*it)->Compute(1) == nts::FALSE)
    std::cout << "It's False" << std::endl;
  else
    std::cout << "It's all but it's not False Motherfucker" << std::endl;
  
  it++;
  (*it)->Dump();
  return (0);
}
