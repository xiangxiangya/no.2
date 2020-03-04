#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<class T>
struct BSTNode//二叉搜索树的节点组成
{	
	BSTNode(const T & data = T())
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _data(data)
	{}

	BSTNode<T> * _pLeft;
	BSTNode<T> * _pRight;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}

	//构造二叉搜索树
	bool Insert(const T & data)
	{
		//如果根为空，new一个节点并把值放入
		if (_pRoot == nullptr){
			_pRoot = new BSTNode<T>;
			_pRoot->_data = data;
			return true;
		}
		//如果根不为空说明已经有元素，比较要插入的元素和每个节点的大小并插入
		Node *cur = _pRoot;
		Node *parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data > data){
				//根的值比较大，所以要插入的值要往左子树放
				cur = cur->_pLeft;
			}
			else if (cur->_data < data){
				//根的值比较小，往右子树搜索
				cur = cur->_pRight;
			}
			else{
				return false;
			}
		}
		//插入元素
		cur = new Node(data);
		if (parent->_data > data){
			parent->_pLeft = cur;
		}
		else{
			parent->_pRight = cur;
		}
		return true;
	}

	/////////////////////////////////////////////////////////////////////////

	Node *Find(const T& data)
	{
		Node *cur = _pRoot;
		while (cur)
		{
			if (cur->_data == data){
				return cur;
			}
			if (cur->_data>data)
			{
				//要找的比根节点小，说明在左子树
				cur = cur->_pLeft;
			}
			else{
				//要找的比根节点大，说明在右子树
				cur = cur->_pRight;
			}
		}
		return nullptr;
	}

	/////////////////////////////////////////////////
	//删除
	bool Delete(const T & data)
	{
		if (nullptr == _pRoot){
			return false;
		}
		//找要删除的节点的位置
		Node * pCur = _pRoot;//Cur代表要删除的节点
		Node * pParent = nullptr;//pParent代表Cur的双亲，如果没有这个节点就无法将删除后的节点建立联系
		while (pCur)
		{
			if (data == pCur->_data){
				break;
			}
			else if (data < pCur->_data){
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else{
				pParent = pcur;
				pCur = pCur->_pRight;
			}
		}

		if (nullptr == pCur){
			return false;
		}
		//删除
		Node *pDelNode = pCur;
		//删除分四种情况：
		//要删除的节点是叶子节点、要删除的节点只有右孩子节点、要删除的节点只有左孩子节点、要删除的节点有左右孩子节点
		//将叶子节点和只有右孩子节点可以当作一种情况来处理

		if (nullptr == pCur->_pLeft){
			//1.左孩子为空
			if (nullptr == pParent){
				//2.pCur是根节点
				_pRoot = pCur->_pRight;
			}
			else{
				if (pCur == pParent->_pLeft){//如果要删除的是节点在pParent的左边，就将pParent的左边与之链接
					pParent->_pLeft = pCur->_pRight;
				}
				else{
					pParent->_pRight = pCur->_pRight;
				}
			}
		}
		else if (nullptr == pCur->_pRight){
			//3.右孩子为空
			if (nullptr == pParent){
				_pRoot = pCur->_pLeft;
			}
			else{
				if (pCur == pParent->_pLeft){
					pParent->_pLeft = pCur->_pLeft;
				}
				else{
					pParent->_pRight = pCur->_pLeft;
				}
			}
		}
		else{
			//4.左右孩子均存在
			//思路：首先在待删除的节点的左子树或右子树中找一替代节点
			//可以是右子树中最小的节点或是左子树中最大的节点（因为替换后还是要保持二叉搜索树的特性）
			//以下方法采用右子树中最小的节点
			Node * pDel = pCur->_pRight;//Del是替代节点
			pParent = pCur;
			while (pDel->_pLeft){
				pParent = pDel;
				pDel = pDel->_pLeft;
			}
			pCur->_data = pDel->_data;//交换数据
			if (pParent->_pLeft == pDel){
				pParent->_pLeft = pDel->_pRight;
			}
			else{
				pParent->_pRight = pDel->_pRight;
			}
			pDelNode = pDel;
		}
		delete pDelNode;
		return true;
	}


	/////////////////////////////////////////////////////////
	//找到最左侧的节点
	Node*LeftMost()
	{
		if (_pRoot == nullptr){
			return nullptr;
		}
		Node*cur = _pRoot;
		while (cur->_pLeft){
			cur = cur->_pLeft;
		}
		return cur;
	}

	//找到最右侧的节点
	Node * RightMost()
	{
		if (nullptr == _pRoot){
			return nullptr;
		}
		Node * cur = _pRoot;
		while (cur->_pRight){
			cur = cur->_pRight;
		}
		return cur;
	}


	//中序遍历二叉搜索树
	void Display()//因为在外部无法拿到根节点所以要再封装一次
	{
		DisPlay(_pRoot);
	}

private:
	void DisPlay(Node *root)
	{
		if (root){
			DisPlay(root->_pLeft);
			cout << root->_data << " ";
			DisPlay(root->_pRight);
		}
	}
	Node * _pRoot;
};

void TestFun()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> node;
	for (auto & e : a){
		node.Insert(e);
	}
	//node.Display();
	cout << node.Find(5) << endl;
}

int main()

{

	TestFun();
	system("pause");
	return 0;
}