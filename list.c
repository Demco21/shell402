#include "libraries.h"
#include "constants.h"
#include "utils.h"
#include "listFunctions.h"

void main(int argc, char ** argv)
{
  /* list */
  if(argc == 1)
  {
    char * pathname = getCWD();
    list(pathname);
  }
  /* list -i */
  else if(argc == 2 && strcmp(argv[1], INFO_FLAG) == 0)
  {
    char * pathname = getCWD();
    listi(pathname);
  }
  /* list -i pathname */
  else if(argc == 3 && strcmp(argv[1], INFO_FLAG) == 0)
  {
    char * pathname = argv[2];
    listi(pathname);
  }
  /* list -h */
  else if(argc == 2 && strcmp(argv[1], HIDDEN_FLAG) == 0)
  {
    char * pathname = getCWD();
    listh(pathname);
  }
  /* list -h pathname */
  else if(argc == 3 && strcmp(argv[1], HIDDEN_FLAG) == 0)
  {
    char * pathname = argv[2];
    listh(pathname);
  }
  /* list pathname */
  else if(argc == 2)
  {
    char * pathname = argv[1];
    list(pathname);
  }
  else
  {
    printError("ERROR: Wrong number of arguments.\n");
  }
}