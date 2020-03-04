#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

#if 0
bool Is_true(int num)
{
	int i = 1;
	int sum = 0;
	while (i < num){
		if (num%i == 0){
			sum += i;
		}
		i++;
	}
	if (sum == num){
		return true;
	}
	return false;
}
int main()
{
	int n = 0;
	
	while (cin >> n)
	{
		int count = 0;
		int i = 0;
		for (i = 1; i < n; ++i){
			if (Is_true(i)){
				count++;
			}
		}
		cout <<count<<endl;
	}
	system("pause");
	return 0;
}
#endif


#if 0

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> split(string str);
int main()
{
	string a;
	while (getline(cin, a))
	{
		int pos = a.find_first_of("-");
		vector<int> left_one = split(a.substr(0, pos));
		vector<int> right_one = split(a.substr(pos + 1));
		if (left_one[0] == 13 && left_one[1] == 2)          //左边对王 
			cout << a.substr(0, pos) << endl;               //输出左边   
		else if (right_one[0] == 13 && right_one[1] == 2)   //右边对王  
			cout << a.substr(pos + 1) << endl;              //输出右边 
		else if (left_one[1] == 4 && right_one[1] != 4)     //左边炸弹，右边不是    
			cout << a.substr(0, pos) << endl;               //输出左边    
		else if (right_one[1] == 4 && left_one[1] != 4)     //右边炸弹，左边不是 
			cout << a.substr(pos + 1) << endl;              //输出右边      
		else if (left_one[1] == right_one[1])               //其他情况  
		if (left_one[0] > right_one[0])
			cout << a.substr(0, pos) << endl;
		else
			cout << a.substr(pos + 1) << endl;
		else
			cout << "ERROR" << endl;
	}
	return 0;
}
vector<int> split(string str)
{
	vector<string> table = { "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "joker", "JOKER" };
	vector<int>  poker(2, 0);
	//第一位存牌的大小，第二位存牌个数  
	int pos = str.find_first_of(" ");
	if (pos != -1)
	{
		string temp = str.substr(0, pos);
		if (temp == "10"&&str.substr(pos + 1, 2) != "10")
			//因为只有除了大小王以外只有10是两位，      
			poker[1] = 5;
		//当第一张是10，第二张不是的时候，一定是顺子  
		else
			poker[1] = (str.size() + 1) / (temp.size() + 1);
		//其他情况可以统一计算牌的个数。即使是第一张牌不为10，中间有10的顺子，只多了一张牌，除数为2，因此，不会出错    
		poker[0] = find(table.begin(), table.end(), temp) - table.begin();
	}
	else
	{
		poker[1] = 1;
		poker[0] = find(table.begin(), table.end(), str) - table.begin();
	}
	return poker;
}

#endif

#if 0
int main()
{
#if 0
	char a[14] = "abcd";
	char b[5];
	b ="abcd";
#endif
	int i = 3;
	printf("%d %d", ++i, ++i);
	system("pause");
	return 0;
}
#endif


#if 0
void print(char *s)
{
	if (*s)
	{
		print(++s);
		printf("%c", *s);
	}
}

int main()
{ 
	char str[] = "Geneius";
	print(str);
}

#endif

#if 0

class A 
{
public: 
	void FuncA() { printf("FuncA called\n"); }
	virtual void FuncB() { printf("FuncB called\n"); }
};
class B : public A 
{ 
public:
	void FuncA()
	{
		A::FuncA();
		printf("FuncAB called\n");
	}
	virtual void FuncB()	
	{ printf("FuncBB called\n"); }
};
void main(void)
{
	B b; 
	A *pa = &b;
	A *pa2 = new A;
	pa->FuncA();
	pa->FuncB();
	delete pa2;
}
#endif


int main()
{
	string line;
	while (getline(cin, line))
	{
		if (line.find("joker JOKER") != -1){
			cout << "joker JOKER" << endl;
			break;
		}
		int pos = line.find('-');
		//分成两手牌
		string car1 = line.substr(0, pos);
		string car2 = line.substr(pos + 1);
		//获取空格的次数，牌数为空格数+1
		int c1 = count(car1.begin(), car1.end(), ' ');
		int c2 = count(car2.begin(), car2.end(), ' ');
		//取到第一张牌
		string first1 = car1.substr(0, car1.find(' '));
		string first2 = car2.substr(0, car2.find(' '));
		string str = "345678910JQKA2jokerJOKER";
		//牌数相等，则直接比较第一个的大小
		if (c1 == c2){
			if (str.find(first1) > str.find(first2)){
				cout << car1 << endl;
			}
			else
			{
				cout << car2 << endl;
			}	
		}
		//牌数不相等，则说明类型不同，只有炸弹可以其他牌比较，否则就是错误的
		else{
			if (c1 == 3)
				cout << car1 << endl;
			else if (c2 == 3){
				cout << car2 << endl;
			}
			else{
				cout << "ERROR" << endl;
			}
		}
	}
	system("pause");
	return 0;
}