//контроль переполнения
#include <array>
#include <iostream>

void Fibonacci(int n, int arr[])    //заполняет массив числами Фибоначчи
{
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
};

void formula228(int n, int arr[])   //изменение элементов путём возведения в степень n и добавлением n
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = pow(arr[i], n) + n;
        if (arr[i] < 0)
            throw "The number is too big";
    }
};

void arrayOutput(int n, int arr[])	// функция вывода массива
{
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == n)
            std::cout << arr[i];
        else
            std::cout << arr[i] << ", ";
    }
};

int main()
{
    try
    {
        int n;
        std::cout << "Enter the number of elements: ";
        std::cin >> n;
        while (n <= 0)
        {
            std::cout << "Wrong data. Try again: ";
            std::cin >> n;

        }
        int* arr = new int[n];
        Fibonacci(n, arr);
        arrayOutput(n, arr);
        std::cout << std::endl;
        formula228(n, arr);
        arrayOutput(n, arr);
    }
    catch (const char* lopuh)
    {
        std::cout << lopuh;
    }
}