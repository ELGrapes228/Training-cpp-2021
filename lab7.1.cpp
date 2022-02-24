#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <ctime>
//#include <stdlib.h>

void vectorOutput(int n, std::vector<int> abc)	// функция вывода
{
    std::cout << "----------------------------------------"  << std::endl;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == n)
            std::cout << abc[i] << std::endl;
        else
            std::cout << abc[i] << ", ";
    }
    std::cout << "----------------------------------------"  << std::endl;
};

void sortPogU(int n, std::vector<int> &abc)	//сортировка
{
    int copy;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (abc[j] > abc[j + 1])
            {
                copy = abc[j];
                abc[j] = abc[j + 1];
                abc[j + 1] = copy;
            };
        }
    }
//    vectorOutput(n, abc);
};

int bruh(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    std::vector<int> a;
    std::vector<int> ab;
    std::vector<int> abc;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        a.push_back(rand() % 100 + 1);
        if (i + 1 == n)
            std::cout << a[i] << std::endl;
        else
            std::cout << a[i] << ", ";
        ab.push_back(a[i]);
 //       abc.push_back(ab[i]);
    };
	
    vectorOutput(n, a);
	
	//auto start = std::chrono::system_clock::now();
    sortPogU(n, a);/*
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "speed1: " << elapsed_seconds.count() << " mks" << std::endl;
	
	auto start = std::chrono::system_clock::now();*/
	std::sort(ab.begin(), ab.end());/*
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "speed1: " << elapsed_seconds.count() << " mks" << std::endl;
	
	auto start = std::chrono::system_clock::now();
    qsort(&ab, n, sizeof(int), bruh);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "speed1: " << elapsed_seconds.count() << " mks" << std::endl;*/
    
	vectorOutput(n, a);
    vectorOutput(n, ab);
//    vectorOutput(n, abc);
}