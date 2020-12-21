#pragma once
#include"common.hpp"
#include"File.hpp"


//cd指令补充，回到上级目录程序崩溃，进入某个目录完善（已知路径进入）


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
		allIns.insert("less");//查看文件中的内容
	}

	//对用户输入的指令进行解析、操作
	static bool s_Dealins(const std::string& instruction, std::string& str, std::string& out_path)
	{
		//1.对指令进行分割
		std::vector<std::string> vins;
		Parsing::s_Parsing(instruction, vins, ' ');
		if (vins.size() == 0)
		{
			//用户没有输入指令
			return false;
		}
		//vins[0]是指令部分，判断指令是否正确
		bool isTrueIns = DealInsruction::s_Judgeins(vins[0]);
		if (!isTrueIns)
		{
			//用户输入的指令有问题，提示用户重新输入
			str = vins[0];
			return false;
		}
		//用户输入的指令是正确的，对用户所输入的指令进行相应的处理
		if (vins[0] == "mkdir")
		{
			//创建目录指令,vins[0]之外的内容都是要创建的内容
			for (int i = 1; i < vins.size(); ++i)
			{
				//调用创建目录的接口
				std::string path;
				std::string filename = "";
				std::string nowPath = dl.CurPath();
				if (vins[i][0] == '\\')
				{
					//绝对路径
					path = vins[i];
				}
				else
				{
					//path = '\\' + nowPath + vins[i];
					//如果是相对路径，区分第一个元素是否为根节点
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
			//创建目录指令,vins[0]之外的内容都是要创建的内容
			for (int i = 1; i < vins.size(); ++i)
			{
				//调用创建目录的接口
				std::string path;
				std::string filename = "";
				std::string nowPath = dl.CurPath();
				if (vins[i][0] == '\\')
				{
					//绝对路径
					path = vins[i];
				}
				else
				{
					//path = '\\' + nowPath + vins[i];
					//如果是相对路径，区分第一个元素是否为根节点
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
			//打印文件的内容
			if (vins.size() != 2)
			{
				return false;
			}
			//此路径可以是绝对路径也可以是相对路径
			std::string path = vins[1];//用户要进入的目录
			std::string FinallyPath;
			if (path[0] == '\\')
			{
				//绝对路径
				FinallyPath = path;
			}
			else
			{
				std::string nowPath = dl.CurPath();
				//相对路径,将当前路径与相对路径拼接
				if (nowPath == "\\")
				{
					//当前是根路径，直接拼接
					FinallyPath = nowPath + vins[1];
				}
				else
				{
					//当前不是根路径，需要加分隔符"\"
					FinallyPath = nowPath + '\\' + vins[1];
				}
			}
			dl.PrintFile(FinallyPath);
		}



		else if (vins[0] == "cd")
		{
			//后面只能是一个路径
			if (vins.size() != 2)
			{
				std::cout << "系统找不到指定的路径" << std::endl;
				return true;
			}
			//第二个参数是用户想要进入的目录
			std::string path = vins[1];//用户要进入的目录
			std::string FinallyPath;
			if (path == ".")
			{
				//在本级目录，什么都不做
				return true;
			}
			if (path == "..")
			{
				//回到上级目录
				std::string nowPath = dl.CurPath();
				
				//把路径拼接出来后使cd直接进入
				ReturnUp(nowPath);
				dl.Cd(nowPath,dl);
				SetPath(out_path, dl);//设置当前路径
				return true;
			}
			if (path[0] == '\\')
			{
				//绝对路径
				FinallyPath = path;
			}
			else
			{
				std::string nowPath = dl.CurPath();
				//相对路径,将当前路径与相对路径拼接
				if (nowPath == "\\")
				{
					//当前是根路径，直接拼接
					FinallyPath = nowPath + vins[1];
				}
				else
				{
					//当前不是根路径，需要加分隔符"\"
					FinallyPath = nowPath + '\\' + vins[1];
				}
				
			}
			//std::cout << FinallyPath << std::endl;
			dl.Cd(FinallyPath,dl);
			SetPath(out_path, dl);
		}



		else if (vins[0] == "copy")
		{
			//对磁盘上的文件按照字节拷贝
			//1.如果只有一个参数且正确的话是将待拷贝文件拷贝到当前文件夹
			//2.通配符复制会将满足条件的所有文件都复制到对应目录
			//3.待拷贝目录中有的话提示是否覆盖
			//4.待拷贝目录只能是目录

			//1.检查参数的个数
			int vinsnums = vins.size();
			if (vinsnums == 1)
			{
				//只有一个copy命令，提示用户命令语法不正确
				std::cout << "语法不正确" << std::endl;
			}
			else if (vinsnums == 2)
			{
				//有一个参数，这个参数是否正确？正确的话讲内容拷贝到当前目录
				std::string before_path = vins[1];
				//1.检查在磁盘中是否存在这个文件
				bool exist = ExistFile(vins[1]);
				if (!exist)
				{
					std::cout << "文件不存在" << std::endl;
					return false;
				}
				else
				{
					//文件存在，拷贝到当前目录
					dl.CopyMyFile(vins[1],dl.CurPath());
				}
			}
			else if (vinsnums == 3)
			{
				//有两个参数，将内容拷贝到待拷贝目录中
				std::string path2 = vins[2];
				std::string FinallyPath;
				if (path2[0] == '\\')
				{
					//绝对路径
					FinallyPath = dl.CurPath();
				}
				else
				{
					//相对路径，现在的路径拼接上待去路径
					std::string nowPath = dl.CurPath();
					//相对路径,将当前路径与相对路径拼接
					if (nowPath == "\\")
					{
						//当前是根路径，直接拼接
						FinallyPath = nowPath + vins[2];
					}
					else
					{
						//当前不是根路径，需要加分隔符"\"
						FinallyPath = nowPath + '\\' + vins[2];
					}
				}
				dl.CopyMyFile(vins[1], FinallyPath);
			}
			else
			{
				std::cout << "语法不正确" << std::endl;
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
		_file.close();//关闭文件句柄
	}

	static bool  ExistFile(const std::string& filePath)
	{
		//打开磁盘上的这个文件
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
		//查找指令表
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

