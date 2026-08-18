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

void doubleLiteral(const std::string &input)
{
	try
	{
		float f = std::stof(input);
    	double d = std::stod(input);
		
		if (d >= std::numeric_limits<char>::min() &&
			d <= std::numeric_limits<char>::max() &&
			d == static_cast<int>(d) && input[0] != '-')
		{
			char c = static_cast<char>(d);

			if (std::isprint(static_cast<unsigned char>(c)))
				std::cout << "char: '" << c << "'\n";
			else
				std::cout << "char: Non displayable\n";
		}
		else
		{
			std::cout << "char: impossible\n";
		}
		if (d >= std::numeric_limits<int>::min() &&
			d <= std::numeric_limits<int>::max())
		{
			std::cout << "int: " << static_cast<int>(d) << "\n";
		}
		else
		{
			std::cout << "int: impossible\n";
		}

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

void floatLiteral(const std::string &input)
{
	try
	{
    	float f = std::stof(input);
		
		if (f >= std::numeric_limits<char>::min() &&
			f <= std::numeric_limits<char>::max() &&
			f == static_cast<int>(f) && input[0] != '-')
		{
			char c = static_cast<char>(f);

			if (std::isprint(static_cast<unsigned char>(c)))
				std::cout << "char: '" << c << "'\n";
			else
				std::cout << "char: Non displayable\n";
		}
		else
		{
			std::cout << "char: impossible\n";
		}
		if (f >= std::numeric_limits<int>::min() &&
			f <= std::numeric_limits<int>::max())
		{
			std::cout << "int: " << static_cast<int>(f) << "\n";
		}
		else
		{
			std::cout << "int: impossible\n";
		}

		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f\n";
		std::cout << "double: " << static_cast<double>(f) << "\n";
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

void intLiteral(const std::string &input)
{
	try
	{
    	int x = std::stoi(input);

		if (x < std::numeric_limits<char>::min() ||
			x > std::numeric_limits<char>::max() || input[0] == '-')
		{
			std::cout << "char: impossible\n";
		}
		else
		{
			char c = static_cast<char>(x);

			if (std::isprint(static_cast<unsigned char>(c)))
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

void charLiteral(const std::string &input)
{
	char c = input[0];
	int x = static_cast<int>(c);

	if (std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << x << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(x) << "f\n";
	std::cout << "double: " << static_cast<double>(x) << "\n";
}
