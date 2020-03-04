#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string s1;
	string s2;
	while (getline(cin, s1) && getline(cin, s2))
	{
		int size1 = s1.size();
		int size2 = s2.size();
		int i = 0;
		int j = 0;
		for (i = 0; i<size2; i++)
		{
			size1 = s1.size();
			for (j = 0; j<size1; j++)
			{
				if (s1[j] == s2[i])
				{
					s1.erase(j);
				}
			}
		}
		cout << s1 << endl;
		s1.clear();
		s2.clear();
	}
	return 0;
}