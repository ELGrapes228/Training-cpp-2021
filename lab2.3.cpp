#include <iostream>
#include <vector>
#include <algorithm>

void output(std::vector<int>& abc)
{
    std::for_each(abc.begin(), abc.end(), [](int i) { std::cout << i << std::endl; });
}


void FibonacciCont(float n, float k, std::vector<int>& abc)    //дозаполняет вектор числами Фибоначчи
{
    for (int i = n - k; i < n; i++)
    {
        abc.push_back(abc[i - 1] + abc[i - 2]);
    }
}

void FibonacciBegin(float n, std::vector<int>& abc)    //заполняет вектор начальными числами Фибоначчи
{
    abc.push_back(0);
    abc.push_back(1);
    FibonacciCont(n, n - 2, abc);
}

int main()
{
    float n = 9;
    float k = 4;
    std::vector<int> abc;
    FibonacciBegin(n, abc);
    output(abc);
    std::cout << std::endl;
    std::vector<int> abc2;
    std::for_each(abc.begin() + k, abc.end(), [&abc2](int i) { abc2.push_back(i); });
    output(abc2);
    std::cout << std::endl;
    FibonacciCont(n, k, abc2);
    output(abc2);
}