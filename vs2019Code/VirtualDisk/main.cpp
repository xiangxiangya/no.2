#include"common.hpp"
#include"Print.hpp"
#include"DealInsruction.hpp"
#include"File.hpp"

std::string now_path = "\\";
//����һ��ȫ�ֱ�������¼��ǰ��Ŀ¼����һ��λ��
int main()
{
	//SetConsoleOutputCP(65001);//����cmdΪutf-8����
	SetConsoleOutputCP(936);//����cmd����ΪĬ�ϱ���GBK
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//�������������ɫ
	//��ָ����ʼ��
	DealInsruction::InitAllins();
	std::cout << "��ӭ�����������" << std::endl;
	while (1)
	{
		//���ݵ�ǰ���ļ��ṹչʾ��ʾ��
		Print::s_PrintPrompt(now_path);//Ӧ���ṩ���������涨���ȫ�ֱ�����
		std::string instruction;
		std::getline(std::cin , instruction);
		//����ָ��
		std::string ins;
		bool ret = DealInsruction::s_Dealins(instruction,ins,now_path);
		if (ret == false)
		{
			//�û������ָ��������ʾ�û���������
			if (ins.empty())
			{
				continue;
			}
			else
			{
				std::cout << "'" << ins << "'�����ڲ����ⲿ�������������!" << std::endl;
			}
		}
	}
	return 0;
}



