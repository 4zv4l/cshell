#include <stdio.h>
#include "cmd.c"

int main(void){
    int err;
    while(err != -1){
        err = get_cmd();
    }
}