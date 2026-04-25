#include "Animal.hpp"

Animal::Animal() : _type("human")
{
	std::cout << "default constructor called" << std::endl;
}
Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << _type << " constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << _type << " copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << this->_type << " copy assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << _type << " destructor called" << std::endl;
}


void	Animal::makeSound() const
{
	std::cout << "hello" << std::endl;
}

std::string const &Animal::getType() const
{
	return (_type);
}
