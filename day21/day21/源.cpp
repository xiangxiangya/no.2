#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
#include<iostream>
#include<string>
using namespace std; 
int main()
{
	int num;//歌曲总数   
	string s;
	while(cin>>num>>s)
	{
		int pos=1;//光标初始位置    
		int start=1;//首信息   
		int len=s.length();
		for(int i=0;i<len;++i){
			if(s[i]=='U'){ 
				if(pos-start>0){ 
					pos-=1;    
				}
				else{
					start==1?(start=(num>3?num-3:1),pos=num):(start-=1,pos-=1); 
				}  
			}
			else if(s[i]=='D'){
				if(pos-start<3 && pos-start<num-1){
					pos+=1;  
				}
				else{
					(start+4>num || num<5)?(start=1,pos=1):(start+=1,pos+=1);
				}
			}
		}
		int count;
		if(num<5) count=num; 
		else count=4;
		cout<<start; 
		for(int i=1;i<count;++i){
			cout<<" "<<start+i;
		}
		cout<<endl;
		cout<<pos<<endl;
	}
	return 0;
}
#endif


#if 0
int main()
{
	int _music_num = 0;
	char com[] = "";
	while (cin >> _music_num&&cin >> com){
		int music[100] = { 0 };
		int i = 0;
		for (i = 0; i < _music_num; i++){
			music[i] = i + 1;
		}
		int lenofcom = strlen(com);
		for (int j = 0; j < lenofcom; j++){
			if (com[j] == 'U'){

			}
			else{

			}
		}
	}
	return 0;
}
#endif



#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
struct DataSet
{
	int n;
	int k;
	vector<int> data;
};
int main()
{    //接收数据    
	int zushu;
	cin>>zushu;
	vector<DataSet> buf;
	while(zushu){
		zushu--;   
		DataSet temp;
		cin>>temp.n;  
		cin>>temp.k;
		int s1 = 0;  
		int s2 = 0; 
		while(s1<temp.n*2){
			cin>>s2;   
			temp.data.push_back(s2);
			s1++;    
		}
		buf.push_back(temp); 
	}
	for(auto it = buf.begin();it != buf.end();++it){
		for(int i = 0;i<(*it).k;++i){
			int n = (*it).n;
			vector<int> temp1((*it).data.begin(),(*it).data.begin()+n);   
			vector<int> temp2((*it).data.begin()+n,(*it).data.end()); 
			for(int j = 0;j<n*2;j+=2){    
				(*it).data[j] = temp1[j/2];  
				(*it).data[j+1] = temp2[j/2];  
			}        
		}
	}
	for(auto it = buf.begin();it != buf.end();++it){
		int n = (*it).n;
		for(int i = 0;i<n*2-1;++i){   
			cout<<(*it).data[i]<<" "; 
		}
		cout<<(*it).data[n*2-1]<<endl;  
	}
	return 0;
}
