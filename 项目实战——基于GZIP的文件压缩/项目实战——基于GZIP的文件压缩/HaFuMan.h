#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<queue>
using namespace std;
#include<vector>
#include<functional>
#include<stdlib.h>
#include<algorithm>

template<class T>
class HaFuManTreeNode//给出哈夫曼树的节点结构
{
public:
	    HaFuManTreeNode(const T & w=T())
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, weight(w)
	    {
		}


public:
	HaFuManTreeNode * _pLeft;
	HaFuManTreeNode * _pRight;
	HaFuManTreeNode * _pParent;
	T weight;
};

template<class T>
class Com
	//比较器，优先级队列
{
public:
	//typedef HaFuManTreeNode<int> Node;
	bool operator ()( const T & Left, const T & Right)
	{
		if (Left->weight._count>Right->weight._count)//默认大堆（小于号），改成小堆（大于号）
		{
			return  true;
		}
		else{
			return false;
		}
	}
};


template<class T>
class HaFuManTree
{
	typedef HaFuManTreeNode<T> Node;
public:
	HaFuManTree(vector<T> & v)
		:_pRoot(new Node)
	{
		priority_queue<Node *,vector<Node *>,Com<Node *>> q;
		//1.首先创造所有节点并将其放入森林中（优先级队列管理）
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i]._count != 0)
			{
				Node * cur = CreatHaFuManTree(v[i]);
				q.push(cur);
			}
			
		}
		//2.让这些节点构造为一棵哈夫曼树
		//Node * tmp = new Node;
		//注意：如果将这条语句写在外面那么tmp指针是固定的，每一次修改时都会蝴蝶效应
#if	1
		while (q.size()>1)
		{
			//为tmp指针重新分配了内存空间
			Node * tmp = new Node;//将这条语句写在里面每一次进来都会为tmp重新开辟空间，修改其时也不会影响别的
			Node *Left = q.top();
			q.pop();
			Node *Right = q.top();
			q.pop();
			tmp->_pLeft = Left;
			tmp->_pRight = Right;
			tmp->weight._count = Left->weight._count+ Right->weight._count;
			Left->_pParent = tmp;
			Right->_pParent = tmp;
			q.push(tmp);
		}

		
#endif
		_pRoot = q.top();
		/////////////////////////////////////
		//3.获取哈夫曼编码
		GetHaFuManCode(_pRoot,v);//已将正确的编码保存到树中
		
	}


	~HaFuManTree()
	{
		Destroy(_pRoot);
	}

	Node * CreatHaFuManTree(const T & t = T())
	{
		Node * cur = new Node(t);
		return cur;
	}
public:


	void GetHaFuManCode(Node * root, vector<T> & v)//规定向左为0，向右为1
	{
		//将所有的编码信息都保存起来，但是必须要逆置才是最终的编码
		if ((root) == nullptr){
			return;
		}
		if (root->_pLeft == nullptr&&root->_pRight == nullptr){
			Node *cur = root;
			Node *res = cur;
			while (cur != _pRoot){
				if ((cur) == (cur)->_pParent->_pLeft){//cur是左孩子
					(res)->weight._strcode += '0';
				}
				else if ((cur) == (cur)->_pParent->_pRight){
					(res)->weight._strcode += '1';
				}
				cur = (cur)->_pParent;
			}
			reverse(res->weight._strcode.begin(), res->weight._strcode.end());
			for (int i = 0; i < v.size(); ++i){
				if (v[i]._ch == res->weight._ch){
					v[i]._strcode = res->weight._strcode;
				}
			}
		}

		GetHaFuManCode(root->_pLeft,v);
		GetHaFuManCode(root->_pRight,v);
	}



	Node * GetRoot()
	{
		return _pRoot;
	}
private:
	void Destroy(Node *& _proot)
	{
		delete _proot;
	}
	Node *_pRoot;
};


