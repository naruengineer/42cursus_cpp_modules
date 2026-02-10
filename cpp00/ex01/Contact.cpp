#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	this->lastName = lastName;
}

void Contact::setNickName(const std::string &nickName)
{
	this->nickName = nickName;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

std::string Contact::getNickName() const
{
	return (this->nickName);
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}