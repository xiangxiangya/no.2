#pragma once
#include"common.hpp"

class Print
{
public:
	static void s_PrintPrompt(const std::string &now_path)
	{
		std::cout << "C:" + now_path  + ">";
	}
};


