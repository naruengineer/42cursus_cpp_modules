#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	std::cout << "=== Test 1: stack zombie (randomChump) ===" << std::endl;
	randomChump("ZomA");
	// ZomA は関数を抜けた時点で自動的にデストラクタが呼ばれる

	std::cout << "\n=== Test 2: heap zombie (newZombie) ===" << std::endl;
	Zombie *z = newZombie("ZomB");
	z->announce();
	delete z;
	// ZomB は delete した時点でデストラクタが呼ばれる

	std::cout << "\n=== Test 3: multiple heap zombies ===" << std::endl;
	Zombie *z1 = newZombie("ZomC");
	Zombie *z2 = newZombie("ZomD");
	z1->announce();
	z2->announce();
	delete z1;
	delete z2;

	return (0);
}
