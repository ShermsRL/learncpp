#include <iostream>

// This function get an user input integer and print out the double of it

int main()
{	
	/*
	std::cout << "Enter an integer: ";

	int number{ 0 };    // define number as an integer variable and initialise it to 0
	std::cin >> number; // get integer value from user's keyboard
	std::cout << "Double " << number << " is: " << number * 2 << '\n';
	std::cout << "Triple " << number << " is: " << number * 3;
	*/

	std::cout << "Enter an integer: ";
	int firstNumber{ 0 };
	std::cin >> firstNumber;

	std::cout << "Enter another integer: ";
	int secondNumber{ 0 };
	std::cin >> secondNumber;

	std::cout << firstNumber << " + " << secondNumber << " is " << firstNumber + secondNumber << '\n';
	std::cout << firstNumber << " - " << secondNumber << " is " << firstNumber - secondNumber << '\n';

	return 0;
}