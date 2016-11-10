#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	//Check if program is to run batch mode
	
	//Run interactive mode if
	
	int i=0;
	int j=0;
	char *string;
	char *input[100];
	if(argc==1)
	{
		printf("Prompt>	");
		scanf("%s",string);			//scans user input
		while(string!=NULL)
		{
			input[i]=strtok(string,";");		//puts substrings from string into input commands
			i++;
		}
		for(j=0;j<i;j++)	//executes commands
		{
			char *arg[]={input[i],NULL};
			execvp(input[i],arg);
		}
	}	
}  
