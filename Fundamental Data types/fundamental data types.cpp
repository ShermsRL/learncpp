#include <iostream>
#include <cstdint>
#include <string> // allow use of std::string
#include <string_view>

// void data type is known as a incomplete type - declared but not defined

// void is most commonly used to indicate a function that does not return any value
void writeValue(int x)
{
	std::cout << "The value of x is: " << x << '\n';
}

void integerDataTypes()
{
	short s;       // short     = short int
	int i;
	long l;        // long      = long int
	long long ll;  // long long = long long int

	// storing a number larger than the range of type will result in integer overflow = undefined behaviour

	// defining unsigned integers
	// AVOID IT! (unless its a really specific circumstance)
	// i.e. dealing with bit manipulation, arrays indexing
	unsigned short us;
	unsigned int ui;
	unsigned long ul;
	unsigned long long ull;
}

// have two downsides 
// 1. not guaranteed to be defined on all architectures
// 2. may be slower than a wider type on some architectures
void fixedWidthInt() 
{
	std::int16_t i{ 5 };
	std::cout << i << '\n';
}

// to fix the above downsides, c++ came up with fast and least integers
// also have their own downsides
// 1. not many programmers use them
// 2. fast can lead to memory wastage
void fastandLeast()
{
	std::int_least8_t a;
	std::int_fast8_t b;
	// can replace 8 with 16,32,64 (its the bits)
	// fast means the integral type that can be processed most quickly by cpu

	// avoid 8 bit fixed width and the respective fast and least integer types as they are often treated like chars
}

/*
*Overall for int:
* Prefer int when size doesnt matter
* prefer std::#int when storing a quantity that needs a guranteed range
* prefer std::uint#_t when doing bit manipulation
*/

void floatVariables()
{
	float fValue{ 5.3f }; // floating point literals default to type double, f suffix to denote its of type float
	double dValue{ 5.3 };
	std::cout << fValue << '\n';
	std::cout << dValue << '\n';
	long double ldValue;

	// favor double over float 
	// floating point numbers is useful for storing very large or very small numbers
	// floating point numbers have rounding error (BEWARE!)
}

void booleanVaraibles()
{
	bool b;
	// std::cout prints true/ false as 1/0
	// to print true/ false, use std::cout << std::boolalpha (std::noboolalpha to turn off)
}

void ifStatements()
{
	std::cout << "Enter an integer: ";

	int x{};
	std::cin >> x;

	if (x == 0)
		std::cout << "The value is zero\n";
	else if (x < 0)
		std::cout << "The value is negative\n";
	else
		std::cout << "The value is not zero\n";
}

void isPrime()
{
	std::cout << "Enter a number from 0 to 9: ";
	int num{};
	std::cin >> num;

	if (num == 2)
		std::cout << "The digit is prime";
	else if (num == 3)
		std::cout << "The digit is prime";
	else if (num == 5)
		std::cout << "The digit is prime";
	else if (num == 7)
		std::cout << "The digit is prime";
	else
		std::cout << "The digit is not prime";
}

void characterVariables()
{
	char c{'a'}; 
	std::cout << "First\tSecond"; // tab character
	// Put stand-alone chars in single quotes (e.g. 't' or '\n', not "t" or "\n"). 
	// This helps the compiler optimize more effectively.
}

void staticCasting()
{
	static_cast<int>(5.5);
	// static_cast <type> (expr)
}

void implicitCast(int x)
{
	std::cout << "This is the first way: " << x << '\n';
}

void staticCastingQ1()
{
	std::cout << "Enter a single character: ";
	char character{};
	std::cin >> character;
	implicitCast(character);

	int characterInt{ character };
	std::cout << "This is the second way: " << characterInt << '\n';

	std::cout << "You entered " << '\'' << character << '\'' << ", which has ASCII code " << static_cast<int>(character);
}

void constantVariables()
{
	const double gravity{ 9.8 }; // const keyword to show that it is a constant variable
}

