# Untprogram
~Implement a Shell~

•	Can be ran in both Interactive and Batch modes

Interactive Mode:
•	Display a prompt and allow user to type in a command


Batch Mode:
•	Shell starts with a batchfile being specified (i.e. started by calling Shell [BatchFile])
o	Batch file will contain a prompt and semi-colon separated commands
o	Error checking must be done at this step (improper batchfile specified, like if it cannot be found or can’t be written to)
o	Commands from the batchfile must be ran concurrently (i.e. minor 6)

•	Shell shouldn’t print the next prompt (or allow user input) until all commands have finished
o	Use wait() and waitpid() to accomplish this

•	User can type “quit” to exit the shell
o	All commands must be finished before the program exits.
NOTE: In addition, the shell must be able to recognize 2 commands (exit and cd). These work by calling exit and chdir





Requirements:

o	Invoked by using shell [BatchFile]

o	Defensive programming – All inputs must be idiot proof (i.e. error messages if improper user input is received )

Consider these situations as errors:
o	Incorrect number of arguments to the shell command
o	Batchfile doesn’t exist or can’t be opened
-For these cases, a message needs to be printed to stderr & the shell exits

For this situation:
o	A command doesn’t exist or can’t be executed from the batchfile
-If this occurs, a message should be printed to stderr and the shell should continue 
(note: this is optional, but being able to handle a command longer than 512 by printing to stderr and continuing to operate)

Be able to handle:
o	An empty command line
o	Extra white space
o	Batch file ends without quit or the user types Ctrl-D
o	Oddly formatted command lines (this one may print an error)
-All of these situations should allow the shell to continue without an error message (besides the oddly formatting command lines)

Also: The shell should recognize 2 internal commands: exit and cd.exit
o	The shell calls exit
o	cd.exit uses chdir() to change to the new directory


Must Include:

o	README file:
o	Our names
o	Design overview
o	Complete spec
o	Known bugs

o	Makefile (done)
o	Must compile into shell 
o	Must have a clean function
