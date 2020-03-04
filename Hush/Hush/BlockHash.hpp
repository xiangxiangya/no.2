#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Common.hpp"
#include<vector>



//****实现的是不重复出现的哈希表(闭散列)*****

//哈希表每个位置的标记
enum State{EMPTY,EXIST,DELETE};

template<class T>
class HushElem
{
public:
	HushElem(const T& data=T())
	:_data(data)
	,_st(EMPTY)
	{}
	T _data;
	State _st;
};

template<class T>
class Hushtable
{
public:
	Hushtable(const int capacity=13)
		:_size(0)
		,_total(0){
		_ht.resize(capacity);
	}

	bool Insert(const T&data){
		//通过哈希函数计算出哈希地址
		int hushAddr = HushFunc(data);
		int count = 0;
		//判断这个地址是否可用？插入；线性探测
		while (_ht[hushAddr]._st != EMPTY){
			//这个地址是不可用的，所以要进行线性探测
			if (_ht[hushAddr]._st==EXIST&&_ht[hushAddr]._data == data){
				return false;//当要插入的元素已经出现在哈希表中时就直接返回了
			}
			
			//当产生哈希冲突时：线性探测和二次探测
			//1.线性探测，直接对地址++
			hushAddr++;
			if (hushAddr == _ht.size()-1){
				hushAddr = 0;
			}
			//2.二次探测，对计算出的哈希地址平方
#if 0
			count++;
			hushAddr = (hushAddr + (2 * i + 1))%_ht.capacity();
#endif
		}
		_ht[hushAddr]._data = data;
		_ht[hushAddr]._st = EXIST;
		_size++;
		_total++;
		return true;
	}

	int Find(const T&data){
		int hushAddr = HushFunc(data);
		while(_ht[hushAddr]._st != EMPTY){
			if (_ht[hushAddr]._st == EXIST&&_ht[hushAddr]._data==data){
				return hushAddr;
			}
			if (hushAddr == _ht.size()-1){
				hushAddr = 0;
				continue;
			}
			hushAddr++;
		}
		return -1;
	}

	bool Earse(const T& data){
		int hushAddr = Find(data);
		if (hushAddr != -1){
			_ht[hushAddr]._st = DELETE;
			_size--;
			return true;
		}
		return false;
	}

private:
	//哈希函数：计算哈希地址
	int HushFunc(const T&data = T()){
		//返回data模上不超过表长的最接近表长的一个素数
		return data % 10;
	}

	bool CheckCapacity(){
		//如果直接进行除运算结果为0，所以要在这基础上x10
		if ((_total * 10) / _ht.capacity() >= 7){
			//当总量已经大于哈希表的容量时需要扩容
			//1.申请新空间
			//ushElem<T> tmp = new HushElem<T>(GetNextPrime(_ht.capacity));
			HushElem<T> tmp(GetNextPrime(_ht.capacity()));
			//2.将旧空间的元素按照哈希地址放到新空间内
			for (auto e & _ht){
				if (e._st == EXIST){
					tmp.Insert(e);
				}
			}
			//3.交换新旧空间
			_ht.swap(tmp);
		}
		return false;
	}

private:
	std::vector<HushElem<T>> _ht;
	int _size;
	int _total;
};