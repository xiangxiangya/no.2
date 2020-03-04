#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.hpp"

int main()
{
	std::vector<int> v = { 8, 5, 2, 6, 9, 3, 1, 4, 0, 7};
	//SelectSort::selectSort(v);
	//InsertSort::Insertsort(v);
	//ShellSort::Shellsort(v);
	//BubbleSort::Bubblesort(v);
	v=MergeSort::Mergesort(v, 0, 9);
	for (auto & e : v){
		std::cout << e << " ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}
