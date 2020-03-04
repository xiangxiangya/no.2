#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#if 0
template<class T>
class SmartPtr
{
public:
	SmartPtr(T * p=nullptr)
		:_ptr(p)
	{}
	~SmartPtr()
	{
		if (_ptr){
			delete _ptr;
		}
	}
	T &operator*()
	{
		return *_ptr;
	}
	T * operator->()
	{
		return _str;
	}
private:
	T* _ptr;
};

int main()
{
	SmartPtr<int> p1(new int);
	SmartPtr<int> p2(p1);
	system("pause");
	return 0;
}
#endif


#if 0
#include<memory>
int main()
{
	auto_ptr<int> p1(new int);
	*p1 = 1;
	auto_ptr<int> p2(p1);
	cout << *p1 << endl;
	cout << *p2 << endl;
	system("pause");
	return 0;
}
#endif 


#if 0
template<class T>
class SmartPtr
{
public:
	SmartPtr(T * p = nullptr)
		:_ptr(p)
	{}
	~SmartPtr()
	{
		if (_ptr){
			delete _ptr;
		}
	}
	SmartPtr(SmartPtr<T> & p)
		:_ptr(p._ptr)
	{
		p._ptr = nullptr;

	}
	SmartPtr<T>& operator=(SmartPtr<T> & p)
	{
		if (this != &p)
		{
			//如果当前对象有资源先将当前资源释放
			if (_ptr){//如果_ptr内有资源则先将自己的资源释放，否则会造成内存泄漏
				delete _ptr;
			}
			_ptr = p._ptr;
			p._ptr = nullptr;
		}
		return *this;
	}
	T &operator*()
	{
		return *_ptr;
	}
	T * operator->()
	{
		return _str;
	}
private:
	T* _ptr;
};

int main()
{
	SmartPtr<int> p1(new int);
	SmartPtr<int> p2(p1);
	SmartPtr<int> p3(new int);
	SmartPtr<int> p2 = p3;//体现赋值运算符第二个if的作用

	system("pause");
	return 0;
}
#endif


#if 0
template<class T>
class SmartPtr
{
public:
	SmartPtr(T * p = nullptr)
		:_ptr(p)
		, _owner(false)
	{
		if (_ptr){
			_owner = true;
		}
	}

	~SmartPtr()
	{
		if (_ptr&&_owner){
			delete _ptr;
			_ptr = nullptr;
		}
	}

	SmartPtr(SmartPtr<T> & p)
		:_ptr(p._ptr)
		, _owner(p._owner)//将_owener更新，所以拷贝构造只释放_owner为true的
		//解决了浅拷贝的问题
	{
		p._owner = false;
	}
	SmartPtr<T>& operator=(SmartPtr<T> & p)
	{
		if (this != &p){
			//如果当前对象管理了资源先把它释放
			if (_ptr){
				delete _ptr;
			}
			_ptr = p._ptr;//资源转移
			_owner = p._owner;//释放权限转移
			p._owner = false;
		}
	}
	T &operator*()
	{
		return *_ptr;
	}
	T * operator->()
	{
		return _str;
	}
private:
	T* _ptr;
	bool _owner;
};

#include<memory>
int main()
{
	SmartPtr<int> p1(new int);
	if (1){
		SmartPtr<int> p2(p1);
		*p2 = 10;
	}
	//p1是野指针
	*p1 = 20;
	
	system("pause");
	return 0;
}
#endif

#include<memory>

#if 0
int main()
{
	unique_ptr<int> p1(new int);
	//报错
	unique_ptr<int> p2(p1);
	unique_ptr<int> p3(new int);
	//报错
	p3 = p1;
	system("pause"); 
	return 0;
}
#endif


#if 0
template<class T>
class mine{
	class unique_ptr
	{
	public:
		unique_ptr(T * p = nullptr)
			:_ptr(p)
			, _owner(false)
		{
			if (_ptr){
				_owner = true;
			}
		}

