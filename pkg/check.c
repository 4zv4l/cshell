#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

// check if it's a reserved word
int check(char *cmd[]){
    if(!strcmp(cmd[0],"cd")){
        if(cmd[1] == NULL){
            return 0;
        }
        chdir(cmd[1]);
        if(errno != 0){
            perror("");
            errno = 0;
        }
        return 0;
    }
    return 1;
}