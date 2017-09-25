#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	if(open("tempfile", O_RDWR) < 0)
		perror("open error");
	if(unlink("tempfile") < 0)
		perror("unlink error");
	printf("file unlinked\n");
	sleep(15);
	printf("done\n");
	exit(0);
}
