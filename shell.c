/*
Group Number 24: Nicholas Partridge, Samuel Malenfant, Andrew Clark, Andrew Jenkins
Course Info: CSCE 3600 - 004 / Dr. Thompson
Date: 11/14/16
Project: Major 1
Description: Implement a basic shell program that can run an interactive mode which
	prompts for continuous user input until the program is exited
	or a batch mode which accepts a command line argument which is a file name.
	Within the files are commands which are to be run line by line.
*/
#include <stdio.h> //printf, fgets
#include <stdlib.h> //exit
#include <string.h>  //strtok,strcmp
#define MAX_LENGTH 512  //max length for a single command to 512 characters

int main(int argc, char *argv[]){

char * token;     //temporary pointer to tokenize command for processing
char  buffer[MAX_LENGTH]; //parent processing buffer

    if (argc > 2){	 //if wrong # of arguments supplied, exit the shell
        printf("Usage: ./shell [batchFile] \nerror- too many arguments (%i)!\n", argc);
        exit(0);
    }

    else if (argc == 1){ //if shell is to run in interactive mode
        printf("*** interactive mode ***\n");

        while (1){ 	 //run continuously until quit is signaled
            printf("prompt> ");
            fgets (buffer, sizeof(buffer), stdin); //grab the string from the command line

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
	fclose(infile);
    }//else if

    return 0;
}//main

