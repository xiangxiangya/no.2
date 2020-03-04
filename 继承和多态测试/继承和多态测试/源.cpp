#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;
#if 0
class B
{
public:
	int _b;
};

class D : public B
{
public:
	int _d;
};
int main()
{
	B b;
	b._b = 3;
	D d;
	d._b = 5;

	system("pause");
	return 0;
}
#endif

#if 0
class B
{
public:
	B()
	{

	}
	int _b;
};

class D : public B
{
public:
	D()
		: _d(3)
			,B()
	{

	}
	int _d;
};
#endif

#if 0

class Person
{
public:
	int id;
};
class Student : public Person
{
public:
	int id;
};
int main()
{
	Person S;
	S.Person::id = 10;
	system("pause");
	return 0;
}
#endif

#if 0
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string S;
	int num = 0;
	char c;
	while (getline(cin, S) && cin >> c)
	{
		int i = 0;
		int j = 0;
		if (c >= 'a' || c <= 'z')
		{
			while (i<S.size())
			{

				if (S[j] == c || S[j] == toupper(c))//c是小写
				{
					num++;
				}
				i++;
				j++;
			}
		}
		else
		{
			while (i<S.size())
			{

				if (S[j] == c || S[j] == tolower(c))//c是大写
				{
					num++;
				}
				i++;
				j++;
			}
		}
		cout << num << endl;
		S.clear();
	}
	return 0;
}
#endif

#if 0
class B
{
public:
	B(int b)
	:_b(b)
	{}
protected:
	int _b;
};

class D : public B
{
public:
	D(int b, int d)
		:B(b)
		, _d(d)
	{}
private:
	int _d;
};
int main()
{
	B b(10);
	D d(20, 30);
	system("pause");
	return 0;
}
#endif


#if 0
#include<iostream>
using namespace std;

class B
{
public:
	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};
#pragma pack(4)
int main()
{
	D d;
	cout << sizeof(d) << endl;
	system("pause");
	return 0;
}
#endif


#if 0
class A
{
public:
	int *a;
	char c;
	int *b;
	int *d;
};
class B : virtual public A
{
public:
	int b;
};

int main()
{
	cout << sizeof(B) << endl;
	system("pause");
	return 0;
}
#endif

#if 0
struct A
{
	int c;
	char b;
};
int main()
{
	cout << sizeof(A) << endl;
	system("pause");
	return 0;
}
#endif


#if 0
class B
{
public:

	virtual void TestFunc()
	{
		cout << "B::TestFunc();" << endl;
	}
	int _b;
};

class D : public B
{
public:
	virtual void TsetFunc()override//没有对基类中任何成员函数进行重写，报错
	{
		cout << "D:TestFun();" << endl; 
	}
	int _d;
};

void Func(B & b)//调基类对象的TestFunc()
{
	b.TestFunc();
}

int main()
{
	B b; 
	Func(b);
	D d;
	Func(d);
	system("pause");
	return 0;
}
#endif

#if 0
class B
{
public:

	virtual void TestFunc()
	{
		cout << "B::TestFunc();" << endl;
	}
	int _b;
};

class D : public B
{
public:
	virtual void TestFunc()final override//没有对基类中任何成员函数进行重写，报错
	{
		cout << "D:TestFun();" << endl;
	}
	int _d;
};

class DD :public D
{
public:
	virtual void TestFunc()final override
	{
		cout << "D:TestFun();" << endl;
	}
	int _dd;
};


#endif


#if 0

class B
{
public:
	virtual B * TestFun()
	{
		cout << "B::TestFun()" << endl;
		return new B;
	}
};

class D : public B
{
public:
	virtual D * TestFun() override
	{
		cout << "D::TestFun()" << endl;
		return new D;
	}
};


void Test(B & b)
{
	b.TestFun();
}

int main()
{
	B b;
	Test(b);
	D d;
	Test(d);
	system("pause");
	return 0;
}
#endif





#if 0
class WC
{
public:
	void GoToManRoom()
	{
		cout << "go to left" << endl;
	}

	void GoToWoManRoom()
	{
		cout << "go to right" << endl;
	}
};

// 抽象类--包含有纯虚函数的类
// 特性：不能实例化对象，但可以创建该类的指针(引用)
// 作用：规范后序接口
class Person
{
public:
	// 纯虚函数
	virtual void GoToWC(WC& wc) = 0;

