#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include<iostream>
using namespace std;
#include<string>
#include<vector>

int main()
{
	string s;
	while (getline(cin, s))
	{
		int i = 0; int count = 0;
		vector<string> v;
		int j = 0;
		auto it = s.begin();
		for (i = 0; i < s.size(); i++){
			if (s[i] == ' ')count++;
			if (s[i] == '"'){
				for (j = i+1; s[j] != '"'; j++){

				}
				i =j;
			}
		}
		cout << count+1 << endl;
		auto start = s.begin();
		auto finish = s.begin();
		while (start != s.end()&&finish!=s.end()){
			if (*finish == ' '){
				while(start!=finish){
					cout << *start;
					start++;
				}
				finish++;
				start = finish;
				cout << endl;
				continue;
			}
			else if (*start == '"'){
				start++;
				finish++;
				while (*finish != '"'){
					finish++;
				}
				while (start != finish){
					cout << *start;
					start++;
				}
				finish++;
				start = finish;
				
				continue;
			}
			finish++;
		}
		while (start != finish){
			cout << *start;
			start++;
		}
	}
	system("pause");
	return 0;
}
#endif



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INT_MAX 100001
int main()
{    int n, m; 
while(cin >> n >> m) 
{     
	vector<int> dp(m + 1, INT_MAX);
	//dp[i]为在第i个石板时，所需要的步数，初始设为条件范围内的最大值     
	dp[n] = 0;
	for (int i = n; i <= m; i++)
	{  
		for (int j = 2; j*j <= i; j++) 
			//比如i为8，当找到i的一个约数j为2时，另一个约数就为i/j  
		{
			//所以只需要找j*j<=i,事实上如果不这样做，部分用例运行超时    
			if (i%j == 0)
			{  
				if (i + j <= m)  
					dp[i + j] = min(dp[i + j],dp[i]+1); 
				if(i+i/j<=m) //关键步骤      
					dp[i + i/j] = min(dp[i + i/j],dp[i]+1);   
			}
		}
	}
	if(dp[m]==INT_MAX)      
		cout<<"-1"<<endl;  
	else 
		cout<<dp[m]<<endl;
}
return 0;
}
