#define _CRT_SECURE_NO_WARNINGS 1
#include"HaFuMan.h"
#include"HaFuManFile.h"

int main()
{
	//vector<int> v = { 3,1,5,7 };
	//HaFuManTree<int>::HaFuManTree(v);
	FileCompressHuff d;
	d.CompressFile();
	d.UnCompressFile();
	system("pause");
	return 0;
}