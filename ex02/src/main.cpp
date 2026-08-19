#include "../include/Base.hpp"

int main(void)
{
	srand(std::time(NULL));
	Base* base = generate();

	identify(base);
	identify(*base);

	delete base;

	return 0;
}