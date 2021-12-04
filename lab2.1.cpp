//Создать лямбда-выражение для вывода элементов вектора.
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n = 10;
	std::vector<int> abc;
    Fibonacci(n, abc);
    std::transform(abc.begin(), abc.end(), abc.begin(), [](int i) { return i = rand() % 1000 + 1; });
    std::for_each(abc.begin(), abc.end(), [](int i) { std::cout << i << std::endl; });
}