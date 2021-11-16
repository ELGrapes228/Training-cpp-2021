//работа с конструкторами
#include <iostream>

class Vector
{
private:
    int chisla[10];
public:
	Vector() : chisla{ 2, 7, 16, 32, 8, 3, 1, 5, 10, 11 }
	{
		std::cout << "Constructor without parameters" << std::endl;
	}
	Vector(int x)
	{
		chisla[10] = { 6, 2, 1, 76, 123, 13, 8, 9, 3, 29 };
		std::cout << "Constructor No. 2" << std::endl;
	}
	void sort()	//сортировка
	{
		int copy;
		for (int i = 0; i < 10 - 1; i++)
		{
			for (int j = 0; j < 10 - 1; j++)
			{
				if (chisla[j] < chisla[j + 1])
				{
					copy = chisla[j];
					chisla[j] = chisla[j + 1];
					chisla[j + 1] = copy;
				};
			}
		}
	};
	~Vector()
	{
		std::cout << "Memory has been cleaned. Good bye." << std::endl;
	}
	int get_chislo(int i)
	{
		return chisla[i];
	}
	void get_vector()
	{
		int i;
		for (i = 0; i < 10; i++)
		{
			std::cout << chisla[i] << std::endl;
		}
	}
};

int main()
{
	Vector object1;
	Vector object2 (2);
	object1.get_vector();
	std::cout << std::endl;
	object2.get_vector();
	return 0;
}