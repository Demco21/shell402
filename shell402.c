#include "libraries.h"
#include "constants.h"
#include "utils.h"
#include "shellFunctions.h"
#include "input.h"

void main(int argc, char ** argv)
{
  if(argc > 2)
    printError("ERROR: Too many command line arguments.\n");
  
  /* Store the absolute path of the 'list' and 'create' programs */
  char * shellPath = getCWD();
  char * listPath = modifyPath(shellPath, "list");
  char * createPath = modifyPath(shellPath, "create");
  
  /* Handles a script file */
  if(argc == 2)
  {
    FILE* scriptStream;
    char* currentLine;
    char * command[MAX_COMMAND];
    
    if((scriptStream = fopen(argv[1], "r")) == NULL)
      printError("ERROR: Could not open file for reading.\n");

    /* Keep reading each line into 'currentLine' until the end of the script is reached */
    while((currentLine = getLine(scriptStream)) != NULL)
    {    
        /* Fill 'command' with each token of 'currentLine' tokenized by spaces with NULL as the last token */
        parse_line(currentLine, command);

        /* Handle each command accordingly */
        if(command[0] == NULL)
        {
          fprintf(stderr, "ERROR: Argument limit exceeded.\n");
          fflush(stderr);
        }
        else if(strcmp(command[0], EXIT_COMMAND) == 0)
        {
          puts("Goodbye!");
          fclose(scriptStream);
          break;
        }
        else if(strcmp(command[0], "wd") == 0)
        {
          printf("%s\n", getCWD());
        }
        else if(strcmp(command[0], "chwd") == 0)
        {
          if(chdir(command[1]) == -1)
            perror("ERROR: Failed to change current working directory.\n");
        }
        else
        {
          if(strcmp(command[0], "list") == 0)
            command[0] = listPath;
          if(strcmp(command[0], "create") == 0)
            command[0] = createPath;
            
          run_command(command);
        }
    }
  }
  /* Handles user input via stdin */
  else if(argc == 1)
  {
    char * userInput;
    char * command[5];
    
    do
    {
      printf("%s", SHELL_PROMPT);
      fflush(stdout);
      
      /* Read in each line the user enters into 'userInput' */
      if((userInput = getLine(stdin)) != NULL)
      {
        /* Fill 'command' with each token of 'userInput' tokenized by spaces with NULL as the last token */
        parse_line(userInput, command);
        
        /* Handle each command accordingly*/
        if(command[0] == NULL)
        {
          fprintf(stderr, "ERROR: Argument limit exceeded.\n");
          fflush(stderr);
        }
        else if(strcmp(command[0], "quit") == 0)
        {
          puts("Goodbye!");
          break;
        }
        else if(strcmp(command[0], "wd") == 0)
        {
          printf("%s\n", getCWD());
        }
        else if(strcmp(command[0], "chwd") == 0)
        {
          if(chdir(command[1]) == -1)
            perror("ERROR: Failed to change current working directory.\n");
        }
        else
        {
          if(strcmp(command[0], "list") == 0)
            command[0] = listPath;
          if(strcmp(command[0], "create") == 0)
            command[0] = createPath;
          
          run_command(command);
        }
      }
      
    }while(1);
  }
  
}
