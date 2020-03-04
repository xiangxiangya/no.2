#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
//int main()
//{
//	int n = 0;
//
//	string s;
//	while (cin >> n)
//	{
//		int i = 0;
//		while (i<n)
//		{
//			cin >> s;
//			i++;
//		}
//		auto first = s.begin();
//		auto last = s.end();
//		sort(first,last);
//		cout << s;
//	}
//	return 0;
//}


#include<iostream>
using namespace std;
#include<string>
int main()
{
	int flag[4] = { 0 };
	string str;
	while (getline(cin, str))
	{
		if (str.size()<8)
		{
			cout << "NG" << endl;
			continue;
		}

		for (int i = 0; i < str.size(); ++i)
		if (str[i] >= 'a' && str[i] <= 'z')
			flag[0] = 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			flag[1] = 1;
		else if (str[i] >= '0' && str[i] <= '9')
			flag[2] = 1;
		else flag[3] = 1;
		if (flag[0] + flag[1] + flag[2] + flag[3] < 3)
		{
			cout << "NG" << endl;
			continue;
		}

		for (int i = 0; i <= str.size() - 6; i++)
		for (int j = i + 3; j < str.size(); j++)
		if (str[i] == str[j] && str[i + 1] == str[j + 1] && str[i + 2] == str[j + 2])
		{
			cout << "NG" << endl;
			continue;
		}
		cout << "OK" << endl;
		continue;
	}
	return 0;
}