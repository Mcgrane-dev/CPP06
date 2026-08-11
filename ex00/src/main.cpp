#include "../include/Parser.hpp"
#include "../include/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "Only 2 arguments allowed!\n";
		return 1;
	}

	ScalarConverter conv;
	std::string input = av[1];
	conv.convert(input);

	return 0;
}

void printPseudoLiteral(const std::string &input)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";

    if (input.back() == 'f')
    {
        std::cout << "float: " << input << "\n";
        std::cout << "double: " << input.substr(0, input.size() - 1) << "\n";
    }
    else
    {
        std::cout << "float: " << input << "f\n";
        std::cout << "double: " << input << "\n";
    }
}

bool isPseudoLiteral(const std::string& input)
{
    if (input == "nan")
        return true;
    if (input == "nanf")
        return true;
    if (input == "+inf")
        return true;
    if (input == "-inf")
        return true;
    if (input == "+inff")
        return true;
    if (input == "-inff")
        return true;
    return false;
}