void constantExpression() // constexpr var can only be a compile-time constant, if not it will result in compiler error
{	
    // constant expression
	constexpr double gravity{ 9.8 };
	constexpr double pi{ 3.14 };
	constexpr int three{ 3 };
	constexpr double equation{ three + pi };

	// non-constant
	/*int num{};
	std::cin >> num;
	constexpr int newNum{ num };*/
}

void literalsSuffix()
{
	// generally dont need to use suffix for int data type
	std::cout << 5 << '\n';
	std::cout << 5L << '\n';
	std::cout << 5U << '\n';

	double f{ 4.1f };

	// octal literal(hardly use, just avoid it), prefix with 0
	int octalNum{ 012 };
	std::cout << octalNum << '\n';

	// hexadecimal, prefix with 0x
	int hexaNum{ 0xF };
	std::cout << hexaNum << '\n';

	// binary literals, prefix with 0b (only in c++14 and above)
	int binaryNum{ 0b1111'0000 }; // ' is used as a digit seperator, cannot occur before the first digit
	std::cout << binaryNum << '\n';

	// changing output format via std::dec, std::oct, std::hex
}

void stringVariables()
{
	std::string name{ "Sherman" };
	std::cout << "My name is: " << name << '\n';

	// use std::getline() to input text
	std::cout << "Enter your full name: ";
	std::string fullName{};
	std::getline(std::cin >> std::ws, fullName); // std::ws input manipulator, tells cin to ignore any leading whitespace

	// length of std::string
	std::cout << fullName << " has " << fullName.length() << " characters\n";
}

void stdStringQ1()
{
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	// name.length return unsigned integral, assign to int to avoid warning about signed/unsigned conversions
	int letters{ static_cast <int> (name.length()) };
	std::cout << "The sum of your age and number of letters in your name is: " << age + letters;
}

void stringViews()
{
	std::string_view s{ "Hello world!" }; // string_view introduced in c++17, provides read-only access to an existing string'

	// string_view also support constexpr
	constexpr std::string_view constString{ "Hello world!" };
}

double userValue()
{
	std::cout << "Enter a double value: ";
	double num{};
	std::cin >> num;
	return num;
}

double sign(double val1, double val2, char symbol)
{
	if (symbol == '+')
		return val1 + val2;
	else if (symbol == '-')
		return val1 - val2;
	else if (symbol == '*')
		return val1 * val2;
	else
		return val1 / val2;
}

void summaryQ1()
{
	double value1{ userValue() };
	double value2{ userValue() };
	std::cout << "Enter one of the following: +, -, *, or /: ";
	char symbol{};
	std::cin >> symbol;
	std::cout << value1 << " " << symbol << " " << value2 << " is " << sign(value1, value2, symbol);
}

int getTowerHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	int height{};
	std::cin >> height;
	return height;
}

void printHeight(int seconds, double height)
{
	if (height > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

double heightFallen(int towerHeight ,int seconds, double gravity)
{
	double heightfell{ gravity * (seconds * seconds) / 2 };
	double currBallHeight{ towerHeight - heightfell};
	printHeight(seconds, currBallHeight);
	return currBallHeight;
}

void summaryQ2()
{
	constexpr double gravity{ 9.8 };
	int towerHeight{ getTowerHeight() };
	heightFallen(towerHeight, 0, gravity);
	heightFallen(towerHeight, 1, gravity);
	heightFallen(towerHeight, 2, gravity);
	heightFallen(towerHeight, 3, gravity);
	heightFallen(towerHeight, 4, gravity);
	heightFallen(towerHeight, 5, gravity);
}

int summaryQ3()
{
	std::cout << "How old are you?\n";

	// using of uint8_t, not good as it will be treated as char when std::cout
	std::uint8_t age{};
	std::cin >> age;
	std::cout << "Allowed to drive a car in Texas [";

	// 16 can be seen as magic num, use constexpr to make it clearer
	if (age >= 16)
		// char should use single ''
		std::cout << "x";
	else
		std::cout << " ";

	std::cout << "]\n";

	return 0;
}

int main()
{
	summaryQ3();

	return 0;
}