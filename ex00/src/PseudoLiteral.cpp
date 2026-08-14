#include "../include/Parser.hpp"
#include "../include/ScalarConverter.hpp"

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

void printPseudoLiteral(const std::string &input)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";

	if (input == "-inff" || input == "+inff" || input == "nanf")
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
