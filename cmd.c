#include "check.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#define PROMPT "> "

// execute the command in a child process
int exec(char *cmd[]){
    if(!strcmp(cmd[0], "exit")){
        return -1;
    }
    if(fork() == 0){
        execvp(cmd[0],cmd);
        int i=0;
        while(cmd[i]!= NULL){
            printf("%s ",cmd[i++]);
        }
        printf(" : command not found...\n");
        return 0;
    }else{
        wait(NULL);
    }
    return 0;
}

// separate the command in arguments
int get_arg(char* cmd){
    int i = 0;
    char *arg[33];
    char *tok = strtok(cmd, " ");

    while (tok != NULL){
        arg[i++] = tok;
        tok = strtok(NULL, " ");
    }
    arg[i++] = NULL;
    check(arg) ? i = exec(arg) : 0; // if not special cmd exec()
    return i;
}

// get the command
int get_cmd(void){
    char *cmd = readline(PROMPT);
    if(!strcmp(cmd,"")){
        return 0;
    }
    return get_arg(cmd);
}