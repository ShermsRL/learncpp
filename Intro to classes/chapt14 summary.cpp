#include <iostream>
#include <cmath>

class Point2d
{
public:
    Point2d() = default;

    Point2d(double x, double y)
        : m_x{x}
        , m_y{y}
    {
    }

    void print()
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")" << std::endl;
    }

    double distanceTo(const Point2d& point)
    {
        return std::sqrt((m_x - point.m_x)*(m_x - point.m_x) + (m_y - point.m_y)*(m_y - point.m_y));
    }
    

private:
    double m_x{ 0.0 };
    double m_y{ 0.0 };
};

class Fraction
{
public:

    explicit Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{numerator}
        , m_denominator{denominator}
    {
    }

    void getFraction()
    {
        std::cout << "Enter a value for numerator: ";
        std::cin >> m_numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> m_denominator;
    }

    Fraction multiply(const Fraction& f)
    {
        return Fraction{ m_numerator * f.m_numerator, m_denominator * f.m_denominator };
    }

    void printFraction()
    {
        std::cout << m_numerator << "/" << m_denominator << std::endl;
    }

private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << std::endl;

    Fraction f1{};
    f1.getFraction();
    Fraction f2{};
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";
    f1.multiply(f2).printFraction();
    
    return 0;
}
