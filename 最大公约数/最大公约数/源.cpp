#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int  fun(int a, int b)
{
	//return b == 0 ? a : fun(b, a%b);
	if (b == 0)
	{
		return a;
	}
	else
	{
		return fun(b, a%b);
	}
}
int main()
{
	int a = 12;
	int b = 13;
	int c=fun(a, b);
	cout << c << endl;
	system("pause");
	return 0;
}