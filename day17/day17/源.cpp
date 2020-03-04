#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>

#if 0
int main()
{
	vector<vector<int>> vv;
	int n=0;
	while(cin>>n)
	{
		int num=0;
		vv.resize(n);
		int i=0,j=0;
		while(i<n){
			vv[i].resize(n);
			i++;
		}
		vv[0][0]=1;
		//将数组vv完成初始化
		for(i=0;i<n;++i){
			vv[i][0]=1;
			vv[i][2*i-1]=1;
			for(j=0;j<n;++j){
				if(j==1){
					vv[i][j]=vv[i-1][j]+vv[i-1][j-1];
				}
				else{
					vv[i][j]=vv[i-1][j]+vv[i-1][j-1]+vv[i-1][j-2];
				}
			}
		}
		//找第一个出现的偶数
		int flag = 0;
		for (i = 0; i<vv[n].size(); ++i){
			if (vv[n - 1][i] % 2 == 0){
				cout << vv[n][i] << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			cout << -1 << endl;
		}
	}
	vv.clear();
	return 0;
}
#endif



#if 0

int main()
{
	int n = 0;

	while (cin >> n)
	{
		int arr[][1000000] = { 0 };
		int pos = 0;
		int i = 0;
		int j = 0;
		for (i = 0; i < n; ++i){
			arr[i][0] = 1;
			arr[i][2 * i + 1] = 1;
			for (j = 0; j < n; ++j){
				if (arr[i-1][j-1])
			}
		}
	}
	system("pause");
	return 0;
}
#endif

#if 0
class A {
public: A() { printf("A "); }~A() { printf("deA "); }
}; 
class B { public: B() { printf("B "); }~B() { printf("deB "); } }; 
class C : public A, public B {
public:
	C()
	{
		printf("C ");
	}
	~C()
	{ printf("deC "); } }; 
int main()
{
	A *a = new C();
	delete a;
	system("pause");
	return 0;
}
#endif



#if 0
#include<iostream>
using namespace std;
#include<vector>
int _main()
{
	int n = 0;
	while (cin >> n)
	{
		int tmp = 0;
		vector<int> v;
		int i = 0;
		while (i<n){
			cin >> tmp;
			v.push_back(tmp);
			++i;
		}
		int max = -100;
		int Max = 0;
		for (i = 0; i<n; ++i){
			if (v[i] + max<0){
				max = 0;
			}
			else{
				if (Max<max){
					Max = max;
				}
			}
		}
		cout << Max << endl;
		v.clear();
	}
	return 0;
}


int main()
{
	int 卧龙 = 10;
	printf("%d\n", 卧龙);
	system("pause");
	return 0;
}
#endif


#if 0
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string s1, s2;
	int pos = 0;
	while (getline(cin, s1) && getline(cin, s2)){
		for (int i = 0; i < s2.size(); ++i){
			for (int j = 0; j < s1.size(); ++j){
				pos = s1.find(s2[i]);
				if (pos != -1){
					s1.erase(pos, 1);
				}
			}
		}
		cout << s1 << endl;
		s1.clear();
		s2.clear();
	}
	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n = 0;
	int num;
	vector<int> v;
	while (cin >> n){
		int Max = 0;
		int max = 0;
		for (int i = 0; i < n; ++i){
			cin >> num;
			v.push_back(num);
		}
		//求连续数组的最大和
		for (int i = 0; i < v.size(); ++i){
			max = max + v[i];
			if (Max < max){
				Max = max;
			}
			if (max < 0){
				max = 0;
			}
		}
		if (Max >= 0){
			cout << Max << endl;
		}
		else{
			cout << v[0] << endl;
		}
		v.clear();
	}
	return 0;
}
#endif


#if 0
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int a1, a2, a3, a4;
	vector<int> v;
	while (cin >> a1 >> a2, a3, a4){
		v.push_back(a1);
		v.push_back(a2);
		v.push_back(a3);
		v.push_back(a4);
		//判断能否通过加减乘除构成24点

	}
	return 0;
}


#endif

#if 0
class Base
{
public:
	virtual void Func1(){
		
	}
};

class Dirvead:public Base
{
public:
	virtual void Fuc1()
	{
	}
};


int main()
{
	Base b;
	Dirvead d;
	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void Func1()
	{
		cout << "i am Base" << endl;
	}
	Base()
	{
		cout << "基类构造完毕\n" << endl;
	}
	virtual ~Base()
	{
		cout << "基类析构完毕\n" << endl;
	}
};

class Drived :public Base
{
public:
	void Func1()
	{
		cout << "i am Drived" << endl;
	}
	Drived()
	{
		cout << "子类构造结束\n" << endl;
	}
	~Drived()
	{
		cout << "子类析构结束\n" << endl;
	}
};


int main()
{
	Base * b = new Drived;
	(*b).Func1();
	delete b;
	return 0;
}
#endif

#include<iostream>
using namespace std;
#include<functional>
class Mine
{
public:
	class string{
	public:
		string(char * str)
			:_str(str)
		{

		}

		string(const string&  str){
			string tmp(str._str);
			swap(_str, tmp._str);
		}

	private:
		char *_str;
	};
};


int main()
{
	a b;
	b._a;
	return 0;
}