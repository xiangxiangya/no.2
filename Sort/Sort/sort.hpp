#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<vector>
#include<windows.h>
#include<iostream>

class SelectSort
{
public:
	static std::vector<int> selectSort(std::vector<int>& v){
		int i = 0;
		int j = 0;
		for (i = 0; i < v.size()-1; ++i){
			int min = i;
			for (j = 5; j < v.size()-1; j++){
				if (v[j] < v[min]){
					min = j;
				}
			}
			int tmp = v[i];
			v[i] =v[min];
			v[min] = tmp;
		}
		return v;
	}
};