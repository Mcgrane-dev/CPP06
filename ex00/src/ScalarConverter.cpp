#include "../include/Parser.hpp"
#include "../include/ScalarConverter.hpp"

int ScalarConverter::convert(const std::string &input)
{
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
		charLiteral(input);
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
			intLiteral(input);
			return 0;
		}	
	}

	// Float check
	int result = floatCheck(len, input);
	if(result == 1)
		return 1;
	else if(result == 2) // Float found
	{
		std::cout << "Float\n";
		floatLiteral(input);
		return 0;
	}

	// Double check
	result = doubleCheck(len, input);
	if(result == 1)
		return 1;
	else if(result == 2) // Double found
	{
		std::cout << "Double\n";
		doubleLiteral(input);
		return 0;
	}
	return 0;
}
