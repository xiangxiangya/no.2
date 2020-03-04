#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<vector>
#include<windows.h>
#include<iostream>

//每次选择最小的往前放
class SelectSort
{
public:
	static std::vector<int> selectSort(std::vector<int>& v){
		int i = 0;
		int j = 0;
		for (i = 0; i < v.size(); ++i){
			int min = i;
			for (j = i+1; j < v.size() ; j++){
				if (v[j] < v[min]){
					min = j;
				}
			}
			int tmp = v[i];
			v[i] = v[min];
			v[min] = tmp;
		}
		return v;
	}
};

//插入排序，从第二个元素开始，将这个元素的指先记录下来
//然后往前找到第一个不比它大的元素所插入的位置就在其后面
class InsertSort
{
public:
	static std::vector<int> Insertsort(std::vector<int> &v){
		if (v.size() < 2){
			//当只有一个元素的时候直接返回
			return v;
		}
		//进行插排
		for (int i = 1; i < v.size(); ++i){
			int tmp = v[i];
			int k = i - 1;//
			while (k >= 0 && v[k]>tmp){
				k--;
			}
			//此时已经找到插入位置为k+1,把位置腾出来并把元素插入进去
			for (int j = i; j >k+1; j--){
				v[j] = v[j - 1];
			}
			v[k+1] = tmp;
		}
		return v;
	}
};

//希尔排序就是在插入排序的基础上加上增量，使原序列更有序提高程序效率
class ShellSort
{
public:
	static void Shellsort(std::vector<int> & v){
		//定义增量gap
		int gap = v.size()/2;
		for (gap; gap >0; gap/=2){
			//在分组内使用插排,从第gap个元素开始逐个对其所在分组进行插排
			for (int i = gap; i < v.size(); ++i){
				int j = i;
				int tmp = v[j];
				if (v[j] < v[j - gap]){
					while (j - gap >= 0 && v[j] < v[j - gap]){
						v[j] = v[j - gap];
						j -= gap;
					}
					v[j] = tmp;
				}
			}
		}
	}
};



class BubbleSort
{
public:
	static void Bubblesort(std::vector<int> & v){
		if (v.size() < 2){
			return;
		}
		//flag的作用是：如果一次冒泡都没有发生说明此时序列已有序可以直接返回不需要再继续循环
		bool flag=true;
		for (int i = 0; i < v.size(); ++i){
			//第二层循环表示第i趟需要的次数：n-i-1
			for (int j = 0; j < v.size()-i-1; ++j){
				if (v[j+1] < v[j]){
					int tmp = v[j];
					v[j] = v[j+1];
					v[j+1] = tmp;
					flag = false;
				}
			}
			if (flag){
				break;
			}
		}
	}
};

//归并排序的思想是将序列对半分成两个子序列排序后再合并
class MergeSort
{
public:
	static std::vector<int> Mergesort(std::vector<int> v, int left, int right){
		if (left < right){
			//将数组分为两个子数组
			int mid = (right - left) / 2;
			//对左边的数组进行排序
			v=Mergesort(v, left, mid);
			//对右边的数组进行排序
			v=Mergesort(v, mid + 1, right);
			//合并
			merge(v, left, mid, right);
		}
		return v;
	}

	static void merge(std::vector<int> &v, int left, int mid, int right){
		std::vector<int> tmp;
		tmp.resize(right-left+1);
		int i = 0;
		int j = left;
		int k = mid+1;
		while (j <= mid&&k <= right){
			if (v[j] <	v[k]){
				tmp[i++] = v[j++];
			}
			else{
				tmp[i++] = v[k++];
			}
		}
		while (j <= mid){
			tmp[i++] = v[j++];
		}
		while (k <= right){
			tmp[i++] = v[k++];
		}
			v = tmp;
	}
};



