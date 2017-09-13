//
// component.hpp for component in /home/meuric_a/Projet_T2/nanotekspice/cpp_nanotekspice/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Tue Feb 23 11:16:26 2016 Alban Meurice
// Last update Tue Feb 23 17:32:20 2016 Alban Meurice
//

#ifndef COMPONENT_HPP_
# define COMPONENT_HPP_

#include "comp/IComp.hpp"
#include "comp/class_pin.hpp"
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

class	C4001 : nts::IComponent
{
  //Four NOR gates
public:
  C4001() {}
  ~C4001() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4008 : nts::IComponent
{
  //4 bits adder
public:
  C4008() {}
  ~C4008() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4011 : nts::IComponent
{
  //Four NAND gates
public:
  C4011() {}
  ~C4011() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4013 : nts::IComponent
{
  //Dual Flip Floap
public:
  C4013() {}
  ~C4013() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4017 : nts::IComponent
{
  //10 bits Johnson Decade
public:
  C4017() {}
  ~C4017() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4030 : nts::IComponent
{
  //four XOR gates
public:
  C4030() {}
  ~C4030() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4040 : nts::IComponent
{
  //12 bits counter
public:
  C4040() {}
  ~C4040() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4069 : nts::IComponent
{
  //Six Inverter gates
public:
  C4069() {}
  ~C4069() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4071 : nts::IComponent
{
  //Four OR gates
public:
  C4071() {}
  ~C4071() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4081 : nts::IComponent
{
  //Four AND gates
public:
  C4081() {}
  ~C4081() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4094 : nts::IComponent
{
  //89 bits shift register
public:
  C4094() {}
  ~C4094() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4514 : nts::IComponent
{
  //4 bits decoder
public:
  C4514() {}
  ~C4514() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	C4801 : nts::IComponent
{
  //Random acces memory?
public:
  C4801() {}
  ~C4801() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

#endif /* COMPONENT_HPP */
