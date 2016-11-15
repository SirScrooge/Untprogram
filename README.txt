==============================================================================
                MAJOR PROJECT 1 - The Shell and System Calls

Created by:
            (Group 24)
            Nicholas Partridge
            Samuel Malenfant
            Andrew Jenkins
            Andrew Clark


Basic Design Outline:
           This program is designed to imitate a shell by using
system calls and appropriate tokenized strings to run commands. If the
 user supplies an incorrect number of batch files or the batch file
cannot be found, the shell will error and exit out. If the batch file
 is found, the shell will enter Batch Mode. the commands from the batch
file will run, as long as they are semi-colon separated, line by line.
                 If the user only supplies the inital shell command,
the shell will enter Interactive Mode. This mode allows
 the user to input their desired commands directly to the shell, as long
as they are also inputted as a semi-colon separated list.
 At anytime in interactive mode, if the user enters "quit" as a command
(by itself), the shell will exit.

Structure:
           The shell initializes with the command ./shell, thanks to the
supplied makefile. If no batchfile is supplied (argc == 1), then the shell
 enters the Interactive Mode loop. This loop cycles through each supplied
command, and runs them until there are no commands left.
           If a proper Batch file is supplied while starting the shell,
the shell will open the batch file, double check that it is properly opened
 and then it will enter the Batch Mode loop.
The Batch Mode loop also tokenizes each command, but does it for the entire
batch file. The loop continues until no more commands are found (EOF), and
then closes the file and exits the shell.

Specification:
           Our shell is able to handle such ambiguities such as
an improper batchfile being supplied, or the batchfile supplied
 was unable to open. Also, our program is able to correctly omit
semi-colons from commands if more than one is being supplied.
 The shell also will take care of improper commands by attempting
to run them, but then printing an error if a certain command was
 unable to run. We did attempt to add the ability to allow the
user to change his/her prompt, but due to the mountains of errors
 we encounted while trying to implement it properly, it was left
out of the final design.

Known Bugs:
 1) Shell does not have signal capturing capabilities.
  - Using control-D does not stop the shell, it will display an error message
    and continue to display the prompt. Using control-C or control-Z will exit t$
  - Aside from using control-(signaling method), the user can type in "quit" by $
    the shell will exit.

 2) Shell will not quit when "quit" is entered on lines with commands present.
  - If "quit" is not entered on a line by itself, the shell will execute the oth$
    commands and will not exit the shell.
      EX) quit ; ls -l / ls | wc ; ps ; quit
        - Each of theses cases will not quit the shell before running other comm$

 3) Shell does not handle directory redirects.
  - Program cannot handle commands related to directory changes.
      EX) cd abc1234/cs3600




