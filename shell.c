#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	//Check if program is to run batch mode
	
	//Check for and Run interactive mode if batch mode not specified
	
	int i=0;
	char *string;
	char *input[100];
	printf("Prompt>	");
	scanf("%s",string);			//scans user input
	while(string!=NULL)
	{
		input[i]=strtok(string,";");		//puts substrings from string into input commands
		i++;
	}	
}	
  
