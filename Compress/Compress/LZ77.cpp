#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"LZ77.h"
#include<assert.h>

const USH MIN_LOOKAHEAD = MAX_MATCH + MIN_MATCH + 1;
const USH MAX_DIST = WSIZE - MIN_LOOKAHEAD;


LZ77::LZ77()
:_pWin(new UCH[WSIZE*2])
,_ht(WSIZE){

}

LZ77::~LZ77(){
	delete[] _pWin;
	_pWin = nullptr;
}



void LZ77::CompressFile(const std::string &path){
	//首先将源文件打开，当源文件中字符小于三个就不进行压缩了
	FILE*fIn=fopen(path.c_str(), "rb");
	if (nullptr == fIn){
		std::cout << "打开文件失败" << std::endl;
	}
	fseek(fIn, 0, SEEK_END);
	ULL FileSize=ftell(fIn);
	if (FileSize <= MIN_MATCH){
		std::cout << "文件过小，无需压缩" << std::endl;
		return;
	}

	//从压缩文件中读取一个缓冲区的数据到窗口中
	fseek(fIn, 0, SEEK_SET);
	//从文件中读取到的数据为一个缓冲区的大小
	int lookAhead=fread(_pWin, 1, 2 * WSIZE, fIn);

	//由于哈希函数是要根据前面的哈希地址和当前字节计算的
	//所以先将前两个字节的哈希地址算出来
	USH start = 0;//从窗口的最左侧开始处理
	USH hashAddr = 0;
	for (USH i = 0; i < MIN_MATCH-1; ++i){
		_ht.HashFunc(hashAddr, _pWin[i]);
	}

	//开始压缩
	FILE * fOut = fopen("Compress.TXT", "wb");

	assert(fOut);


	//打开标记文件
	FILE* fFlag = fopen("Flag.txt", "wb");

	//定义查找最长匹配有关变量
	USH matchHead = 0;//匹配头
	USH curMatchLength = 0;
	USH curMatchDist = 0;

	//定义标记有关变量
	USH chFlag = 0;
	UCH bitCount = 0;
	bool IsLen = false;

	while (lookAhead){
		//1.将三个三个的字符串插入到哈希表中，并得到匹配链的头
		_ht.Insert(matchHead, _pWin[start + 2], start , hashAddr);
		curMatchLength = 0;
		curMatchDist = 0;
		if (matchHead != 0){
			//2.获取最长的匹配,获取到长度距离对
			curMatchLength=LongestMatch(matchHead, curMatchDist,start);
		}
		//3.查看是否找到匹配
		if (curMatchLength<MIN_MATCH){
			//未找到重复字符串
			//将start写到压缩文件中
			fputc(_pWin[start], fOut);

			//写当前字符对应的标记，是源字符用0标记
			WriteFlag(fFlag, chFlag, bitCount, false);

			++start;
			lookAhead--;
		}else{
			//找到匹配，将长度距离对写入到压缩文件中
			fputc(curMatchLength-3, fOut);
			fwrite(&curMatchDist, sizeof(curMatchDist), 1, fOut);

			//写当前字符对应的标记，长度距离对用1代表
			WriteFlag(fFlag, chFlag, bitCount, true);

			//lookAhead代表先行缓冲区中的字节数
			lookAhead -= curMatchLength;
			
			//将已经匹配到的字符串插入到哈希表中
			--curMatchLength;
			while (curMatchLength){
				start++;
				_ht.Insert(matchHead, _pWin[start+2], start, hashAddr);
				curMatchLength--;
			}
			start++;
		}
		//检测先行缓冲区中剩余字符的个数
		if (lookAhead <=MIN_LOOKAHEAD){
			//填充数据
			FillWindow(fIn, lookAhead,start);
		}

	}

	//循环结束后有可能还有没有写入标记文件中的内容
	if (bitCount > 0 && bitCount < 8){
		chFlag <<= (8 - bitCount);
		fputc(chFlag, fFlag);
	}


	
	fclose(fFlag);
	fclose(fIn);

	MergeFile(fOut, FileSize);
	fclose(fOut);
}

USH LZ77::LongestMatch(USH matchHead, USH &curMatchDist, USH start){
	//是在查找缓冲区中进行匹配
	USH curMatchLen = 0;//当前匹配长度
	UCH maxMatchLen = 0;
	UCH maxMatchCount = 255;//最大的匹配次数，避免环状链的出现
	USH curMatchStart = 0;//当前匹配在查找缓冲区的的起始位置

	//limit约束了向前找匹配的最远距离
	USH limit = start > MAX_DIST ? start - MAX_DIST : 0;

	//先行缓冲区中的起始位置
	UCH* pstart = _pWin + start;
	//先行缓冲区中的终止位置
	UCH *pend = pstart + MAX_MATCH;

	//查找缓冲区匹配串的起始位置
	UCH *pMatchStart = _pWin + matchHead;
	//std::cout << pMatchStart << std::endl;
	//开始匹配
	do{
		
		curMatchLen = 0;
		//开始匹配
		while (pstart < pend&&*pstart == *pMatchStart){
			curMatchLen++;
			pstart++;
			pMatchStart++;
		}
		//一次匹配结束
		if (curMatchLen > maxMatchLen){
			maxMatchLen = curMatchLen;
			curMatchStart = matchHead;
		}
	} while ((matchHead = _ht.GetNext(matchHead)) > limit && maxMatchCount--);


	curMatchDist = start - curMatchStart;
	return maxMatchLen;
}


