#include "Fixed.hpp"
#include <cmath>

// --- コンストラクタ・デストラクタ ---

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int n) : _value(n << _fractionalBits)
{
}

Fixed::Fixed(const float n) : _value(roundf(n * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed()
{
}

// --- 変換関数 ---

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// --- 比較演算子 ---

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

// --- 算術演算子 ---

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((long)this->_value * other._value >> _fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(((long)this->_value << _fractionalBits) / other._value);
	return (result);
}

// --- インクリメント・デクリメント ---

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}

// --- min/max ---

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

// --- 出力演算子 ---

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
