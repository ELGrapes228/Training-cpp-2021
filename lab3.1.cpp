//работа с векторами
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1, v2;
    v1 = { 1,2,8,4,3,9 };
    v2 = { 5,9,3,4,7,6 };
    for (int i = v2.size() / 2; i < v2.size(); i++)
    {
        v1.push_back(v2[i]);
    }
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i];
    }
}