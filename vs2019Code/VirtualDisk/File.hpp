#pragma once
#include"common.hpp"



class FileType
{
public:
	std::string m_fileName;
	//char m_fileType;
	//�ļ�������ʲô����
	std::wstring m_data;
};

class DirType
{
public:
	DirType()
	{
		//�޲ι��캯������������ڵ�
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
	//DirType* m_upLevel;//ָ����һ��Ŀ¼��ָ��
	std::string m_path;//��ǰĿ¼��·��
	//DirType* m_nowLevel;//��ǰĿ¼��ָ��
	std::vector<FileType> m_allFile;//������е��ļ�
	std::vector<DirType> m_allDir;//������е�Ŀ¼
};



class DealDir
{
public:
	DealDir()
	{
		//����һ��DirTypeΪ��Ŀ¼����rootָ�������Ŀ¼
		m_root = new DirType;
		m_CurDir = m_root;
	}

	~DealDir()
	{
		delete m_root;
	}

	//����һ��Ŀ¼
	bool CreateDir(const std::string& path,const std::string dirName)
	{
		//����һ��·�����ڵ�ǰ��Ŀ¼�´���һ��Ŀ¼
		//�����ʱ��path�Ǿ���·��
		std::vector<std::string> dirname;
		Parsing::s_Parsing(path,dirname,'\\');
		//�Ӹ���λ�����β���DirType
		DirType* flow = m_root;
		std::string in = "\\";
		for (int i = 0; i < dirname.size(); ++i) 
		{
			in = in + dirname[i]+'\\';
			//��һ��
			bool exist = s_isFindDir(flow->m_allDir, dirname[i],&flow);
			if (exist)
			{
				continue;
			}
			DirType tmp = DirType(in,dirname[i]);
			flow->m_allDir.push_back(tmp);
			s_isFindDir(flow->m_allDir,dirname[i],&flow);
			flow->m_path.erase(flow->m_path.end()-1);//��ȥ����"\"
		}
		return true;
	}

	void Pwd()
	{
		std::cout << m_CurDir->m_path << std::endl;
	}

	//չʾ��ǰĿ¼�ṹ
	void Dir()
	{
		//�Ե�ǰ��CurDir����Ŀ¼���ļ�
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
		//��֪һ��·����Ҫ�������·�����ȱ��浱ǰ��·�������·������Ļ�����m_CurDir
		DirType nowDir = **CurDir();
		m_CurDir = m_root;
		for (int i = 0; i < vv.size(); ++i)
		{
			//�Ӹ�Ŀ¼��ʼ���ν���
			bool exist = s_isFindDir((*m_CurDir).m_allDir,vv[i],&m_CurDir);
			if (!exist)
			{
				*m_CurDir = nowDir;
				std::cout << "·������" << std::endl;
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

	//pathΪ������ľ���·��
	 bool CopyMyFile(std::string &filename , const std::string &path)
	{
		//��Findָ��ָ���������Ŀ¼
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
				 //�Ӹ�Ŀ¼��ʼ���ν���
				 bool exist = s_isFindDir((*m_FindDir).m_allDir, vv[i], &m_FindDir);
				 if (!exist)
				 {
					 std::cout << "·������" << std::endl;
					 return false;
				 }
			 }
		 }
		 //Find�Ѿ�ָ���˴������Ŀ¼����Ӳ���е��ļ�д�뵽��
		 std::vector<std::string> v;
		 Parsing::s_Parsing(filename, v, '\\');
		 std::string name = v[v.size() - 1];
		 FileType newFile;
		 newFile.m_fileName = name;//1.�����ļ�������
		 //2.�����ļ�������
		 std::wifstream fin(filename.c_str());
		 std::wstring tmp;
		 //Ϊ�˽��ַ�����ת��ΪGBK������ʾ�ļ��е�����
		 while (getline(fin, tmp))
		 {
			 SetConsoleOutputCP(65001);
			 newFile.m_data = newFile.m_data + tmp + stringToWstring("\n");//���getline���������з��ķ���
		 }
		 m_FindDir->m_allFile.push_back(newFile);
		 SetConsoleOutputCP(936);
		return true;
	}

	 //��string���͵Ķ���ת��Ϊwstring
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
		 //��ӡ�ļ��е�����
		 std::vector<std::string> v;
		 Parsing::s_Parsing(filePath, v, '\\');
		 if (v.size() == 0)
		 {
			 std::cout << "�������·������" << std::endl;
			 return false;
		 }
		 std::string filename = v[v.size() - 1];
		 v.pop_back();
		 m_FindDir = m_root;
		 if (v.size() == 0)
		 {
			 //�ڸ�Ŀ¼�²���
			 for (int i = 0; i < m_FindDir->m_allFile.size(); ++i)
			 {
				 if (filename == m_FindDir->m_allFile[i].m_fileName)
				 {
					 //�ҵ�����ӡ
					 SetConsoleOutputCP(65001);
					 std::wcout << m_FindDir->m_allFile[i].m_data;
					 SetConsoleOutputCP(936);
					 return true;
				 }
			 }
			 std::cout << "û������Ҫ�鿴���ļ�" << std::endl;
			 return false;
		 }
		 else
		 {
			 //�ڶ�ӦĿ¼�²����ļ�
			 for (int i = 0; i < v.size(); ++i)
			 {
				 //�Ӹ�Ŀ¼��ʼ���ν���
				 bool exist = s_isFindDir((*m_FindDir).m_allDir, v[i], &m_FindDir);
				 if (!exist)
				 {
					 std::cout << "·������" << std::endl;
					 return false;
				 }
			 }
			 //�����Ŀ¼�����ļ����ӡ
			 for (int i = 0; i < m_FindDir->m_allFile.size(); ++i)
			 {
				 if (filename == m_FindDir->m_allFile[i].m_fileName)
				 {
					 //�ҵ�����ӡ
					 SetConsoleOutputCP(65001);
					 std::wcout << m_FindDir->m_allFile[i].m_data;
					 SetConsoleOutputCP(936);
					 return true;
				 }
			 }
			 std::cout << "û������Ҫ�鿴���ļ�" << std::endl;
			 return false;
		 }
		 return true;
	 }

