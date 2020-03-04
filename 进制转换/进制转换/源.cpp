#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	char str1[20] = { 0 };
	char str2[20] = { 0 };
	int len = 0;
	int i = 0;
	/*while (cin >> str2)
	{*/
	cin >> str1;
		len = strlen(str1);
		int num = 0;
		int j = 0;
		for (i = len, j; i >= 2; i--, j++)
		{
			if (str1[i] >=0 || str1[i] <= 9)
			{
				num = num + (str1[i] * pow(16, j));
			}
			else
			if (str1[i] >= 'A' || str1[i] <= 'F')
			{
				num = num + ((str1[i] - 55)* pow(16, j));
			}
		}
		_itoa(num, str2, 10);
		cout << str2;
	//}
		system("pause");
	return 0;
}

