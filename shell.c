//Jennifer Yu and John Park
//11-23-16

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "readline/readline.h"
#include "readline/history.h"

/**
 * Arguments:
 *  - user input (terminal commands)
 *  - symbol used to separate (semi-colon)
 * Return value:
 *  - arr of separated terminal commands
 * Function:
 *  - splits up commands separated by a symbol
**/
char **splitnsep(char *input, char *sym) {

  //INIT
  char *temp = input;
  int i = 0;
  char **arr = (char **)(malloc(100));
  //SEPARATE
  while (temp) {
    arr[i] = strsep(&temp, sym);
    i++;
  }
  arr[i] = NULL; //NULL TERMINATE

  //RETURN
  return arr;

}

/**
 * Arguments:
 *  - arr of separated terminal commands
 * Return value:
 *  - N/A
 * Function:
 *  - forks and executes the command
**/
void forkpls(char *arr[]) {

  //FORK
  int f = fork();

  //EXECUTE
  if ( f == 0 ) { //CHILD
    execvp(arr[0], arr);
  }
  else { //PARENT
    wait(&f);
  }

}

/**
 * Arguments:
 *  - a string with terminal commands
 * Return value:
 *  - string without unnecessary spaces
 * Function:
 *  - gets rid of spaces so it can be executed
**/
char *fireblanks(char *input) {

  //INIT
  char *temp = (char*)(malloc(100));
  int i = 0;

  //
  while(input[i]) {
    if ( !(input[i]==' ' && (strlen(temp)==0 || input[i+1] == ' ' || !(input[i+1]))) ) {
      sprintf(temp, "%s%c", temp, input[i]);
    }
    i++;
  }

  //RETURN
  return temp;
}

/**
 * Arguments:
 *  - Command and the argument you are searching for
 * Return value:
 *  - location of the entered argument
 * Function:
 *  - Returns the index of the argument you are searching for, returns false otherwise
**/
int searcher(char *input[], char *search){
  int i;
  for(i=0; input[i]; i++){
    if(!(strcmp(input[i], search))){
      return i;
    }
  }
  return 0;
}


/**
 * Arguments:
 *  - The command you input
 * Return value:
 *  - N/A (it will run the command)
 * Function:
 *  - Searches the type of sign entered. Based on thatit will split the input
 *    by the sign. It will perform the approrpiate redirection before executing
 *    the command
**/
// void redir(* input){
//   int pos;
//   if ((pos = searcher(input, ">"))){
//     char *temp = input[pos+1];
//     input[pos] = 0;
//     int fd = open(temp, O_CREAT | O_RDWR, 0644);
//     dup2 (fd, STDOUT_FILENO);
//     forlpls (input);
//   }
//   else if((pos = searcher(input,">>"))){
//     char *temp = input[pos+1];
//     input[pos] = 0;
//     int fd = open(temp, O_APPEND | O_CREAT | O_RDWR, 0644);
//     dup2 (fd, STDOUT_FILENO);
//     forkpls (input);
//   }
//   else if((pos = searcher(input,"2>"))){
//     char *temp = input[ pos + 1];
//     input[pos] = 0;
//     int fd = open(temp, O_CREAT | O_RDWR, 0644);
//     dup2 (fd, STDERR_FILENO);
//     forkpls(input);
//   }
//   else if( (pos = searcher(input,"&>")) ) {
//     char *temp = input[ pos + 1];
//     input[pos] = 0;
//     int fd =open(temp, O_CREAT | O_RDWR, 0644);
//     dup2 (fd, STDOUT_FILENO);
//     dup2 (fd, STDERR_FILENO);
//     forkpls (input);
//   }
//   else if( (pos = searcher(input,"<")) ) {
//     char *temp = input[ pos + 1];
//     input[pos] = 0;
//     int fd = open(temp, O_CREAT | O_RDWR, 0644);
//     dup2(fd,STDIN_FILENO);
//     forkpls(input);
//   }
//   else if((pos = searcher(input,"|"))) {
//     char **temput = &input[pos+1];
//     input[pos] = 0;
//     int fds[2];
//     pipe(fds);
//   	int f2;
//     f2 = fork();
//     if(!f2){
//       close( fds[0] );
//   	  dup2( fds[1], STDOUT_FILENO );
//   	  forkpls( input, f );
//     }else{
//   	  int timer
//   	  wait(&timer);
//   	  close(fds[1]);
//   	  dup2(fds[0], STDIN_FILENO);
//   	  forkpls(temput);
//     }
//   }
// }

int main() {

  //INFINITE LOOP UNTIL YOU EXIT
  while (1) {
    //TAKES INPUT
    char pwd[256];
    getcwd(pwd, sizeof(pwd));
    fprintf(stdout, "%s: ", pwd);
    char input[60];
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = 0;

    //SEPARATES BY SEMICOLON
    char **pieces;
    pieces = splitnsep(input, ";");


  //PRINT PIECES
  int i;
    for (i = 0; pieces[i] != NULL; i++) {
      char * c1 = (char*)(malloc(100));
      char ** c2 = (char**)(malloc(100));

      c1 = fireblanks( pieces[i] );
      c2 = splitnsep(c1, " ");

      char *cdstr;
      //EXIT
      if( !strcmp(c2[0], "exit") ) {
	      exit(0);
      }

      //CD
      else if ( !strcmp(c2[0], "cd") ) {
        cdstr = c2[1];
        /**
        if (cdstr = " ") {
          cdstr = ".";
        }
        **/
        chdir(cdstr);
      }

      //REDIRECTOUT
      else if (strchr(c2[0], '>') || strchr(c2[0], '<') || strchr(c2[0], '|')) {
      //redir(c2[0]);
      } else {
        //EXECUTE NORMALLY
  	    forkpls(c2);
      }
    }
  }
  //END MAIN FUNCTION
  return 0;
}

/**
 * GARBAGE DUMPPP
**/
  /**
  int j = 0;
  char **pieces2;
  while (pieces[i]) {
    if (pieces[i] != " ") {
      pieces2[j] = pieces[i];
      j++;
    }
    i++;
  }
  **/
/**
  i = 0;
  while (pieces[i]) {
    printf("TK: %s\n", pieces[i]);
    i++;
  }
**/
/**
//SPLIT UP TOKENS
  char *tokens;
  tokens = (char**)tokensplit(pieces);
//PRINT EACH TOKEN
  i = 0;
  while (tokens[i]) {
    printf("%s\n", tokens[i]);
    i++;
  }
**/
/**
    execvp(arr[0], arr);

    if (errno) {
      printf("Error %d: %s\n", errno, strerror(errno));
    }
**/
/**
char **tokensplit(char *input) {
  char **arr = (char **)(malloc(100));
  char *temp = input;

  int i = 0;
  while (temp) {
    arr[i] = strsep(&temp, " ");
    i++;
  }
  arr[i] = NULL;

  return arr;
}
**/
/**
void greaterThan(char *command){
  char *file = (char *)malloc(256);
  file = command [loc+1];
  int fd = open(line, O_WRONLY | O_TRUNC | O_CREAT, 0644);
  int ft = dup( STDOUT_FILENO );
  dup2(fd, STDOUT_FILENO);
  forkpls(file);
  dup2(ft, STDOUT_FILENO);
  close(fd);
  free(file);
}
**/
/**
  // IDK HOW TO IMPLEMENT THIS PROB NOT GONNA
  int i = 0;
  while (pieces[i]) {
    pieces = (char**)splitnsep(pieces[i], " ");
    i++;
  }
**/
      /**
  while (pieces[i]) {
    printf("SC: %s\n", pieces[i]);
    i++;
  }
  **/
