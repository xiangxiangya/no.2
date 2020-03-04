#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


void Qsort(vector<int> & v, int low, int high)
{
	int i = low;
	int j = high;
	if (i > j){
		return;
	}
	int tmp = v[low];//÷– ‡÷µ
	while (i != j){
		while (v[i] <= tmp&&i < j){
			i++;
		}
		while (v[j] >= tmp&&i < j){
			j--;
		}
		if (i < j){
			swap(v[i], v[j]);
		}
		swap(v[low], v[i]);
		Qsort(v, low, j - 1);
		Qsort(v, j + 1, high);
		}
}


int main()
{
	vector<int> v = { 1, 3, 7, 5, 9, 4, 6, 2, 0 };
	//sort(v.begin(), v.end());
	//int arr[] = { 1, 2, 3, 4, 5 };
	//cout << sizeof(arr) / sizeof(arr[0]) << endl;
	Qsort(v, 0,v.size()-1);
	auto  it = v.begin();
	while(it!=v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	system("pause");
	return 0;

}


#if 0
int index = 5;
int start = 0;
int end = 8;
int small = start - 1;
swap(v[index], v[end]);
for (index = start; index < end; ++index){
	if (v[index] < v[end]){
		++small;
		if (small != index)
			swap(v[index], v[small]);
	}
}
++small;
swap(v[small], v[end]);

#endif


