#define _CRT_SECURE_NO_WARNINGS 1
#include"HaFuManFile.h"
#include"HaFuMan.h"
typedef HaFuManTreeNode<CharInfo> Node;
FileCompressHuff::FileCompressHuff()
{
	_fileInfo.resize(256);
	for (int i = 0; i < 256; ++i){
		_fileInfo[i]._ch = i;
		_fileInfo[i]._count = 0;
	}
}

void  FileCompressHuff::CompressFile()
{

	//统计字符在文件中出现的次数
	FILE *fp = fopen("1.TXT", "r");
	unsigned char buf[1024] = { 0 };
	int ret = 1;
	while (ret)
	{
		ret = fread(buf, 1024, 1, fp);
		for (int i = 0; i < strlen((char *)buf); ++i){
			_fileInfo[buf[i]]._count++;
		}
	}

	//以字符次数为权值创建哈夫曼树
	HaFuManTree<CharInfo> d(_fileInfo);
	//获取编码
	//由编码改写源文件
	FILE*fp2 = fopen("2.txt", "w");
	char a[1024] = { 0 };
	string str;
	int c = 0;
	for (int i = 0; i < 256; ++i){
		if (_fileInfo[i]._count != 0){
			c++;
		}
	}
	//fputc(c, fp2);
	fwrite(_itoa(c,a,10), 1, 1, fp2);
	fwrite("\n", 1, 1, fp2);
		for (int i = 0; i < 256; i++){
			if (_fileInfo[i]._count != 0){
				str.clear();
				str = _fileInfo[i]._ch;
				fwrite(str.c_str(), 1,1 , fp2);
				fwrite(":", 1, 1, fp2);
				//str.clear();
				//str = _fileInfo[i]._count;
				
				fwrite(_itoa(_fileInfo[i]._count,a,10),1 ,1 , fp2);
				fwrite("\n",1,1,fp2);
			}
	}
		fseek(fp2, 0, SEEK_END);
		//压缩
		/*int Rdsize = 1;
		char Rdbuf[1024] = { 0 };
		while (Rdsize){
			Rdsize = fread(Rdbuf, 1024, 1, fp2);
		}*/
		char ch = 0;
		int count = 0;
			for (int i = 0; i < 256; ++i){
				if (_fileInfo[i]._count != 0){
					for (int k = 0; k < _fileInfo[i]._count; ++k){
						for (int j = 0; j < _fileInfo[i]._strcode.size(); ++j){
							ch <<= 1;
							if (_fileInfo[i]._strcode[j] == '1'){
								ch |= 1;
							}
							count++;
							if (count == 8){
								fputc(ch, fp2);
								count = 0;
								ch = 0;
							}
						}
					}
				}					
			} 
			if (count < 8){
				ch <<= (8 - count);
				fputc(ch, fp2);
			}
			fclose(fp);
			fclose(fp2);
}

void FileCompressHuff::ReadLine(FILE * fp, std::string & StrInfo)
{
	while (!feof(fp))
	{
		char ch = fgetc(fp);
		if (ch == '\n')
			break;
		StrInfo += ch;
	}
}


void FileCompressHuff::UnCompressFile()
{
	FILE *fp3 = fopen("3.txt", "w");
	FILE *fp2=fopen("2.txt", "r");
	if (fp2==nullptr){
		return;
	}

	string StrCount;
	FileCompressHuff::ReadLine(fp2, StrCount);
	int lineCount = stoi(StrCount);

	for (int i = 0; i < lineCount; ++i){
		string strchCount;
		FileCompressHuff::ReadLine(fp2, strchCount);
		if (strchCount.empty())
		{
			strchCount += '\n';
			ReadLine(fp2,strchCount);
		}
		_fileInfo[(unsigned char)strchCount[0]]._count = atoi(strchCount.c_str() + 2);
	}
	//还原哈夫曼树
	HaFuManTree<CharInfo> t(_fileInfo);

	//解压缩
	unsigned char * pReadBuff = new unsigned char[1024];
	char ch = 0;
	HaFuManTreeNode<CharInfo> *pCur = t.GetRoot();
	int filesize = pCur->weight._count;
	int uncount = 0;
	while (true)
	{
		int rdSize = fread(pReadBuff, 1, 1024, fp2);
		if (rdSize == 0){
			break;
		}
		for (int i = 0; i < rdSize; ++i){
			//只需将一个字节中的八个比特位单独处理
			ch = pReadBuff[i];
			for (int pos = 0; pos < 8; ++pos){
				if (ch & 0x80){
					pCur = pCur->_pRight;
				}
				else{
					pCur = pCur->_pLeft;
				}
				ch <<= 1;
				if (nullptr == pCur->_pLeft&&nullptr == pCur->_pRight){
					uncount++;
					fputc(pCur->weight._ch, fp3);
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







