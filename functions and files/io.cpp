#include <iostream>
#include "io.h"

// Question 1: To get a single integer from user
int readNumber()
{
	std::cout << "Enter an integer: ";
	int num{};
	std::cin >> num;
	return num;
}

void writeAnswer(int num)
{
	std::cout << "The answer is: " << num;
}