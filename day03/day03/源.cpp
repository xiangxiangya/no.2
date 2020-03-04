#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string s1;
	while (getline(cin, s1))
	{
		int newlen = 0;//统计数字字符的长度
		int max=0;//数字字符的最大长度
		auto start = s1.begin();
		auto finish = s1.begin();
		string s2;
		while (start != s1.end()&&finish!=s1.end())
		{
			if (*start >= '0'&&*start <= '9')
			{
				newlen = 0;
				finish = start;
				while (finish != s1.end() && *finish >= '0'&&*finish <= '9'&&finish != s1.end())
					//算出从当前位置起连续数字的最大值
				{
					finish++;
					newlen++;
				}
				if (newlen > max)//如果比之前的最大值大则替换
				{
					s2.clear();
					while (start != finish)
					{
						s2.push_back(*start);
						start++;
					}
					max = newlen;
				}
				else//没之前的大就让start继续往后走
				{
					start++;
				}
			}
			else
			{
				start++;
			}
		}
		cout << s2 << endl;
		s1.clear();
		s2.clear();
	}
	system("pause");
	return 0;
}



#if 0
#include<vector>

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		int size = numbers.size();
		int arr[500] = { 0 };
		int i = 0;
		for (i = 0; i < numbers.size(); i++)
		{
			arr[numbers[i]]++;
		}
		for (i = 0;i< size; i++)
		{
			if (arr[numbers[i]] > (size / 2))
			{
				return numbers[i];
			}
		}
			return 0;
		
	}
};


int main()
{
	Solution s;
	//vector<int> v{ 1, 2, 3, 2, 2, 2, 5, 4,2 };
	vector<int> v{ 1, 2, 3, 2, 4, 2, 5, 2, 3 };
	int num=s.MoreThanHalfNum_Solution(v);
	cout << num << endl;
	system("pause");
	return 0;
}

#endif