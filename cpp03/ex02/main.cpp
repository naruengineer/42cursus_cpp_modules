#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "===== [0] OCF check =====" << std::endl;
	{
		ClapTrap a("A"); // parametric constructor
		ClapTrap b;      // default constructor
		ClapTrap c(a);   // copy constructor
		b = a;           // copy assignment operator
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
		ScavTrap sa("SA");   // parametric constructor (ClapTrap -> ScavTrap)
		ScavTrap sb;         // default constructor
		ScavTrap sc(sa);     // copy constructor
		sb = sa;             // copy assignment operator
	}                        // destructors: ScavTrap -> ClapTrap (reverse order)

	std::cout << "\n===== [7] ScavTrap behavior =====" << std::endl;
	{
		ScavTrap s("Serena");
		s.attack("enemy");     // ScavTrap-specific message + AD 20
		s.takeDamage(30);      // inherited (ClapTrap message)
		s.beRepaired(10);      // inherited (ClapTrap message)
		s.guardGate();         // ScavTrap-specific ability
	}

	std::cout << "\n===== [8] ScavTrap energy exhaustion (EP starts at 50) =====" << std::endl;
	{
		ScavTrap s("Tester");
		for (int i = 0; i < 50; ++i)
			s.attack("dummy");
		s.attack("dummy");     // 51st -> has no energy
	}

	std::cout << "\n===== [9] Polymorphism via base pointer =====" << std::endl;
	{
		ClapTrap *p = new ScavTrap("Poly");
		p->attack("target");   // virtual -> ScavTrap::attack is called
		delete p;              // virtual destructor -> ScavTrap -> ClapTrap order
	}

	std::cout << "\n===== [10] FragTrap OCF check =====" << std::endl;
	{
		FragTrap fa("FA");   // parametric constructor (ClapTrap -> FragTrap)
		FragTrap fb;         // default constructor
		FragTrap fc(fa);     // copy constructor
		fb = fa;             // copy assignment operator
	}                        // destructors: FragTrap -> ClapTrap (reverse order)

	std::cout << "\n===== [11] FragTrap behavior =====" << std::endl;
	{
		FragTrap f("Frank");
		f.attack("enemy");     // FragTrap-specific message + AD 30
		f.takeDamage(40);      // inherited (ClapTrap message)
		f.beRepaired(10);      // inherited (ClapTrap message)
		f.highFivesGuys();     // FragTrap-specific ability
	}

	std::cout << "\n===== [12] FragTrap polymorphism =====" << std::endl;
	{
		ClapTrap *p = new FragTrap("Poly2");
		p->attack("target");   // virtual -> FragTrap::attack is called
		delete p;              // virtual destructor -> FragTrap -> ClapTrap order
	}

	return (0);
}