void LZ77::MergeFile(FILE * fOut,  ULL fileSize){
	//将压缩文件和标记文件进行合并
	//读取标记信息文件中的内容，然后写到压缩文件中
	FILE * fInF = fopen("Flag.txt", "rb");
	size_t flagSize = 0;
	UCH *pReadBuff = new UCH[1024];
	while (true){
		size_t rdSize = fread(pReadBuff, 1, 1024, fInF);
		if (rdSize == 0){
			break;
		}
		else{
			fwrite(pReadBuff, 1, rdSize, fOut);
			flagSize += rdSize;
		}
	}

	fwrite(&flagSize, sizeof(flagSize), 1, fOut);
	fwrite(&fileSize, sizeof(fileSize), 1, fOut);

	delete[] pReadBuff;
	fclose(fInF);
	//将标记文件删除
}


//1.将右窗口中数据搬移到左窗口
//2.读取WSIZE个压缩数据到右窗口
//3.更新哈希表
void LZ77::FillWindow(FILE * fIn, int & lookAhead, USH &start){

	if (start >= WSIZE){
		memcpy(_pWin, _pWin + WSIZE, WSIZE);
		memset(_pWin + WSIZE, 0, WSIZE);
		start -= WSIZE;
		//更新哈希表
		_ht.Update();

		if (!feof(fIn)){
			//如果不在文件末尾进行填充
			lookAhead += fread(_pWin + WSIZE, 1, WSIZE, fIn);
		}
	}
}


//chFlag:区分源字符还是长度距离对
//0代表源字符，1代表长度距离对
//bitCount:代表chFlag中已经设置过的比特位
void LZ77::WriteFlag(FILE * fOut, USH &chFlag, UCH &bitCount, bool isLen){
	chFlag <<= 1;
	if (isLen){
		chFlag |= 1;
	}
	bitCount++;
	if (bitCount == 8){
		//将标记写入标记文件中
		fputc(chFlag, fOut);
		chFlag = 0;
		bitCount = 0;
	}
}






void LZ77::UnCompressFile(const std::string & path){
	//打开压缩文件和标记文件
	FILE * fInData = fopen(path.c_str(), "rb");
	if (fInData == nullptr){
		std::cout << "压缩文件打开失败" << std::endl;
		return;
	}

	//操作标记数据的文件指针
	FILE * fInFlag = fopen(path.c_str(), "rb");
	if (fInFlag == nullptr){
		fclose(fInData);
		std::cout << "标记文件打开失败" << std::endl;
		return;
	}

	//获取源文件大小
	ULL fileSize = 0;
	fseek(fInFlag, 0 - sizeof(fileSize), SEEK_END);
	fread(&fileSize, sizeof(fileSize), 1, fInFlag);

	//获取标记信息的大小和源文件的大小
	int flagSize = 0;
	fseek(fInFlag,0-sizeof(fileSize)-sizeof(flagSize) , SEEK_END);
	fread(&flagSize, sizeof(flagSize), 1, fInFlag);

	//将读取标记信息的文件指针移动到保存标记数据的起始位置
	fseek(fInFlag, 0 - sizeof(flagSize)-sizeof(fileSize)-flagSize, SEEK_END);


	FILE * fOut = fopen("LZUnCompre.TXT", "wb");

	//再定义一个文件指针用来还原匹配串
	FILE * fRe = fopen("LZUnCompre.TXT", "rb");

	assert(fOut);
	UCH bitCount = 0;
	UCH chFlag = 0;
	ULL encodeCount = 0;
	while (encodeCount<fileSize){
		if (bitCount == 0){
			//读取一个标记
			chFlag = fgetc(fInFlag);
			bitCount = 8;
		}
		
		//检测当前的标记是0还是1
		if (chFlag & 0x80){
			//如果结果为1表示是距离长度对
			USH matchLen = fgetc(fInData) + 3;
			USH matchDist = 0;
			fread(&matchDist, sizeof(matchDist), 1, fInData);

			//清空缓冲区，将缓冲区中的数据写入到文件中
			fflush(fOut);
			//更新已经解码的大小，作为退出循环的条件
			encodeCount += matchLen;
			UCH ch;

			//用fRe去前文中读取匹配串的内容
			fseek(fRe, 0-matchDist, SEEK_END);
			while (matchLen){
				ch=fgetc(fRe);
				fputc(ch, fOut);
				matchLen--;
				fflush(fOut);
			}
		}
		else{
			//结果为0代表读取到的是原字符
			UCH ch = fgetc(fInData);
			fputc(ch, fOut);
			encodeCount += 1;
		}
		chFlag <<= 1;
		bitCount--;
	}

	fclose(fInData);
	fclose(fInFlag);
	fclose(fOut);
	fclose(fRe);

}