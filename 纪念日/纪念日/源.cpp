#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<time.h>
#include<Windows.h>


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		if (!(_year > 0 &&
			_month > 0 && _month < 13 &&
			_day > 0 && _day <= _GetDaysOfMonth(year, month)))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	// + 不会改变左右操作数中的内容--->只能按照值得方式返回
	// d + (-100)
	Date operator+(int days)
	{
		if (days < 0)
		{
			return *this - (0 - days);
		}

		Date temp(*this);
		temp._day += days;

		int daysofMonth = 0;
		// temp中的day已经大于本月的天数
		while (temp._day >(daysofMonth = temp._GetDaysOfMonth(temp._year, temp._month)))
		{
			temp._day -= daysofMonth;
			temp._month++;
			if (temp._month > 12)
			{
				temp._year++;
				temp._month = 1;
			}
		}

		return temp;
	}

	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}

		Date temp(*this);
		temp._day -= days;

		while (temp._day <= 0)
		{
			temp._month--;
			if (temp._month < 0)
			{
				temp._year -= 1;
				temp._month = 12;
			}

			temp._day += temp._GetDaysOfMonth(temp._year, temp._month);
		}

		return temp;
	}

	// min   max
	int operator-(const Date& d)
	{
		Date minDate(*this);
		Date maxDate(d);
		if (*this > d)
		{
			swap(minDate, maxDate);
		}

		size_t count = 0;
		while (minDate != maxDate)
		{
			count++;
			minDate++;
		}

		return count;
	}

	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}

	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}

	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		*this = *this - 1;
		return temp;
	}

	bool operator>(const Date& d)const
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

	bool operator==(const Date& d)const
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

	int _GetDaysOfMonth(int year, int month)
	{
		int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && IsLeapYear(year))
		{
			days[2] += 1;
		}

		return days[month];
	}

	bool IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year % 100) ||
			(0 == year % 400))
		{
			return true;
		}

		return false;
	}

	int _year;
	int _month;
	int _day;
};


void Show()
{
	cout << "******************************************************" << endl;
	cout << endl;
	cout << "***         1.纪念日                               ***" << endl;
	cout << endl;
	cout << "***         2.我想知道两个日期之间相隔多少天       ***" << endl;
	cout << endl;
	cout << "***         3.我想加一个天数看看是哪天             ***" << endl;
	cout << endl;
	cout << "***         4.我想减一个天数看看是哪天             ***" << endl;
	cout << endl;
	cout << "***         0.我不玩了                             ***" << endl;
	cout << endl;
	cout << "***                                      For Ly.   ***" << endl;
	cout << endl;
	cout << "******************************************************" << endl;
}

void Fun1()
{
	int i = 0;
	char buf[102] = { 0 };
	char str[] = "|/-\\";
	while (i <= 100){
		printf("[%-100s][%d%%][%c]\r", buf, i, str[i % 4]);
		//fflush(stdout);
		buf[i++] = '#';
		Sleep(68);
	}
	cout << "初次相识:2019-11-17" << endl<<endl;
	cout << "第一次牵手:2019-11-23" << endl << endl;
	cout << "两个有趣的灵魂在一起:2019-11-23" << endl<<endl; 
	cout << "第一次muaaaa:2019-11-30" << endl << endl;
	cout << "未完待续..." << endl;
}
	
int Fun2()
{
	Date d1;
	Date d2;
	cout << "请输入第一个日期，年月日间用空格隔开->";
	int year1 = 0; int month1 = 0; int day1 = 0;
	cin >> year1 >> month1 >> day1;
	d1._year = year1;
	d1._month = month1;
	d1._day = day1;
	cout << endl << "请输入第二个日期，年月日间用空格隔开->";
	int year2 = 0; int month2 = 0; int day2 = 0;
	cin >> year2 >> month2 >> day2;
	d2._year = year2;
	d2._month = month2;
	d2._day = day2;
	int ret = d2 - d1;
	return ret;
}
Date Fun3()
{
	Date d1;
	Date d2;
	cout << "请输入日期，年月日间用空格隔开->";
	int year1 = 0; int month1 = 0; int day1 = 0;
	cin >> year1 >> month1 >> day1;
	d1._year = year1;
	d1._month = month1;
	d1._day = day1;
	cout << "请输入一个天数" << endl;
	int day = 0;
	cin >> day;
	Date d3 = d1 + day;
	return d3;
}
Date Fun4()
{
	Date d1;
	cout << "请输入日期，年月日间用空格隔开->";
	int year1 = 0; int month1 = 0; int day1 = 0;
	cin >> year1 >> month1 >> day1;
	d1._year = year1;
	d1._month = month1;
	d1._day = day1;
	cout << "请输入一个天数" << endl;
	int day = 0;
	cin >> day;
	Date d3 = d1 - day;
	return d3;
}

