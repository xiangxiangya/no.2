#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string.h>
#include<string>
#include<algorithm>

#if 0
int main()
{
	string s1;
	string s2;
	while (getline(cin, s1) && getline(cin, s2))
	{
		int i = 0;
		int count = 0;
		int size1 = s1.size();
		while (i<size1+1)
		{
			string s4(s1);
			s4.insert(i, s2);
			string s3(s4);
			reverse(s3.begin(), s3.end());
			if (s4.compare(s3)==0)
			{
				count++;
			}
			i++;
			s3.clear();
			s4.clear();
		}
		cout << count << endl;
		s1.clear();
		s2.clear();
	}
	return 0;
}
#endif



#if 0
#include<iostream>
using namespace std;
int main()
{
	int i=0;
	int j = 0;
	int k = 0;
	int max1 = 0;
	int max2 = 0;
	int tmp = 0;
	int c = 0;
	while (cin>>c)
	{
		int arr[] = { 0 };
		for (i = 0; i<c; i++)
		{
			cin >> arr[i];
		}
		for (j = 0; j <c; j++)
		{
			max1 = 0;
			for (k = j; k <c; k++)
			{
				tmp = max1 + arr[k];
				if (tmp < max1&&k!=0)
				{
					break;
				}
				max1 = tmp;
			}	
			if (max1 >= max2)
			{
				max2 = max1;
			}
		}
		cout << max2 << endl;
		max2 = 0;
	}
		system("pause");
		return 0;
}
#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int max1 = 0;
	int max2 = 0;
	int MAX = 0;
	int tmp = 0;
	int c = 0;
	vector<int> v;
	while (cin >> c)
	{
		int num = 0;
		for (i = 0; i < c; i++)
		{
			cin >> num;
			v.push_back(num);
		}
		for (j = 0; j <c; j++)
		{
			max1 = 0;
			for (k = j; k <c; k++)
			{
				tmp = max1 +v[k];
				if (tmp < max1&&k != 0)
				{
					break;
				}
				max1 = tmp;
			}
			if (max1 >= max2)
			{
				max2 = max1;
			}
		}
		cout << max2 << endl;
		max2 = 0;
		v.clear();
	}
	system("pause");
	return 0;
}
#endif
//-2 1 -3 4 -1 2 1 -5


#if 0
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int max = 0;
	int Max = 0;
	int num = 0;
	int n = 0;
	vector<int> v;
	while (cin >> n)
	{
		int i = 0;
		
		for (i = 0; i<n; i++){
			cin >> num;
			v.push_back(num);
		}
		for (i = 0; i<n; i++){
			if (max <= 0){
				max = v[i];
			}
			else{
				max += v[i];
			}
			if (max > Max){
				Max = max;
			}
		}
		cout << Max << endl;
		v.clear();
	}
	return 0;
}
#endif


int main()
{
	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz"; 
	//strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	strcat(p1 + 2, p2 + 1);
	printf("%s", str);
	system("pause");
	return 0;
}