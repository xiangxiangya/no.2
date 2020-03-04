//#define _CRT_SECURE_NO_WARNINGS 1
//#include<string>
//#include<iostream>
//using namespace std;
//int main()
//{
//	string S;
//	int num = 0;
//	char c;
//	while (getline(cin, S) && cin >> c)
//	{
//		int i = 0;
//		int j = 0;
//		if (c >= 'a' || c <= 'z')
//		{
//			while (i<S.size())
//			{
//
//				if (S[j] == c || S[j] == toupper(c))//c是小写
//				{
//					num++;
//				}
//				i++;
//				j++;
//			}
//		}
//		else
//		{
//			while (i<S.size())
//			{
//
//				if (S[j] == c || S[j] == tolower(c))//c是大写
//				{
//					num++;
//				}
//				i++;
//				j++;
//			}
//		}
//		cout << num << endl;
//		S.clear();
//	}
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
using namespace std;
int main()
{
	char c = 'a';
	int b = islower(c);
	cout << b;
	system("pause");
	return 0;
}
