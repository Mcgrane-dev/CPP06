#include <iostream>

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "Too many arguments!\n";
		return 1;
	}

	std::string input = av[1];
	size_t len = input.length();
	bool found = false;
	int minusFlag = 0;
	if(input[0] == '.')
	{
		std::cerr << "Invalid input '.'\n";
		return 1;
	}

	for(size_t i = 0; i < len; i++)
	{
		if(!isalpha(input[i]) && !isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[0] != '-')
		{
			std::cerr << "Invalid char found in input\n";
			return 1;
		}
	}

	for(size_t j = 0; j < len; j++)
	{
		//Char check
		if(len == 1 && isalpha(input[0]))
		{
			std::cout << "Char\n";
			found = true;
			break;
		}
		if(found == true)
			break;

		//Int check
		for(size_t i = 0; i < len; i++)
		{
			if(input[i] == '-')
			{
				minusFlag++;
				if(minusFlag > 1)
				{
					std::cerr << "Too many '-'\n";
					return 1;
				}
				i++;
			}
			if(!isdigit(input[i]))
				break;
			if(i == (len - 1))
			{
				std::cout << "Int\n";
				found = true;
				break;
			}	
		}
		if(found == true)
			break;
		minusFlag = 0;
		//Float check
		int fHasDec = 0;
		bool fDecFlag = false;
		for(size_t i = 0; i < len; i++)
		{
			if(input[i] == '-')
			{
				minusFlag++;
				if(minusFlag > 1)
				{
					std::cerr << "Too many '-'\n";
					return 1;
				}
			}
			if(isalpha(input[i]) && i != (len - 1))
			{
				std::cerr << "Invalid input1!\n";
				return 1;
			}
			if(input[i] == '.')
			{	
				fHasDec++;
				fDecFlag = true;
				if(fHasDec > 1)
				{
					std::cerr << "Invalid input2!\n";
						return 1;
				}
			}
			if(i == (len - 1) && input.back() == 'f' && (fDecFlag == true))
			{
				std::cout << "Float\n";
				found = true;
				break;
			}
			if(i == (len - 1) && input.back() == 'f' && (fDecFlag == false))
			{
				std::cerr << "Invalid input3\n";
				return 1;
			}
		}
		if(found == true)
			break;
		minusFlag = 0;
		//Double check
		int dHasDec = 0;
		bool dDecFlag = false;
		for(size_t i = 0; i < len; i++)
		{
			if(input[i] == '-')
			{
				minusFlag++;
				if(minusFlag > 1)
				{
					std::cerr << "Invalid input 4\n";
					return 1;
				}
			}
			if(isalpha(input[i]))
			{
				std::cerr << "Invalid input5!\n";
				return 1;
			}
			if(input[i] == '.')
			{	
				dHasDec++;
				dDecFlag = true;
				if(dHasDec > 1)
				{
					std::cerr << "Invalid input6!\n";
						return 1;
				}
			}
			if(i == (len - 1) && (dDecFlag == true) && input[len - 1] != '.')
			{
				found = true;
				std::cout << "Double\n";
			}
		}
		if(found == true)
			break;
	}
	return 0;
}