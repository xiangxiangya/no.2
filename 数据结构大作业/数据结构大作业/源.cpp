#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<stdlib.h>

#include<list>

class Book
{
public:
	char _bookname[25];
	int _id;
	int _price;
};



void Print_list()
{
	cout << "********************" << endl;
	cout << "please select :" << endl;
	cout << "1.创建" << endl;
	cout << "2.插入" << endl;
	cout << "3.查询" << endl;
	cout << "4.删除" << endl;
	cout << "5.销毁" << endl;
	cout << "6.计数" << endl;
	cout << "7.修改" << endl;
	cout << "0.退出" << endl;
	cout << "********************" << endl;
}


void Delete(vector<Book> & b)
{
	char bookname[25];
	cout << "which book would you want delete?" << endl << "please enter the bookname->" << endl;
	cin >> bookname;
	auto it = b.begin();
	int i = 0;
	for (it, i; it != b.end(); it++, i++)
	{
		if (0 == strcmp(bookname, b[i]._bookname))
		{
			b.erase(it); return;
		}
	}
	cout << "没有找到这本书" << endl;
	return;
}

void Find(vector<Book> & b)
{
	char bookname[25];
	cout << "which book would you want delete?" << endl << "please enter the bookname->" << endl;
	cin >> bookname;
	auto it = b.begin();
	int i = 0;
	for (it, i; it != b.end(); it++, i++)
	{
		if (0 == strcmp(bookname, b[i]._bookname))
		{
			cout << "要修改什么？" << endl;
			char select = 0;
			switch (select)
			{
			case :

			default:
				break;
			}
		}
	}
	cout << "没有找到这本书" << endl;
	return;
}

int main()
{
	vector<Book> book;
	int select = 0;
	int k = 0;
	int i = 0;
	while (1)
	{
		Print_list();
		char bookname[25];
		auto it = book.begin();
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "ok" << endl;
			break;
		case 2:
			Book b;
			cout << "please enter bookname" << endl;
			cin >> b._bookname;
			cout << "please enter id" << endl;
			cin >> b._id;
			cout << "please enter price" << endl;
			cin >> b._price;
			book.push_back(b);
			break;
		case 3:
			for (i = 0; i < book.size(); i++)
			{
				cout << "书名| " << book[i]._bookname << endl; 
				cout << "编号| " << book[i]._id << endl;
				cout << "价格| " << book[i]._price << endl;
				cout << endl;
			}
			
			break;
		case 4://shanchu 
			Delete(book);
			break;
		case 5:
			book.clear();
			break;
		case 6:
			cout << book.size();
			break;
		case 7:
			Find(book);
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}
	}
	
	
	system("pause");
	return 0;
}



