#include "libraries.h"
#include "constants.h"
#include "utils.h"


/* Reads one line from a given file and returns that line as char* */
char* getLine(FILE* stream)
{
  if(stream == NULL)
    printError("ERROR: Invalid file stream.\n");

  
  char* lineBuffer = malloc(LINE_MAX*sizeof(char));
  char ch;
  int i = 0;
  
  /* Set the first character to the null terminating character */
  lineBuffer[0] = '\0';
  
  /* Adds one character into the string and pushes the null terminating character forward until newline is reached */
  while((ch = getc(stream)) != EOF)
  {
    if(ch == '\n')
    {
      break;
    }
    else
    {
      lineBuffer[i] = ch;
      lineBuffer[i+1] = '\0';
      i++;
    }
  }
  
  /* If the first character is the null terminating character then no line was read */
  if(lineBuffer[0] == '\0')
    return NULL;
  
  return lineBuffer;
}