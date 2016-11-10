/*

Name: Nicholas Partridge (# 10730618)
Date: 11/7/2016
Instructor: Dr. Mark Thompson
Description: This program implements a CLA pipe by using 2 child
	     processes to pass in the arguments from the command
	     line.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum { READ, WRITE};

int main(int argc, char *argv[]){

	int fd[2];
	char * temp_1[] = {argv[1], NULL};
	char * temp_2[] = {argv[2], NULL};

//argument count check (makes sure 2 arguments are supplied)
	if ((argc < 3) || (argc > 3)){
		printf ("error: too few or too many arguments: %i \n", argc);
		exit(1);
	}
//create pipe
	if (pipe(fd) == -1){
		perror("Pipe");
		exit(2);
	}

//create first child process
	if (fork() == 0){
		dup2(fd[WRITE], fileno(stdout));
		close(fd[READ]);
		close(fd[WRITE]);
		execvp(temp_1[0], temp_1);
	}

	else{
//create second child process
		if (fork() == 0){
			printf("executing: %s | %s \n", *temp_1, *temp_2);
			dup2(fd[READ], fileno(stdin));
			close(fd[READ]);
			close(fd[WRITE]);
			execvp(temp_2[0], temp_2);
		}
	}
//doubly make sure that the read and write ends of the pipe are closed
close(fd[READ]);
close(fd[WRITE]);

//wait for children to finish
	wait();
	wait();
printf("command line pipe completed\n");
	return 0;
}
