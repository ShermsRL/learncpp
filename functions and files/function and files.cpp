#include <iostream>
#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE
#include "add.h"
#include "io.h"

// Forward declarations for functions in other files (also needed if function is defined after main)
void printTest();
int getInteger();


// Function asks user to enter a value
//int getValueFromUser()
//{
//	std::cout << "Enter an integer: ";
//	int num{ 0 };
//	std::cin >> num;
//	return num; // return the value the user entered back to the caller (good to indicate what the return value means)
//}

// used to test linker error
//int add(int x, int y)
//{
//	return x + x + y;
//}

// Function prints out double of value specified
void printDouble(int value) // function parameter
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

int doubleNumber(int num)
{
	return num * 2;
}

int main() 
{	
	// printDouble(getValueFromUser()); // function argument
	// std::cout << doubleNumber(getValueFromUser());
	/*
	int x{ getInteger() };
	int y{ getInteger() };
	std::cout << x << " + " << y << " is " << x + y << '\n';
	std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
	printTest();
	*/
	int firstNum{ readNumber() };
	int secondNum{ readNumber() };
	writeAnswer(firstNum + secondNum);

	return 0;
}


