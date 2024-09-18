#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include <fstream>
class Utils
{

public:
	int getint();
	int enterInteger(int choice = 0, int max = 100, int min = 0, const std::string word = "number");
	std::streampos extractTillDigit(std::fstream& file, std::string& destination, std::streampos position);
	void appendToFile(std::fstream& file, std::string str, std::string fileName);
};

#endif // !UTILS_H

