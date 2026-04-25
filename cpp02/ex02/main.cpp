#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	// --- 課題の必須テスト ---
	{
		Fixed		a;
		Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << std::endl;

	// --- 算術演算子 ---
	{
		Fixed a( 10 );
		Fixed b( 3 );

		std::cout << "--- Arithmetic ---" << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "a + b = " << a + b << std::endl;
		std::cout << "a - b = " << a - b << std::endl;
		std::cout << "a * b = " << a * b << std::endl;
		std::cout << "a / b = " << a / b << std::endl;
	}

	std::cout << std::endl;

	// --- 比較演算子 ---
	{
		Fixed a( 5 );
		Fixed b( 10 );
		Fixed c( 5 );

		std::cout << "--- Comparison ---" << std::endl;
		std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << "a > b  = " << (a > b) << std::endl;
		std::cout << "a < b  = " << (a < b) << std::endl;
		std::cout << "a >= c = " << (a >= c) << std::endl;
		std::cout << "a <= c = " << (a <= c) << std::endl;
		std::cout << "a == c = " << (a == c) << std::endl;
		std::cout << "a != b = " << (a != b) << std::endl;
	}

	std::cout << std::endl;

	// --- デクリメント ---
	{
		Fixed a( 1 );

		std::cout << "--- Decrement ---" << std::endl;
		std::cout << "a   = " << a << std::endl;
		std::cout << "--a = " << --a << std::endl;
		std::cout << "a   = " << a << std::endl;
		std::cout << "a-- = " << a-- << std::endl;
		std::cout << "a   = " << a << std::endl;
	}

	std::cout << std::endl;

	// --- min / max ---
	{
		Fixed a( 3 );
		Fixed b( 7 );
		const Fixed c( 2 );
		const Fixed d( 9 );

		std::cout << "--- Min / Max ---" << std::endl;
		std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
		std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;
	}

	return (0);
}
