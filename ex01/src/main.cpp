#include "../include/Serializer.hpp"

int main(void)
{
	Data data;
	Data* ptr = &data;

	data.name = "Test";
	data.number = 3;

	std::cout << "Pointer: " << ptr << "\n";
	uintptr_t ptrInt = Serializer::serialize(ptr);
	std::cout << "Serialization: " << ptrInt << "\n";

	Data *raw = Serializer::deserialize(ptrInt);
	std::cout << "Deserialization: " << raw << "\n";

	if(ptr == raw)
		std::cout << "Pointers are equal\n";
	else
		std::cout << "Pointers are not equal\n";

	std::cout << "Ptr name: " << ptr->name << "\n";
	std::cout << "Ptr number: " << ptr->number << "\n";

	std::cout << "Raw name: " << raw->name << "\n";
	std::cout << "Raw number: " << raw->number << "\n";
	return 0;
}