	string _name;
	int _age;
};

class Man : public Person
{
public:
	void GoToWC(WC& wc)
	{
		wc.GoToManRoom();
	}
};

class Woman : public Person
{
public:
	void GoToWC(WC& wc)
	{
		wc.GoToWoManRoom();
	}
};

// Monster类也是抽象类，因为该类没有重写基类中的纯虚函数
class Monster : public Person
{};


#include <windows.h>
#include <time.h>

void TestWC(int n)
{
	WC wc;
	srand(time(nullptr));

	for (int i = 0; i < n; ++i)
	{
		Person* pGuard; // 厕所管理员
		if (rand() % 2 == 0)
			pGuard = new Man;
		else
			pGuard = new Woman;

		pGuard->GoToWC(wc);

		delete pGuard;

		Sleep(1000);
	}
}

int main()
{
	Person* p;
	//Monster m;
	TestWC(10);
	return 0;
}
#endif


#if 0
class WC
{
public:
	void GoToManRoom()
	{
		cout << "go to left" << endl;
	}

	void GoToWoManRoom()
	{
		cout << "go to right" << endl;
	}
};


class Person
{
public:
	virtual void GotoWC(WC wc)=0;
	string name;
	int age;
};

class Man : public Person
{
	virtual void GotoWC(WC wc)
	{
		wc.GoToManRoom();
	}
};

class Woman : public Person
{
	virtual void GotoWC(WC wc)
	{
		wc.GoToWoManRoom();
	}
};

#include<Windows.h>
#include<time.h>

int main()
{
	WC wc;
	srand(time(nullptr));
	Person *p;
	int i = 0;
	while (i < 10)
	{
		if (rand() % 2 == 0)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}
		p->GotoWC(wc);
		Sleep(1000);
		delete p;
	}
	system("pause");
	return 0;
}
#endif

#if 0
class B
{
public:
	virtual void TestFun1()
	{
		cout << "B::void TesrFun1()" << endl;
	}
	virtual void TestFun2()
	{
		cout << "B::void TesrFun2()" << endl;
	}
	virtual void TestFun3()
	{
		cout << "B::void TesrFun3()" << endl;
	}
	int _b;
};

class D : public B
{
public:
	virtual void TestFun5()
	{
		cout << "D::void TestFun5()" << endl;
	}
	virtual void TestFun1()override
	{
		cout << "D::void TestFun1()" << endl;
	}
	virtual void TestFun2()override
	{
		cout << "B::void TesrFun2()" << endl;
	}
	virtual void TestFun3()
	{
		cout << "B::void TesrFun3()" << endl;
	}

	virtual void TestFun4()
	{
		cout << "D::void TestFun4()" << endl;
	}
	int _d;
};


void Testvirtualfun(B*b)
{
	b->TestFun1();
	b->TestFun2();
	b->TestFun3();
}
int main()
{
	B b;
	Testvirtualfun(&b);
	D d;
	Testvirtualfun(&d);
	system("pause");
	return 0;
}
#endif


class B
{
public:
	virtual void TestFun1()
	{
		cout << "B::void TesrFun1()" << endl;
	}
	virtual void TestFun2()
	{
		cout << "B::void TesrFun2()" << endl;
	}
	virtual void TestFun3()
	{
		cout << "B::void TesrFun3()" << endl;
	}
	int _b;
};

class D : public B
{
public:
	virtual void TestFun5()
	{
		cout << "D::void TestFun5()" << endl;
	}
	virtual void TestFun1()override
	{
		cout << "D::void TestFun1()" << endl;
	}
	virtual void TestFun2()override
	{
		cout << "B::void TesrFun2()" << endl;
	}
	virtual void TestFun3()
	{
		cout << "B::void TesrFun3()" << endl;
	}

	virtual void TestFun4()
	{
		cout << "D::void TestFun4()" << endl;
	}
	int _d;
};

typedef void (*PVEF)();//给函数指针取别名
void PrintTable(B &b)
{
	PVEF * pVEF = (PVEF*)(*(int*)(&b));
	while (*pVEF)
	{
		(*pVEF)();
		++pVEF;
	}
	cout << endl;
}
int main()
{
	B b;
	PrintTable(b);
	D d;
	PrintTable(d);
	system("pause");
	return 0;
}


