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
	int i = 0;

	while(fgets(line, sizeof(line), infile))
	{
		printf("batch line >> %s\n", line);
		
		for(i; i < strlen(line); i++)
		{
			if(line[i] == ';')
			{
				printf("; is here\n");
			}
		}

	}

	return 0;
}
