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
		//�������ָ��տո��з�
		std::stringstream ss(instruction);
		std::string tmp;
		int i = 0;
		while (getline(ss, tmp, delim))
		{
			//�����ж��ٸ��ָ�������������ȷ�ָ�
			if (tmp != "")
			{
				vins.push_back(tmp);
			}
		}
		return;
	}

};



