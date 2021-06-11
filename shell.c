#include <stdio.h>
#include "pkg/cmd.c"

int main(void){
    int err;
    while(err != -1){ // exit will return -1
        err = get_cmd();
    }
}