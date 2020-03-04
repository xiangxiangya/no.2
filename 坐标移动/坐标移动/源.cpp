#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

#if 1

int main()
{
	
	string s;
	while (getline(cin, s))
	{
		int left = 0;
		int right = 0;
		int num = 0;
		auto first = s.begin();
		auto last = s.begin();
		while (last != s.end())
		{
			
			if (*last == ';')
			{
				if ((*first == 'A' || *first == 'D' || *first == 'W' || *first == 'S') && \
					*(first + 1) >= '0'&&*(first + 1) <= '9'&&*(first + 2) >= '0'&&*(first + 2) <= '9' && (first + 3) == last)
				{
					switch (*first)
					{
					case'A':
						left = left - (*(first + 1) - 48) * 10 - (*(first + 2) - 48);
						break;
					case'D':
						left = left + (*(first + 1) - 48) * 10 + (*(first + 2) - 48);
						break;
					case'W':
						right = right + (*(first + 1) - 48) * 10 + (*(first + 2) - 48);
						break;
					case'S':
						right = right - (*(first + 1) - 48) * 10 - (*(first + 2) - 48);
						break;
					}
				}
				else
				if ((*first == 'A' || *first == 'D' || *first == 'W' || *first == 'S') && *(first + 1) >= '0'&&*(first + 1) <= '9' && (first + 2) == last)
				{
					switch (*first)
					{
					case'A':
						left = left - (*(first + 1) - 48);
						break;
					case'D':
						left = left + (*(first + 1) - 48);
						break;
					case'W':
						right = right + (*(first + 1) - 48);
						break;
					case'S':
						right = right - (*(first + 1) - 48);
						break;
					}
				}
				last++;
				first = last;
			}
			else
				last++;
		}
		cout << left << ',' << right << endl;
		s.clear();
	}
	return 0;
	}
		
#endif