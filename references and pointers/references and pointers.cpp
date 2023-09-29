#include <iostream>
#include <string>

int g_x{ 5 };

int return5()
{
    return 5;
}

void LRvalue()
{
    // lvalue - short for left/locator value, an expression that evaluates to an identifiable obj or funct
    // persist beyond the end of the expression
    int x{ 5 }; // 5 is an rvalue expr
    const double d{ 1.2 };
    int y{ x }; // x is an lvalue expr, a modifiable lvalue expr
    const double e{ d }; // d is a non-modifiable lvalue expr

    // rvalue - short for right value, an expression that is not an lvalue
    // these expr produce temp values that are not identifiable objects
    // discarded at the end of the expression
    int z{ return5() };
    int w{ x + 1 };
    int q{ static_cast<int>(d) };

    // if unsure expr is l or r value, take its address using opr &, which requires operand to be lvalue
    // if it compiles, it must be an lvalue
    &x;
    // &5; - doesnt compile
    // &return5(); - doesnt compile

}

void lValueReference()
{
    // reference, an alias for an existing obj, must be initialised
    // lvalue ref variables

    int x{ 5 };
    int& ref{ x }; // int& defines ref as an lvalue ref to an int, which is initialize with lvalue expr x

    std::cout << x << '\n';
    std::cout << ref << '\n';

    // modifying value through lvalue ref
    x = 6;
    std::cout << x << '\n'; 
    std::cout << ref << '\n';

    ref = 7;
    std::cout << x << '\n';
    std::cout << ref << '\n';
}

// lvalue reference to const
void refToConst()
{
    const int x{ 5 };
    const int& ref{ x };

    std::cout << ref << '\n'; // can access but not modify

    // reference to const with modifiable lvalue
    int y{ 5 };
    const int& ref2{ y }; 
    // will not be able to do things like ref2 = 6; since it is treated like const

    // lvalue ref to const can also bind to rvalue, temp obj is created
    // temp obj used directly at the point created, cannot refer to it beyond that point
    const int& ref3{ 5 };

    // by having a const lvalue ref bounded to a temp obj, it can be used beyond its lifetime

    // constexpr lvalue ref
    constexpr int& ref4{ g_x }; // can bind to global
    static int s_x{ 6 };
    constexpr int& ref5{ s_x }; // can bind to static

    // constexpr int& ref6{ y }; // cannot bind to non static

    // constexpr ref to const variable]
    static const int s_y{ 6 };
    constexpr const int& ref7{ s_y }; // constexpr for the ref, const for the type
}

// pass by lvalue reference
// why use reference? copying can be expensive
void printValue(std::string& y, int& q) // no copying needed when lvalue ref param y is binded to x
{
    std::cout << y << '\n';
    ++q;
}

void callPrintValue()
{
    std::string x{ "Hello, world!" };

    // passing by ref also directly modifies the argument
    int p{ 5 };
    std::cout << p << '\n';
    printValue(x, p);
    std::cout << p << '\n';
}

// pass by const lvalue ref
void printValue2(const int& y)
{
    std::cout << y << '\n';
}

void callPrintValue2()
{
    // a pass by lvalue const works for modifiable, non-modifiable and literals
    // however the value cannot be modified 
    // favor doing this
    int x{ 5 };
    printValue2(x);

    const int p{ 5 };
    printValue2(p);

    printValue2(5);
    
   /* As a rule of thumb, pass fundamental types by value, 
   and class (or struct) types by const reference.

    Other common types to pass by value : 
    enumerated types and std::string_view.

    Other common types to pass by(const) reference : 
    std::string, std::array, and std::vector.*/

    // prefer std::string_view > const std::string& when passing
}

// intro to pointers
// what is * and &??
void operatorsMeaning()
{
    int x{ 5 };
    std::cout << x << '\n';
    std::cout << &x << '\n'; // address of where x is stored

    // dereference operator
    std::cout << *(&x) << '\n'; // value at address of x
}

// pointers (the raw/dumb version)
// an object that holds a memory address typically (of another variable) as its value
void pointers()
{
    int x{ 5 };
    int* ptr{ &x }; // always initialise pointers!(not really but it should be), value needs to be an address
    // int* ptr{ 5 }; is not allowed
    // int* ptr{ 0x0012FF7C }; address if treated as integer literal

    // use dereference opr to access the value at that address
    std::cout << *ptr << '\n';
}

// null pointers
void nullPointers()
{
    int* ptr {}; // ptr is now a pointer that points to nothing

    int x{ 5 };
    ptr = &x; // reassign null to point to x
    std::cout << *ptr << '\n';

    // to be more explicit, use keyword nullptr
    int* ptr2{ nullptr };
    
    // null pointers can be used as conditionals

    // Favor references over pointers unless the additional 
    // capabilities provided by pointers are needed.
}

// pointer to const value
void pointerAndConst()
{
    const int x{ 5 };
    const int* ptr{ &x }; // pointer pointing to const int

    // *ptr = 6; // not allowed to change the value because of const
    const int y{ 6 };
    ptr = &y; // you can however reassign the pointer

    // const pointer
    int z{ 5 };
    int* const ptr2{ &z }; 

    // ptr = &y; // address cant be changed as it is a const pointer
    *ptr2 = 7; // you can however change the value

    // const pointer to const value
    const int a{ 5 };
    const int* const ptr3{ &a };
    // value and address cant be modified
}

// pass by address (via pointers)
void passByAddress(int* ptr)
{
    std::cout << *ptr << '\n';
    *ptr = 10;
}

void callPassByAddress()
{
    int x{ 9 };

    passByAddress(&x);
    std::cout << x << '\n';

    // only do this if u must
    // rule of thumb
    // Pass by reference when you can, pass by address when you must
}

// pass by address by reference (this allows the ptr to change what is it pointing to)
void byAddByRef(int*& refptr)
{
    refptr = nullptr;
}

void callbyAddByRef()
{
    int x{ 5 };
    int* ptr{ &x };

    std::cout << "ptr is " << (ptr ? "not null" : "null") << '\n';
    byAddByRef(ptr);
    std::cout << "ptr is " << (ptr ? "not null" : "null") << '\n';
}

// return by reference and return by address
const std::string& getProgramName()
{
    static const std::string s_programName{ "Calculator" };

    return s_programName;

    // return by reference means the object being referenced 
    // outlives the function returning the ref

    // avoid returning ref to non-const local static variables

    // Prefer return by reference over return by address 
    // unless the ability to return “no object” (using nullptr) is important.
}

void sort2(int& x, int& y)
{
    int minValue{ (x < y) ? x : y };
    int maxValue{ (x < y) ? y : x };
    x = minValue;
    y = maxValue;
}

void callSort2()
{
    int x{ 7 };
    int y{ 5 };

    sort2(x, y);
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y);
    std::cout << x << ' ' << y << '\n'; // should print 5 7
}

int main()
{
    callSort2();
    return 0;
}