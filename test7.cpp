//работа над ошибками в тесте 7
#include <iostream>
#include <vector>
#include <algorithm>

/*template <typename C, typename V>

void wtfFunction(V v, V c)
{
	if (v == c)
	{
		std::cout << c;
	};
}

template <typename C, typename V>

void find_all(C& с, V v) 
{
	transform(C.begin(), C.end(), wtfFunction);
}*/

void output(int a)
{
	std::cout << a << "\t";
}

int transformer(int  b)
{
	b = b + 5;
	std::cout << b << "\t";
	return b;
}

int main()
{
	std::vector<int> data = { 1, 2, 4, 5, 5, 6 };
	auto lower = std::lower_bound(data.begin(), data.end(), 5);
	std::cout << *lower << " at index " << std::distance(data.begin(), lower) << std::endl;
	auto upper = std::upper_bound(data.begin(), data.end(), 5);
	std::cout << *upper << " at index " << std::distance(data.begin(), upper) << std::endl;
	std::for_each(data.begin(), data.end(),output);
	
	//осознание разницы между for_each и transform
	std::cout << std::endl << "for_each" << std::endl;
	std::for_each(data.begin(), data.end(), transformer);
	std::cout << std::endl;
	std::for_each(data.begin(), data.end(),output);

	std::cout << std::endl << "transform" << std::endl;
	std::transform(data.begin(), data.end(), data.begin(), transformer);
	std::cout << std::endl;
	std::for_each(data.begin(), data.end(),output);

	//find_all(data, 5);

}