	//���Һ���������һ��·�����ҵ����·����DirType
	bool s_FindPath(const std::string& path)
	{
		m_FindDir = m_root;
		std::vector<std::string> dirname;
		//���ڸ����ľ���·�����з�Ϊ��ͬ��Ŀ¼��
		Parsing::s_Parsing(path, dirname, '\\');
		if (dirname.size() == 1)
		{
			//�ڸ�Ŀ¼�´���
			return true;
		}
		else
		{
			//�ҵ�����Ŀ¼������
			for (int i = 0; i < dirname.size() - 1; ++i)
			{
				//������ʱָ������ҵ����Ŀ¼

				std::string nowDirName = dirname[i];
				//������Ŀ¼������û�е�ǰ��Ŀ¼��
				DirType* tmp = nullptr;
				bool exist = s_isFindDir(m_FindDir->m_allDir, nowDirName, &tmp);
				if (exist == false)
				{
					//û���ҵ��û����ṩ��·��������false
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
		//���ڸ����ľ���·�����з�Ϊ��ͬ��Ŀ¼��
		Parsing::s_Parsing(path, dirname, '\\');
		if (dirname.size() == 1)
		{
			//�ڸ�Ŀ¼�´���
			return true;
		}
		else
		{
			//�ҵ�����Ŀ¼������
			for (int i = 0; i < dirname.size() - 1; ++i)
			{
				//������ʱָ������ҵ����Ŀ¼

				std::string nowDirName = dirname[i];
				//������Ŀ¼������û�е�ǰ��Ŀ¼��
				DirType* tmp = nullptr;
				bool exist = s_isFindDir(m_FindDir->m_allDir, nowDirName, &tmp);
				if (exist == false)
				{
					//û���ҵ��û����ṩ��·��������false
					return false;
				}
				m_FindDir = tmp;
			}
			return true;
		}
	}

	
	static bool s_isFindDir(std::vector<DirType>& dir,std::string name, DirType **tmp)
	{
		//����vector
		for (int i = 0; i < dir.size(); ++i)
		{
			if (dir[i].m_dirName == name)
			{
				//�ҵ��Ļ� �Ƿ����ָ���л��Ĳ�����
				*tmp = &(dir[i]);
				return true;
			}
		}
		return false;
	}

	static bool s_isFindDir(std::vector<DirType>& dir, std::string name)
	{
		//����vector
		for (int i = 0; i < dir.size(); ++i)
		{
			if (dir[i].m_dirName == name)
			{
				//�ҵ��Ļ� �Ƿ����ָ���л��Ĳ�����
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
	DirType* m_CurDir = nullptr;//��ǰĿ¼ָ��ָ��
	DirType* m_FindDir = nullptr;//����ʱ�õ���ָ��

};


