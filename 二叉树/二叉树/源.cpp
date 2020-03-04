#define _CRT_SECURE_NO_WARNINGS 1
#define NULL 0
#include<iostream>
using namespace std;
#include<string.h>
#include<stack>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#if 0

typedef char datatype;
typedef struct node{
	datatype elem;
	struct node * lchild, *rchild;
}BTNode, *BinTree;


//BinTree createBinTree_1(Binn)

BinTree CreateBTree_2()//创建二叉树
{
	BinTree bt = NULL;
	char ch;
	scanf("%c", &ch);
	if (ch != '#'){
		bt = new	BTNode;
		bt->elem = ch;
		bt->lchild = CreateBTree_2();
		bt->rchild = CreateBTree_2();
	}
	return bt;
}

void preOrder(BinTree root)
{
	if (root != NULL){
		cout << root->elem << " ";
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
	//cout<<endl;
}

void inOrder(BinTree root)
{
	if (root != NULL){
		inOrder(root->lchild);
		cout << root->elem << " ";
		inOrder(root->rchild);
	}
	//cout<<endl;
}

void postOrder(BinTree root)
{
	if (root != NULL){
		postOrder(root->lchild);
		postOrder(root->rchild);
		cout << root->elem << " ";
	}
	//cout<<endl;
}

int maxDepth(BinTree root)
{
	int m, n;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		m = maxDepth(root->lchild);
		n = maxDepth(root->rchild);
		if (m>n){
			return (m + 1);
		}
		else
		{
			return (n + 1);
		}
	}

}



void display(BinTree root)//展示二叉树
{
	if (root != NULL){
		cout << root->elem;
		if (root->lchild != NULL || root->rchild != NULL){
			cout << '(';
			display(root->lchild);
		}
		if (root->rchild != NULL){
			cout << ',';
			display(root->rchild);
			cout << ')';
		}
	}
}

void DelTree(BinTree root)
{
	if (root != NULL){
		DelTree(root->lchild);
		DelTree(root->rchild);
	}
	free(root);
}

BinTree Parent(BinTree bt, char NodeName)
{
	if (bt)
	{
		if (bt->elem == NodeName){
			cout << "该节点为根节点" << endl;
			return NULL;
		}

	}
	if ((bt->lchild->elem == NodeName&&bt->lchild != NULL) || (bt->rchild->elem == NodeName&&bt->rchild != NULL))
		return bt;
	else{
		BTNode *tmpP = NULL;
		
	}
}
int main()
{
	int max = 0;
	BinTree root = NULL;
	root = CreateBTree_2();
	//display(root);
	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	max = maxDepth(root);
	cout << max << endl;
	return 0;
}
//abc##de#g##f###
#endif

#define NULL 0
#include<iostream>
#include<string.h>
#include<cstdio>
#include<stdlib.h>
#include<stack>
using namespace std;
#include<stdio.h>

typedef char datatype;
typedef struct node
{
	datatype elem;
	struct node *lchild, *rchild;
}BTNode, *BinTree;

BinTree CreatBinTree_1(BinTree bt, int isRoot);
BinTree CreatBinTree_2();
void DelTree(BinTree root);
void display(BinTree root);
void preOrder(BinTree root);
void inOrder(BinTree root);
void postOrder(BinTree root);
int maxDepth(BinTree root);
BinTree Parent(BinTree bt, char NodeName);
BinTree Search(BinTree bt, char NodeName);
int Nodes(BinTree bt);
void DispLeaf(BinTree bt);


//交互式创建二叉树
BinTree CreatBinTree_1(BinTree bt, int isRoot)
{
	char ch;
	if (isRoot)
		printf("Root：");
	fflush(stdin);
	scanf("%c", &ch);
	fflush(stdin);
	if (ch != '#')
	{
		isRoot = 0;
		bt = new BTNode;
		bt->elem = ch;
		bt->lchild = NULL;
		bt->rchild = NULL;
		printf("%c's left child is:", bt->elem);
		bt->lchild = CreatBinTree_1(bt->lchild, isRoot);
		printf("%c's right child is:", bt->elem);
		bt->rchild = CreatBinTree_1(bt->rchild, isRoot);
	}
	return bt;
}

//先序创建二叉树
BinTree CreatBinTree_2()
{
	BinTree bt = NULL;
	char ch;
	scanf("%c", &ch);
	if (ch != '#')
	{
		bt = new BTNode;
		bt->elem = ch;
		bt->lchild = CreatBinTree_2();
		bt->rchild = CreatBinTree_2();
	}
	return bt;
}

