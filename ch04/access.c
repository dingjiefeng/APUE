#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
		perror("input error");
	if(access(argv[1], R_OK) < 0)
		perror("cannot access");
	else
		printf("read access ok\n");
	if(open(argv[1], O_RDONLY) < 0)
		perror("open error");
	else
		printf("open for reading OK\n");
	exit(0);
}
