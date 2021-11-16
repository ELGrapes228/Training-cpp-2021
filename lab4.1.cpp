//работа с исключениями
#include <iostream>
#include <cassert>
#include <stdexcept>

class Fraction
{
public:
    Fraction(float a1, float b1) : a(a1), b(b1)
    {
        if (b == 0)
        {
           throw "Divisor cannot be 0!";
        };
    };
    ~Fraction()
    {
        std::cout << "Memory has been cleaned. Good bye." << std::endl;
    }
    float razdelim()
    {
        c = a / b;
        return c;
    }
    float razdelim2()
    {
        return a;
    }
private:
    float a, b, c;
};

float division(float a, float b)
{
    float c;
    c = a / b;
    return c;
};

int main()
{
    try
    {
        float a, b, c;
        std::cout << "Input dividend: ";
        std::cin >> a;
        std::cout << "Input divisor: ";
        std::cin >> b;
        assert((b != 0) && "Divisor cannot be 0!");
        c = division(a, b);
        std::cout << "The quotient is " << c << std::endl;
        Fraction division1(a, b);
        c = division1.razdelim();
        std::cout << "The quotient is " << c << std::endl;
    }
    catch (const char *lopuh)
    {
        std::cout << lopuh;
    }
}