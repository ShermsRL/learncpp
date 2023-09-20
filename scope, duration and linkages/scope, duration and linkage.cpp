#include <iostream>
#include <utility> // for std::swap
#include "add.h"
#include "constants.h"
#include "newconstants.h"

// internal linkage (const global have this by default)
static int g_x{ 1 }; // static keyword, g_x can only be used in this file, inacessible anywhere else
// use it when
// 1. explicit reason to disallow access from other files

// external linkage (non const global have this by default)
extern int g_y{ 2 }; // extern keyword, g_y acessible everywhere

static int g_accumulate{ 0 }; // for summaryQ3

// nested namespace (C++17)
namespace Foo::Goo
{
	int add(int x, int y)
	{
		return x + y;
	}
}

void localVariablesQ1()
{
	std::cout << "Enter an integer: ";
	int smaller{};
	std::cin >> smaller;
	std::cout << "Enter a larger integer: ";
	int larger{};
	std::cin >> larger;

	if (larger < smaller)
		{
			std::cout << "Swapping the values" << '\n';
			int temp{ smaller };
			smaller = larger;
			larger = temp;
			std::cout << "The smaller value is " << smaller << '\n';
			std::cout << "Ther larger value is " << larger << '\n';
		} // z destroyed here
} // smaller and larger destroyed here

//constexpr int greater(int x, int y) // can be used in a constant expression
//{
//	return (x > y ? x : y);
//
//	// to be eligible for compile-time eval, function must have a constexpr return type and not call
//	// any non-constexpr functions
//	// must also have constexpr args
//
//	// constexpr func allows non-constexpr args but it will be evaluated at runtime
//}

// forcing constexpr function to be evaluated at compile time
// introducing consteval (c++20)
consteval int greater(int x, int y)
{
	return (x > y ? x : y);

	// cant be evaluated at runtime, less flexible compared to constexpr func
}

// making consteval to be able to be evaluated either at compile or runtime with auto keyword
consteval auto compileTime(auto value)
{
	return value;
}

void summaryQ1()
{
	std::cout << "Enter a positive number: ";
	int num{};
	std::cin >> num;


	if (num < 0)
	{
		std::cout << "Negative number entered.  Making positive.\n";
		num = -num;
	}
	std::cout << "You entered: " << num;
}

void summaryQ2()
{
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;


	if (students > newconstants::max_class_size)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class isn't too large";

}

int accumulate(int x)
{
	g_accumulate += x;
	return g_accumulate;
}

void summaryQ3()
{
	std::cout << accumulate(4) << '\n'; // prints 4
	std::cout << accumulate(3) << '\n'; // prints 7
	std::cout << accumulate(2) << '\n'; // prints 9
	std::cout << accumulate(1) << '\n'; // prints 10
}

int main()
{
	//std::cout << BasicMath::add(4, 3) << '\n';
	//std::cout << Foo::Goo::add(5, 2) << '\n';

	//// namespace aliases
	//namespace active = Foo::Goo;
	//std::cout << active::add(1, 4) << '\n';

	//localVariablesQ1();
	/*std::cout << constants::earthGravity << '\n';
	std::cout << newconstants::pi;

	constexpr int x{ 5 };
	constexpr int y{ 6 };

	constexpr int g{ greater(x, y) };
	std::cout << g << " is greater!\n";*/

	summaryQ3();

	return 0;
}