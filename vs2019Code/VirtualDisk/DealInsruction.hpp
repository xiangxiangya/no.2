#pragma once
#include"common.hpp"
#include"File.hpp"


//cdָ��䣬�ص��ϼ�Ŀ¼�������������ĳ��Ŀ¼���ƣ���֪·�����룩


std::set<std::string> allIns;

DealDir dl;

class DealInsruction
{
public:
	DealInsruction()
	{}


	static void InitAllins()
	{
		allIns.insert("md");
		allIns.insert("mkdir");
		allIns.insert("cd");
		allIns.insert("copy");
		allIns.insert("del");
		allIns.insert("rmdir");
		allIns.insert("dir");
		allIns.insert("compare");
		allIns.insert("quit");
		allIns.insert("chdir");
		allIns.insert("less");//�鿴�ļ��е�����
	}

	//���û������ָ����н���������
	static bool s_Dealins(const std::string& instruction, std::string& str, std::string& out_path)
	{
		//1.��ָ����зָ�
		std::vector<std::string> vins;
		Parsing::s_Parsing(instruction, vins, ' ');
		if (vins.size() == 0)
		{
			//�û�û������ָ��
			return false;
		}
		//vins[0]��ָ��֣��ж�ָ���Ƿ���ȷ
		bool isTrueIns = DealInsruction::s_Judgeins(vins[0]);
		if (!isTrueIns)
		{
			//�û������ָ�������⣬��ʾ�û���������
			str = vins[0];
			return false;
		}
		//�û������ָ������ȷ�ģ����û��������ָ�������Ӧ�Ĵ���
		if (vins[0] == "mkdir")
		{
			//����Ŀ¼ָ��,vins[0]֮������ݶ���Ҫ����������
			for (int i = 1; i < vins.size(); ++i)
			{
				//���ô���Ŀ¼�Ľӿ�
				std::string path;
				std::string filename = "";
				std::string nowPath = dl.CurPath();
				if (vins[i][0] == '\\')
				{
					//����·��
					path = vins[i];
				}
				else
				{
					//path = '\\' + nowPath + vins[i];
					//��������·�������ֵ�һ��Ԫ���Ƿ�Ϊ���ڵ�
					if (nowPath == "\\")
					{
						path = nowPath + vins[i];
					}
					else
					{
						path = nowPath + '\\' + vins[i];
					}

				}
				//filename = nullptr;
				dl.CreateDir(path, filename);
			}
			SetPath(out_path, dl);
		}



		else if (vins[0] == "quit")
		{
			std::cout << "goodbye" << std::endl;
			exit(1);
		}




		else if (vins[0] == "md")
		{
			//����Ŀ¼ָ��,vins[0]֮������ݶ���Ҫ����������
			for (int i = 1; i < vins.size(); ++i)
			{
				//���ô���Ŀ¼�Ľӿ�
				std::string path;
				std::string filename = "";
				std::string nowPath = dl.CurPath();
				if (vins[i][0] == '\\')
				{
					//����·��
					path = vins[i];
				}
				else
				{
					//path = '\\' + nowPath + vins[i];
					//��������·�������ֵ�һ��Ԫ���Ƿ�Ϊ���ڵ�
					if (nowPath == "\\")
					{
						path = nowPath + vins[i];
					}
					else
					{
						path = nowPath + '\\' + vins[i];
					}

				}
				//filename = nullptr;
				dl.CreateDir(path, filename);
			}
			SetPath(out_path, dl);
		}



		else if (vins[0] == "dir")
		{
			dl.Dir();
		}



		else if (vins[0] == "chdir")
		{
			dl.Pwd();
		}

		else if (vins[0] == "less")
		{
			//��ӡ�ļ�������
			if (vins.size() != 2)
			{
				return false;
			}
			//��·�������Ǿ���·��Ҳ���������·��
			std::string path = vins[1];//�û�Ҫ�����Ŀ¼
			std::string FinallyPath;
			if (path[0] == '\\')
			{
				//����·��
				FinallyPath = path;
			}
			else
			{
				std::string nowPath = dl.CurPath();
				//���·��,����ǰ·�������·��ƴ��
				if (nowPath == "\\")
				{
					//��ǰ�Ǹ�·����ֱ��ƴ��
					FinallyPath = nowPath + vins[1];
				}
				else
				{
					//��ǰ���Ǹ�·������Ҫ�ӷָ���"\"
					FinallyPath = nowPath + '\\' + vins[1];
				}
			}
			dl.PrintFile(FinallyPath);
		}



		else if (vins[0] == "cd")
		{
			//����ֻ����һ��·��
			if (vins.size() != 2)
			{
				std::cout << "ϵͳ�Ҳ���ָ����·��" << std::endl;
				return true;
			}
			//�ڶ����������û���Ҫ�����Ŀ¼
			std::string path = vins[1];//�û�Ҫ�����Ŀ¼
			std::string FinallyPath;
			if (path == ".")
			{
				//�ڱ���Ŀ¼��ʲô������
				return true;
			}
			if (path == "..")
			{
				//�ص��ϼ�Ŀ¼
				std::string nowPath = dl.CurPath();
				
				//��·��ƴ�ӳ�����ʹcdֱ�ӽ���
				ReturnUp(nowPath);
				dl.Cd(nowPath,dl);
				SetPath(out_path, dl);//���õ�ǰ·��
				return true;
			}
			if (path[0] == '\\')
			{
				//����·��
				FinallyPath = path;
			}
			else
			{
				std::string nowPath = dl.CurPath();
				//���·��,����ǰ·�������·��ƴ��
				if (nowPath == "\\")
				{
					//��ǰ�Ǹ�·����ֱ��ƴ��
					FinallyPath = nowPath + vins[1];
				}
				else
				{
					//��ǰ���Ǹ�·������Ҫ�ӷָ���"\"
					FinallyPath = nowPath + '\\' + vins[1];
				}
				
			}
			//std::cout << FinallyPath << std::endl;
			dl.Cd(FinallyPath,dl);
			SetPath(out_path, dl);
		}



		else if (vins[0] == "copy")
		{
			//�Դ����ϵ��ļ������ֽڿ���
			//1.���ֻ��һ����������ȷ�Ļ��ǽ��������ļ���������ǰ�ļ���
			//2.ͨ������ƻὫ���������������ļ������Ƶ���ӦĿ¼
			//3.������Ŀ¼���еĻ���ʾ�Ƿ񸲸�
			//4.������Ŀ¼ֻ����Ŀ¼

			//1.�������ĸ���
			int vinsnums = vins.size();
			if (vinsnums == 1)
			{
				//ֻ��һ��copy�����ʾ�û������﷨����ȷ
				std::cout << "�﷨����ȷ" << std::endl;
			}
			else if (vinsnums == 2)
			{
				//��һ����������������Ƿ���ȷ����ȷ�Ļ������ݿ�������ǰĿ¼
				std::string before_path = vins[1];
				//1.����ڴ������Ƿ��������ļ�
				bool exist = ExistFile(vins[1]);
				if (!exist)
				{
					std::cout << "�ļ�������" << std::endl;
					return false;
				}
				else
				{
					//�ļ����ڣ���������ǰĿ¼
					dl.CopyMyFile(vins[1],dl.CurPath());
				}
			}
			else if (vinsnums == 3)
			{
				//�����������������ݿ�����������Ŀ¼��
				std::string path2 = vins[2];
				std::string FinallyPath;
				if (path2[0] == '\\')
				{
					//����·��
					FinallyPath = dl.CurPath();
				}
				else
				{
					//���·�������ڵ�·��ƴ���ϴ�ȥ·��
					std::string nowPath = dl.CurPath();
					//���·��,����ǰ·�������·��ƴ��
					if (nowPath == "\\")
					{
						//��ǰ�Ǹ�·����ֱ��ƴ��
						FinallyPath = nowPath + vins[2];
					}
					else
					{
						//��ǰ���Ǹ�·������Ҫ�ӷָ���"\"
						FinallyPath = nowPath + '\\' + vins[2];
					}
				}
				dl.CopyMyFile(vins[1], FinallyPath);
			}
			else
			{
				std::cout << "�﷨����ȷ" << std::endl;
			}
		}
		return false;
	}

	

private:

	static void SetPath(std::string & now_path,DealDir &dl)
	{
		std::string path = dl.CurPath();
		if (path == "\\")
		{
			now_path = "\\";
			return;
		}
		now_path = path;
	}


	static bool OpenMyFile(const std::string& filePath, std::fstream& _file)
	{
		_file.open(filePath, std::ios::in);
	}

	static void CloseMysFile(std::fstream& _file)
	{
		_file.close();//�ر��ļ����
	}

	static bool  ExistFile(const std::string& filePath)
	{
		//�򿪴����ϵ�����ļ�
		std::fstream _file;
		_file.open(filePath.c_str(), std::ios::in);
		if (!_file)
		{
			return false;
		}
		else
		{
			_file.close();
			return true;
		}

	}

	static void ReturnUp(std::string &nowPath)
	{
		for (auto it = --nowPath.end(); it != nowPath.begin(); --it)
		{
			if (*it != '\\')
			{
				nowPath.erase(it);
			}
			else
			{
				if (it == nowPath.begin())
				{
					return;
				}
				else
				{
					nowPath.erase(it);
					return;
				}
			}
		}
	}


	static bool s_Judgeins(const std::string & ins)
	{
		//����ָ���
		if (allIns.find(ins) != allIns.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

