#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
void fun(string & s,string & s3)
{
	int size1 = s.size();
	while (size1>8)//当大于八个时不需要添加0
	{
		s3.insert(s3.size(), s, 0, 8);//在s3.size()的位置插入s从位置0开始的8个字节
		s3.push_back('\n');//换行
		size1 -= 8;
		s.erase(0, 8);//把s前8个元素擦去
	}
	int newsize1 = s.size();
	s3.insert(s3.size(), s, 0, newsize1);//把s中剩余部分添加到s3中
	s3.insert(s3.size(), 8 - newsize1, '0');//s3中剩余部分用0补充
	s3.push_back('\n');
}


int main()
{
	string s1;
	string s2;
	string news;
	int i = 0;
	int pos = 0;
	while (cin >> s1&&cin >> s2)
	{
		fun(s1, news);
		fun(s2, news);
	}
	cout << news;
	system("pause");
	return 0;
}