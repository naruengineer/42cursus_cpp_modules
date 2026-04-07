#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

void	add(PhoneBook &phoneBook);
void	search(const PhoneBook &phoneBook);

int	main(void)
{
	PhoneBook	phoneBook;

	std::string command;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			return (0);
		if (command == "ADD")
			add(phoneBook);
		else if (command == "SEARCH")
			search(phoneBook);
		else if (command == "EXIT")
			return (0);
	}
}

void	add(PhoneBook &phoneBook)
{
	Contact		contact;
	std::string	input;

	std::cout << "First name: ";
	if (!std::getline(std::cin, input) || input.empty())
	{
		std::cout << "Field cannot be empty." << std::endl;
		return ;
	}
	contact.setFirstName(input);
	std::cout << "Last name: ";
	if (!std::getline(std::cin, input) || input.empty())
	{
		std::cout << "Field cannot be empty." << std::endl;
		return ;
	}
	contact.setLastName(input);
	std::cout << "Nick name: ";
	if (!std::getline(std::cin, input) || input.empty())
	{
		std::cout << "Field cannot be empty." << std::endl;
		return ;
	}
	contact.setNickName(input);
	std::cout << "Phone number: ";
	if (!std::getline(std::cin, input) || input.empty())
	{
		std::cout << "Field cannot be empty." << std::endl;
		return ;
	}
	contact.setPhoneNumber(input);
	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, input) || input.empty())
	{
		std::cout << "Field cannot be empty." << std::endl;
		return ;
	}
	contact.setDarkestSecret(input);
	phoneBook.addContact(contact);
	std::cout << "Contact added." << std::endl;
}

std::string formatColumn(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	search(const PhoneBook &phonebook)
{
	int	count;
	int	index;

	std::string selectIndex;
	count = phonebook.getContactCount();
	if (count == 0)
	{
		std::cout << "No Contacts available" << std::endl;
		return ;
	}
	for (int i = 0; i < count; i++)
	{
		const Contact &c = phonebook.getContact(i);
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << formatColumn(c.getFirstName()) << "|";
		std::cout << std::setw(10) << formatColumn(c.getLastName()) << "|";
		std::cout << std::setw(10) << formatColumn(c.getNickName()) << std::endl;
	}
	std::cout << "select index: ";
	if (!std::getline(std::cin, selectIndex) || selectIndex.empty())
		return ;
	if (selectIndex.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	index = std::atoi(selectIndex.c_str());
	if (!phonebook.isValidIndex(index - 1))
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	const Contact &c = phonebook.getContact(index - 1);
	std::cout << "FirstName: " << c.getFirstName() << std::endl;
	std::cout << "LastName: " << c.getLastName() << std::endl;
	std::cout << "NickName: " << c.getNickName() << std::endl;
	std::cout << "PhoneNumber: " << c.getPhoneNumber() << std::endl;
	std::cout << "DarkestSecret: " << c.getDarkestSecret() << std::endl;
	return ;
}
