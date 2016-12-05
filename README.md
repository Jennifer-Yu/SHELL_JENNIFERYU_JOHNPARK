# SHELL_JENNIFERYU_JOHNPARK
JJSHELL
by Jennifer Yu and John Park

Features:
- can parse the commands!
- can fork and execute!
- can exit!
- can cd!
- can redirectout!
- can do pretty much anything and everything!! except, you know, everything

Attempted:
- the garbage dump commented out contains failure
- redirection
- pipes

Bugs:
- cd + space is supposed to bring you back to the home directory. but ours doesn't
- redirectin has some serious issues!!
- pipes may not be functional

Files & Function Headers:

shell.c

char **splitnsep(char *input, char *sym);

 * arguments: user input (terminal commands), symbol used to separate (semi-colon)
 * return value: arr of separated terminal commands
 * function: splits up commands separated by a symbol


void forkpls(char *arr[]);

 * arguments: arr of separated terminal commands
 * return value: N/A
 * function: forks and executes the command

char *fireblanks(char *input);

 * arguments: a string with terminal commands
 * return value: string without unnecessary spaces
 * function: gets rid of spaces so it can be executed
 
int searcher(char *input[], char *search);
 
 * Arguments: Command and the argument you are searching for
 * Return value: location of the entered argument
 * Function:Returns the index of the argument you are searching for, returns false otherwise
 
void redir(* input);

 * Arguments: The command you input
 * Return value: N/A (it will run the command)
 * Function: Searches the type of sign entered. Based on thatit will split the input by the sign. It will perform the approrpiate redirection before executing the command.
