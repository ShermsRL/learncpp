#include <iostream>
#include <cassert> // for assert()
#include <random> // for std::mt19937
#include <chrono>
#include "constants.h"
#include "random.h"

// if statement is evaluated on runtime
void ifStatement()
{
    constexpr double gravity{ 9.8 };

    if (gravity == 9.8) // constexpr is always true
        std::cout << "Gravity is normal. \n";
    else
        std::cout << "We are not on Earth. \n";

    // evaluating constexpr conditional at runtime is wasteful!
}

void constexprIfStatement() // (C++17)
{
    constexpr double gravity{ 9.8 };

    if constexpr (gravity == 9.8) // require conditional to be expr
        std::cout << "Gravity is normal. \n";
    else
        std::cout << "We are not on earth. \n";

    // this will be evaluated at compile time
}

void switchCaseStatement(int x)
{
    switch (x) // x must be an integral value
    {
    case 1:
        std::cout << "One";
        break;
    case 2:
        std::cout << "Two";
        break;
    case 3:
        std::cout << "Three";
        break;
    default:
        std::cout << "Unknown";
        break;
    }
    std::cout << "Hello";

    // break statements can be changed to return if you want to return to the function that call it
    // otherwise, it will break out of the switch and execute hello

    // if there is no matching case or default case, only hello will be executed.

}

void intentionalFallthrough(int x)
{
    switch (x)
    {
    case 1:
        std::cout << "One" << '\n';
    case 2:
        std::cout << "Two" << '\n';
        [[fallthrough]]; // using a fallthrough attribute and null statement to indicate its intentional
    case 3:
        std::cout << "Three" << '\n';
        break;
    }
}

int calculate(int x, int y, char opr)
{
    switch (opr)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '%':
            return x % y;
        default:
            std::cout << "Error, no operator found." << '\n';
            return 0;
    }
}

// avoid goto statements (unless it provides better readability)
void gotoStatements()
{
    double x{};
tryAgain: // statement labels
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
        goto tryAgain; // goto where the statement that is identified via the statement labels
}

void whileLoopQ1()
{
    char alphabet{ 'a' };
    while (alphabet <= 'z')
    {
        std::cout << alphabet << ' ' << static_cast<int>(alphabet) << '\n';
        ++alphabet;
    }
}

void whileLoopQ2()
{
    int outer{ 1 };
    while (outer <= 5)
    {
        int inner{ 5 };
        while (inner >= outer)
        {
            std::cout << inner - outer + 1 << ' ';
            --inner;
        }

        std::cout << '\n';
        ++outer;
    }
}

void whileLoopQ3()
{
    int outer{ 1 };
    while (outer <= 5)
    {
        int count{ 5 - outer };
        int inner{ 5 - count };
        while (count >= 1)
        {
            std::cout << 'x' << ' ';
            --count;
        }

        while (inner >= 1)
        {
            std::cout << inner << ' ';
            --inner;
        }

        std::cout << '\n';
        ++outer;
    }
}

void doWhileLoops() //favor while loops over do-while when given an equal choice
{
    int selection{};

    do
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    } 
    while (selection != 1 && selection != 2 &&
        selection != 3 && selection != 4);

    std::cout << "You selected option #" << selection << '\n';
}

void forLoops()
{
    // once condition of for loops evaluates to false, it will exit
    for (int i{ 0 }; i <= 10; i+=2) // increments can be modified
    {
        std::cout << i << '\n';
    }

    // you can omit any or all of the statements/expressions
    /*int i{ 0 };
    for (; i <= 10; )
    {
        std::cout << i << ' ';
        ++i;
    }*/

    // for loops with multiple counters
    for (int i{ 0 }, y{ 10 }; i <= 10; ++i, --y)
    {
        std::cout << i << ' ' << y << '\n';
    }

    //prefer for loops when there is a obvious loop variable
}

void forLoopsQ1()
{
    for (int i{ 0 }; i <= 20; i += 2)
    {
        std::cout << i << ' ';
    }
}

void sumTo(int value) //for loops Q2
{
    int total{ 0 };
    for (int i{ 0 }; i <= value; ++i)
    {
        total += i;
    }
    std::cout << total;
}

