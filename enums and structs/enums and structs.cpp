#include <iostream>
#include <string_view>
#include <utility> // for std::pair

// define a new unscoped enumeration named Color
enum Color
{
    // here are the enumerators
    // these symbolic constants define all the possible values this type can hold
    // each enumerator is seperated by a comma, not semicolon
    red = -3,
    green, // assigned -2
    blue, // assigned -1
}; // end with semicolon

// Prefer putting your enumerations inside a named scope region 
// (such as a namespace or class) so the enumerators don’t pollute the global namespace.
namespace Feeling
{
    enum Feeling
    {
        happy,
        tired,
        sad,
    };
}

namespace MonsterType
{
    enum MonsterType
    {
        orc, // assigned 0
        goblin, // assigned 1
        troll, // assigned 2
        ogre, // assigned 3
        skeleton, // assigned 4
    };
}

// printing enumerator names
// using if else is inefficient
void printColor(Color color)
{
    if (color == red) std::cout << "red";
}

//std::string getColor(Color color) {
//    switch (color)
//    {
//    case red: return "red";
//    case blue: return "blue";
//    default: return "???";
//    }
//}

// for c++17
constexpr std::string_view getColor(Color color) {
    switch (color) {
    case red: return "red";
    case blue: return "blue";
    default: return "???";
    }
}

// overloading operator<< to print enum type
// Teach operator<< how to print a Color
// Consider this magic for now since we haven't explained any of the concepts it uses yet
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from being made)!
std::ostream& operator<<(std::ostream& out, Color color)
{
    switch (color)
    {
    case red:   return out << "red";
    case blue:  return out << "blue";
    default:    return out << "???";
    }
}

// overloading operator>> to take in enum type input
// Consider this magic for now
// We pass pet by reference so we can have the function modify its value
std::istream& operator>> (std::istream& in, MonsterType::MonsterType& monster)
{
    int input{};
    in >> input; // input an integer

    monster = static_cast<MonsterType::MonsterType>(input);
    return in;
}

std::ostream& operator<<(std::ostream& out, MonsterType::MonsterType monster)
{
    switch (monster)
    {
    case MonsterType::orc:   return out << "orc";
    case MonsterType::goblin:  return out << "goblin";
    default:    return out << "???";
    }
}

// scoped enumerators
// will not convert to integers
// however can be done so via static cast or std::to_underlying() (from utility header)
enum class Consoles
{
    playstation,
    xbox,
    nintendo,
};

enum class Games
{
    godOfWar,
    spiderman,
    liesOfP,
};

enum class Animals
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animals animal)
{
    using enum Animals;

    switch (animal)
    {
    case pig: return "pig";
    case chicken: return "chicken";
    case goat: return "goat";
    case cat: return "cat";
    case dog: return "dog";
    case duck: return "duck";
    default: return "no such animal";
    }
}

void printNumberOfLegs(Animals animal)
{
    using enum Animals;

    switch (animal)
    {
    case pig:
    case goat:
    case dog:
    case cat:
        std::cout << "A " << getAnimalName(animal) << " has 4 legs" << std::endl;
        break;
    case duck:
    case chicken:
        std::cout << "A " << getAnimalName(animal) << " has 2 legs" << std::endl;
        break;
    default:
        std::cout << getAnimalName(animal) << std::endl;
        break;
    }
}

// structures (allow bundling of multiple variables into a single type)
// define structs
struct Employee
{
    // these are known as data members/member variables
    int id{};
    int age{};
    double wage{};
};

struct Rectangle
{
    double length{};
    double width{};
};

// passing structs by reference
void printEmployee(const Employee& employee)
{
    std::cout << "ID:   " << employee.id << std::endl;
    std::cout << "Age:  " << employee.age << std::endl;
    std::cout << "Wage: " << employee.wage << std::endl;
}

// returning structs
struct Point3d
{
    double x{ 0.0 };
    double y{ 0.0 };
    double z{ 0.0 };
};

Point3d getZeroPoint() {
    return {};
}

struct Adrevenue
{
    int adsWatched{};
    double usersClickPercent{};
    double earningsPerClick{};
};

Adrevenue getAdRevenue() {
    Adrevenue temp{};
    std::cout << "How many ads were shown?: " << std::endl;
    std::cin >> temp.adsWatched;
    std::cout << "Percentage of users that click on the ads?: " << std::endl;
    std::cin >> temp.usersClickPercent;
    std::cout << "What is the earnings per click?: " << std::endl;
    std::cin >> temp.earningsPerClick;

    return temp;
}

void earningsCalculation(const Adrevenue& adrevenue)
{
    std::cout << "Ads watched: " << adrevenue.adsWatched << std::endl;
    std::cout << "Percentage of users clicked on ad: " << adrevenue.usersClickPercent << std::endl;
    std::cout << "Average earnigs per clicked ad: " << adrevenue.earningsPerClick << std::endl;
    std::cout << "Earnings for that day: " << adrevenue.adsWatched * 
        (adrevenue.usersClickPercent / 100) * adrevenue.earningsPerClick << std::endl;
}

struct Fraction 
{
    int numerator{0};
    int denominator{1};
};

