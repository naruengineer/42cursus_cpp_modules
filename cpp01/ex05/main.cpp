#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	harl;

	std::cout << "=== Test 1: 各レベル単体 ===" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("ERROR");

	std::cout << "\n=== Test 2: 不正なレベル ===" << std::endl;
	harl.complain("UNKNOWN");
	harl.complain("");
	harl.complain("debug"); // 小文字は不一致

	return (0);
}
