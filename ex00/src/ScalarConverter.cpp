#include "../include/Parser.hpp"
#include "../include/ScalarConverter.hpp"

int ScalarConverter::convert(std::string input)
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
		// conv.convert(input);
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
			// conv.convert(input);
			return 0;
		}	
	}

	// Float check
	if(floatCheck(len, input) == 1)
		return 1;
	else if(floatCheck(len, input) == 2) // Float found
	{
		std::cout << "Float\n";
		// conv.convert(input);
		return 0;
	}	

	// Double check
	if(doubleCheck(len, input) == 1)
		return 1;
	else if(doubleCheck(len, input) == 2) // Double found
	{
		std::cout << "Double\n";
		// conv.convert(input);
		return 0;
	}
	return 0;
}