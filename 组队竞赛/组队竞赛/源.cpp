#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
	int n = 0;
	vector <vector<int>> vv;
	
	while (cin >> n)
	{
		long long sum = 0;
		vv.resize(n);
		int j = 0;
		int i = 0;
		int tmp;
		for (i; i < n; i++)
		{
			vv[i].resize(3);
			for (j = 0; j < 3; j++)
			{
				cin >> tmp;
				vv[i][j] = tmp;
			}
		}
		for (i = 0; i < n; i++)
		{
			sort(vv[i].begin(), vv[i].end());
			sum = sum + vv[i][1];
		}
		cout << sum<<endl;
		vv.clear();
	}
	system("pause");
		return 0;
}