#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
enum {READ, WRITE}; // values of 0 and 1. enum for easier understanding of pipe open/close

int main(int argc, char **argv)
{	
	FILE *infile = fopen(argv[1], "r");
	if(infile == NULL)
	{
		perror("Error ");
		return 1;
	}
	
	char line[120];

	while(fgets(line, sizeof(line), infile))
	{
		printf("batch line >> %s\n", line);
		

	}

	return 0;
}