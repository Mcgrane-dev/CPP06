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
		// conv.convert(input);
		return 0;
	}	

	// Double check
	result = doubleCheck(len, input);
	if(result == 1)
		return 1;
	else if(result == 2) // Double found
	{
		std::cout << "Double\n";
		// conv.convert(input);
		return 0;
	}
	return 0;
}

void intLiteral(std::string &input)
{
	try
	{
    	int x = std::stoi(input);

		if (x < std::numeric_limits<char>::min() ||
			x > std::numeric_limits<char>::max())
		{
			std::cout << "char: impossible\n";
		}
		else
		{
			char c = static_cast<char>(x);

			if (std::isprint(c))
				std::cout << "char: '" << c << "'\n";
			else
				std::cout << "char: Non displayable\n";
		}
		std::cout << "int: " << x << "\n";
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(x) << "f\n";
    	std::cout << "double: " << static_cast<double>(x) << "\n";
	}
	catch (const std::out_of_range&)
	{
		try
		{
			float f = std::stof(input);
			double d = std::stod(input);
	
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f\n";
			std::cout << "double: " << d << "\n";
		}
		catch(const std::exception& e)
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			try
			{
				double d = std::stod(input);
				std::cout << std::fixed << std::setprecision(1);
				std::cout << "double: " << d << "\n";
			}
			catch(const std::exception& e)
			{
				std::cout << "double: impossible\n";
			}
		}
	}
}
