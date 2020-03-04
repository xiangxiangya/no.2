#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h> 
#include<Windows.h>
int main()
{
	float y, x, z;
	system("COLOR fc");
	printf("那一天\n");
	Sleep(1000);
	printf("第一次遇见你\n");
	Sleep(1000);
	printf("忘不了\n");
	Sleep(1000);
	printf("你的容颜\n");	Sleep(1000);
	printf("若轻云之蔽月,如流风之回雪\n");	Sleep(1000);
	printf("\n\n\n");	Sleep(1000);
	printf("其实\n");	Sleep(1000);
	printf("有一句话\n");	Sleep(1000);
	printf("我一直想对你说:\n");	Sleep(3000);

	int i = 0;
	char buf[102] = { 0 };
	char str[] = "|/-\\";
	while (i <= 100){
		printf("[%-100s][%d%%][%c]\r", buf, i, str[i % 4]);
		//fflush(stdout);
		buf[i++] = '#';
		Sleep(68);
	}
	
	printf("\n");
	for (double y = 2.5; y >= -1.6; y = y - 0.2)
	{
		for (double x = -3; x <= 4.8; x = x + 0.1)
		{
			(pow((x*x + y*y - 1), 3) <= 3.6*x*x*y*y*y
				|| (x>-2.4 && x<-2.1 && y<1.5 && y>-1)
				|| (((x<2.5 && x>2.2) || (x>3.4 && x<3.7)) && y>-1 && y<1.5)
				|| (y>-1 && y<-0.6 && x<3.7 && x>2.2)) ? printf("*") : printf(" ");
		}

		printf("\n");
	}
	printf("我想和你在一起！\n");
	getchar();

	system("pause");
	return 0;
}