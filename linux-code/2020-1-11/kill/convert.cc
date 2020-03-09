#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<string>

int main()
{
    //char str[]="123456";
    //int num=0;
    //sscanf(str,"%d",&num);
    //printf("%d\n",num);
    

    //std::stringstream ss;
    //std::string s="1234";
    //int num=0;
    //ss<<s;
    //ss>>num;
    //std::cout<<num;
    
    std::string s="100";
    int num=std::stoi(s);
    std:: cout<<num<<std::endl;
    return 0;
}
