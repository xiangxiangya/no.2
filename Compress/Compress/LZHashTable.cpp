#define _CRT_SECURE_NO_WARNINGS 1
#include"LZHashTable.h"
#include"Common.h"
#include<cstring>

const USH HASH_BITS  = 15;
const USH HASH_SIZE = (1 << HASH_BITS);
const USH HASH_MASK = HASH_SIZE - 1;//掩码，保证下标不会越界
 
LZHashTable::LZHashTable(USH size)
:_prev(new USH[size * 2])
, _head(_prev + size){
	memset(_prev, 0, size * 2 * sizeof(USH));
}

LZHashTable::~LZHashTable(){
	delete[] _prev;
	_prev = nullptr;
}

//hashAddr代表前一次计算出的哈希地址
//ch代表本次匹配的字符串的最后一个字符
//上一次计算出的哈希地址已经保存了
//例如：abcdefg
//hashAddr时abc的地址
//本次要计算bcd的哈希地址就只需要将d字符传入就可
void LZHashTable::HashFunc(USH& hashAddr, UCH ch){
	hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}

USH LZHashTable::H_SHIFT(){
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}


// hashAddr：上一次哈希地址              ch：先行缓冲区第一个字符 
// pos：ch在滑动窗口中的位置             matchHead：如果匹配，保存匹配串的起始位置
void LZHashTable::Insert(USH& macthHead,UCH ch, USH pos,USH& hashAddr){
	// 计算哈希地址
	HashFunc(hashAddr, ch);
	// 随着压缩的不断进行，pos肯定会大于WSIZE，与上WMASK保证不越界
	_prev[pos & HASH_MASK] = _head[hashAddr];
	macthHead = _head[hashAddr]; 
	_head[hashAddr] = pos;
}

USH LZHashTable::GetNext(USH matchHead){
	return _prev[matchHead&HASH_MASK];
}

void LZHashTable::Update(){
	for (USH i = 0; i < WSIZE; ++i){
		//更新head
		if (_head[i] >= WSIZE){
			_head[i] -= WSIZE;
		}
		else{
			_head[i] = 0;
		}
		//更新prev
		if (_prev[i] >= WSIZE){
			_prev[i] -= WSIZE;
		}
		else{
			_prev[i] = 0;
		}
	}
}