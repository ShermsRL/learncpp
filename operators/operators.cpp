#include <iostream>

int getUserNum()
{
	std::cout << "Enter an integer: ";
	int num{};
	std::cin >> num;
	return num;
}

bool isEven(int num)
{
	return (num % 2 == 0);
}

void prefixIncrement()
{
	int x{ 5 };
	int y{ ++x };
	std::cout << x << y << '\n';
}

void postfixIncrement()
{
	int x{ 5 };
	int y{ x++ };
	std::cout << x << y << '\n'; // output 6 5

	// 1. temp copy of x is made
	// 2. actual x is incremented
	// 3. copy of x is returned and assigned to y
	// 4. copy of x is destroyed
}

void conditionalOperator()
{
	int x{ 5 };
	int y{ 6 };
	int z = { (x > y) ? 7 : 8 };
	std::cout << z;
}

int main()
{
	/*int userNum{ getUserNum() };
	if (isEven(userNum))
		std::cout << userNum << " is even";
	else
		std::cout << userNum << " is odd";*/

	// favor prefix > postfix
	
	conditionalOperator();
	return 0;
}