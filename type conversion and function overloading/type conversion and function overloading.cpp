#include <iostream>
#include "mytypes.h"

void cStyleCast() // best practice: avoid using
{
    int x{ 10 };
    int y{ 4 };

    double d{ (double)x / y };
    double dd{ double(x) / y }; // a more function-call like syntax works too
    std::cout << d << '\n';
    std::cout << dd << '\n';
}

void staticCast() // provides compile time type checking
{
    for (char alphabet{ 'a' }; alphabet <= 'z'; ++alphabet)
        std::cout << static_cast<int>(alphabet) << ' ';
}

void typeAlias()
{
    using Distance = int;
    // naming convention - type alias should start with capital letter
    Distance kmToDestination = 8.6;

    std::cout << kmToDestination << '\n';

    Miles distance{ 438 };
    std::cout << typeid(distance).name(); // type of long because Miles = long in mytype header
}

void typeDef() // type definition
{
    typedef long Distance; // replaced by type alias
}

void typeAliasQ1()
{
    using PrintError = int;
    PrintError printData();
}

void typeDeduction()
{
    // automatically deduce the type
    auto d{ 5.0 };
    auto i{ 1 + 2 };
    auto c{ 'a' };

    std::cout << typeid(d).name() << '\n';
    std::cout << typeid(i).name() << '\n';
    std::cout << typeid(c).name() << '\n';

    // type deduction will drop const / constexpr qualifiers
    const int x{ 5 };
    auto y{ x }; // y will jus be an int, not const int
    const auto z{ x }; // z will be const int 
}

// type deduction for functions
auto sum(int x, int y)
{
    return x + y;

    // type deduction for function, all return statement must return the same type
    // must also be fully defined before it can be used
}

// trailing return syntax - makes function name line up neatly
auto add(int x, int y) -> int
{
    return x + y;
}

auto deduct(int x, int y) -> int
{
    return x - y;
}

// function overloading - the add function only works for int, what if u need double?
auto add(double x, double y) -> double
{
    return x + y;
    // have a function with the same name but takes in diff arguments!
}

// default arguments - if arguments is specified, it will override the default
auto divide(int x, int y = 5) -> int
{
    return x / y;
    // if function have forward declaration, default argument should be declared there
}

//auto max(int x, int y) -> int
//{
//    return (x < y) ? x : y;
//}

// creating a template based on max function
//template <typename T>
//T max(T x, T y) // use single capital letter to name templates
//{
//    return (x < y) ? y : x;
//
//    // if template needs to be used in multiple files, define in header
//}

// function templates with multiple template type params
template <typename T, typename U>
auto max(T x, U y)
{
    return (x < y) ? y : x;
}

// abbreviated function templates (C++20)
// best practice - Feel free to use abbreviated function templates 
// with a single auto parameter, or where each auto parameter should be an independent type
auto min(auto x, auto y)
{
    return (x < y) ? x : y;
}

// using the function template
void usingFuncTemp()
{
    std::cout << max<int>(3, 4) << '\n';
    std::cout << max<double>(9.4, 10.6) << '\n';

    // argument deduction
    std::cout << max<>(5, 6) << '\n';
    // or
    std::cout << max(7, 8) << '\n'; // favor this

    std::cout << max(2, 3.5) << '\n';

    std::cout << min(2, 3.5) << '\n';
}

//int main()
//{
//    std::cout << add(1, 2) << '\n'; // call the int add
//    std::cout << add(1.2, 3.4) << '\n'; // call the double add
//
//    usingFuncTemp();
//    return 0;
//}