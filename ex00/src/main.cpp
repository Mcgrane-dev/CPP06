#include "../include/Parser.hpp"
#include "../include/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "Need exactly 2 arguments!\n";
		return 1;
	}

	ScalarConverter conv;
	std::string input = av[1];

	if(conv.convert(input) == 1)
		return 1;
	return 0;
}

// CPP06 doesnt require you to implement escape-sequence parsing. "\n", "\t" etc
