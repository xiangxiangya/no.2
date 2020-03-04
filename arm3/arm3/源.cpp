#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<unistd.h>


#if 0
int main()
{
	pid_t pid1 = 0;
	pid1 = fork();
	if (pid1<0)
	{
		printf("error\n");
	}
	else if (pid1 == 0)
	{
		execl("./test1", "./test1", NULL);
	}
	else{
		wait(NULL);
		pid_t pid2 = 0;
		if (pid2<0)
		{
			printf("error\n");
		}
		else if (pid2 == 0)

{
	execl("./test2", "./test2", NULL);
}
else
{
	wait(NULL);
	pid_t pid3 = 0;
	if (pid3<0)
	{
		printf("error");
	}
	else if (pid3 == 0)
	{
		execl("./test3", "./test3", NULL);
	}
	else
	{
		wait(NULL);
	}
}
  }
  return 0;
}
#endif


int main()
{
	pid_t pid1 = 0;
	pid1 = fork();
	if (pid1 < 0)
	{
		printf("error\n");
	}
	else if (pid1 == 0)
	{
		execl("./test1", "./test1", NULL);
	}
	else{
		wait(NULL);
	}


	pid_t pid2 = 0;
	pid2 = fork();
	if (pid2 < 0)
	{
		printf("error\n");
	}
	else if (pid2 == 0)
	{
		execl("./test2", "./test2", NULL);
	}
	else{
		wait(NULL);
	}

	pid_t pid3 = 0;
	pid3 = fork();
	if (pid3 < 0)
	{
		printf("error\n");
	}
	else if (pid3 == 0)
	{
		execl("./test3", "./test3", NULL);
	}
	else{
		wait(NULL);
	}

	return 0;
}
