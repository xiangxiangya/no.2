#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.hpp"

int main()
{
	std::vector<int> v = { 8, 5, 2, 6, 9, 3, 1, 4, 0, 7 };
	SelectSort::selectSort(v);
	for (auto&e : v){
		std::cout << e << " ";
	}
	system("pause");
	return 0;
}