#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


int Division(int a, int b)
{
	if (b == 0){
		throw "Division error";
	}
	return a / b;
}

void Fun()
{
	int * arr= new int[10];
	try
	{
		int ret = Division(10, 0);
	}
	catch (...)
	{
		delete arr;
		throw;
	}
}


int main()
{
	try
	{
		Fun();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	system("pause");
	return 0;
}