#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <iostream>
// #define DEBUG

/*
* Why debug statements are no good:
* Debug statements clutter your code.
* Debug statements clutter the output of your program.
* Debug statements require modification of your code to both add and to remove, which can introduce new bugs.
* Debug statements must be removed after you’re done with them, which makes them non-reusable.
*/

int getValue()
{
//std::cerr << "getValue() called\n"; // debug statements
    //PLOGD << "getUsertInput() called";
	return 4;
}

void printValue(int value)
{
	std::cout << value << '\n';
}

int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int readNumber2()
{
	std::cout << "Please enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

void writeAnswer2(int x)
{
	std::cout << "The quotient is: " << x << '\n';
}

int main()
{
//std::cerr << "main() called \n";
	//plog::init(plog::none, "Logfile.txt");
	//PLOGD << "main() called";
	#ifdef DEBUG
	// To ensure that all output from std::cout is output immediately - this is only to be used for debugging
	std::cout << std::unitbuf;
    #endif

	/*printValue(5);
	printValue(6);
	printValue(7);*/

	/*int x{10};
	int y{ 0 };
	std::cout << x / y << '\n';*/

	/*int x{ readNumber(x) };
	x = x + readNumber(x);
	writeAnswer(x);*/

	int x{};
	int y{};
	x = readNumber2();
	y = readNumber2();
	writeAnswer2(x / y);

	return 0;
}