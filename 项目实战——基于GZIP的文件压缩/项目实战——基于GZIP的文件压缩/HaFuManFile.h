#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<string>
using namespace std;
#include<vector>
#if 1
struct CharInfo
{
	//CharInfo()
	//:_ch('0')
	//, _count(0)
	//, _strcode("")
	//{
	//}

	unsigned char _ch;//具体字符
	int _count;//字符出现的字数
	string _strcode;//字符的编码
};


class FileCompressHuff
{
public:
	FileCompressHuff();
	void CompressFile();
	void UnCompressFile();
private:
	void ReadLine(FILE * fp, std::string & StrInfo);
private:
	vector<CharInfo> _fileInfo;
};

#endif


#if 0
class CharIn
{
public:
	CharIn()
	{
		for (int i = 0; i < sizeof(arr); ++i)
		{
			arr[i] = 0;
		}
	}
	char ch;
	char arr[256];
	int count;
};

class Out
{
public:
	char ch;

};



class File
{
public:
	void TJFileIO()
	{
		CharIn charin;
		char buf[1024] = { 0 };
		int ret = 1;
		FILE *fp = fopen("1.TXT", "r");
		while (ret)
		{
			ret = fread(buf, 1024, 1, fp);//每次读取1024个字节，读取一次，若读到文件末尾则返回值为0就退出
			for (int i = 0; i < sizeof(buf); ++i)
			{
				charin.arr[buf[i]]++;//arr中元素的对应的值即为该字符出现的次数（下标对应字符ASCII码值）
			}
			for (int i = 0; i < sizeof(charin.arr); ++i)
			{
				if (charin.arr[i] == 0){
					continue;
				}
				charin.ch = i;
			}
		}


		fclose(fp);
	}

};
#endif