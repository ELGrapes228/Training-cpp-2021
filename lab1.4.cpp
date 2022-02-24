#include <iostream>

class Massive	// дружественные функции, вариант 17: Определить количество строк, не содержащих ни одного нулевого элемента
{
private:
    int a;
    int b;
    int **ab;
public:
    Massive(int aa, int bb) : a(aa), b(bb)
    {
        ab = new int*[a];
        for (int i = 0; i < a; i++)
        {
            ab[i] = new int[b];
            for (int j = 0; j < b; j++)
            {
                std::cin >> ab[a][b];
                std::cout << std::endl;
            }
        }
    };
    ~Massive()
    {
        delete ab;
    };
    void output()
    {
        std::cout << std::endl;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                std::cout << ab[i][j] <<"\t";
            }
            std::cout << std::endl;
        }
    };
};


int main()
{
    Massive abc(2, 3);
    
}