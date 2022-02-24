#include <iostream>

class Simple
{
public:
    Simple() {}
    operator bool() const 
    {
        return true;
    }
};

class SimpleExplicit
{
public:
    explicit SimpleExplicit() {}
    explicit operator bool() const
    {
        return true;
    }
};

int main()
{
    Simple bruh1();
    SimpleExplicit bruh2();


}