Fraction getUserFraction()
{
    Fraction fraction{};
    std::cout << "Enter a value for the numerator: ";
    std::cin >> fraction.numerator;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> fraction.denominator;

    return fraction;
}

Fraction multiplyFraction(const Fraction& fraction1, const Fraction& fraction2)
{
    /*Fraction multipliedFraction{};
    multipliedFraction.numerator = fraction1.numerator * fraction2.numerator;
    multipliedFraction.denominator = fraction1.denominator * fraction2.denominator;
    return multipliedFraction;*/
    return { fraction1.numerator * fraction2.numerator, fraction1.denominator * fraction2.denominator };
}

void printFraction(const Fraction& fraction)
{
    std::cout << "Your fractions multiplied together: " << fraction.numerator << "/" << fraction.denominator;
}

// class templates (typically in header files)
template <typename T>
struct Pair
{
    T first{};
    T second{};
};

template <typename T>
constexpr T max(Pair<T> p)
{
    return (p.first < p.second ? p.second : p.first);
}

// class templates with template and non template types
template <typename T>
struct Example
{
    T first{};
    int second{};
    T third{};
};

// class templates with multiple template types
template <typename T, typename U>
struct NewPair
{
    T first{};
    U second{};
};

template <typename T, typename U>
void printNewPair(NewPair<T, U> p)
{
    std::cout << p.first << '\t' << p.second << std::endl;
}

// working with pair numbers is common, use std::pair
template <typename T, typename U>
void print(std::pair<T, U> p)
{
    std::cout << p.first << '\t' << p.second << std::endl;
}

// class template argument deduction (CTAD) - needed in c++17
template <typename T, typename U>
NewPair(T, U) -> NewPair<T, U>;

// Alias templates (must be defined in global scope)
template <typename T>
using Coord = Pair<T>;

template <typename T>
void print(const Coord<T>& c)
{
    std::cout << c.first << '\t' << c.second << std::endl;
}

//int main()
//{
//    Color apple{ red };
//    Color shirt{ green };
//    Color cup{ blue };
//
//    /*Color socks{ white };
//    Color hat{ 2 };*/
//
//    // accessing enumerator from scope of color
//    Color raspberry{ Color::red };
//
//    if (apple == red) {
//        std::cout << "The apple is ripe!" << '\n';
//    }
//    else {
//        std::cout << "The apple is unripe!" << '\n';
//    }
//
//    MonsterType::MonsterType Monster{ MonsterType::troll };
//
//    // unscoped enum input
//    // using static cast
//    std::cout << "Enter a monster (0=orc, 1=goblin, 2=troll, 3=ogre, 4=skeleton)";
//
//    int input{};
//    std::cin >> input;
//
//    MonsterType::MonsterType Monster2{ static_cast<MonsterType::MonsterType>(input) };
//    std::cout << Monster2;
//
//    // accessing scoped enums
//    Consoles console{ Consoles::xbox };
//    Games game{ Games::godOfWar };
//
//    //Animals cat{ Animals::cat };
//    //Animals chicken{ Animals::chicken };
//    printNumberOfLegs(Animals::cat);
//    printNumberOfLegs(Animals::chicken);
//
//    Employee sherman{};
//    sherman.age = 25; // member selection operator to access the member variables
//    sherman.id = 1;
//    sherman.wage = 0;
//    
//    Employee sherman2{};
//    sherman2.age = 26;
//    sherman2.id = 2;
//    sherman2.wage = 100000;
//
//    // aggregrate initialisation for struct
//    Employee sherman3{ 27, 3, 50000 };
//
//    // const struct
//    const Rectangle rect1{ 1.0, 1.0 };
//
//    // designated initialiser (C++20)
//    // must be in order of how struct is defined
//    Employee sherman4{ .id{4}, .age{28} };
//
//    printEmployee(sherman3);
//
//    Adrevenue adrevenue{getAdRevenue()};
//    earningsCalculation(adrevenue);
//
//    Fraction fraction1{ getUserFraction() };
//    Fraction fraction2{ getUserFraction() };
//    printFraction(multiplyFraction(fraction1, fraction2));
//
//    // member selection with pointers and reference
//    // method 1
//    Employee* ptr{ &sherman };
//    std::cout << (*ptr).id << std::endl;
//
//    // method 2 (pointer operator)
//    std::cout << ptr->age << std::endl;
//
//    Pair<int> p1{ 5,6 };
//    std::cout << p1.first << '\t' << p1.second << std::endl;
//    std::cout << max<int>(p1) << std::endl;
//    std::cout << "==========================" << std::endl;
//
//    Pair<double> p2{ 1.2, 3.4 };
//    std::cout << p2.first << '\t' << p2.second << std::endl;
//    std::cout << max<double>(p2) << std::endl;
//    std::cout << "==========================" << std::endl;
//
//    NewPair<int, double> p3{ 2, 3.4 };
//    printNewPair(p3);
//
//    // std::pair
//    std::pair <int, double> p4{ 4, 5.6 };
//    print(p4);
//
//    // type alias for class template
//    using Point = Pair<int>;
//    Point p5{ 1,2 };
//
//    return 0;
//}

