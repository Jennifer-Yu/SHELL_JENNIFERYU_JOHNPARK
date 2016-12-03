//Jennifer Yu and John Park
//11-23-16

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * arguments:
 *  - user input (terminal commands)
 *  - symbol used to separate (semi-colon)
 * return value:
 *  - arr of separated terminal commands
 * function:
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
 * arguments:
 *  - arr of separated terminal commands
 * return value:
 *  - N/A
 * function:
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
 * arguments:
 *  - a string with terminal commands
 * return value:
 *  - string without unnecessary spaces
 * function:
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



int main() {

  //INFINITE LOOP UNTIL YOU EXIT
  while (1) {

    //TAKES INPUT
    printf("What would you like to do? ");
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
      else if ( !strcmp(c2[0], ">") ) {
        // redirectout(command[0]);
      }
      //REDIRECTIN
      else if ( !strcmp(c2[0], "<") ) {
        // redirectin(command[0]);
      }
      else if ( !strcmp(c2[0], "|") ) {
        // pipes(command[0]);
      }
      else {

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
