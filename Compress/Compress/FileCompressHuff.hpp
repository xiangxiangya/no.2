#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<string>
#include<assert.h>
#include"HuffmanTree.h"

class CharIn
{
public:
	unsigned char _ch;
	int _count;
	std::string _strcode;
	CharIn(int count=0)
	:_count(count){

	}
	CharIn operator +(const CharIn & ch)const{
		return CharIn(ch._count + _count);
	}

	bool operator >(const CharIn & c)const{
		return _count > c._count;
	}

	bool operator ==(const CharIn & c)const {
		return c._count == _count;
	}
};

class FileCompressHuff
{
public:
	FileCompressHuff(){
		for (int i = 0; i < 256; ++i){
			_fileIn.resize(256);
			_fileIn[i]._ch = i;
			_fileIn[i]._count = 0;
		}
	}

	void FileCompresshuff(const std::string & path){
		//1.统计源文件中字符信息
		Done_CharIn_File(path);
		//2.根据信息构建哈夫曼树
		HuffmanTree<CharIn> t;
		t.CreatHuffmanTree(_fileIn,CharIn(0));
		//3.获取哈夫曼编码
		GetHuffmanCode(t.GetRoot());
		//4.对源文件中每个字符根据新的编码改写并放入压缩文件中
		Compress_File(path);
	}

	void UnFileCompresshuff(const std::string & path){
		FILE *fp3 = fopen("fUnCompre.jpg", "wb");
		FILE *fp2 = fopen(path.c_str(), "rb");
		if (fp2 == nullptr){
			return;
		}

		//读取文件后缀
		std::string strPost;
		ReadLine(fp2, strPost);

		//读取字符信息的总行数
		std::string strCount;
		ReadLine(fp2, strCount);
		int lineCount = atoi(strCount.c_str());

		//读取字符信息
		for (int i = 0; i < lineCount; ++i){
			std::string strCharIn;//字符信息
			ReadLine(fp2, strCharIn);
			//如果读取到的是换行
			if (strCharIn.empty())
			{
				strCharIn += '\n'; 
				ReadLine(fp2, strCharIn);
			}
			_fileIn[(unsigned char )strCharIn[0]]._count = atoi(strCharIn.c_str() + 2);
		}
		//还原哈夫曼树
		HuffmanTree<CharIn> t(_fileIn,CharIn(0));

		//解压缩
		unsigned char * pReadBuff = new unsigned char[2048];
		char ch = 0;
		HuffmanTreeNode<CharIn> *pCur = t.GetRoot();
		int filesize = pCur->_weight._count;
		int uncount = 0;
		while (true)
		{
			int rdSize = fread(pReadBuff, 1,2048, fp2);
			if (rdSize == 0){
				break;
			}
			for (int i = 0; i < rdSize; ++i){
				//只需将一个字节中的八个比特位单独处理
				ch = pReadBuff[i];
				for (int pos = 0; pos < 8; ++pos){
					if (ch & 0x80){
						pCur = pCur->_pright;
					}
					else{
						pCur = pCur->_pleft;
					}
					ch <<= 1;
					if (nullptr == pCur->_pleft&&nullptr == pCur->_pright){
						uncount++;
						fputc(pCur->_weight._ch, fp3);
						if (uncount == filesize){
							break;
						}
						pCur = t.GetRoot();
					}
				}
			}
		}
		delete[] pReadBuff;
		fclose(fp2);
		fclose(fp3);
	}
private:
	void Done_CharIn_File(const std::string & path)
	{
		FILE *fIn = fopen(path.c_str(), "r");
		if (nullptr == fIn){
			assert(false);
			return;
		}
		unsigned char * readBuff = new unsigned char[1024];
		int readSize = 0;
		while (1){
			readSize = fread(readBuff, 1, 1, fIn);
			if (readSize == 0){
				break;
			}
			//统计
			for (int i = 0; i < readSize; ++i){
				_fileIn[readBuff[i]]._count++;
			}
		}
		delete[] readBuff;
		fclose(fIn);
	}

	//获取哈夫曼编码
	void GetHuffmanCode(HuffmanTreeNode<CharIn>* proot){
		typedef HuffmanTreeNode<CharIn> Node;
		std::string strCode;
		if (proot == nullptr){
			return;
		}
		GetHuffmanCode(proot->_pleft);
		GetHuffmanCode(proot->_pright);
		if (nullptr==proot->_pleft &&nullptr == proot->_pright){
			Node * cur = proot;
			Node * parent = proot->_pparent; 
			while (parent){
				if (cur == parent->_pleft){
					strCode += '0';
				}
				else{
					strCode += '1';
				}
				cur = parent;
				parent = cur->_pparent;
			}	
			reverse(strCode.begin(), strCode.end());
			_fileIn[proot->_weight._ch]._strcode = strCode;
		}
	}
	
	//对源文件中每个字符根据新的编码改写并放入压缩文件中
	void Compress_File(const std::string &path){
		FILE*fIn=fopen(path.c_str(), "rb");
		FILE*fCompre = fopen("fCompre.TXT", "wb");
		//在压缩文件中不光要保存压缩信息，还需要保存文件的后缀、字符信息的行数、字符出现的次数
		WriteHead(fCompre,path);

		fseek(fIn, 0, SEEK_SET);
		//重新读取文件中的信息
		unsigned char * readBuff = new unsigned char[2048];
		int readSize = 0;
		char ch = 0;
		int bitCount = 0;
		while (true){
			readSize = fread(readBuff, 1, 2048, fIn);
			if (readSize == 0){
				break;
			}
			//已经读到了
			for (int i = 0; i < readSize; ++i){
				std::string newStrCode = _fileIn[readBuff[i]]._strcode;
				for (int j = 0; j < newStrCode.size(); ++j){
					ch <<= 1;
					if (newStrCode[j] == '1'){
						ch |= 1;
					}
					
					bitCount++;
					if (bitCount == 8){
						fputc(ch, fCompre);
						ch = 0;
						bitCount = 0;
					}
				}
			}
		}
		if (bitCount > 0){
			ch = ch << (8 - bitCount);
			fputc(ch, fCompre);
		}
		delete[] readBuff;
		fclose(fCompre);
		fclose(fIn);
	}

	//添加压缩文件中的头部信息
	void WriteHead(FILE * fCompress, const std::string &path ){

		std::string filePost;//文件后缀
		filePost=path.substr(path.rfind('.'));//截取文件后缀
		//把截取出的文件后缀先写到压缩文件中
		fwrite(filePost.c_str(), 1, filePost.size(), fCompress);
		fwrite("\n", 1, 1, fCompress);


		//将行数和字符出现的次数写入压缩文件中
		int count = 0;//行数
		std::string CharIn;//字符信息
		char Itoa[32] = { 0 };
		for (int i = 0; i < 256; ++i){
			if (_fileIn[i]._count != 0){
				count++;
				CharIn += _fileIn[i]._ch;
				CharIn += ':';
				CharIn += _itoa(_fileIn[i]._count, Itoa, 10);
				CharIn += '\n';
			}
		}
		fwrite(_itoa(count,Itoa,10), 4, 1, fCompress);
		fwrite("\n", 1, 1, fCompress);
		fwrite(CharIn.c_str(), 1, CharIn.size(), fCompress);
	}

	void ReadLine(FILE * fp, std::string & StrInfo)
	{
		while (!feof(fp))
		{
			char ch = fgetc(fp);
			if (ch == '\n')
				break;
			StrInfo += ch;
		}
	}


private:
	std::vector<CharIn> _fileIn;
};