#include "libraries.h"
#include "constants.h"

/* print error message to stderr */
void printError(char * errorMsg)
{
  fprintf(stderr, errorMsg);
  fflush(stderr);
  exit(1);
}


/* print error message using perror */
void printPerror(char * errorMsg)
{
  perror(errorMsg);
  fflush(stderr);
  exit(1);
}


/* Returns the number of string tokens with delimiter '-' using the file as the string */
int tokenCount(char * string, char delim)
{
  int numTokens = 1;
  int i = 0;
  
  for(i = 0; i < strlen(string); i++)
  {
    if(string[i] == delim)
      numTokens++;
  }
  
  return numTokens;
}


/* Returns an array of string tokens using '-' as the delimitor */
char ** tokenize(char string[], char delimiter)
{

  int numTokens = tokenCount(string, delimiter);
  char ** strTokens = malloc(numTokens*sizeof(char *));
  char delim[2];
  char newString[strlen(string) + 1];
  int i = 0;
  
  /* Make a copy of the string */
  strcpy(newString, string);

  delim[0] = delimiter;
  delim[1] = '\0';

  char * token = strtok(newString, delim);
  strTokens[0] = malloc(strlen(token) + 1);
  strcpy(strTokens[0], token);
  

  i = 1;
  /* fill strTokens[] with each token */
  while((token = strtok(NULL, delim)) != NULL)
  {
    strTokens[i] = malloc(strlen(token) + 1);
    strcpy(strTokens[i], token);
    i++;
  }
  
  return strTokens;
}



/* This function will append onto oldPath a '/' character followed by the contents of newDirectory */
char * modifyPath(char * oldPath, char * newDirectory)
{
  char * newPath;
  char slash[2] = "/";
  
  if(strlen(oldPath) < 1 || strlen(newDirectory) < 1)
  {
    printError("ERROR: Cannot pass an empty string into the parameters of getPath()\n");
  }
  else
  {
    newPath = malloc(1 + strlen(oldPath) + strlen(newDirectory));
    
    strcat(newPath, oldPath);
    
    if(oldPath[strlen(oldPath)] != '/')
      strcat(newPath, slash);
      
    strcat(newPath, newDirectory);
  }
  
  return newPath;
}


/* opens a directory, prints error if it doesn't exist */
DIR* openDirectory(char * targetDirectory)
{
  DIR* dirptr;
  
  if ((dirptr = opendir(targetDirectory)) == NULL)
    printPerror("ERROR: directory could not be opened.\n");
  
  return dirptr;
}


/* Returns the current working directory. */
char * getCWD()
{
  char cwd[LINE_MAX];
  char * currentDir = malloc(LINE_MAX);
  
  if(getcwd(cwd, sizeof(cwd)) != NULL)
  {
    strcpy(currentDir, cwd);
    return currentDir;
  }
  else
  {
    printPerror("ERROR: Failed to return cwd path.\n");
  }
}



