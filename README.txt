There are two ways to execute the shell:

1. Type into the command line: shell402
This will execute the shell402 program and prompt the user for commands
at the command line until he or she decides to quit.

2. Type into the command line: shell402 <scriptfile>
where scriptfile is a file that contains commands to give to shell402
and shell402 will read each command line by line and execute them.
Each command should be separated by a newline.

Commands:

The create command can be used as follows:

create -f file 		  /*creates a new file with the name file*/
create -d directory       /*creates a new directory with the name directory*/
create -h oldfile newfile /*creates a hardlink to oldfile with the name newfile*/
create -s oldfile newfile /*creates a symbolic link to oldfile with the name newfile*/

The list command can be used as follows:

list         /*prints all non-hidden files in the current working directory*/
list path    /*prints all non-hidden files in the given path*/
list -i      /*prints all non-hidden files along with their size, octal permission bits, and inone number
               respectively in the current working directory*/ 
list -i path /*prints the same thing as "list -i" on the given path*/
list -h      /*prints all hidden files in the current working directory*/
list -h path /*prints all hidden files in the given path*/

The chwd command can be used as follows:

chwd path /*changes the current working directory to the given path*/

The wd command can be used to display the current working directory.
The quit command will kill all shell402 processes.

