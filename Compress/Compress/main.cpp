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
	FileCompressHuff hf;
	Lz.CompressFile("1.TXT");
	hf.FileCompresshuff("Compress.TXT");
	hf.UnFileCompresshuff("fCompre.TXT");
	Lz.UnCompressFile("fUnCompre.TXT");

	system("pause");
	return 0;
}
