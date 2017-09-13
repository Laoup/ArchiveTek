//
// Function.hh for Funcion in /home/meuric_a/ZBEUL/Irrlicht_zbeul/CommandControler
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu May 26 12:31:36 2016 Alban Meurice
// Last update Sun Jun  5 17:22:43 2016 christophe lucas
//

#ifndef FUNCTION_HH_
# define FUNCTION_HH_

#include "CommandControler.hh"
#include <vector>

int	upPosMesh(void *, std::vector<struct CommandSet *> *, unsigned int);
int	downPosMesh(void *, std::vector<struct CommandSet *> *, unsigned int);
int	rightPosMesh(void *, std::vector<struct CommandSet *> *, unsigned int);
int	leftPosMesh(void *, std::vector<struct CommandSet *> *, unsigned int);

#endif /* FUNCTION_HH_ */
