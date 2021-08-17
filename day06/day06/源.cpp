#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//CACCD CAADD


#if 0
class Solution {
public:    
	int StrToInt(string str) {
			   int n = str.size(), s = 1;   
			   long long res = 0;
			   if (!n) return 0;     
			   if (str[0] == '-') s = -1; 
			   for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < n; ++i)
			   {
				   if (!('0' <= str[i] && str[i] <= '9'))
					   return 0;     
				   res = (res << 1) + (res << 3) + (str[i] & 0xf);//res=res*10+str[i]-'0';     
			   }
			   return res * s;  
	}
};
#endif


#if 0




#include<math.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{

	int w = 0;
	int h = 0;
	int count = 0;
	while (cin >> w&&cin >> h)
	{
		int arr[1000][1000] = { 0 };
		int i = 0;
		int j = 0;
		for (i = 0; i < w; i++){
			for (j = 0; j < h; j++){
				if (arr[i][j] == 0){
					count++;
					if (i + 2<w){
						arr[i + 2][j] = -1;
					}
					if (j + 2<h){
						arr[i][j + 2] == -1;
					}
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}

#endif


class Solution
{
public:
	int StrToInt(string str)
	{
		if (str.empty())
			return 0;
		int symbol = 1;
		if (str[0] == '-') //处理负号  
		{
			symbol = -1;
			str[0] = '0'; //这里是字符'0',不是0     
		}
		else if (str[0] == '+') //处理正号      
		{
			symbol = 1;
			str[0] = '0';
		}           
		int sum = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return symbol * sum;
	}
};

