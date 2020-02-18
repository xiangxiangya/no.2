#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<vector>
#include<queue>

//哈夫曼树的节点
template<class T>
class HuffmanTreeNode
{
public:
	HuffmanTreeNode(const T & w=T())
		:_pleft(nullptr)
		, _pright(nullptr)
		, _pparent(nullptr)
		, _weight(w)
	{}

	HuffmanTreeNode<T> * _pleft;
	HuffmanTreeNode<T> * _pright;
	HuffmanTreeNode<T> * _pparent;
	T _weight;
};

template<class T>
class Great
{
	typedef HuffmanTreeNode<T> Node;
public:
	bool operator ()(const Node *left, const Node *right){
		return left->_weight > right->_weight;
	}
};

template<class T>
class HuffmanTree
{
	//由于哈夫曼树的节点使用频率高所以对其重命名
	typedef HuffmanTreeNode<T> Node;
public:
	//构造一棵空树
	HuffmanTree()
	:_proot(nullptr){}
	//构造哈夫曼树
	HuffmanTree(const std::vector<T>& v,const T & inval){
		CreatHuffmanTree(v,inval);//inval表示无效权值，避免再在构造二叉树的时候出错（0）
	}

	~HuffmanTree(){
		DestroyHuffmanTree(_proot);
	}

	//创建哈夫曼树
	void CreatHuffmanTree(const std::vector<T> v , const T & inval=T()){
		//1.把参数传入的信息放到优先级队列中进行管理
		//优先级队列默认构造的堆是大堆，所以要提供小堆的构造方式
		std::priority_queue<Node*,std::vector<Node *>,Great<T>> q;
		for (auto e : v){
			//当值为0的时候就不要往队列中放，否则二叉树构造出错（叶子节点左右孩子不为空）
			if (e == inval){
				continue;
			}
			q.push(new Node(e));
		}
		//2.构造哈夫曼树
		while (q.size() > 1){
			Node * pleft = q.top();
			q.pop();
			Node * pright = q.top();
			q.pop();
			Node * tmp = new Node(pleft->_weight + pright->_weight);
			tmp->_pleft = pleft;
			tmp->_pright = pright;
			pleft->_pparent = tmp;
			pright->_pparent = tmp;
			q.push(tmp);
		}
		_proot = q.top();
	}

	Node* GetRoot(){
		return _proot;
	}
private:
	void DestroyHuffmanTree(Node *&root){
		if (root){
			//通过后序遍历的方式销毁一颗二叉树
			DestroyHuffmanTree(root->_pleft);
			DestroyHuffmanTree(root->_pright);
			delete root;
			root = nullptr;
		}
	}
private:
	Node * _proot;
};
