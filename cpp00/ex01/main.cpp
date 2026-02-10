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

bool	promptAndSet(const std::string &prompt, Contact &contact,
		void (Contact::*setter)(const std::string &))
{
	std::string input;
	std::cout << prompt;
	if (!std::getline(std::cin, input) || input.empty())
		return (false);
	(contact.*setter)(input);
	return (true);
}

void	add(PhoneBook &phoneBook)
{
	Contact	contact;

	std::string input;
	if (!promptAndSet("First name: ", contact, &Contact::setFirstName))
		return ;
	if (!promptAndSet("Last name: ", contact, &Contact::setLastName))
		return ;
	if (!promptAndSet("Nick name: ", contact, &Contact::setNickName))
		return ;
	if (!promptAndSet("Phone number: ", contact, &Contact::setPhoneNumber))
		return ;
	if (!promptAndSet("Darkest secret: ", contact, &Contact::setDarkestSecret))
		return ;
	phoneBook.addContact(contact);
	std::cout << "Contact added.\n";
	return ;
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
	// 1.登録件数check
	count = phonebook.getContactCount();
	if (count == 0)
	{
		std::cout << "No Contacts available\n";
		return ;
	}
	// 2.一覧表示
	for (int i = 0; i < count; i++)
	{
		const Contact &c = phonebook.getContact(i);
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << formatColumn(c.getFirstName()) << "|";
		std::cout << std::setw(10) << formatColumn(c.getLastName()) << "|";
		std::cout << std::setw(10) << formatColumn(c.getNickName()) << "\n";
	}
	// 3.index入力受付
	std::cout << "select index: ";
	if (!std::getline(std::cin, selectIndex) || selectIndex.empty())
		return ;
	if (selectIndex.find_first_not_of("0123456789") != std::string::npos)
		return ;
	// 4.詳細表示
	index = std::atoi(selectIndex.c_str());
	if (index < 1 || index > count)
		return ;
	const Contact &c = phonebook.getContact(index - 1);
	std::cout << "FirstName: " << c.getFirstName() << "\n";
	std::cout << "LastName: " << c.getLastName() << "\n";
	std::cout << "NickName: " << c.getNickName() << "\n";
	std::cout << "PhoneNumber: " << c.getPhoneNumber() << "\n";
	std::cout << "DarkestSecret: " << c.getDarkestSecret() << "\n";
	return ;
}
