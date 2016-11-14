#include <stdio.h> //printf, fgets
#include <stdlib.h> //exit
#include <string.h>  //strtok,strcmp
#define MAX_LENGTH 512  //max length for a single command to 512 characters

int changePrompt(char[], char[]);

int main(int argc, char *argv[]){


char * token;     //temporary pointer to tokenize command for processing
char  buffer[MAX_LENGTH]; //parent processing buffer

    if (argc > 2){	 //if wrong # of arguments supplied, exit the shell
        printf("Usage: ./shell [batchFile] \nerror- too many arguments (%i)!\n", argc);
        exit(0);
    }

    else if (argc == 1){ //if shell is to run in interactive mode
        printf("*** interactive mode ***\n");

	char prompt[50] = "prompt-> ";
	char newPrompt[50];
	printf("Enter prompt or press ENTER for default prompt: ");
	fgets(newPrompt, 50, stdin);
	if(newPrompt[0] != '\n')
	{
		changePrompt(prompt, newPrompt);
	}
        while (1){ 	 //run continuously until quit is signaled
            printf("%s", prompt);
            fgets (buffer, sizeof(buffer), stdin); //grab the string from the command line
	    if(buffer[1] == '\0')
		continue;
	    token = strtok (buffer, ";\n");	//tokenize until ; or \n is found
      	    if (strcmp(token, "quit") == 0){	//if user enters quit, exit the shell
		exit(1);
	    }//nested if
            while (token != NULL){	//while there are still tokens to be run, continue
        
		system(token);
	        token = strtok(NULL, ";"); //remove the previous token
            
	    }//2nd while
	}//1st while
    }//else if
    else if (argc == 2){	//if a batch file is supplied, run batch mode
	FILE *infile = fopen(argv[1], "r");

        if(infile == NULL){
	    perror("Error ");
	    return 1;
	}//if
	printf ("*** batch mode ***\n");
        char line[MAX_LENGTH];

   	while(fgets(line, sizeof(line), infile)){	//grab each line for processing
            printf("\nbatch line> %s\n", line);
            token = strtok(line, ";\n");	//tokenize until ; or \n is found

	    while (token != NULL){	//while the token is still valid
                system(token);
                token = strtok(NULL, ";\n");	//remove previous token
            }//2nd while
        }//1st while

    }//else if

    return 0;
}//main


int changePrompt(char str[], char newstr[])
{
	int i;
	for(i = 0; newstr[i]; i++)
	{
		str[i] = newstr[i];
	}
	str[i - 1] = 0;
	return 0;
}
