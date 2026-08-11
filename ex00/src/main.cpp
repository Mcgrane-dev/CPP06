#include <iostream>

bool minusCheck(const std::string& input, size_t &i);
bool plusCheck(const std::string &input, size_t &i);
bool validateChars(const std::string input, size_t len);
bool charPositions(const size_t &len, const std::string &input);
bool intValidation(const size_t &len, const std::string &input);
int floatCheck(const size_t &len, const std::string &input);
int doubleCheck(const size_t &len, const std::string &input);
bool charCheck(const size_t &len, const std::string &input);
bool isPseudoLiteral(const std::string& input);
void printPseudoLiteral(const std::string &input);

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "Only 2 arguments allowed!\n";
		return 1;
	}

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

bool charCheck(const size_t &len, const std::string &input)
{
	if(!validateChars(input, len))
		return false;

	if(!charPositions(len, input))
		return false;

	// Invalid single chars
	if(len == 1 && !isalpha(input[0]) && !isdigit(input[0]))
	{
		std::cout << "Invalid char '" << input[0] << "' found in input2\n";
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
			std::cerr << "Invalid input5!\n";
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
			std::cerr << "Invalid input1!\n";
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
			std::cerr << "Invalid input3\n";
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
		std::cerr << "No digit found\n";
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
			std::cerr << "Invalid char found in input1\n";
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
			std::cerr << "Invalid input00\n";
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
			std::cerr << "Invalid char found in input0\n";
			return false;	
		}
	}
	if(input[0] == '+' && input[1] == '-')
	{
		std::cerr << "Invalid input\n";
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
			std::cerr << "Invalid char detected '-'\n";
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
			std::cerr << "Invalid char detected '+'\n";
			return false;
		}
		i++;
	}
	return true;
}