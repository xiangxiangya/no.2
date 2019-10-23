#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;

#if 0
#include<queue>
#include<vector>
int main()
{
	vector<int> v{ 2, 5, 1, 6, 3, 9, 8, 0, 7 };
	priority_queue<int> q(v.begin(), v.end());//优先队列的默认底层实现是按照大堆来实现的
	int size = q.size();
	int i = 0;
	while (i<size)
	{
		cout << q.top() << " ";
		q.pop();
		i++;
	}
	system("pause");
	return 0;
}

#endif



#include<deque>//栈和队列的底层结构使用双端队列实现的

#if 0
namespace mine
{
	template<class T, class Container = deque<T>>
	class stack//栈
	{
	public:
		stack()
		{

		}

		void push(const T&data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			_con.pop_back();
		}

		int size()const
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}

		T&top()
		{
			return _con.back();
		}

		template <class T, class Container = deque<T>>
		class queue
		{
		public:
			queue()
			{}

			void push(const T& data)
			{
				_con.push_back(data);
			}

			void pop()
			{
				_con.pop_front();
			}

			T& front()
			{
				return _con.front();
			}

			const T& front()const
			{
				return _con.front();
			}

			T& back()
			{
				return _con.back();
			}

			const T& back()const
			{
				return _con.back();
			}

			size_t size()const
			{
				return _con.size();
			}

			bool empty()const
			{
				return _con.empty();
			};



		private:
			Container _con;
		};
	};
}
	int main()
	{
		system("pause");
		return 0;
	}

#endif




#include<vector>
#include<functional>
	namespace mine
	{
		template <class T, class Container = vector<T>, class Compare = less<T>>//默认（less）创建的是大堆
		class priority_queue
		{
		public:
			priority_queue()
				:c()
			{}

			template<class Iterator>
			priority_queue(Iterator first, Iterator last)//区间构造，将root进行向下调整
				: c(first, last)
			{
				// 将c中的元素调整成堆的结构
				int count = c.size();
				int root = ((count - 2) >> 1);
				for (; root >= 0; root--)
					AdjustDown(root);
			}

			void push(const T & data)
			{
				c.push_back(data);
				AdjustUP(c.size()-1);//传入下标
			}

			void pop()//头删的话先将头元素与最后一个元素交换，把最后一个元素删掉后再执行向下排序
			{
				if (empty())
					return;
				else
				{
					swap(c.front(), c.back());
					c.pop_back();
					AdjustDown(0);
				}
			}
			int size()const
			{
				return c.size();
			}
			bool empty()const
			{
				return c.empty();
			}
			const T & top()const
			{
				return c.front();
			}

		private:

			//这里的向上调整和向下调整都是大堆模式
			void AdjustDown(int parent)//向下调整算法,把较小元素调整下去
			{
				int child = parent * 2 + 1;//child代表下标
				while (child < c.size())
				{
					//找到以parent为根的较大的孩子
					//如果根有右孩子并且左孩子比右孩子小，让child等于右孩子
					//即child此时为较大的孩子
					if (child + 1 < c.size() && com(c[child], c[child + 1]))
					{
						child = child + 1;
					}
					//如果孩子节点比父亲节点大则交换
					if (com(c[parent], c[child]))
					{
						swap(c[child], c[parent]);
						parent = child;
						child = parent * 2 + 1;
					}
					else
						return;
				}
			}

			void AdjustUP(int child)//向上调整算法，将较大元素调整上去
			{
				int parent = (child - 1) >> 1;
				while (child)//没有到根的话继续循环
				{
					//如果父亲节点比孩子节点小，交换
					//将较大节点调整到根位置
					if (com(c[parent], c[child]))
					{
						swap(com(c[parent], c[child]));
						child = parent;
						parent = (child - 1) >> 1;
					}
					else
					{
						return;
					}
				}
			}
		private:
			Container c;
			Compare com;
		};
	}

	int main()
	{
		vector <int> v = { 1, 5, 8, 2, 9, 3, 4, 6 };
		mine::priority_queue <int> q(v.begin(), v.end());
		system("pasue");
		return 0;
	}