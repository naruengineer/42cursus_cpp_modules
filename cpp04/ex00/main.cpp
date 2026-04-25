#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "=== Subject test (Animal/Dog/Cat) ===" << std::endl;
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << std::endl;

	{
		std::cout << "=== WrongAnimal test ===" << std::endl;
		const WrongAnimal *wmeta = new WrongAnimal();
		const WrongAnimal *wc = new WrongCat();

		std::cout << wc->getType() << " " << std::endl;
		wc->makeSound();
		wmeta->makeSound();

		delete wmeta;
		delete wc;
	}

	std::cout << std::endl;

	{
		std::cout << "=== Direct (non-pointer) test ===" << std::endl;
		Dog d;
		Cat c;
		d.makeSound();
		c.makeSound();
	}

	std::cout << std::endl;

	{
		std::cout << "=== Copy constructor / assignment test ===" << std::endl;
		Dog a;
		Dog b(a);
		Dog c;
		c = a;
		std::cout << "a.getType(): " << a.getType() << std::endl;
		std::cout << "b.getType(): " << b.getType() << std::endl;
		std::cout << "c.getType(): " << c.getType() << std::endl;
	}

	return (0);
}
