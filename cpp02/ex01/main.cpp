#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	// --- 課題の必須テスト ---
	{
		Fixed		a;
		Fixed const	b( 10 );
		Fixed const	c( 42.42f );
		Fixed const	d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}

	std::cout << std::endl;

	// --- getRawBits / setRawBits ---
	{
		Fixed a;

		std::cout << "getRawBits: " << a.getRawBits() << std::endl;
		a.setRawBits(256);
		std::cout << "setRawBits(256): " << a.getRawBits() << std::endl;
		std::cout << "toFloat: " << a.toFloat() << std::endl;
		std::cout << "toInt: " << a.toInt() << std::endl;
	}

	return (0);
}
