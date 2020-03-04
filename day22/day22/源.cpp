
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#if 0
int gcd(int a, int b)
{
	int r = 0;
	while (r = a%b){
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int _monsternum = 0;
	int _ablity = 0;
	while (cin >> _monsternum >> _ablity){
		vector<int> v;
		int tmp = 0;
		int i = 0;
		while (i<_monsternum)
		{
			cin >> tmp;
			v.push_back(tmp);
			i++;
		}
		for (i = 0; i < v.size(); ++i){
			if (v[i] <= _ablity){
				_ablity += v[i];
			}
			else{
				int num = gcd(_ablity, v[i]);
				_ablity += num;
			}
		}
		cout << _ablity << endl;
		_monsternum = 0;
		_ablity = 0;
		v.clear();
	}
	return 0;
}
#endif


#if 1
#include<iostream>
using namespace std;
#include<string>
#include<vector>
int fun(string &s,int arr[], int line)
{
	int i = 0;
	for (i = 0; i < line; ++i){
		if (arr[i] == 1){
			return i;
		}
	}
	return -1;
}
int main()
{
	string s;
	while (getline(cin, s))
	{
		int line = s.size();
		int i = 0;
		int arr[200] = { 0 };
		for (i = 0; i < line; ++i){
			arr[s[i]]++;
		}
		int pos = fun(s,arr, 200);
		if (pos == -1){
			cout << -1 << endl;
		}
		else{
			cout << arr[s[pos]] << endl;
		}
	}
	system("pause");
	return 0;
}
#endif

#include<string>
#include<vector>
int _main()
{
	string s;
	while (getline(cin, s)){
		vector<int>v;

	}
	system("pause");
	return 0;
}

