#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	randomChump("ZomA");
	Zombie *z = newZombie("zomB");
	z->announce();
	delete z;

	return (0);
}
