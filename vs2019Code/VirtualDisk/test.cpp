#define _CRT_SECURE_NO_WARNINGS

#if 0
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
std::string path = "C:\\Users\\岳\\Desktop\\test\\hello.txt";


string UTF8ToGB(const char* str)
{
    string result;
    WCHAR* strSrc;
    LPSTR szRes;

    //获得临时变量的大小
    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i + 1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    //获得临时变量的大小
    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new CHAR[i + 1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    result = szRes;
    delete[]strSrc;
    delete[]szRes;

    return result;
}

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    ifstream in;
    in.open(path);

    string s;
    //getline(t, s);
    //out << s << "\n";

    while (std::getline(in, s))
    {
        string str = UTF8ToGB(s.c_str()).c_str();
        //对每一行进行操作。
        cout << s << endl;

    }
   
    in.close();


    system("pause");
    return 0;
}
#endif



#if 0
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
std::string path = "C:\\Users\\岳\\Desktop\\test\\hello.txt";


void  ReadDataFromFileLBLIntoString()
{
    wifstream fin(path.c_str());
    
    wstring s;
    while (getline(fin, s))
    {
        //int a = 10;
        //fin.imbue(locale("chs"));
        wcout << "Read from file: " << s << endl;
    }

}

int main()
{
    SetConsoleOutputCP(65001);
    ReadDataFromFileLBLIntoString();
    return 0;
}
#endif