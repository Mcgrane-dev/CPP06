#include "../include/Parser.hpp"
#include "../include/ScalarConverter.hpp"


bool charCheck(const size_t &len, const std::string &input)
{
	if(!validateChars(input, len))
		return false;

	if(!charPositions(len, input))
		return false;

	// Invalid single chars
	if(len == 1 && !isalpha(input[0]) && !isdigit(input[0]))
	{
		std::cout << "Invalid char '" << input[0] << "' found in input\n";
		return false;
	}
	return true;
}

int doubleCheck(const size_t &len, const std::string &input)
{
	bool decFlag = false;

	for(size_t i = 0; i < len; i++)
	{
		// std::cout << "Checking Double\n";
		if(!minusCheck(input, i))
			return 1;
		if(!plusCheck(input, i))
			return 1;
		if(isalpha(input[i]))
		{
			std::cerr << "Invalid input!\n";
			return 1;
		}
		if(input[i] == '.')
			decFlag = true;
		if(i == (len - 1) && (decFlag == true))
		{
			return 2;
		}
	}
	return 0;
}

int floatCheck(const size_t &len, const std::string &input)
{
	bool decFlag = false;

	for(size_t i = 0; i < len; i++)
	{
		if(!minusCheck(input, i))
			return 1;
		if(!plusCheck(input, i))
			return 1;
		if(isalpha(input[i]) && i != (len - 1))
		{
			std::cerr << "Invalid input!\n";
			return 1;
		}
		if(input[i] == '.')
			decFlag = true;
		if(i == (len - 1) && input.back() == 'f' && (decFlag == true))
		{
			return 2;
		}
		if(i == (len - 1) && input.back() == 'f' && (decFlag == false))
		{
			std::cerr << "Invalid input\n";
			return 1;
		}
	}
	return 0;
}

bool intValidation(const size_t &len, const std::string &input)
{
	bool foundDigit = false;

	for(size_t i = 0; i < len; i++)
	{
		if(isdigit(input[i]))
			foundDigit = true;
	}
	if(foundDigit == false)
	{
		std::cerr << "Invalid input!\n";
		return false;
	}
	return true;
}

bool charPositions(const size_t &len, const std::string &input)
{
	int minus = 0;
	int f = 0;
	int dec = 0;
	int plus = 0;

	for(size_t i = 0; i < len; i++)
	{
		if(!isalpha(input[i]) && !isdigit(input[i]) && input[i] != '.' 
		&& input.back() != 'f' && input[0] != '-' && input[0] != '+')
		{
			std::cerr << "Invalid input!\n";
			return false;
		}
		if(input[i] == 'f')
			f++;
		if(input[i] == '-')
			minus++;
		if(input[i] == '.')
			dec++;
		if(input[i] == '+')
			plus++;
		if(f > 1 || minus > 1 || dec > 1 || plus > 1)
		{
			std::cerr << "Invalid input!\n";
			return false;
		}
	}
	return true;
}

bool validateChars(const std::string input, size_t len)
{
	for(size_t i = 0; i < len; i++)
	{
		if(!isalpha(input[i]) && !isdigit(input[i]) && input[i] != '.' 
		&& input[i] != 'f' && input[i] != '-' && input[i] != '+')
		{
			std::cerr << "Invalid input!\n";
			return false;	
		}
	}
	if(input[0] == '+' && input[1] == '-')
	{
		std::cerr << "Invalid input!\n";
		return false;
	}
	return true;
}

bool minusCheck(const std::string &input, size_t &i)
{
	if(input[i] == '-')
	{
		if(i != 0)
		{
			std::cerr << "Invalid input!\n";
			return false;
		}
		i++;
	}
	return true;
}

bool plusCheck(const std::string &input, size_t &i)
{
	if(input[i] == '+')
	{
		if(i != 0)
		{
			std::cerr << "Invalid input!\n";
			return false;
		}
		i++;
	}
	return true;
}