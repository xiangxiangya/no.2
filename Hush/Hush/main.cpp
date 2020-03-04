#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"BlockHash.hpp"
#include"Common.hpp"

int main()
{
	Hushtable<int> ht;
	std::vector<int> v = { 18,75,60,43,54,90,46 };
	for (auto &e : v){
		ht.Insert(e);
	}

	system("pause");
	return 0;
}