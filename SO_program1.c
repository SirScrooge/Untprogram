/*
this program waas gathered from StackOverflow
http://stackoverflow.com/questions/12681034/parsing-input-with-strtok-in-c
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int parseCommands(char *command, char **args){
    int pos = 0;
    printf("%s\n", command);
    char *readCommand = NULL;
    char delims[] = {" \n"};
    readCommand = strtok(command, delims);
    while(readCommand != '\0'){
        printf("%s\n", readCommand); 
        strcpy(args[pos], readCommand);
        printf("%s\n", args[pos]);
        readCommand = strtok(NULL, delims);
        pos++;
    }
    return pos;
}

int executeCommand(char **args){
    pid_t pID;
    switch(pID = fork()){
        case 0:
            execvp(args[0], args);
            perror("Some sort of exec error");
            return -1;
        case -1:
            perror("Could not even fork");
            return -2;
        default:
            wait(NULL);
            return 0;
    }
}

void main(){

    char wd[256];
    char input[256];
    char *args[15];

    char strDelims[] = ";";
    char *readInput = NULL;

    while(1){

        getcwd(wd, sizeof wd);
        printf("mysh: %s> ", wd);
        fgets(input, sizeof input, stdin);

        readInput = strtok(input, strDelims);

        int numArgs;
        numArgs = parseCommands(readInput, args);
            if(numArgs < 1)
                printf("There was a problem parsing the command\n");

            if(strcmp(args[0], "cd") == 0){
                printf("%d\n", numArgs);
                if(numArgs > 1){
                    if((chdir(args[1])) < 0){
                        perror("I'm afraid I can't let you do that Dave\n");
                    }
                }
                else{
                    if((chdir(getenv("HOME"))) < 0){
                        perror("Can't go home\n");
                    }
                }
            }
            else if(strcmp(readInput, "quit") == 0){
                break;
            }
            else{
                if((executeCommand(args)) != 0)
                    printf("Problem executing the command\n");
            }
            readInput = strtok(input, strDelims);
    }

}
