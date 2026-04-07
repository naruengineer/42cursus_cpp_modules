#include <cctype>
#include <iostream>
#include <string>

void louder(std::string str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str(argv[i]);
			louder(str);
		}
	}
	std::cout << std::endl;
	return (0);
}

void	louder(std::string str)
{
	char s;
	for (size_t i = 0; i < str.length(); i++)
	{
		s = std::toupper(static_cast<unsigned char>(str[i]));
		std::cout << s;
	}
	return ;
}
