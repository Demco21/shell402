#include "libraries.h"
#include "constants.h"
#include "utils.h"

/* Executes the given command by creating a child process. */
int run_command(char ** command) 
{
  pid_t child;   /* Child pid returned by fork. */
  pid_t c;       /* Pid of child to be returned by wait. */
  
  /* Child process */
  if ((child = fork()) == 0) 
  {
    /* Execute the program given by the parameter command. */
    execvp(command[0], command);
    
    /* If this point is reached, then execvp must have failed. */
    printError("ERROR: Invalid command passed to execvp.\n");
  }
  
  /* Parent process. */
  else 
  {
    if (child == (pid_t)(-1)) 
      printError("Fork failed.\n");
    else
      c = wait(NULL); /* Wait for child to complete. Ignore the exit status of child. */
      
    return 0;
  }
}

/* Tokenizes 'line' by spaces and fills 'argbuf' with each token plus a NULL token at the end */
void parse_line(char * line, char ** argbuf)
{
  int numTokens = 0;
  numTokens = tokenCount(line, ' ');

  /* Only execute tokenizing if there is a correct number of commands */
  if(numTokens > 0 && numTokens < MAX_COMMAND)
  {
    char ** tokens = malloc(numTokens*sizeof(char *));
    tokens = tokenize(line, ' ');

    int i;
    for(i = 0; i < numTokens; i++)
      argbuf[i] = tokens[i];
      
    argbuf[numTokens] = NULL;
    free(tokens);
  }
  else
  {
    argbuf[0] = NULL;
  }

}