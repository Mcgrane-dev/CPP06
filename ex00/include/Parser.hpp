#ifndef PARSER_HPP
#define PARSER_HPP

#include <limits>
#include <iomanip>
#include <iostream>

void	intLiteral(const std::string &input);
void 	charLiteral(const std::string &input);
void 	floatLiteral(const std::string &input);
bool 	isPseudoLiteral(const std::string& input);
void 	printPseudoLiteral(const std::string &input);
bool 	plusCheck(const std::string &input, size_t &i);
bool 	minusCheck(const std::string& input, size_t &i);
bool 	validateChars(const std::string input, size_t len);
bool 	charCheck(const size_t &len, const std::string &input);
int 	floatCheck(const size_t &len, const std::string &input);
int 	doubleCheck(const size_t &len, const std::string &input);
bool 	charPositions(const size_t &len, const std::string &input);
bool 	intValidation(const size_t &len, const std::string &input);

#endif