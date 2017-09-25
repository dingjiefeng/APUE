#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	buf1[] = "abcdefghij";
char	buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int	fd;
	if((fd = creat("file.hole", 777)) < 0)
		perror("create file fail");
	if(write(fd, buf1, 10) != 10)
		perror("write buf1 fail");
	if(lseek(fd, 16348, SEEK_SET) == -1)
		perror("lseek fail");
	if(write(fd, buf2, 10) < 10)
		perror("write bu2 fail");
	exit(0);
}
