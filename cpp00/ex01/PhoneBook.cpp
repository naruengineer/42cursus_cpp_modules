#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0){};

void PhoneBook::addContact(const Contact &contact)
{
	contacts[nextIndex] = contact;
	if (contactCount < 8)
		contactCount++;
	nextIndex = (nextIndex + 1) % 8;
}

int PhoneBook::getContactCount() const
{
	return (contactCount);
}

const Contact &PhoneBook::getContact(int index) const
{
	return (contacts[index]);
}

bool PhoneBook::isValidIndex(int index) const
{
	return (0 <= index && index < contactCount);
}
