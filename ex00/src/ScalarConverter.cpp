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
		floatLiteral(input);
		return 0;
	}

	// Double check
	result = doubleCheck(len, input);
	if(result == 1)
		return 1;
	else if(result == 2) // Double found
	{
		doubleLiteral(input);
		return 0;
	}
	return 0;
}

ScalarConverter::ScalarConverter(){}
