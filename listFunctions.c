#include "libraries.h"
#include "constants.h"
#include "utils.h"

/* Handles list with no flag */
void list(char * pathname)
{
  DIR * dirptr;
  struct dirent * dp;
    
  dirptr = openDirectory(pathname);
  
  /* Read in each file */
  while((dp = readdir(dirptr)) != NULL)
  {
    char * file = malloc(strlen(dp->d_name));
    strcpy(file, dp->d_name);
    
    /* Print the name of each file except hidden files */
    if(file[0] != HIDDEN_FILE)
      printf("%s\n", file);
  }
  
  closedir(dirptr);
}

/* Handles -i flag */
void listi(char * pathname)
{
  DIR * dirptr;
  struct dirent * dp;
    
  dirptr = openDirectory(pathname);
  
  /* Read in each file */
  while((dp = readdir(dirptr)) != NULL)
  {
    char * file = malloc(strlen(dp->d_name));
    strcpy(file, dp->d_name);
    char * filePath = modifyPath(pathname, file);
    
    struct stat fileStat;
    lstat(filePath, &fileStat);
    
    /* boolVal will be set to 0 if the file is a directory and nonzero if file is a regular file */
    int boolVal = S_ISREG(fileStat.st_mode);
    
    /* Get stats on all files except hidden files */
    if(file[0] != HIDDEN_FILE)
    {
      int filesize = fileStat.st_size;
      int permission = fileStat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
      int inode = fileStat.st_ino;
      
      printf("%s %d %o %d\n", file, filesize, permission, inode);
    }
  }
  closedir(dirptr);
}

/* Handles -h flag */
void listh(char * pathname)
{
  DIR * dirptr;
  struct dirent * dp;
    
  dirptr = openDirectory(pathname);
  
  /* Read in each file */
  while((dp = readdir(dirptr)) != NULL)
  {
    char * file = malloc(strlen(dp->d_name));
    strcpy(file, dp->d_name);
    
    /* Only print hidden files */
    if(file[0] == HIDDEN_FILE)
      printf("%s\n", file);
  }
  
  closedir(dirptr);
}
