#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#if 0
int calStringDistance(string charA, string charB)
{
	string Short;
	string Long;
	//让charA作为长度较短的字符串
	if (charA.size() >= charB.size()){
		/*if (charA.compare(charB) == 0){
			return 0;
		}
		else {
			return -1;
		}*/
		Short = charB;
		Long = charA;
	}
	else{
		Short = charA;
		Long = charB;
	}

	int count = 0;
	auto startS = Short.begin();
	auto startL = Long.begin();
	while (startL!=Long.end()){
		if (*startL == *startS&&startS){
			startS++;
		}
		else{
			count++;
		}
		startL++;
	}
	if (startL == Long.end()){
		return count;
	}
	else{
		return -1;
	}
}
int main()
{
	string s1;
	string s2;
	while (getline(cin, s1) && getline(cin, s2)){
		int result = calStringDistance(s1, s2);
		cout << result << endl;
		s1.clear();
		s2.clear();
	}
    return 0;
}
#endif


#include<iostream>
using namespace std;
#include<vector>
void fun(vector<vector<int>> vv,int &i,int &j,int &m)
{
	while (i != m&&j != m){
		if (vv[i + 1][j] == 1){
			cout << '(' << i << ',' << j + 1 << ')' << endl;
			i++;
			j++;
		}
		else if (vv[i][j + 1] == 1){
			cout << '(' << i + 1 << ',' << j << ')' << endl;
			j++;
			i++;
		}
		else{
			fun(vv, i+1, j, m);
		}
	}
	return;
}
int main()
{
	vector<vector<int>> vv;
	int m = 0;
	int n = 0;
	while (cin >> m>>n){
		int tmp;
		int i = 0;
		int j = 0;
		vv.resize(m);
		for (i = 0; i<m; ++i){
			vv[i].resize(m);
			for (int j = 0; j<m; ++j){
				cin >> tmp;
				vv[i][j] = tmp;
			}
		}
		cout << "(0,0)" << endl;
		i = 0; j = 0;
		fun(vv, i, j,m);
	}
	return 0;
}
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0