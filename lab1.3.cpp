//работа с конструкторами:
//задать векторы разными конструкторами, один отсортировать, а втором найти модульное произведение элементов после последнего максимального элемента
#include <iostream>

class Vector
{
private:
    int chisla[10];
public:
	Vector()
	{
		std::cout << "Constructor without parameters" << std::endl;
	}
	Vector(int x)
	{
		chisla[0] = x;
		chisla[1] = 2;
		chisla[2] = 1;
		chisla[3] = 76;
		chisla[4] = 123;
		chisla[5] = 13;
		chisla[6] = 8;
		chisla[7] = 123;
		chisla[8] = 3;
		chisla[9] = 29;
		std::cout << "Constructor No. 2" << std::endl;
	}
	void sort()	//сортировка
	{
		int copy;
		for (int i = 0; i < 10 - 1; i++)
		{
			for (int j = 0; j < 10 - 1; j++)
			{
				if (chisla[j] > chisla[j + 1])
				{
					copy = chisla[j];
					chisla[j] = chisla[j + 1];
					chisla[j + 1] = copy;
				};
			}
		}
	};
	int task17()
	{
		int max = chisla[0];
		int ogo = 1;
		for (int i = 0; i < 10; i++)
		{
			if (chisla[i] >= max)
			{
				max = chisla[i];
				ogo = 1;
			}
			else
			{
				if (chisla[i] < 0)
					ogo = ogo * chisla[i] * (-1);
				else
					ogo = ogo * chisla[i];
			}/*
			std::cout << "max " << i << " is " << max << std::endl;
			std::cout << "ogo " << i << " is " << ogo << std::endl;*/
		}
		return ogo;
	}
	~Vector()
	{
		std::cout << "Memory has been cleaned. Good bye." << std::endl;
	}
	int get_chislo(int i)
	{
		return chisla[i];
	}
	void set_vector(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
	{
		chisla[0] = a;
		chisla[1] = b;
		chisla[2] = c;
		chisla[3] = d;
		chisla[4] = e;
		chisla[5] = f;
		chisla[6] = g;
		chisla[7] = h;
		chisla[8] = i;
		chisla[9] = j;
	};
	void get_vector()
	{
		int i;
		//std::cout << "----------------------------------------" << std::endl;
		for (i = 0; i < 10; i++)
		{
			if (i + 1 == 10)
				std::cout << chisla[i] << std::endl;
			else
				std::cout << chisla[i] << ", ";
		}
		//std::cout << "----------------------------------------" << std::endl;
		std::cout << std::endl;
	}
};

int main()
{
	Vector object1;
	object1.set_vector(2, 7, 16, 32, 8, 3, 1, 5, 10, 11);
	Vector object2 (19);
	object1.get_vector();
	object1.sort();
	object1.get_vector();
	object2.get_vector();
	std::cout << object2.task17();
	std::cout << std::endl;
	return 0;
}