#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
int rows=10, starNo, spaceNo;




	
	char input[100] =   { 0 };	        
	//system("shutdown -s -t 60");
     printf("        #  #  #     #  #  #        \n");
     printf("     #                       #     \n");
     printf("  #     圣诞快乐我滴宝贝er！    #  \n");
     printf("  #                             #  \n");
     printf("     #        lyy&yhx           #     \n");
     printf("        #                 #        \n");
     printf("           #           #           \n");
     printf("              #     #              \n");
     printf("                 #                 \n");
	 for (int i = 1; i <= rows; i++)
	 {
		 starNo = i * 2 - 1;
		 spaceNo = i + rows - starNo;
		 for (int j = 0; j<spaceNo; j++)
		 {
			 printf("%c", ' ');
		 }
		 for (int k = 0; k<starNo; k++)
		 {
			 printf("%c", '*');
		 }
		 printf("\n");
	 }

	 for (int l = 0; l<3; l++)
	 {
		 for (int m = 0; m<(rows * 2 + 1) / 2; m++)
		 {
			 printf("%c", ' ');
		 }
		 printf("%c\n", '*');
	 }
 /*again:
	printf("电脑将在1分钟内关机，如果输入：岳浩翔我爱你，就取消关机!\n请输入:>");
	scanf("%s", input);
	if (0 == strcmp(input, "岳浩翔我爱你"))
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}*/																													  
	return 0;
}