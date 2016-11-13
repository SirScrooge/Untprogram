#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int pip(char *input);
int main()
{
	//Check if program is to run batch mode
	
	//Run interactive mode if
	//
	int i=0;
	int j=0;
	char *string;
	char *input;
	char *p;
	//char tok[100];
	while(1)
	{
		
		printf("Prompt> ");
    	scanf("%s",string);                     //scans user input
		input=strtok(string,";");  		//puts substrings from string into input commands
		//i=0;
		/*while((getchar(input))!=NULL)
		{
			tok[i]=getchar(input);
		}*/
		while(input!=NULL)	//executes commands
		{
			/*i=0;
			while(tok[i]!="|"||tok[i]!=NULL||tok[i]!=";")
			{
				if(tok[i]=="|")
				{
					pip(input);
					break;
				}
				else
				{
					i++;
				}	
			}		*/
			//if(fork()==0)
		//	{	
			if(input=="quit\n")
			{
				exit(1);
			}	
			char *arg[]={input,NULL};
			execvp(input,arg);
			input=strtok(NULL,";");
		//	}	
			
		}

	}	
}  
/*int pip(char *input)
{
	int fd[2];
	pipe(fd);	//creates a pipe
	char *cmd[2];
	cmd[0]=strtok(input,"|");
	cmd[1]=strtok(NULL,"|");
	if (fork()==0)
	{
		
		dup2(fd[1],1); //puts output into pipe
		close(fd[0]);
		close(fd[1]);
		
		char *arg[]={cmd[0],NULL};
		execvp(cmd[0],arg);	//does the first argument
		exit(1);
	}
	else if(fork()==0)
	{
		dup2(fd[0],0);		//reads the input from pipe
		close(fd[0]);
		close(fd[1]);
		char *arg[]={cmd[1],NULL};
		execvp(cmd[1],arg);	//does 2nd argument	
		exit(1);
	}
	else 
	{
		
		close(fd[0]);
		close(fd[1]);
		
		wait();
		wait();
		printf("command line pipe completed.\n");
	}

}	
*/
