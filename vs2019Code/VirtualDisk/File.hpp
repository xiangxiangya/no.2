#pragma once
#include"common.hpp"



class FileType
{
public:
	std::string m_fileName;
	//char m_fileType;
	//文件内容用什么保存
	std::wstring m_data;
};

class DirType
{
public:
	DirType()
	{
		//无参构造函数用来构造根节点
		m_dirName = "\\";
		//m_upLevel = nullptr;
		m_path = "\\";
	}

	DirType(const std::string &path,const std::string &dirname)
	{
		m_dirName = dirname;
		m_path = path;
	}

public:
	std::string m_dirName;
	//DirType* m_upLevel;//指向上一层目录的指针
	std::string m_path;//当前目录的路径
	//DirType* m_nowLevel;//当前目录的指针
	std::vector<FileType> m_allFile;//存放所有的文件
	std::vector<DirType> m_allDir;//存放所有的目录
};



class DealDir
{
public:
	DealDir()
	{
		//创建一个DirType为根目录，让root指向这个根目录
		m_root = new DirType;
		m_CurDir = m_root;
	}

	~DealDir()
	{
		delete m_root;
	}

	//创建一个目录
	bool CreateDir(const std::string& path,const std::string dirName)
	{
		//给定一个路径，在当前的目录下创建一个目录
		//假设此时的path是绝对路径
		std::vector<std::string> dirname;
		Parsing::s_Parsing(path,dirname,'\\');
		//从根的位置依次插入DirType
		DirType* flow = m_root;
		std::string in = "\\";
		for (int i = 0; i < dirname.size(); ++i) 
		{
			in = in + dirname[i]+'\\';
			//查一下
			bool exist = s_isFindDir(flow->m_allDir, dirname[i],&flow);
			if (exist)
			{
				continue;
			}
			DirType tmp = DirType(in,dirname[i]);
			flow->m_allDir.push_back(tmp);
			s_isFindDir(flow->m_allDir,dirname[i],&flow);
			flow->m_path.erase(flow->m_path.end()-1);//擦去最后的"\"
		}
		return true;
	}

	void Pwd()
	{
		std::cout << m_CurDir->m_path << std::endl;
	}

	//展示当前目录结构
	void Dir()
	{
		//对当前的CurDir遍历目录和文件
		traverse(m_CurDir->m_allDir);
		traverse(m_CurDir->m_allFile);
	}

	void Cd(const std::string & path,DealDir & dl)
	{
		std::vector<std::string> vv;
		Parsing::s_Parsing(path, vv, '\\');
		if (vv.size() == 0)
		{
			m_CurDir = m_root;
			return;
		}
		//已知一个路径想要进入这个路径，先保存当前的路径，如果路径有误的话更新m_CurDir
		DirType nowDir = **CurDir();
		m_CurDir = m_root;
		for (int i = 0; i < vv.size(); ++i)
		{
			//从根目录开始依次进入
			bool exist = s_isFindDir((*m_CurDir).m_allDir,vv[i],&m_CurDir);
			if (!exist)
			{
				*m_CurDir = nowDir;
				std::cout << "路径有误" << std::endl;
				return;
			}
		}
	}

	std::string CurPath()
	{
		return m_CurDir->m_path;
	}


	DirType** CurDir()
	{
		return &m_CurDir;
		
	}

public:

	//path为拷贝后的绝对路径
	 bool CopyMyFile(std::string &filename , const std::string &path)
	{
		//将Find指针指向待拷贝的目录
		 std::vector<std::string> vv;
		 Parsing::s_Parsing(path, vv, '\\');
		 if (vv.size() == 0)
		 {
			 if (m_CurDir != m_root)
			 {
				 m_CurDir = m_root;
				 return false;
			 }
		 }
		 m_FindDir = m_root;
		 if (path == "\\")
		 {
			 m_FindDir = m_root;
		 }
		 else 
		 {
			 for (int i = 0; i < vv.size(); ++i)
			 {
				 //从根目录开始依次进入
				 bool exist = s_isFindDir((*m_FindDir).m_allDir, vv[i], &m_FindDir);
				 if (!exist)
				 {
					 std::cout << "路径有误" << std::endl;
					 return false;
				 }
			 }
		 }
		 //Find已经指向了待插入的目录，将硬盘中的文件写入到此
		 std::vector<std::string> v;
		 Parsing::s_Parsing(filename, v, '\\');
		 std::string name = v[v.size() - 1];
		 FileType newFile;
		 newFile.m_fileName = name;//1.设置文件的名称
		 //2.设置文件的内容
		 std::wifstream fin(filename.c_str());
		 std::wstring tmp;
		 //为了将字符编码转换为GBK正常显示文件中的中文
		 while (getline(fin, tmp))
		 {
			 SetConsoleOutputCP(65001);
			 newFile.m_data = newFile.m_data + tmp + stringToWstring("\n");//解决getline读不到换行符的方法
		 }
		 m_FindDir->m_allFile.push_back(newFile);
		 SetConsoleOutputCP(936);
		return true;
	}

	 //将string类型的对象转化为wstring
	 std::wstring stringToWstring(const std::string& str)
	 {
		 LPCSTR pszSrc = str.c_str();
		 int nLen = MultiByteToWideChar(CP_ACP, 0, pszSrc, -1, NULL, 0);
		 if (nLen == 0)
			 return std::wstring(L"");

		 wchar_t* pwszDst = new wchar_t[nLen];
		 if (!pwszDst)
			 return std::wstring(L"");

		 MultiByteToWideChar(CP_ACP, 0, pszSrc, -1, pwszDst, nLen);
		 std::wstring wstr(pwszDst);
		 delete[] pwszDst;
		 pwszDst = NULL;

		 return wstr;
	 }

