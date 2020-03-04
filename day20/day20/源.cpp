#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string.h>
int getCommonStrLength(char *pFirstStr, char *pSecondStr)
{
	int _max = 0;
	int count = 0;
	int small = strlen(pFirstStr);
	int big = strlen(pSecondStr);
	//pFirstStrÊÇ×î¶ÌµÄ
	if (big<small){
		char *tmp = pFirstStr;
		pFirstStr = pSecondStr;
		pSecondStr = pFirstStr;
		small = big;
	}
	char *start = pFirstStr;
	char *end = pFirstStr + small - 1;
	while (start != end)
	{
		char *str2 = pSecondStr;
		while (*str2 != '\0'){
			if (*start == *str2){
				count++;
				start++;
				if (count >= _max){
					_max = count;
				}
				continue;
			}

			start = pFirstStr;
			str2++;
		}
		for (int i = 1; i <= small; i++){
			start += i;
		}
	}
	return _max;
}
int main()
{
	char s1[] = "";
	char s2[] = "";
	while (cin >> s1 &&cin>> s2)
	{
		int num = 0;
		num = getCommonStrLength(s1, s2);
		cout << num << endl;
	}
	return 0;
}