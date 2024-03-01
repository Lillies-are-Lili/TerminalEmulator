/**
@author Lillian Ngohuynh
*/
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define _POSIX_SOURCE

#include <ctype.h>

/**
 * Function declarations
*/
void chgDir(char* path, char* currDir);
void showpid(int idList[]);


/**
main method
*/
int main(int argc, char **argv){

	/**
	 * Declaring and initializing variables
	*/
int execStatus = 0;
int trackNum = 0; //to track the number of arguments
int i = 0;
int j = 0; //track list
pid_t pid;
int tokencount = 0;
//pid_t child;
int *status = 0;
int idList[5] = {0, 0, 0, 0, 0};  
char currDir[1000];
char str[1000] = "";
char* tokenArr; //token array for strtok() function
char* argumentList[10]; //allows memory for 10 space-separated tokens
char* command = "";


// Malloc a char* pointer with length 81 and initialize it to null
for(i=0; i<10; i++){
		argumentList[i] = (char*)malloc(sizeof(char)*81);
		argumentList[i] = NULL;
	}	


	if ( (getcwd(currDir,1000)) == NULL){
		perror("getcwd() error");
	}//ending if


while(1)
{
//get user input using fgets
	printf("\033[0;31m%s$ ", currDir);//this prints current directory + $
	printf("\033[0m"); //reset from red

	if( fgets(str, 1000, stdin) != NULL) {
//printf("User inputted string: %s\n", str);
            char *p;
            //strchr checks if the str contains a newline character, and put that into p
			p=strchr(str, '\n');
            if(p != NULL) {
                *p = 0;
            } 
            else  {
                //clear upto newline
                scanf("%*[^\n]");
                scanf("%*c");
            }
	}
  //Remove the '\n' character from fgets
        for(i=0; i < strlen(str); i++) {
            if(str[i] == '\n')   {
                str[i] = '\0'; //\0 is null or null terminator. replace new line w/ \0.
                break;
            }
        }

/**
 * Built in exit function
*/
	if( strncmp(str, "exit", 4) == 0 ){
		printf("EXITING!\n");
		break;
	}

/**
parses command and arguments
*/
//using strtok to create tokens and count each token as 1 word
	 tokenArr = strtok(str, " ");     
	int i=0;
	while(tokenArr != NULL)
	{
		if( i == 0)
			{
			command = strdup(tokenArr);
			}	
		argumentList[i] = strdup(tokenArr);
		trackNum++;
		tokencount++;
		//	printf("command: %s\n", command);
//	printf("argument list: %s\n", argumentList[i]);
		tokenArr = strtok(NULL, " ");
		i++;
	}//ending while loop



/**
more built-in commands, body of functions below
*/

 if( strcmp(command, "cd") == 0 )
		{
/**
	if(argumentList[1] == NULL){
	fprintf(stderr, "expected argument to cd command.\n");
}
*/
		chgDir(argumentList[1], currDir);
		}	



 else if( strcmp(command, "showpid") == 0){
	showpid(idList);
} 


/** 
command execution if not built-in command
*/
else{
 if((pid = fork()) ==0){
	//child process code goes here
  //printf("fork is successful,child pid: %d\n", getpid());
	execStatus = execvp(command, argumentList);
	if(execStatus == -1) {
		printf("Error: Command could not be executed\n");
		exit(1);
	}
	else if (execStatus == 0){
printf("Command successful, Execstatus: %d\n", execStatus);
}
		kill(pid, SIGTERM);
}

else if (pid < 0){
        printf("Error in fork execution.\n");
        printf("Parent process. pid is: %d\n" , getpid());
}

 else{
	//parent process code goes here
	if(j == 5){					
		j = 0;
	}
	idList[j] = pid;
	j++;
		//parent process (your shell program itself)
	waitpid(pid, status, 0); 
}
}// ending else for command execution

    // Reset variables
		for(i=0; i<argc; i++)
		{
			argumentList[i] = NULL;
		}	
		
        tokencount = 0;
		argc=0;		
} //ending while loop

	// Free argumentList pointers
	for(i=0; i<argc; i++)
	{
		free(argumentList[i]);
	}	
	
    return 0;

}//ending main function

/**
chDir method
*/
void chgDir(char* path, char* currDir)
{
	if(chdir(path) == -1)
	{
		printf("Error: cannot change directory\n");
		return;
	}
	if( (getcwd(currDir,1000)) == NULL) 
	{
		perror("getcwd() error");
	}
	setenv("pwd", currDir, 1);
}

/**
showpid function
*/
void showpid(int idList[]){
int i = 0;
for(i=0; i< 5; i++){
	printf("%d\n", idList[i]);
	}
 return;
}