#include<iostream>

#include<vector>

using namespace std;
//需求：通过WeaterData类，如果有新的天气更新，则更新天气，可以有不同的发布栏显示
//在此只实现当新的天气到来时显示当前的天气


//主题
class WeaterDate
{
	WeaterDate()
	{}
	//提供加入订阅者、移除订阅者、通知订阅者的函数

private:
	vector<Observer> m_observer;
	float temperature;
};


//订阅者
class Observer
{
public:
	void Update(float temperature);
};

class Display
{
public:
	void disPaly();
};



//为显示当前的天气发布栏设计的类
//继承自订阅者类和显示类，不同的订阅者有不同的类
class CurrentDisplay :public Observer,Display
{
public:
	void Update(float temperature)
	{
		m_temperature = temperature;
		disPaly();
	}
	void disPlay()
	{
		//显示当前的天气
	}
private:
	WeaterDate m_WeaterData;
	float m_temperature;
};


int main() 
{

	return 0;
}