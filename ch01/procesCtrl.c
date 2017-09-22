#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 4096

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");
	while(fgets(buf, MAXLINE, stdin) != NULL) {
		if(buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf)-1] = 0;
		if((pid = fork()) < 0) {
			perror("fork error");
			return 0;
		}else if(pid == 0) { /*child*/
			execlp(buf, buf, (char *)0);
			perror("could not execute this");
			exit(127);
		}
		/*parent*/
		if((pid = waitpid(pid, &status, 0)) < 0)
			return -1;
		printf("%% ");
	}
	exit(0);
}
