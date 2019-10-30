#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>

int main()
{
	string s1;
	s1.reserve(100);
	string s2;
	int i = 0;
	s2.reserve(100);
	while (cin >> s1)
	{

		for (i = 0; i < s1.size(); i++)
		{
			if (s2.find(s1[i]) == -1)
			{
				s2.push_back(s1[i]);
			}
		}
		auto it = s2.begin();
		while (it != s2.end())
		{
			cout << *it;
			it++;
		}
		cout << endl;
		s1.clear();
		s2.clear();
	}
	
	system("pause");
	return 0;
}