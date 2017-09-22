#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("the pid of the process is:%ld\n",(long)getpid());
	exit(0);
}
