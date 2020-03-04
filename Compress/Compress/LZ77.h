#pragma once
#include"LZHashTable.h"
#include<string>

class LZ77
{
public:
	LZ77();
	~LZ77();
	void CompressFile(const std::string &path);
	void UnCompressFile(const std::string & path);
	USH LongestMatch(USH matchHead, USH &curMatchDist,USH start);
	void MergeFile(FILE * fOut, ULL fileSize);
	void FillWindow(FILE * fIn, int & lookAhead, USH &start);
private:
	void WriteFlag(FILE * fOut,USH &chFlag,UCH &bitCount,bool isCharOrLen);
	
private:
	UCH*_pWin;//窗口：表示缓冲区
	LZHashTable _ht;
};

