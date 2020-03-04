#pragma once 
#include"Common.h"

class LZHashTable
{
public:
	LZHashTable(USH size);
	~LZHashTable();
	void Insert(USH& hashAddr, UCH ch, USH pos, USH& macthHead);
	void HashFunc(USH& hashAddr, UCH ch);
	USH GetNext(USH matchHead);
	USH H_SHIFT();
	void Update();
private:
	USH *_prev;
	USH *_head;
};