int _main()
{
	while (1)
	{
		Show();
		cout << "请小梁同学选择功能->";
		int select = 0;
		int num = 3;
		int ret2 = 0;
		Date ret3;
		Date ret4;
		char str1[10000] = { 0 };
		cin >> select;
		switch (select)
		{
		case 1:
			Fun1();
			break;
		case 2:
			ret2=Fun2();
			cout <<"相差"<< ret2<<"天哦" << endl;
			break;
		case 3:
			ret3 = Fun3();
			cout << "未来的这一天是->";
			cout << ret3._year << "-" << ret3._month << "-" << ret3._day << endl;
			break;
		case 4:
			ret4 = Fun4();
			cout << "过去的这一天是->";
			cout << ret4._year << "-" << ret4._month << "-" << ret4._day << endl;
			break;
		case 0:
		cout << "请输入岳浩翔我爱你退出,否则后果自负哦" << endl;
	    loop:cin >> str1;
			if (strcmp(str1, "岳浩翔我爱你") == 0){
				return 0;
			}
			else
			{
				num--;
				if (num == 0){
					system("shutdown -s");
				}
				else{
					cout << "ok，你还有" << num << "次机会哦" << endl;
					goto loop;
				}
				
				break;
			}
		default:
			cout << "别瞎按，重输->";
			break;
		}
		cout << endl << endl << endl << endl ;
	}
	system("pause");
	return 0;
}


#if 0
#include<iostream>
//#include"stdafx.h"
#include"stdlib.h"
using namespace std;

//函数定义
void binaryTree();
int* CollisionFlagArray(int* flagID);
void ReadTag(int* readRequestID, int* ID);
int pow(int a, int b);
int main(void)
{
	binaryTree();
	return 0;
}

void binaryTree()
//二进制树形搜索算法
{
	int FlagID[8] = { 0, 0, 0, 0, 0, 0, 0, 0, };
	int ID[4] = { 11110010, 10100011, 10110011, 11100001 };
	//用于存储所读取的电子标签的UID
	int* flagID = CollisionFlagArray(FlagID);
	//返回与标签UID等长数组记录发生碰撞位置，有碰撞-1
	ReadTag(flagID, ID);
	//读取标签
	return;
}

int* CollisionFlagArray(int* flagID)
{
	int id[4][8] = { { 1, 1, 1, 1, 0, 0, 1, 0 }, { 1, 0, 1, 0, 0, 0, 1, 1 },
	{ 1, 0, 1, 1, 0, 0, 1, 1 }, { 1, 1, 1, 0, 0, 0, 0, 1 } };
	flagID[8];
	for (int i = 0; i<8; i++)
	if (id[0][i] == id[1][i] && id[1][i] == id[2][i] && id[2][i] == id[3][i])
		flagID[i] = 1;
	else
		flagID[i] = -1;
	return flagID;
}

void ReadTag(int* readRequestID, int* ID)
{
	int Initial = 11111111;
	//阅读器第一次发出的请求总是11111111
	int *Reader = &Initial;
	//需要识别所有标签，阅读器所要发出的所有请求序列
	int ReadRequestCount = 1;
	//用*(Reader + ReadRequestCount)来标识和访问阅读器发出的请求序列
	int ReadedTag[4] = { 0, 0, 0, 0 };
	//用来标记所有标签被识别情况
	int ReadingID = 0;
	int ReadedTagCount = 0;
	for (int i = 0; i < 8; i++) {
		//此循环用来计算阅读器要识别所有标签，发出的序列号
		if (*(readRequestID + i) == -1) {
			*(Reader + ReadRequestCount) = *(Reader + (ReadRequestCount - 1)) - pow(10, 8 - (i + 1));
			ReadRequestCount++;
		}
	}

	int i = 0;
	//标识阅读器发出的是哪个序列
	while (1)
	{
		int AnswerCount = 0;
		if (ReadedTagCount == 4)
			break;
		else {
			for (int j = 0; j < 4; j++)
			if (*(ID + j) <= *(Reader + i) && ReadedTag[j] != 1)
			{
				AnswerCount++;
				//printf("AnswerCount:%d\n", AnswerCount);
				//printf("Reader:%d\n", *(Reader + i));
				ReadingID = j;
			}
			if (AnswerCount != 1)
				i++;
			else {
				printf("\n识别标签%d:%d\n\n", ReadingID + 1, *(ID + ReadingID));
				ReadedTagCount++;
				ReadedTag[ReadingID] = 1;
			}
		}
	}
	system("pause");
}
int pow(int a, int b)
{
	if (b == 0)
		return 1;
	return a*pow(a, b - 1);
}

#endif