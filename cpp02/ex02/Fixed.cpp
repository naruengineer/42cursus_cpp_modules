#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const int n) : _rawBits(n << _fractionalBits)
{
}

Fixed::Fixed(const float n) : _rawBits(roundf(n * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_rawBits = other._rawBits;
	return (*this);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >> _fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

// --- 比較演算子 ---

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_rawBits != other._rawBits);
}

// --- 算術演算子 ---
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((long)this->_rawBits * other._rawBits >> _fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(((long)this->_rawBits << _fractionalBits) / other._rawBits);
	return (result);
}

Fixed &Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_rawBits++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_rawBits--;
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
