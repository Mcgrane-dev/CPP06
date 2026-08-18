#include "../include/Parser.hpp"
#include "../include/ScalarConverter.hpp"

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
