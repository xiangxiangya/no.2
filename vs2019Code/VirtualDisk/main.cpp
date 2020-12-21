#include"common.hpp"
#include"Print.hpp"
#include"DealInsruction.hpp"
#include"File.hpp"

std::string now_path = "\\";
//定义一个全局变量来记录当前在目录的哪一个位置
int main()
{
	//SetConsoleOutputCP(65001);//设置cmd为utf-8编码
	SetConsoleOutputCP(936);//设置cmd编码为默认编码GBK
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置输出内容颜色
	//对指令表初始化
	DealInsruction::InitAllins();
	std::cout << "欢迎进入虚拟磁盘" << std::endl;
	while (1)
	{
		//根据当前的文件结构展示提示符
		Print::s_PrintPrompt(now_path);//应该提供参数（上面定义的全局变量）
		std::string instruction;
		std::getline(std::cin , instruction);
		//处理指令
		std::string ins;
		bool ret = DealInsruction::s_Dealins(instruction,ins,now_path);
		if (ret == false)
		{
			//用户输入的指令有误，提示用户重新输入
			if (ins.empty())
			{
				continue;
			}
			else
			{
				std::cout << "'" << ins << "'不是内部或外部命令，请重新输入!" << std::endl;
			}
		}
	}
	return 0;
}