		~unique_ptr()
		{
			if (_ptr&&_owner){
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T &operator*()
		{
			return *_ptr;
		}
		T * operator->()
		{
			return _str;
		}
	/*private:
		unique_ptr(unique_ptr<T> & p){};
		unique_ptr<T> &operator=(unique_ptr<T> &p){};*/
		
		//c++11
		unique_ptr(const unique_ptr<T> &p) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
	private:
		T* _ptr;
		bool _owner;
	};
};

#endif

#if 0

#include <memory>

template<class T>
class DFDef
{
public:
	void operator()(T*& p)//（）的重载，只需要接受一个T类型对象的指针
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};


class FClose
{
public:
	void operator()(FILE*& p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};

namespace Mine
{
	template<class T, class DF = DFDef<T>>//DF是一个自定义类型模板，默认调用DFDef
	class unique_ptr
	{
	public:
		// RAII
		unique_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				//delete _ptr; // 释放资源的方式固定死了，只能管理new的资源，不能处理任意类型的资源
				//DF()(_ptr);
				DF df;//创建一个DF对象
				df(_ptr);//调用df中的（）重载，传入指针
				_ptr = nullptr;
			}
		}

		// 具有指针类似行为
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		unique_ptr(const unique_ptr<T>&) = delete;  // 1. 释放new的空间  2.默认成员函数 = delete ： 告诉编译器，删除该默认成员函数
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;

	private:
		T* _ptr;
	};
}

#include<malloc.h>
void TestUniquePtr()
{
	//通过模板参数列表的第二个参数，选择在析构时选择对应的析构方法
	Mine::unique_ptr<int> up1(new int);
	Mine::unique_ptr<int, Free<int>> up2((int*)malloc(sizeof(int)));//传一个类进去
	Mine::unique_ptr<FILE, FClose> up3(fopen("1.txt", "w"));
}

int main()
{
	TestUniquePtr();
	return 0;
}
#endif


#if 0
//模拟实现shared_ptr
//利用写时拷贝解决浅拷贝

template<class T>
class DFDef
{
public:
	void operator()(T*&ptr){
		if (ptr){
			delete ptr;
			ptr = nullptr;
		}
	}
};
namespace Mine
{
	template<class T,class DF=DFDef<T>>
	class shared_ptr
	{
	public:
		shared_ptr(T*ptr = nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr){
				_pCount = new int(1);//当_ptr不为空时给_pCount赋值为1
			}
		}

		~shared_ptr()
		{
			//当计数>0时只给_pCount--
			//当计为0时说明当前资源已是最后一个对象在使用，此时由当前对象释放资源
			if (_ptr && 0 == --(*_pCount)){
				//delete _ptr;
				DF df;
				df(_ptr);
				delete _pCount;
			}
		}

		T& operator *()
		{
			return *_ptr;
		}

		T*operator->()
		{
			return _ptr;
		}

		//拷贝构造函数和赋值运算符的重载就需要考虑计数的问题了
		shared_ptr(const shared_ptr<T> &sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr){
				++(*_pCount);
			}
		}

		shared_ptr<T> & operator=(const shared_ptr<T> &sp)
		{
			if (this != &sp){
				//1.首先与旧资源断开联系(如果不是最后一个使用资源的对象就只让计数减一，如果是最后一个使用资源的对象则释放资源)
				if (_ptr && 0 == -(*_pCount)){
					delete _ptr;
					delete _pCount;
				}
				//2.与sp共享资源和计数
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr){
					++*_pCount;
				}
			}
			return *this;
		}

		int use_count()
		{
			return *_pCount;
		}
	private:
		T*_ptr;
		int *_pCount;
	};
}



void TestShradPtr()
{
	Mine::shared_ptr<int> sp1(new int);
	cout << sp1.use_count() << endl;

	Mine::shared_ptr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;


	Mine::shared_ptr<int> sp3(new int);
	cout << sp3.use_count() << endl;

	Mine::shared_ptr<int> sp4(sp3);
	cout << sp3.use_count() << endl;
	cout << sp4.use_count() << endl;

	sp3 = sp2;
	cout << sp2.use_count() << endl;
	cout << sp3.use_count() << endl;

	sp4 = sp2;
	cout << sp2.use_count() << endl;
	cout << sp4.use_count() << endl;
}


int main()
{
	TestShradPtr();
	system("pause");
	return 0;
}
#endif


