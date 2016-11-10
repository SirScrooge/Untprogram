//Shell.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>  //strtok()
#include <signal.h> //ctrl-c quit

#define MAX_LENGTH 512 	//max length for a single command to 512 characters
#define READ 0		//read index
#define WRITE 1 	//write index

void run_batch();
void run_interactive();
	
int main(int argc, char *argv[]){

int fd[2];		  //file descriptor variable
char * token; 	  //temporary pointer to tokenize command for processing
char  buffer[MAX_LENGTH]; //parent processing buffer
//char * temp_cmd[100];

    pipe(fd);	//create pipe in parent

    if (argc > 2){
	printf("Usage: ./shell [batchFile] \nerror- too many arguments (%i)!\n", argc);
	exit(0);
    }
    else if(argc == 2)
    {
	run_batch();
    }
    else if (argc == 1)
    {
	run_interactive();	
    }

    return 0;
}

void run_batch()
{
	
}

void run_interactive()
{
        printf("*** interactive mode ***\n");

	while (1){
	    printf("prompt> ");

	    fgets (buffer, MAX_LENGTH, stdin);
	    token = strtok (buffer, ";\n");
	    while (token != NULL){

	    }
        }	
}
