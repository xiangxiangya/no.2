#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
bool Isprime(int num)
{
	int i = 0;
	for (i = 2; i<num; i++){
		if (num%i == 0){
			return false;
		}
	}
	return true;
}

int main()
{
	int num = 0;
	int i = 0;
	while (cin >> num){
		int a = 0;
		int b = 0;
		if (num<2){
			return 1;
		}
		for (i = 1; i <= num / 2; i++){
			if (Isprime(i) && Isprime(num - i)){
				a = i;
				b = num - i;
			}
		}
		cout << a << endl;
		cout << b << endl;
	}
	return 0;
}
#endif


void fun(const int&v1, const int &v2)

{
	cout << v1 << endl;
	cout << v2 << endl;
}
int main()
{
	int test = 10;
	int a = 0;
	fun(++a, a++);
	system("pause");
	return 0;
}

#define SQR(A) A*A
int _main()
{
	int x = 6, y = 3, z = 2;
	x/=SQR(y + z) / SQR(y + z);
	cout << x << endl;
	system("pause");
	return 0;
}