#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;

	printf("Parent Process Started\n");
	printf("Parent PID: %d\n",getpid());

	pid = fork();

	if(pid < 0)
	{
		printf("Process creation Failed\n");
	}
	else if (pid ==0)
	{
		printf("\nChild Process\n");
		printf("Child PID: %d\n",getpid());
		printf("Parent PID: %d\n",getppid());
		execl("/bin/ls","ls","-l",NULL);
		printf("Exec Failed\n");
	}
	else
	{
		wait(NULL);
		printf("\nChild Process Completed\n");
		printf("Parent Process exiting\n");
	}
	return 0;
}