//删除二叉树
void DelTree(BinTree root)
{
	if (root != NULL)
	{
		DelTree(root->lchild);
		DelTree(root->rchild);
	}
	free(root);
}

//显示树形结构
void display(BinTree root)
{
	if (root != NULL)
	{
		cout << root->elem;
		if (root->lchild != NULL || root->rchild != NULL)
		{
			cout << '(';
			display(root->lchild);
		}
		if (root->rchild != NULL)
		{
			cout << ',';
			display(root->rchild);
			cout << ')';
		}
	}
}

//递归先序遍历
void preOrder(BinTree root)
{
	if (root != NULL)
	{
		cout << root->elem;
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

//递归中序遍历
void inOrder(BinTree root)
{
	if (root != NULL)
	{
		inOrder(root->lchild);
		cout << root->elem;
		inOrder(root->rchild);
	}
}

//递归后序遍历
void postOrder(BinTree root)
{
	if (root != NULL)
	{
		postOrder(root->lchild);
		postOrder(root->rchild);
		cout << root->elem;
	}
}

//求二叉树的最大深度
int maxDepth(BinTree root)
{
	int m, n;
	if (root == NULL)
		return 0;
	else
	{
		m = maxDepth(root->lchild);
		n = maxDepth(root->rchild);
		if (m>n)
			return(m + 1);
		else
			return(n + 1);
	}
}

//查询某个结点的父结点
BinTree Parent(BinTree bt, char NodeName)
{
	if (bt)
	{
		if (bt->elem == NodeName)
			cout << "该结点为根结点" << endl;
		return NULL;
	}
	if ((bt->lchild->elem == NodeName&&bt->lchild != NULL) || (bt->rchild->elem == NodeName&&bt->rchild != NULL))
		return bt;
	else
	{
		BTNode *tempP = NULL;
		if (tempP = Parent(bt->lchild, NodeName))
			return tempP;
		if (tempP = Parent(bt->rchild, NodeName))
			return tempP;
	}
	return NULL;
}

//查找某个结点
BinTree Search(BinTree bt, char NodeName)
{
	BinTree p;
	if (bt)
	{
		if (bt->elem == NodeName)
			return bt;
		if (bt->lchild)
		{
			p = Search(bt->lchild, NodeName);
			if (p)
				return p;
		}
		if (bt->rchild)
		{
			p = Search(bt->rchild, NodeName);
			if (p)
				return p;
		}
	}
	return NULL;
}

//统计二叉树结点个数
int Nodes(BinTree bt)
{
	if (bt == NULL)
		return 0;
	else
		return Nodes(bt->lchild) + Nodes(bt->rchild) + 1;
}

//输出二叉树所有叶子结点
void DispLeaf(BinTree bt)
{
	if (bt != NULL)
	{
		if (bt->lchild == NULL&&bt->rchild == NULL)
			cout << bt->elem << ' ';
		DispLeaf(bt->lchild);
		DispLeaf(bt->rchild);
	}
}


int main()
{
	BinTree root = NULL;
	root = CreatBinTree_2();
	display(root);
	/*cout << "输出此二叉树：" << endl;
	display(root);
	cout << "\n 先序排列为：";
	preOrder(root);
	cout << "\n 中序排列为：";
	inOrder(root);
	cout << "\n 后序排列为：";
	postOrder(root);
	int num = maxDepth(root);
	cout << "\n 该二叉树的深度为：" << num << endl;
	BinTree nn;
	char name;
	cout << "输入要查找的结点名：";
	cin >> name;
	nn = Parent(root, name);
	if (nn)
		cout << name << "的父结点名为：" << nn->elem << endl;
	nn = Search(root, name);
	if (nn->lchild)
		cout << name << "的左孩子为：" << nn->lchild->elem << endl;
	else
		cout << name << "无左孩子。" << endl;
	if (nn->rchild)
		cout << name << "的右孩子为：" << nn->rchild->elem << endl;
	else
		cout << "无右孩子。" << endl;
	cout << "此二叉树的结点数为：";
	cout << Nodes(root) << endl;
	cout << "输出所有的叶子结点：\n";*/
	DispLeaf(root);
	system("pause");
	return 0;
}
//abc##de#g##f###
