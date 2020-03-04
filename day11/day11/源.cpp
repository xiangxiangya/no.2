#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<math.h>
#if 0
using namespace std;
int main()
{
	int sum = 0;
	int num = 0;
	while (cin >> num)
	{
		int _max = 0;
		while (num)
		{
			if (num & 1)
			{
				++sum;
				_max = max(sum, _max);
			}
			else{
				sum = 0;
			}
			num = num >> 1;
		}
		cout << _max << endl;
	}
	return 0;
}
#endif


#if 0
int foo(int n)
{
	if (n < 2)
	{
		return n;
	}
	else
	{
		return 2 * foo(n - 1) + foo(n - 2);
	}
}

int main()
{
	int n = foo(5);
	system("pause");
	return 0;
}
#endif


class A
{
	A()
	{
		
	}
};
int main()
{
	A(*ad)[3];
	return 0;
}