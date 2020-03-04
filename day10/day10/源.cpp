#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>

#if 0
bool checkWon(vector<vector<int> > a) 
{ 
	if (a[0][2] + a[1][1] + a[2][0] == 3)
		return true;     

	if (a[0][0] + a[1][1] + a[2][2] == 3)
		return true;
	for (int i = 0; i<3; i++)
	{ 
		if (a[i][0] + a[i][1] + a[i][2] == 3)
			return true;     
		if (a[0][i] + a[1][i] + a[2][i] == 3) 
			return true;
	}       
	return false; 
}
int main(){
	vector<vector<int>> board{ { 1, 0, 1 }, { 1, -1, 1 }, { 1, -1, 0 } };
	b.checkWon(board);
	return 0;
}
#endif


#include<iostream>
using namespace std;
#include<string>
void Look_char(string & s, int & c)
{
	int i = 0;
	int count = 0;
	int small = 0;
	int big = 0;
	for (i = 0; i<s.size(); i++){
		if (s[i] >= 'a'&&s[i] <= 'z'){
			small++;
		}
		if (s[i] >= 'A'&&s[i] <= 'Z'){
			big++;
		}
	}
	if (big == 0 && small>0 || big >= 0&&small == 0){
		c = c + 10;
	}
	if (big>0 && small>0){
		c = c + 20;
	}
}

void Look_num(string &s, int & c)
{
	int i = 0;
	int count = 0;
	for (i = 0; i<s.size(); i++){
		if (s[i] >= '0'&&s[i] <= '9'){
			count++;
		}
	}
	if (count == 1){
		c += 10;
	}
	if (count >= 2){
		c += 20;
	}
}

void Look_price(string & s, int & c)
{
	int i = 0;
	int flag0 = 0;//Ð¡Ð´×ÖÄ¸
	int flag1 = 0;//´óÐ´×ÖÄ¸
	int flag2 = 0;//Êý×Ö
	int flag3 = 0;//·ûºÅ
	for (i = 0; i<s.size(); i++){
		if (s[i] >= 'a'&&s[i] <= 'z'){
			flag0 = 1;
		}
		if (s[i] >= 'A'&&s[i] <= 'Z'){
			flag1 = 1;
		}
		if (s[i] >= '0'&&s[i] <= '9'){
			flag2 = 1;
		}
		else{
			flag3 = 1;
		}
	}
	if (flag0&&flag1&&flag2&&flag3){
		c += 5;
		return;
	}
	if (flag2&&flag3 && (flag1 || flag0)){
		c += 3;
			return;
	}
	if (flag2 && (flag1 || flag0)){
		c += 2;
		return;
	}
}

void Look_F(string & s, int &c)
{
	int i = 0;
	int num = 0;
	for (i = 0; i < s.size(); i++){
		if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] - '0' >= 0 && s[i] - '0' <= 9))
		{
			num++;
		}
	}
	if (num == 0)  
		return; 
	else if (num == 1)
		c += 10;
	else
		c += 25;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		int cour = 0;
		int size = s.size();
		if (size <= 4){
			cour += 5;
		}
		if (size >= 5 && size <= 7){
			cour += 10;
		}
		if (size >= 8){
			cour += 25;
		}
		//Í³¼Æ×ÖÄ¸
		Look_char(s, cour);
		Look_num(s, cour);
		Look_F(s, cour);
		Look_price(s, cour);

		if (cour >= 90)
			cout << "VERY_SECURE" << endl;
		else if (cour >= 80)
			cout << "SECURE" << endl;
		else if (cour >= 70)
			cout << "VERY_STRONG" << endl;
		else if (cour >= 60)
			cout << "STRONG" << endl;
		else if (cour >= 50)
			cout << "AVERAGE" << endl;
		else if (cour >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}