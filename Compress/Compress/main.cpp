#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include"HuffmanTree.h"
#include"FileCompressHuff.hpp"

int main()
{
	FileCompressHuff h;
	h.FileCompresshuff("1.TXT");
	h.UnFileCompresshuff("fCompre.TXT");
	system("pause");
	return 0;
}