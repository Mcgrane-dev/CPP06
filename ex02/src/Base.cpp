#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include "../include/Base.hpp"

Base* generate(void)
{
	switch(std::rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "\"A\"\n";
	else if(dynamic_cast<B*>(p))
		std::cout << "\"B\"\n";
	else if(dynamic_cast<C*>(p))
		std::cout << "\"C\"\n";
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "\"A\"\n";
		return;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "\"B\"\n";
		return;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "\"C\"\n";
		return;
	}
	catch(const std::exception& e)
	{
	}
}

Base::~Base(){}