	 bool PrintFile(const std::string& filePath)
	 {
		 //打印文件中的内容
		 std::vector<std::string> v;
		 Parsing::s_Parsing(filePath, v, '\\');
		 if (v.size() == 0)
		 {
			 std::cout << "你输入的路径有误" << std::endl;
			 return false;
		 }
		 std::string filename = v[v.size() - 1];
		 v.pop_back();
		 m_FindDir = m_root;
		 if (v.size() == 0)
		 {
			 //在根目录下查找
			 for (int i = 0; i < m_FindDir->m_allFile.size(); ++i)
			 {
				 if (filename == m_FindDir->m_allFile[i].m_fileName)
				 {
					 //找到，打印
					 SetConsoleOutputCP(65001);
					 std::wcout << m_FindDir->m_allFile[i].m_data;
					 SetConsoleOutputCP(936);
					 return true;
				 }
			 }
			 std::cout << "没有您想要查看的文件" << std::endl;
			 return false;
		 }
		 else
		 {
			 //在对应目录下查找文件
			 for (int i = 0; i < v.size(); ++i)
			 {
				 //从根目录开始依次进入
				 bool exist = s_isFindDir((*m_FindDir).m_allDir, v[i], &m_FindDir);
				 if (!exist)
				 {
					 std::cout << "路径有误" << std::endl;
					 return false;
				 }
			 }
			 //在这个目录中找文件后打印
			 for (int i = 0; i < m_FindDir->m_allFile.size(); ++i)
			 {
				 if (filename == m_FindDir->m_allFile[i].m_fileName)
				 {
					 //找到，打印
					 SetConsoleOutputCP(65001);
					 std::wcout << m_FindDir->m_allFile[i].m_data;
					 SetConsoleOutputCP(936);
					 return true;
				 }
			 }
			 std::cout << "没有您想要查看的文件" << std::endl;
			 return false;
		 }
		 return true;
	 }

	//查找函数，给定一个路径，找到这个路径的DirType
	bool s_FindPath(const std::string& path)
	{
		m_FindDir = m_root;
		std::vector<std::string> dirname;
		//对于给定的绝对路径，切分为不同的目录名
		Parsing::s_Parsing(path, dirname, '\\');
		if (dirname.size() == 1)
		{
			//在根目录下创建
			return true;
		}
		else
		{
			//找到最终目录，创建
			for (int i = 0; i < dirname.size() - 1; ++i)
			{
				//定义临时指针接受找到后的目录

				std::string nowDirName = dirname[i];
				//从所有目录中找有没有当前的目录名
				DirType* tmp = nullptr;
				bool exist = s_isFindDir(m_FindDir->m_allDir, nowDirName, &tmp);
				if (exist == false)
				{
					//没有找到用户所提供的路径，返回false
					return false;
				}
				m_FindDir = tmp;
			}
			return true;
		}
	}

	bool s_FindPath(const std::string& path,std::vector<std::string> & dirname)
	{
		m_FindDir = m_root;
		//对于给定的绝对路径，切分为不同的目录名
		Parsing::s_Parsing(path, dirname, '\\');
		if (dirname.size() == 1)
		{
			//在根目录下创建
			return true;
		}
		else
		{
			//找到最终目录，创建
			for (int i = 0; i < dirname.size() - 1; ++i)
			{
				//定义临时指针接受找到后的目录

				std::string nowDirName = dirname[i];
				//从所有目录中找有没有当前的目录名
				DirType* tmp = nullptr;
				bool exist = s_isFindDir(m_FindDir->m_allDir, nowDirName, &tmp);
				if (exist == false)
				{
					//没有找到用户所提供的路径，返回false
					return false;
				}
				m_FindDir = tmp;
			}
			return true;
		}
	}

	
	static bool s_isFindDir(std::vector<DirType>& dir,std::string name, DirType **tmp)
	{
		//遍历vector
		for (int i = 0; i < dir.size(); ++i)
		{
			if (dir[i].m_dirName == name)
			{
				//找到的话 是否进行指针切换的操作？
				*tmp = &(dir[i]);
				return true;
			}
		}
		return false;
	}

	static bool s_isFindDir(std::vector<DirType>& dir, std::string name)
	{
		//遍历vector
		for (int i = 0; i < dir.size(); ++i)
		{
			if (dir[i].m_dirName == name)
			{
				//找到的话 是否进行指针切换的操作？
				return true;
			}
		}
		return false;
	}

	static void traverse(const std::vector<FileType>& v)
	{
		if (v.size() == 0)
		{
			return;
		}
		for (int i = 0; i < v.size()-1; ++i)
		{
			std::cout << v[i].m_fileName << "\t";
		}
		std::cout << v[v.size() - 1].m_fileName << std::endl;
	}

	static void traverse(const std::vector<DirType>& v)
	{
		if (v.size() == 0)
		{
			return;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
			FOREGROUND_BLUE);
		for (int i = 0; i < v.size()-1; ++i)
		{
			std::cout << v[i].m_dirName << "\t";
		}
		std::cout << v[v.size() - 1].m_dirName << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
			FOREGROUND_GREEN | FOREGROUND_BLUE);
	}




private:
	DirType *m_root;
	DirType* m_CurDir = nullptr;//当前目录指针指向
	DirType* m_FindDir = nullptr;//查找时用到的指针

};


