//
// component_spe.hpp for component_spe.hpp in /home/meuric_a/Projet_T2/nanotekspice/cpp_nanotekspice/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Tue Feb 23 10:56:50 2016 Alban Meurice
// Last update Tue Feb 23 18:28:11 2016 Alban Meurice
//

#ifndef COMPONENT_SPE_HPP_
# define COMPONENT_SPE_HPP_

#include "comp/IComp.hpp"
#include "comp/class_pin.hpp"
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

class	Input : public nts::IComponent
{
public:
  Input() {}
  virtual ~Input() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	Clock : public nts::IComponent
{
public:
  Clock() {}
  virtual	~Clock() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	True : public nts::IComponent
{
public:
  True()
  {
    Pin	my_pin(nts::TRUE);

    this->pins.push_back(my_pin); 
  }
  virtual	~True() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	False : public nts::IComponent
{
public:
  False()
  {
    Pin	my_pin(nts::FALSE);

    this->pins.push_back(my_pin); 
  }
  virtual	~False() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

class	Output : public nts::IComponent
{
public:
  Output() {}
  ~Output() {}

  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
  virtual void		Dump() const;

  std::vector<Pin>	pins;
};

#endif /* COMPONENT_SPE_HPP_ */