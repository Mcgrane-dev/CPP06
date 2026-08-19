#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

public:
	static int convert(const std::string &input);
};

#endif