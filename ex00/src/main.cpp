#include "../include/Parser.hpp"
#include "../include/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "Only 2 arguments allowed!\n";
		return 1;
	}

	// ScalarConverter conv;
	std::string input = av[1];
	size_t len = input.length();
	
	// Pseudo literal check
	if(isPseudoLiteral(input))
	{
		printPseudoLiteral(input);
		return 0;
	}

	// Char check
	if(!charCheck(len, input))
		return 1;
	if(len == 1 && isalpha(input[0]))
	{
		std::cout << "Char\n";
		return 0;
	}

	// Int Validation
	if(!intValidation(len, input))
		return 1;

	// Int check
	for(size_t i = 0; i < len; i++)
	{
		if(!minusCheck(input, i))
			return 1;
		if(!plusCheck(input, i))
			return 1;
		if(!isdigit(input[i]))
			break;
		if(i == (len - 1))
		{
			std::cout << "Int\n";
			return 0;
		}	
	}

	// Float check
	if(floatCheck(len, input) == 1)
		return 1;
	else if(floatCheck(len, input) == 2) // Float found
	{
		std::cout << "Float\n";
		return 0;
	}	

	// Double check
	if(doubleCheck(len, input) == 1)
		return 1;
	else if(doubleCheck(len, input) == 2) // Double found
	{
		std::cout << "Double\n";
		return 0;
	}
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
