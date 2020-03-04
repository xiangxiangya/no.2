#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#include<vector>
int main()
{
  int arr[] = { 1, 3, 2, 5, 1, 7, 4, 5 };
  int i = 0;
  vector <int> v2(100,0);
  vector<int> v1(begin(arr),end(arr));//1,5
     while (i<v1.size())
      {
        v2[v1[i]]++;
        i++;
      }
     for (i = 0; i<v2.size(); i++)
      {
        if (v2[i] >= 2)
     {
       cout << i<<" ";
     }
      }
	 system("pause");
 return 0;
 }
