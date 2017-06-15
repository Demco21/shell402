
void printError(char * errorMsg);

void printPerror(char * errorMsg);

int tokenCount(char * string, char delim);

char ** tokenize(char string[], char delim);

DIR* openDirectory(char * targetDirectory);

char * getCWD();

char * modifyPath(char * oldPath, char * newDirectory);
