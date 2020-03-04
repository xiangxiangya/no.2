#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string s1;
	string s2;
	while (getline(cin, s1) && getline(cin, s2)){
		string Short(s1.size() < s2.size() ? s1 : s2);
		string Long(s1.size() > s2.size() ? s1 : s2);
		int i = 0;
		for (i = 0; i < Short.size(); ++i){
		}
	}
	system("pause");
	return 0;
}