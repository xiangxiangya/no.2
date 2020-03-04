#define _CRT_SECURE_NO_WARNINGS 1
 #include<iostream>
 using namespace std;
 #include<stack>
#include<vector>
 int main()//用STL中的stack容器，不会有栈满的情况
{
 stack<int> s;
 int num;
 while (cin >> num)
 {
	 if (num != -1)
	 {
		 s.push(num);
	 }
	 else
	 {
		 cout << s.top();
		 s.pop();
	 }
 }
 return 0;
}

