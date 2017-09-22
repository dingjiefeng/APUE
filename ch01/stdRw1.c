#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int 	c;
	while((c = getc(stdin)) != EOF)
	{
		if(putc(c, stdout) == EOF)
		{
			perror("output error");
			return 0;
		}
	}
	if(ferror(stdin))
	{
		perror("input error");
		return 0;
	}
	exit(0);
}
