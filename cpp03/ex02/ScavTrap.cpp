#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("unknown", 100, 50, 20)
{
	std::cout << "ScavTrap unknown constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _getName() << " copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap " << _getName() << " copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _getName() << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_getHitPoints() == 0)
	{
		std::cout << "ScavTrap " << _getName() << " is dead." << std::endl;
		return ;
	}
	if (_getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << _getName() << " has no energy." << std::endl;
		return ;
	}
	_consumeEnergy();
	std::cout << "ScavTrap " << _getName() << " ferociously attacks " << target
		<< ", causing " << _getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _getName() << " is now in Gate keeper mode." << std::endl;
}
