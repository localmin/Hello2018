#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE* fp = NULL;
    if(argc < 2){
        fp = stdin;
    }else{
        fp = fopen(argv[1], "rb");
    }

    fclose(fp);
}
