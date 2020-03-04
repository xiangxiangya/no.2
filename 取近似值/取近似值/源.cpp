#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#if 0
#include<iostream>
using namespace std;
int main()
{
	float c = 0;
	cin >> c;
	cout << int(c+0.5);//利用强制类型转化，强转的规则是直接去掉小数部分，若小数部分>=5则加上0.5到下一个数字
	system("pause");
	return 0;
}
#endif


#if 0
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int num = 0;
	int index = 0;
	int value = 0;
	vector<int> v;
	v.reserve(100);
	while (cin >> num&&cin >> index >> value)
	{
		int i = 0;
		while (i<num)
		{
			v[index] = value+;
			i++;
		}
		auto it = v.begin();
		while (it != v.end())
		{
			cout << *it << " " << endl;
			it++;
		}
		v.clear();
}
	return 0;
}
#endif


#if 0
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
	vector<int> v;
	int num = 0;
	while (cin >> num)
	{
		while (num)
		{
			if (find(v.begin(), v.end(), num % 10)==v.end())
			{
				v.push_back(num % 10);
			}
			num = num / 10;
		}
		auto it = v.begin();
		while (it != v.end())
		{
			cout << *it;
			it++;
		}
		cout << endl;
		v.clear();
	}
	return 0;
}
#endif

#if 0

#include<iostream>
using namespace std;
#include<string>
int main()
{
	string s;
	string s2;
	int sum = 0;
	while (getline(cin, s))
	{
		while (!s.empty())
		{
			if (s.front() == '\n')
			{
				break;
			}
			else if (s2.find(s.front()) == -1)
			{
				s2.push_back(s.front());
				sum++;
			}
			s.erase(0,1);
		}
		cout << sum << endl;
		s.clear();
	}
	return 0;
}
#endif


#if 0
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
int main()
{
	string s;
	while (getline(cin, s))
	{
		int num = 0;
		int i = 0;
		reverse(s.begin(), s.end());
		auto f = s.begin();
		auto b = s.begin();
		while (b != s.end())
		{
			if (*b == ' ' || *b == '\n')
			{
				reverse(f, b);
				b++; f = b;
			}
			b++;
		}// 当*b == s.end()时退出循环，此时最后一个单词并未完成逆置

		reverse(f, b);



		auto it = s.begin();
		while (it != s.end())
		{
			cout << *it;
			it++;
		}
		cout << endl;
		s.clear();
	}
	return 0;
}
#endif




#include<vector>


struct ListNode {
	int val;
	struct ListNode *next;
};



/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
#include<stack>
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head)
	{
		vector<int> v;
		ListNode * cur = head;
		stack<ListNode *> s;
		while (cur != nullptr)
		{
			s.push(cur);
		}
		while (!s.empty())
		{
			v.push_back(s.top()->val);
			s.pop();
		}
		return v;
	}
};


int main()
{
	ListNode
	return 0;
}









