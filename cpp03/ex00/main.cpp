#include "ClapTrap.hpp"
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
		ClapTrap a("A");
		ClapTrap b("B");
	std::cout << "\n===== [2] Basic attack / takeDamage / beRepaired =====" << std::endl;
	{
		a.attack("B");
		b.takeDamage(0);
		b.takeDamage(5);
		b.beRepaired(0);
		b.beRepaired(5);
	}
	std::cout << "\n===== [3] Energy exhaustion (EP starts at 10) =====" << std::endl;
	{
		for (int i = 0; i < 10; ++i)
		a.attack("B");
		a.attack("B");
	}
	std::cout << "\n===== [4] HP clamp at 0 (takeDamage over HP) =====" << std::endl;
	{
		b.takeDamage(1000);
	 	b.attack("A");
		b.beRepaired(10);
	}
	std::cout << "\n===== [5] Destruction (reverse order) =====" << std::endl;
return (0);
}
