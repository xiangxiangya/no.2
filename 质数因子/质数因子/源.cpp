#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
int main()
{    
	long input; 
	while (cin >> input)  
{      
		while (input != 1)      
	{          
			for (int i = 2; i <= input; i++)     
		{           
				if (input % i == 0)   
			{                  
					input /= i;                 
					cout << i << ' ';            
			break;           
			}         
		}    
	}         
}             
		system("pause");
	return 0;
}
#endif




#if 0
#include<iostream>
using namespace std;
#include<string>
string getResult(long ulDataInput)
{
	string s;
	while (ulDataInput != 1)
	{
		for (int i = 2; i <= ulDataInput; i++)
		{
			if (ulDataInput%i == 0)
			{
				ulDataInput /= 2;
				s.push_back(i);
				s.push_back(' ');
				break;
			}
		}
	}
	return s;
}
	int main()
	{
		long ulDataInput;
		string s;
		while (cin >> ulDataInput)
		{
			s = getResult(ulDataInput);
			char arr[100];
			int i = 0;
			while (i < s.size())
			{
				arr[i] = s[i];
				i++;
			}
			arr[i + 1] = '\0';
			cout << atoi(arr);
		}
		system("pause");

		return 0;
	}
#endif