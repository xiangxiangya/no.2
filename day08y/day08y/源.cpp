#define _CRT_SECURE_NO_WARNINGS 1

//DDBAB DADDB
#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#include<vector>
#if 0
int main()
{
	int i = 0;
	int n = 0;
	string s;
	vector<string> v;
	int flag1 = 1;//字典排序
	int flag2 = 1;
	while (cin >> n){
		v.reserve(2*n);
		for (i = 0; i<n; i++){
			cin >> s;
			v.push_back(s);
		}
		for (i = 0; i<n-1; i++){
			if (v[i].compare(v[i + 1]) >0){
				flag1 = 0;
				break;
			}
		}
		for (i = 0; i < n - 1; ++i){

			if (v[i].size()>v[i + 1].size()){
				flag2 = 0;
				break;
			}
		}
		if (flag1 == 1 && flag2 == 0){
			cout << "lexicographically" << endl;
		}
		else if (flag1 == 1 && flag2 == 1){
			cout << "both" << endl;
		}
		else if (flag1 == 0 && flag2 == 1){
			cout << "lengths" << endl;
		}
		else if (flag1 == 0 && flag2 == 0)
		{
			cout << "none" << endl;
		}
		s.clear();
	}
	return 0;
}
//string类中按照字典顺序比较大小可以直接用>和<比较

int _main()
{
	string s1 = "av";
	string s2 = "b";
	if (s2 > s1){
		cout << "yes" << endl;
	}
	system("pause");
	return 0;
}
#endif


#if 0
class A 
{
public:    
	A() :m_iVal(0){ test(); }   
	virtual void func() 
	{ cout << m_iVal << ' '; } 
	void test(){ func(); }
public:     
	int m_iVal; 
};
class B : public A
{ public:   
	B(){ test(); }  
	virtual void func()  
	{
		++m_iVal;      
		cout << m_iVal << ' ';
	}
}; 
int main(int argc, char* argv[]) 
{ A*p = new B;
p->test(); 
return 0; 
}
#endif

int gcd(int a, int b)
{
	int r;
	while (r = a%b){
		a = b; 
		b = r;
	}
	return b;
}
int main()
{
	int a = 0;
	int b = 0;
	while (cin >> a >> b){
		cout << a*b / (gcd(a, b));
	}
	system("pause");
	return 0;
}