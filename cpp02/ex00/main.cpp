#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	// --- 課題の必須テスト ---
	{
		Fixed a;
		Fixed b(a);
		Fixed c;

		c = b;

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}

	std::cout << std::endl;
	// --- setRawBits ---
	{
		Fixed a;

		std::cout << "before: " << a.getRawBits() << std::endl;
		a.setRawBits(42);
		std::cout << "after:  " << a.getRawBits() << std::endl;
	}

	return (0);
}
