#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<algorithm>
#include<Windows.h>
#include<fstream>



class Parsing
{
public:
	static void s_Parsing(const std::string& instruction, std::vector<std::string>& vins, char delim)
	{
		//将传入的指令按照空格切分
		std::stringstream ss(instruction);
		std::string tmp;
		int i = 0;
		while (getline(ss, tmp, delim))
		{
			//不管有多少个分隔符，都可以正确分割
			if (tmp != "")
			{
				vins.push_back(tmp);
			}
		}
		return;
	}

};



