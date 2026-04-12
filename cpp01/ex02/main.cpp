#include <string>
#include <iostream>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "=== memory addresses ===" << std::endl;
	std::cout << "brain address     : " << &brain     << std::endl;
	std::cout << "stringPTR value   : " << stringPTR  << std::endl;
	std::cout << "stringREF address : " << &stringREF << std::endl;

	std::cout << "=== values ===" << std::endl;
	std::cout << "brain      : " << brain      << std::endl;
	std::cout << "*stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF  : " << stringREF  << std::endl;

	return (0);
}
