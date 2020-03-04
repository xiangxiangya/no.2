#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

// DADBB ADDAD

#if 0
#include<vector>
#include<algorithm>
int main()
{
	int f1 = 0;
	int f2 = 1;
	int n = 0;
	int tmp = 0;
	int N = 0;
	int i = 0;
	vector<int> v;
	while (cin >> n){
		if (n == 0){
			cout<<0<<endl;
			break;
		}
		v.push_back(0);
		v.push_back(1);
		for (i = 2; i<70; i++){
			tmp = f1 + f2;
			v.push_back(tmp);
			f1 = f2;
			f2 = tmp;
		}
		v.push_back(n);
		sort(v.begin(), v.end());
		for (i = 0; i<v.size(); i++){
			if (v[i] == n)break;
		}
		v[i] - v[i - 1] >= v[i + 1] - v[i] ? N = v[i + 1] - v[i] : N = v[i] - v[i - 1];
		cout << N << endl;
		v.clear();
	}
	system("pause");
	return 0;
}
#endif


#include<stack>
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> s;
		int i = 0;
		auto it = A.begin();
		while (it != A.end()){
			if (*it == '(' || *it == ')'){
				if (*it == '('){
					s.push(*it);
				}
				else{
					if (!s.empty()){
						s.pop();
					}
					else{
						return false;
					}
				}
			}
			else{
				return false;
			}
			it++;
		}
		if (s.empty()){
			return true;
		}
		else{
			return false;
		}
	}
};