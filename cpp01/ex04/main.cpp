#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

static std::string	replaceAll(std::string str, const std::string &s1,
		const std::string &s2)
{
	size_t	pos;

	pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string	filename(argv[1]);
	std::string	s1(argv[2]);
	std::string	s2(argv[3]);

	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return (1);
	}

	std::ifstream	ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error: could not open file: " << filename << std::endl;
		return (1);
	}

	std::ostringstream	oss;
	oss << ifs.rdbuf();
	ifs.close();

	std::string	content = replaceAll(oss.str(), s1, s2);

	std::ofstream	ofs((filename + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Error: could not create file: " << filename + ".replace" << std::endl;
		return (1);
	}

	ofs << content;
	ofs.close();

	return (0);
}
