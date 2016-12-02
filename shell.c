//Jennifer Yu and John Park
//11-23-16

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

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

char **splitnsep(char *input, char *sym) {
  char *temp = input;

  int i = 0;
  char **arr = (char **)(malloc(100));

//SEPARATE
  while (temp) {
    arr[i] = strsep(&temp, sym);
    i++;
  }
  arr[i] = NULL;

  return arr;
}

void forkpls(char *arr[]) {
  int f = fork();
  if ( f == 0 ) {
    execvp(arr[0], arr);
  }
  else {
    wait(&f);
  }
}

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

char *fireblanks(char *input) {
  char * temp = (char*)malloc(100);
  int i;
  for (i = 0; input[i] != '\0'; i++) {
    if ( !(input[i] == ' ' && (strlen(temp)==0 || input[i+1] == '\0' || input[i+1] == ' ')) ) {
      sprintf(temp, "%s%c", temp, input[i]);
    }
  }
  return temp;
}

int main() {

while (1) {
  printf("What would you like to do? ");
  char input[60];
  fgets(input, sizeof(input), stdin);
  input[strlen(input)-1] = 0;

  char **pieces;
  pieces = splitnsep(input, ";");
/**
  // IDK HOW TO IMPLEMENT THIS PROB NOT GONNA
  int i = 0;
  while (pieces[i]) {
    pieces = (char**)splitnsep(pieces[i], " ");
    i++;
  }

**/

//PRINT PIECES

  int i;
    for (i = 0; pieces[i] != NULL; i++) {
      char * command_nonsplit = (char *)(malloc(100));
      char ** command = (char **)(malloc(100));

      command_nonsplit = fireblanks( pieces[i] );
      command = splitnsep(command_nonsplit, " ");
      /**
  while (pieces[i]) {
    printf("SC: %s\n", pieces[i]);
    i++;
  }
  **/

 // forkpls(pieces);

      if( !strcmp(command[0], "exit") ) {
	        exit(0);

      }

      else if ( !strcmp(command[0], "cd") ) {
          chdir("..");
}
          else if ( !strcmp(command[0], ">") ) {
         // greaterThan(command[0]);
          }

   else {
	forkpls(command);
      }

    }
  }

  return 0;
}

/**
 * GARBAGE DUMP
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