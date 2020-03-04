#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void test1()
{
	FILE *fp = fopen("2222.txt", "rb");
	if (fp == nullptr){
		throw 1;
	}
}


int main()
{
	try
	{
		test1();
	}
	catch (int)
	{
		cout << "文件打开失败" << endl;
	}
	system("pause");
	return 0;
}