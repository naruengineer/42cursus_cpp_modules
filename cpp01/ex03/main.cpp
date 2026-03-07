#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	std::cout << "=== Test 1: HumanA (always armed, weapon by reference) ===" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack(); // weapon の変更がbobにも反映されるはず
	}

	std::cout << "\n=== Test 2: HumanB (weapon set after construction) ===" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack(); // weapon の変更がjimにも反映されるはず
	}

	std::cout << "\n=== Test 3: HumanB with no weapon ===" << std::endl;
	{
		HumanB noarm("NoArm");
		noarm.attack(); // 武器なしの状態
	}

	std::cout << "\n=== Test 4: shared weapon between two HumanB ===" << std::endl;
	{
		Weapon sword = Weapon("sword");
		HumanB alice("Alice");
		HumanB carol("Carol");
		alice.setWeapon(sword);
		carol.setWeapon(sword);
		alice.attack();
		carol.attack();
		sword.setType("broken sword");
		alice.attack(); // 両方に変更が反映されるはず
		carol.attack();
	}

	return (0);
}
