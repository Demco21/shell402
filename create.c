#include "libraries.h"
#include "constants.h"
#include "utils.h"

void main(int argc, char ** argv)
{
  if(argc < 3 || argc > 4)
    printError("ERROR: Wrong number of arguments.\n");
    
  /* Handles -f flag */
  /* Creates argument 3 as a new file. */
  if(argc == 3 && strcmp(argv[1], FILE_FLAG) == 0)
  {
    char * filepath = argv[2];
    FILE *fileptr;
    
    /* Check if a file with the same name already exists. */
    if((fileptr = fopen(filepath, "r")) == NULL)
    {
      fclose(fileptr);
      if((fileptr = fopen(filepath, "w")) == NULL)
        printPerror("Could not create file.\n");
      fclose(fileptr);
    }
    else
    {
      printError("File already exists.\n");
      fclose(fileptr);
    }
  }
  /* handles -d flag */
  /* Creates argument 3 as a new directory. */
  else if(argc == 3 && strcmp(argv[1], DIR_FLAG) == 0)
  {
    char * dirpath = argv[2];
    DIR * dirptr;
    
    /* Check if a directory with the same name already exists */
    if((dirptr = opendir(dirpath)) == NULL)
    {
      if((mkdir(dirpath, DEFAULT_MODE)) == -1)
        printPerror("Could not create directory.\n");
      closedir(dirptr);
    }
    else
    {
      puts("Directory already exists.");
    }
  }
  /* handles -h flag */
  /* Creates a hardlink using argument 3 as the old file and argument 4 as the new hardlink */
  else if(argc == 4 && strcmp(argv[1], HARDLINK_FLAG) == 0)
  {
    FILE * fileptr;
    char * oldname = argv[2];
    char * linkname = argv[3];
    
    /* Check if the old file exists. */
    if((fileptr = fopen(oldname, "r")) == NULL)
      printPerror("Could not find file for linking.\n");
    fclose(fileptr);
    
    /* Hardlink the files. */
    if(link(oldname, linkname) == -1)
      printPerror("Could not create hard link.\n");
    
  }
  /* handles -s flag */
  /* Creates symbolic link using argument 3 as the old file and argument 4 as the new symbolic link */
  else if(argc == 4 && strcmp(argv[1], SYMLINK_FLAG) == 0)
  {
    FILE * fileptr;
    char * oldname = argv[2];
    char * linkname = argv[3];
    
    /* Check if the old file exists. */
    if((fileptr = fopen(oldname, "r")) == NULL)
      printPerror("Could not find file for linking.\n");
    fclose(fileptr);
    
    /* Symbolic link the files. */
    if(symlink(oldname, linkname) == -1)
      printPerror("Could not create symbolic link.\n");
  }
  else
  {
    printError("ERROR: Invalid command.\n");
  }
}