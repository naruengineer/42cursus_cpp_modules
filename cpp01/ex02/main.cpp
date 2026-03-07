#include <string>
#include <iostream>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";

	std::string *brainPTR = &brain;
	std::string &brainREF = brain;

	std::cout << "=== Test 1: memory addresses (should all be the same) ===" << std::endl;
	std::cout << "brain address   : " << &brain    << std::endl;
	std::cout << "brainPTR value  : " << brainPTR  << std::endl;
	std::cout << "brainREF address: " << &brainREF << std::endl;

	std::cout << "\n=== Test 2: values (should all be the same) ===" << std::endl;
	std::cout << "brain    : " << brain      << std::endl;
	std::cout << "*brainPTR: " << *brainPTR  << std::endl;
	std::cout << "brainREF : " << brainREF   << std::endl;

	std::cout << "\n=== Test 3: modify via pointer, check ref ===" << std::endl;
	*brainPTR = "MODIFIED BY PTR";
	std::cout << "brain   : " << brain    << std::endl;
	std::cout << "brainREF: " << brainREF << std::endl;

	std::cout << "\n=== Test 4: modify via ref, check pointer ===" << std::endl;
	brainREF = "MODIFIED BY REF";
	std::cout << "brain    : " << brain     << std::endl;
	std::cout << "*brainPTR: " << *brainPTR << std::endl;

	return (0);
}

