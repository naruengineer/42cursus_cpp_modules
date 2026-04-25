#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("unknown", 100, 100, 30)
{
	std::cout << "FragTrap unknown constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _getName() << " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << _getName() << " copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _getName() << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_getHitPoints() == 0)
	{
		std::cout << "FragTrap " << _getName() << " is dead." << std::endl;
		return ;
	}
	if (_getEnergyPoints() == 0)
	{
		std::cout << "FragTrap " << _getName() << " has no energy." << std::endl;
		return ;
	}
	_consumeEnergy();
	std::cout << "FragTrap " << _getName() << " joyfully attacks " << target
		<< ", causing " << _getAttackDamage() << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _getName() << " requests a high five! Anyone up for it?" << std::endl;
}
