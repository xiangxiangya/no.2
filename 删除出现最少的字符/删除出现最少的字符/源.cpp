#define _CRT_SECURE_NO_WARNINGS 1
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<char> v;
	string s;
	while (getline(cin, s))
	{
		v.resize(s.size()+1,0);
		int i = 0;
		for (i = 0; i < s.size(); i++)
		{
			v[s[i]];
		}
	}
	return 0;
}