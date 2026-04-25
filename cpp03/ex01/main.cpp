#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	
	std::cout << "===== [0] OCF check =====" << std::endl;
	{
		ClapTrap a("A");
		ClapTrap b;
		ClapTrap c(a);
		b = a;
	}
	std::cout << "\n===== [1] Construction =====" << std::endl;
	{
		ClapTrap a("A");
		ClapTrap b("B");
		std::cout << "\n===== [2] Basic attack / takeDamage / beRepaired =====" << std::endl;
		a.attack("B");
		b.takeDamage(0);
		b.takeDamage(5);
		b.beRepaired(0);
		b.beRepaired(5);
		std::cout << "\n===== [3] Energy exhaustion (EP starts at 10) =====" << std::endl;
		for (int i = 0; i < 10; ++i)
		a.attack("B");
		a.attack("B");
		std::cout << "\n===== [4] HP clamp at 0 (takeDamage over HP) =====" << std::endl;
		b.takeDamage(1000);
		b.attack("A");
		b.beRepaired(10);
		std::cout << "\n===== [5] Destruction (reverse order) =====" << std::endl;
	}
	std::cout << "\n===== [6] ScavTrap OCF check =====" << std::endl;
	{
		ScavTrap sa("SA"); // parametric constructor (ClapTrap -> ScavTrap)
		ScavTrap sb;       // default constructor
		ScavTrap sc(sa);   // copy constructor
		sb = sa;           // copy assignment operator
	}                      // destructors: ScavTrap -> ClapTrap (reverse order)
	std::cout << "\n===== [7] ScavTrap behavior =====" << std::endl;
	{
		ScavTrap s("Serena");
		s.attack("enemy"); // ScavTrap-specific message + AD 20
		s.takeDamage(30);  // inherited (ClapTrap message)
		s.beRepaired(10);  // inherited (ClapTrap message)
		s.guardGate();     // ScavTrap-specific ability
	}
	std::cout << "\n===== [8] ScavTrap energy exhaustion (EP starts at 50) =====" << std::endl;
	{
		ScavTrap s("Tester");
		for (int i = 0; i < 50; ++i)
		s.attack("dummy");
		s.attack("dummy"); // 51st -> has no energy
	}
	std::cout << "\n===== [9] Polymorphism via base pointer =====" << std::endl;
	{
		ClapTrap	*p;
		p = new ScavTrap("Poly");
		p->attack("target"); // virtual -> ScavTrap::attack is called
		delete p;            // virtual destructor -> ScavTrap -> ClapTrap order
	}
	return (0);
}
