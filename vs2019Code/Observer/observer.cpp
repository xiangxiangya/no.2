#include<iostream>

#include<vector>

using namespace std;
//����ͨ��WeaterData�࣬������µ��������£�����������������в�ͬ�ķ�������ʾ
//�ڴ�ֻʵ�ֵ��µ���������ʱ��ʾ��ǰ������


//����
class WeaterDate
{
	WeaterDate()
	{}
	//�ṩ���붩���ߡ��Ƴ������ߡ�֪ͨ�����ߵĺ���

private:
	vector<Observer> m_observer;
	float temperature;
};


//������
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



//Ϊ��ʾ��ǰ��������������Ƶ���
//�̳��Զ����������ʾ�࣬��ͬ�Ķ������в�ͬ����
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
		//��ʾ��ǰ������
	}
private:
	WeaterDate m_WeaterData;
	float m_temperature;
};


int main() 
{

	return 0;
}