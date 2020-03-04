#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include"HuffmanTree.h"
#include"FileCompressHuff.hpp"
#include<string>
#include"LZ77.h"
#include<iostream>
int main()
{
	LZ77 Lz;
	Lz.CompressFile("1.TXT");
	Lz.UnCompressFile("Compress.TXT");
	system("pause");
	return 0;
}
