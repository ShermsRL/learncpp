#include <iostream>
#include <string_view>

// classes are similar to struct
class Date
{
public:
    int m_day{};
    int m_month{};
    int m_year{};
};

void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year << std::endl;
}

// struct member function version
struct Time
{
    int hour{};
    int minute{};
    int second{};

    // member function
    void print()
    {
        std::cout << hour << ":" << minute << ":" << second << std::endl;
    }
};

struct Gamer
{
    std::string_view name{};
    std::string_view game{};

    void playing(const Gamer& gamer)
    {
        std::cout << name << " playing " << gamer.game << std::endl;
    }

};

struct IntPair
{
    int num1{};
    int num2{};

    // const member function
    void print() const
    {
        std::cout << "Pair(" << num1 << ", " << num2 << ")" << std::endl;
    }

    bool isEqual(const IntPair& pair)
    {
        if ((num1 == pair.num1) && (num2 == pair.num2)) return true;
        return false;
    }
};

// public and private access level
// members of struct is public while members of class is private by default
// setting the public and private access specifiers
class Measurements
{
public: // public access specifier
    void print() const
    {
        std::cout << m_chestSize << "," << m_shoulderLength << "," << m_waistSize << std::endl;
    }

private: // private access specifier
    double m_chestSize{100.3};
    double m_shoulderLength{50.0};
    double m_waistSize{30.2};
};

class Point3d
{
public:
    void setValues(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print() const
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">" << std::endl;
    }

    bool isEqual(const Point3d& point) const
    {
        return ((m_x == point.m_x) && (m_y == point.m_y) && (m_z == point.m_z));
    }

private:
    int m_x{};
    int m_y{};
    int m_z{};
};

// Access function - a trivial public member function that retrieve or change the value of a private member variable
class BirthDate
{
private:
    int m_birthyear{ 1998 };
    int m_birthmonth{ 03 };
    int m_birthday{ 04 };

public:
    void print()
    {
        std::cout << m_birthyear << "/" << m_birthmonth << "/" << m_birthday << std::endl;
    }

    // getter and setter
    // returning by const reference
    const int& getYear() const { return m_birthyear; }
    void setYear(int year) { m_birthyear = year; }

    // using auto to ensure no conversion - this howevers affect documentation
    const auto& getMonth() const { return m_birthmonth; }
    void setMonth(int month) { m_birthmonth = month; }

    int getDay() const { return m_birthday; }
    void setDay(int day) { m_birthday = day; }

    // do not return non-const reference to private data members

};

// Intro to constructors
class Foo
{
public:
    Foo(int x, int y) // constructor function, must be non const
        : m_x{x}, 
          m_y{y} // member initialization list, must match the order in which they are initialised
    {
        // body is most often left empty as its only used for initiaization
        // which is done via member initialization list
        // however this can be also used to do setups
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }

private:
    int m_x{};
    int m_y{};
};

//class Ball
//{
//public:
//    Ball(std::string_view color, double radius)
//        : m_color{ color }
//        , m_radius{ radius }
//    {
//    }
//
//    void print() const
//    {
//        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
//    }
//
//private:
//    std::string m_color{"None"};
//    double m_radius{0.0};
//};

// constructors with default arguments
class Foo2
{
public:

    // Overloading constructors
    Foo2()
    {
        std::cout << "Foo2 constructed\n";
    }

    Foo2(int x, int y)
        : m_x{x}
        , m_y{y}
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    // generate implicit default constructor
    // Foo2() = default;

private:
    int m_x{};
    int m_y{};
};

// delegating constructors
// constructors can delegate initialization to another constructor of same class type
// this is known as constructor chaining
// however you are unable to do any member initialization
class Employee
{
public:
    Employee(std::string_view name)
        : Employee{ name, 0 } // delegate initialization to Employee(std::string_view name, int id)
    {
    }

    Employee(std::string_view name, int id)
        : m_name{ name }
        , m_id{ id }
    {
        std::cout << "Employee " << m_name << " created\n";
    }

private:
    std::string m_name{};
    int m_id{ 0 };
};

class Ball
{
public:
    Ball(double radius)
        :Ball{ "black", radius }
    {
    }

    Ball(std::string_view color = "black", double radius = 10.0)
        : m_color{color}
        , m_radius{radius}
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")" << std::endl;
    }

private:
    std::string m_color{};
    double m_radius{};
};

int main()
{
    /*Date date{ 19, 10, 2023 }; 
    printDate(date);

    Time time{ 11, 40, 25 };
    time.print();

    Gamer sherman{ "sherman", "god of war" };
    Gamer sherman2{ "sherman2", "spiderman" };
    sherman.playing(sherman2);

    IntPair p1{ 1, 2 };
    IntPair p2{ 3, 4 };

    std::cout << "p1: ";
    p1.print();

    std::cout << "p2: ";
    p2.print();

    std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
    std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

    Measurements m{};
    m.print();*/

    /*Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';*/

    /*Point3d point1{};
    point1.setValues(1, 2, 3);

    Point3d point2{};
    point2.setValues(1, 2, 3);

    std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

    Point3d point3{};
    point3.setValues(3, 4, 5);

    std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";*/

    BirthDate birthday{};
    birthday.print();
    birthday.setYear(2023);
    std::cout << "The year is: " << birthday.getYear() << std::endl;
    birthday.print();

    Foo foo{ 6, 7 };
    foo.print();

    /*Ball blue{ "blue", 10.0 };
    blue.print();

    Ball red{ "red", 12.0 };
    red.print();*/

    Foo2 foo2{};
    Foo2 foo21{ 6, 7 };

    Employee employee1{ "Sherman" };
    Employee employee2{ "Sherman", 1 };

    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}

