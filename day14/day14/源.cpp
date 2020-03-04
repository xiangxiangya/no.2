#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

#if 0
 int getOutDay(int year, int month, int day)
{
	 int count = 0;
	 int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	 if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		 days[2] += 1;
	 }
	 if (month<1 || month>12){
		 return -1;
	 }
	 else if (day<1 || day>31){
		 return -1;
	 }
	 int i = 0;
	 for (i = 1; i < month; i++){
		 count = days[i] + count;
	 }
	 count += day;
	 return count;
}

int main()
{
	int year=0, month=0, day = 0;
	while (cin >> year>>month>> day){
		int count = 0;
		count = getOutDay(year, month,day);
		cout << count << endl;
	}
	system("pause");
	return 0;
}
#endif

#include<iostream>
using namespace std;
#include<vector>
bool Iscon(vector<int> v)
{
	int i = 0;
	int sum = 0;
	int pub = 1;
	for (i = 0; i<v.size(); i++){
		sum = sum + v[i];
		pub = pub*v[i];
	}
	if (sum == pub){
		return true;
	}
	else{
		return false;
	}
}
int main()
{
	int n = 0;
	vector<int> v;
	
	while (cin >> n){
		int i = 0;
		int tmp = 0;
		for (i = 0; i<n; i++){
			cin >> tmp;
			v.push_back(tmp);
		}
		int count = 0;
		int j = 0;
		int k = 0;
		for (j = 0; j < v.size(); j++){
			vector<int> tmp(v);
			tmp._Pop_back_n(j);
			if (Iscon(tmp)){
				count++;
			}
			tmp.clear();
		}
		v.clear();
		cout << count << endl;
	}
	return 0;
}