void fizzbuzz(int count) //for loops Q3
{
    
    for (int i{ 1 }; i <= count; ++i)
    {
        bool printed{ false };
        if (i % 3 == 0)
        {
            std::cout << "fizz";
            printed = true;
        }

        if (i % 5 == 0)
        {
            std::cout << "buzz";
            printed = true;
        }

        if (i % 7 == 0)
        {
            std::cout << "pop";
            printed = true;
        }
            
        if (!printed)
            std::cout << i;
        
        std::cout << '\n';
    }
}

// if expression evaluates to true, does nothing, if false, it will terminate via std::abort and display error message
int assertions(int x, int y)
{
    // making assert statements more descriptive using string literals
    assert(y > 0 && "Cannot divide by 0"); 
    return x / y;

    // assert is checked at run time
}

void staticAssert()
{
    // static assert is checked at compile time
    // syntax = static_assert(condition, diagnostic message)
    // static_assert(sizeof(long) == 8, "long must be 8 bytes");
    // since it is evaluated at compile time, condition must be a const expr
}

void PRNG()
{
    // for most application, use mersenne twister
    // if you require highest quality random results: use 3rd party library
    // Xoshiro family and Wyrand for non-cryptographic 
    // Chacha family for cryptographic 
}

void usingMersenneTwister()
{
    std::mt19937 mt{};

    for (int count{ 1 }; count <= 40; ++count)
    {
        std::cout << mt() << '\t';

        if (count % 5 == 0)
            std::cout << '\n';
    }
}

void diceWithMersenneTwister() // this will output the same result everytime 
{
    std::mt19937 mt{};

    std::uniform_int_distribution die6{ 1, 6 };

    for (int count{ 1 }; count <= 40; ++count)
    {
        std::cout << die6(mt) << '\t';

        if (count % 10 == 0)
            std::cout << '\n';
    }
}

void seedingWithClock()
{
    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };

    std::uniform_int_distribution die6{ 1, 6 };

    for (int count{ 1 }; count <= 40; ++count)
    {
        std::cout << die6(mt) << '\t';

        if (count % 10 == 0)
            std::cout << '\n';

    }
}

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen{ myConstants::gravity * seconds * seconds / 2 };
    double heightNow{ initialHeight - distanceFallen };

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight, int time)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << '\n';
}

void summaryQ1()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight{};
    std::cin >> initialHeight;

    for (int time{ 0 };; ++time)
    {
        if (calculateHeight(initialHeight, time) == 0.0)
        {
            std::cout << "At " << time << " seconds, the ball reach the ground";
            break;
        }
        else
            calculateAndPrintHeight(initialHeight, time);
    }
}

bool isPrime(int x)
{
    if (x == 1)
        return false;

    for (int divisor{ 1 }; divisor <= 3; ++divisor)
    {
        if (divisor != 1 && divisor != x && x % divisor == 0)
            return false;
    }
    return true;
}

void isPrimeChecker()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";
}

int getUserNumber()
{
    /*int userNumber{};
    std::cin >> userNumber;
    return userNumber;*/

    while (true) // loop until user enters valid input
    {
        int userNumber{};
        std::cin >> userNumber;

        if (std::cin.fail()) // did the extraction fail?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input
            std::cout << "That is not a valid input, please enter again: ";
            continue; // and try again
        }

        if (userNumber < 1 || userNumber > 100)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return userNumber;
    }
}

char getUserPlayAgain()
{
    char userPlayAgain{};
    while (userPlayAgain != 'n' && userPlayAgain != 'y')
    {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> userPlayAgain;
    }
    return userPlayAgain;
}

void highLowGame()
{
    bool playAgain{ true };
    while(playAgain)
    { 
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << '\n';
        int number{ Random::get(1, 100) };
        for (int guessCount{ 1 }; guessCount <= 7; ++guessCount)
        {
            std::cout << "Guess #" << guessCount << ": ";
            int userNumber{ getUserNumber() };
            if (userNumber == number)
            {
                std::cout << "Correct! You Win!" << '\n';
                break;
            }
            else if (userNumber > number)
                std::cout << "Your guess is too high." << '\n';
            else if (userNumber < number)
                std::cout << "Your guess is too low." << '\n';

            if (guessCount == 7 && userNumber != number)
            {
                std::cout << "Sorry, you lose. The correct number was " << number << '\n';
            }
        }
        char userPlayAgain{ getUserPlayAgain() };
        if (userPlayAgain == 'y')
            playAgain = true;
        else
            playAgain = false;
    }
}

int main()
{
    highLowGame();
    return 0;
}