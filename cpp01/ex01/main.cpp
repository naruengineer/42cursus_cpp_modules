#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*horde;
	int		N;

	std::cout << "=== Test 1: normal horde (N=5) ===" << std::endl;
	N = 5;
	horde = zombieHorde(N, "Horde");
	if (horde)
	{
		for (int i = 0; i < N; i++)
			horde[i].announce();
		delete[] horde;
	}

	std::cout << "\n=== Test 2: single zombie (N=1) ===" << std::endl;
	horde = zombieHorde(1, "Lone");
	if (horde)
	{
		horde[0].announce();
		delete[] horde;
	}

	std::cout << "\n=== Test 3: invalid N (N=0) ===" << std::endl;
	horde = zombieHorde(0, "Ghost");
	if (!horde)
		std::cout << "NULL returned as expected" << std::endl;

	std::cout << "\n=== Test 4: invalid N (N=-1) ===" << std::endl;
	horde = zombieHorde(-1, "Ghost");
	if (!horde)
		std::cout << "NULL returned as expected" << std::endl;

	return (0);
}
